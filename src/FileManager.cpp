

#include "FileManager.h"
#include "MarketDataContainer.h"

FileManager::FileManager()
{
	outputFile = fopen("MultiPlexedFile.txt","w");
	cout << "FileManager Created" << endl;
}

FileManager::~FileManager()
{
	fclose(outputFile);
	outputFile = nullptr;
	cout << "FileManager Destroyed" << endl;
}

void FileManager::insertStockFiles(int stockFilesCount_, char** stockFilesList_)
{
	for(int i=0; i<stockFilesCount_; i++)
	{
		StocksFileList.push_back({stockFilesList_[i],i});
	}
	cout << "Total Stock Files:" << StocksFileList.size() << endl;
}

int FileManager::readStockFiles()
{
	for(int i=0; i<StocksFileList.size(); i++)
	{
        FILE* files = fopen(StocksFileList[i].filename.c_str(), "r");
        if (!files) {
        	cout << StocksFileList[i].filename << endl;
            perror("Failed to open file");
            return EXIT_FAILURE;
        }
        // Set line buffering
        setvbuf(files, NULL, _IOLBF, 0);
        char LINE[MAX_LINE_LEN];
        fgets(LINE, sizeof(LINE), files);
        memset(LINE,'\0',MAX_LINE_LEN);

        while (fgets(LINE, sizeof(LINE), files) != NULL)
        {
        	cout << LINE;
        }
	}
	return EXIT_SUCCESS;
}

void FileManager::writeToFile(MarketDataTick* tick)
{
	string dump_line = tick->fileMetaData.filename + ", " + tick->data;
	if(fputs(dump_line.c_str(),outputFile) == EOF)
	{
		perror("Failed to write to File");
		fclose(outputFile);
		abort();
	}
	readFile(tick->fileMetaData);
}

int FileManager::readFile(FilesMetadata fileMetaData)
{
    FILE* file = fopen(fileMetaData.filename.c_str(), "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    // Set line buffering
    setvbuf(file, NULL, _IOLBF, 0);
    char LINE[MAX_LINE_LEN];

    //skip the first line (Timestamp, Price, Size, Exchange, Type)
    if(fileMetaData.fileOffset==0) fgets(LINE, sizeof(LINE), file);
    else fseek(file, fileMetaData.fileOffset, SEEK_SET);  // Move to the saved offset

    memset(LINE,'\0',MAX_LINE_LEN);

    if (fgets(LINE, sizeof(LINE), file) != NULL) {
    	char timestamp[TIMESTAMP_LEN];
		char exchange[EXCHANGE_LEN];
		char data[MAX_LINE_LEN];

    	//2021-03-05 10:00:00.123, 228.5, 120, NYSE, Ask
//		sscanf(LINE, "%*10s %12s, %*f, %*d, %9s, %*4s", timestamp, exchange);
		sscanf(LINE, "%29[^,], %*f, %*d, %9[^,], %*3s", timestamp, exchange);
    	strcpy(data,LINE);

    	fileMetaData.fileOffset = ftell(file);
    	MarketDataTick *tick = new MarketDataTick(timestamp,exchange,data,fileMetaData);
    	MarketDataContainer::getInstance()->pushToContainer(tick);
    }

    fclose(file);
	return EXIT_SUCCESS;
}

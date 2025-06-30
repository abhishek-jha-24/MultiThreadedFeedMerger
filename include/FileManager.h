/*
 * FileManager.h
 *
 *  Created on: 30-06-2025
 *      Author: Abhishek
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include "CommonStrctures.h"

class FileManager {

	vector<FilesMetadata> StocksFileList;
	FILE* outputFile = nullptr;

public:
	FileManager();
	~FileManager();
	void insertStockFiles(int stockFilesCount_, char** stockFilesList_);
	int readStockFiles();
	int readFile(FilesMetadata fileMetaData);
	void writeToFile();

	inline const int GetStockFileListSize()			 		const {return StocksFileList.size();}
	inline const vector<FilesMetadata>& getStocksFileList() const {return StocksFileList;}
	inline FilesMetadata getFileName(int num) 				const {return StocksFileList[num];}
};

#endif /* FILEMANAGER_H_ */

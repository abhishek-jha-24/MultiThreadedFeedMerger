
#include "GlobalMembers.h"

int main(int argc, char** argv) {

#ifdef UNIT_TESTING
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#endif

	int stocksCount = argc-1;	// ./exe file1 file2 .. ..
	char** stockFiles = argv+1;

	InitializeGlobalMembers();
	GetFileManager()->insertStockFiles(stocksCount,stockFiles);
//	GetFileManager()->readStockFiles();
	SpawnThreadWorkers();
	DumpFeed();
	DestroyGlobalMembers();

	cout << "FeedMerger End Successfully :)" << endl;

	return 0;
}

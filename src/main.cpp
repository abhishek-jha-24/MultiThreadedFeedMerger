//============================================================================
// Name        : FeedMerger
// Author      : Abhishek Jha
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GlobalMembers.h"

int main(int argc, char** argv) {


	int stocksCount = argc-1;	// ./exe file1 file2 .. ..
	char** stockFiles = argv+1;

	InitializeGlobalMembers();
	
	cout << "FeedMerger End Successfully :)" << endl;

	return 0;
}

/*
 * GlobalMembers.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "ConfigReader.h"
#include "GlobalMembers.h"


void InitializeGlobalMembers()
{
	ConfigReader::getInstance("FeedMerger.cfg");
	
}


void SpawnThreadWorkers()
{
	std::cout << "SpawnThreadWorkers" << std::endl;
}


void DestroyGlobalMembers()
{
	
	cout << "Global Member Destroyed Successfully" << endl;
}

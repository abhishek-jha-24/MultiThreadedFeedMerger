

#include "MarketDataContainer.h"
#include "FileManager.h"

extern FileManager *fm;

MarketDataContainer* MarketDataContainer::obj = nullptr;
mutex MarketDataContainer::mtx;

void MarketDataContainer::pushToContainer(MarketDataTick *tick_)
{
	//Multithreading Protection
	lock_guard<mutex> lock(mtx);
	PQ.push(tick_);
}

MarketDataContainer::MarketDataContainer()
{
	cout << "market data container default constructor called" << endl;
}


MarketDataContainer::~MarketDataContainer()
{
cout << "market data container destructed!" << endl;
}

void MarketDataContainer::popFromContainer()
{
	while(PQ.size()!=0)
	{
		MarketDataTick *tick= PQ.top();
		PQ.pop();
		fm->writeToFile(tick);
		delete tick;
	}
}

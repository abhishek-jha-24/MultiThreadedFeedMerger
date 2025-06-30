
#ifndef MARKETDATATICK_H_
#define MARKETDATATICK_H_

#include "CommonStrctures.h"

struct MarketDataTick {
    string timestamp;
    string exchange;
    string data;
    FilesMetadata fileMetaData;

public:
	MarketDataTick(string timestamp_, string exchange_, string data_, FilesMetadata fileMetaData_);
	virtual ~MarketDataTick();
};

#endif /* MARKETDATATICK_H_ */

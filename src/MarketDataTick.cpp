
#include "MarketDataTick.h"

MarketDataTick::MarketDataTick(string timestamp_, string exchange_, string data_, FilesMetadata fileMetaData_)
:timestamp(timestamp_),exchange(exchange_),data(data_),fileMetaData(fileMetaData_)
{

}

MarketDataTick::~MarketDataTick()
{

}

#include "Utils.h"


Utils::Utils()
{

}

Utils::~Utils()
{

}


long long Utils::CurrentTimeStamp()
{
	long long currentTime;
	auto timeEpoch = std::chrono::system_clock::now().time_since_epoch();
	currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeEpoch).count();
	return currentTime;
}
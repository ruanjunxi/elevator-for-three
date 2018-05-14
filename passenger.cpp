#include"passenger.h"
void Passenger::setRequestTime(int requesttime)  // 设置请求时间 
{
	requestTime = requesttime;
}
void Passenger::setInitialFloor(int floor = 1)   // 设置乘客所在楼层 
{
	initialFloor = floor;
}
void  Passenger::setDestination(int dest)   // 设置目的地 
{
	destination = dest;
}
int   Passenger::getRequestTime()
{
	return requestTime;
}
int  Passenger::getInitialFloor()
{
	return initialFloor;
}
int  Passenger::getDestination()
{
	return destination;
}
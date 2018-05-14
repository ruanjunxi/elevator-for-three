class Passenger
{
private:
	int requestTime;
	int initialFloor;
	int destination;
public:
	int flag;  // 0 代表未上电梯 1代表上了电梯  -1代表结束行程
	void setRequestTime(int request_time);
	void setInitialFloor(int floor);
	void setDestination(int dest);
	int getRequestTime();  //返回请求时间
	int getInitialFloor();   // 返回请求楼层
	int getDestination();  // 返回目的地
};


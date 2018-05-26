#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Elevator
{
private:
	int currentFloor;   // 电梯当前楼层 
	int direction;    // 1 代表向上  ，0 代表向下
public:
	Elevator(string type ,int dir = 1, int floor = 1, int pp = 0 );  // 电梯初始向上走 ,且电梯在第1层
	~Elevator();
	vector<int> v_request_time;  // 用户请求时间
	vector<int> v_initial_floor;  //请求楼层
	vector<int> v_destination;  // 目的地
	int state[500]; // // 0 代表未上电梯 1代表上了电梯  -1代表结束行程 用户状态
	bool start = false;  // 当start == true 则电梯开始运动
	string type;
	int population;
	void changeDirection(int dir);  // 改变电梯运行方向
	void move(int dir ,string tp);  // 电梯的移动
	int getCurrentFloor(); // 电梯当前楼层
	int getDirection();
};


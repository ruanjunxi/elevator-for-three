#include"elevator.h"
#include<iostream>
using namespace std;
Elevator::Elevator(string type ,int dir, int floor, int pp)  // 电梯初始向上走 ,且电梯在第0层
{
	direction = dir;
	currentFloor = floor;
	population = pp;
	this->type = type;
}
	void Elevator::changeDirection(int dir)   // 改变电梯运行方向
	{
		direction = dir;
	}
	void Elevator::move(int dir ,string tp)  // 电梯的移动  tp = type
	{
		if (tp == "odd")  //奇数
		{
			if (dir)  currentFloor+=2;
			else currentFloor-=2;
		}
		if (tp == "even") // 偶数
		{
			if (getCurrentFloor() == 1) currentFloor++; //电梯在一层往上
			else if (getCurrentFloor() == 2 && dir == 0) currentFloor--;  // 电梯在二层往下
			else if (dir)
			{
				currentFloor += 2;
			}
			else if (!dir)
			{
				currentFloor -= 2;
			}
		}
		else
		{
			if (dir)  currentFloor ++;
			else currentFloor --;
		}
	}
	int Elevator::getCurrentFloor()  // 电梯当前楼层
	{
		return currentFloor;
	}
	int Elevator::getDirection()
	{
		return direction;
	}
Elevator::~Elevator()
{
	cout << "析构函数" << endl;
}

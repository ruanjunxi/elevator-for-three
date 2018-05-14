#include"elevator.h"
#include<iostream>
using namespace std;
Elevator::Elevator(string type ,int dir, int floor, int pp)  // ���ݳ�ʼ������ ,�ҵ����ڵ�0��
{
	direction = dir;
	currentFloor = floor;
	population = pp;
	this->type = type;
}
	void Elevator::changeDirection(int dir)   // �ı�������з���
	{
		direction = dir;
	}
	void Elevator::move(int dir ,string tp)  // ���ݵ��ƶ�  tp = type
	{
		if (tp == "odd")  //����
		{
			if (dir)  currentFloor+=2;
			else currentFloor-=2;
		}
		if (tp == "even") // ż��
		{
			if (getCurrentFloor() == 1) currentFloor++; //������һ������
			else if (getCurrentFloor() == 2 && dir == 0) currentFloor--;  // �����ڶ�������
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
	int Elevator::getCurrentFloor()  // ���ݵ�ǰ¥��
	{
		return currentFloor;
	}
	int Elevator::getDirection()
	{
		return direction;
	}
Elevator::~Elevator()
{
	cout << "��������" << endl;
}

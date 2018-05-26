#include<iostream>
#include<fstream>
#include<string>
#include"elevator.h"
#include"passenger.h"
using namespace std;
vector <int>::iterator j;   // 定义正向迭代器
int totalRequest = 0;
int oddRequest = 0 ,evenRequest = 0 ,allRequest = 0;
Elevator oddLift("odd");  // 奇数电梯  output1.txt
Elevator evenLift("even");  // 偶数电梯 output3.txt
Elevator elevator("all");  // 万能电梯 output2.txt
Passenger p[500];
void outputFile(string judge, int time, int floor ,char *output)
{
	ofstream fout;
	if (judge == "odd")
	{
		ofstream fout(output, ios::app);    //奇数电梯
		fout << "奇数电梯在" << time << "时刻停在" << floor << "楼层"<<endl;
	}
	else if (judge == "even")
	{
		ofstream fout(output, ios::app);   // 偶数电梯
		fout << "偶数电梯在" << time << "时刻停在" << floor << "楼层"<<endl;
	}
	else
	{
		ofstream fout(output, ios::app);  //万能电梯
		fout << "万能电梯在" << time << "时刻停在" << floor << "楼层"<<endl;
	}
	fout.close();
}
void  ReadData(char *input)
{
	ifstream fin(input);
	if (!fin)
	{
		cout << "no such file,please check the file name!" << endl;
		exit(0);
	}
	int n, a, b, c;
	fin >> n;
	totalRequest = n;
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b >> c;
		p[i].setRequestTime(a);
		p[i].setInitialFloor(b);
		p[i].setDestination(c);
	}
}
int main(int arc, char *argv[])
{
	if (arc <= 1 || arc > 5)
	{
		cout << "输入过多或过少命令，请重新输入" << endl;
	}
	for (int i = 1; i < arc; i++)
	{
		string temp = "txt";
		
	}
	int count = 0;
	ReadData(argv[1]);
	int currentTime = -1;
	/* 以下为数据存放  */
	for (int i = 0; i < totalRequest; i++)   // 将请求放入每个电梯的vector里
	{
		if (p[i].getInitialFloor() % 2 == 0 && p[i].getDestination() % 2 == 0) // 请求楼层和目的地均是偶数
		{
			evenLift.v_destination.push_back(p[i].getDestination());
			evenLift.v_initial_floor.push_back(p[i].getInitialFloor());
			evenLift.v_request_time.push_back(p[i].getRequestTime());
			evenLift.state[i] = 0; // 默认乘客状态未上电梯
			oddRequest++;
		}
		else if (p[i].getInitialFloor() % 2 != 0 && p[i].getDestination() % 2 != 0)  //均是奇数楼
		{
			oddLift.v_destination.push_back(p[i].getDestination());
			oddLift.v_initial_floor.push_back(p[i].getInitialFloor());
			oddLift.v_request_time.push_back(p[i].getRequestTime());
			oddLift.state[i] = 0;
			evenRequest++;
		}
		else
		{
			elevator.v_destination.push_back(p[i].getDestination());
			elevator.v_initial_floor.push_back(p[i].getInitialFloor());
			elevator.v_request_time.push_back(p[i].getRequestTime());
			elevator.state[i] = 0;
			allRequest++;
		}
	}
		/*                */
		while (1)
		{
			/*以下判断电梯是否进入工作状态*/
			if (!oddLift.start)  // 奇数电梯不在工作状态
			{
				for (j = oddLift.v_request_time.begin(); j != oddLift.v_request_time.end(); ++j) // 奇数电梯
				{
					if (*j <= currentTime)
					{
						oddLift.start = true;   // 有1个请求就进入工作
						break;
					}
				}
			}
			if (!evenLift.start)  //偶数电梯不在工作状态
			{
				for (j = evenLift.v_request_time.begin(); j != evenLift.v_request_time.end(); ++j) // 偶数电梯
				{
					if (*j <= currentTime)
					{
						evenLift.start = true;   // 有1个请求就进入工作
						break;
					}
				}
			}
			if (!elevator.start)   // 万能电梯不在工作状态
			{
				for (j = elevator.v_request_time.begin(); j != elevator.v_request_time.end(); ++j) // 奇数电梯
				{
					if (*j <= currentTime)
					{
						elevator.start = true;   // 有1个请求就进入工作
						break;
					}
				}
			}
			/*以上判断电梯是否进入工作状态*/

			/*以下判断哪些乘客可以上电梯*/
			int ifStop = 0;
			for (j = oddLift.v_request_time.begin(); j != oddLift.v_request_time.end(); ++j) // 奇数电梯
			{
				if (*j <= currentTime && oddLift.state[count] == 0 && oddLift.v_initial_floor[count] == oddLift.getCurrentFloor())
				{
					oddLift.state[count] = 1;
					oddLift.population++;
					ifStop++;
				}
				count++;
			}
			count = 0;
			for (j = evenLift.v_request_time.begin(); j != evenLift.v_request_time.end(); ++j) // 偶数电梯
			{
				if (*j <= currentTime && evenLift.state[count] == 0 && evenLift.v_initial_floor[count] == evenLift.getCurrentFloor())
				{
					evenLift.state[count] = 1;
					evenLift.population++;
					ifStop++;
				}
				count++;
			}
			count = 0;
			for (j = elevator.v_request_time.begin(); j != elevator.v_request_time.end(); ++j) // 万能电梯
			{
				if (*j <= currentTime && elevator.state[count] == 0 && elevator.v_initial_floor[count] == elevator.getCurrentFloor())
				{
					elevator.state[count] = 1;
					elevator.population++;
					ifStop++;
				}
				count++;
			}
			count = 0;
			/*以上判断上电梯*/
		/*以下判断是否有人下电梯*/
			for (j = oddLift.v_request_time.begin(); j != oddLift.v_request_time.end(); ++j) // 奇数电梯
			{
				if (oddLift.state[count] == 1 && oddLift.v_destination[count] == oddLift.getCurrentFloor()) // 判断是否有乘客下电梯
				{
					oddLift.state[count] = 0;
					oddLift.population--;
					ifStop++;
					outputFile("odd", currentTime, oddLift.getCurrentFloor(),argv[2]);
					oddLift.state[count] = -1;
				}
				count++;
			}
			count = 0;
			for (j = evenLift.v_request_time.begin(); j != evenLift.v_request_time.end(); ++j) // 偶数电梯
			{
				if (oddLift.state[count] == 1 && evenLift.v_destination[count] == evenLift.getCurrentFloor())
				{
					evenLift.state[count] = 0;
					evenLift.population--;
					ifStop++;
					outputFile("even", currentTime, evenLift.getCurrentFloor(),argv[4]);
					evenLift.state[count] = -1;
				}
				count++;
			}
			count = 0;
			for (j = elevator.v_request_time.begin(); j != elevator.v_request_time.end(); ++j) // 万能电梯
			{
				if (elevator.state[count] == 1 && elevator.v_destination[count] == elevator.getCurrentFloor())
				{
					elevator.state[count] = 0;
					elevator.population--;
					ifStop++;
					outputFile("all", currentTime, elevator.getCurrentFloor(),argv[3]);
					elevator.state[count] = -1;
				}
				count++;
			}
			count = 0;
			/*以上判断是否有人下电梯*/
			/*以下判断电梯内是否有人 无则停止*/
			if (oddLift.population == 0)  oddLift.start = false;
			if (evenLift.population == 0)  evenLift.start = false;
			if (elevator.population == 0)   elevator.start = false;
			/*以下电梯的运行*/
			if (ifStop) currentTime++;
			currentTime++;
			if (oddLift.start)
			{
				oddLift.move(oddLift.getDirection(), "odd");
			}
			if (evenLift.state)
			{
				evenLift.move(evenLift.getDirection(), "even");
			}
			if (elevator.start)
			{
				elevator.move(elevator.getDirection(), "all");
			}
			/*以上电梯的运行*/
		   /*以下是电梯的更改方向*/
			if ((oddLift.getCurrentFloor() == 9 && oddLift.getDirection() == 1) || (oddLift.getCurrentFloor() == 1 && oddLift.getDirection() == 0))
				oddLift.changeDirection(oddLift.getDirection());
			if ((evenLift.getCurrentFloor() == 10 && evenLift.getDirection() == 1) || (evenLift.getCurrentFloor() == 1 && evenLift.getDirection() == 0))
				evenLift.changeDirection(evenLift.getDirection());
			if ((elevator.getCurrentFloor() == 10 && elevator.getDirection() == 1)|| (elevator.getCurrentFloor() == 1 && elevator.getDirection() == 0))
				elevator.changeDirection(elevator.getDirection());
			/*以上是改变电梯的方向*/
			/*以下是退出判断*/
			int judgeForOut = 0;
			for (int i = 0; i < oddRequest; i++)
			{
				if (oddLift.state[i] != -1) 
				{
					judgeForOut++;
					break;
				}
			}
			for (int i = 0; i < evenRequest; i++)
			{
				if (evenLift.state[i] != -1)
				{
					judgeForOut++;
					break;
				}
			}
			for (int i = 0; i < allRequest; i++)
			{
				if (elevator.state[i] != -1)
				{
					judgeForOut++;
					break;
				}
			}
			if (judgeForOut == 0) return 0;
		}
return 0;
	}
	

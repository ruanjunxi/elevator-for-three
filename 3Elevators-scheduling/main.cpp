#include<iostream>
#include<fstream>
#include<string>
#include"elevator.h"
#include"passenger.h"
using namespace std;
vector <int>::iterator j;   // �������������
int totalRequest = 0;
int oddRequest = 0 ,evenRequest = 0 ,allRequest = 0;
Elevator oddLift("odd");  // ��������  output1.txt
Elevator evenLift("even");  // ż������ output3.txt
Elevator elevator("all");  // ���ܵ��� output2.txt
Passenger p[500];
void outputFile(string judge, int time, int floor ,char *output)
{
	ofstream fout;
	if (judge == "odd")
	{
		ofstream fout(output, ios::app);    //��������
		fout << "����������" << time << "ʱ��ͣ��" << floor << "¥��"<<endl;
	}
	else if (judge == "even")
	{
		ofstream fout(output, ios::app);   // ż������
		fout << "ż��������" << time << "ʱ��ͣ��" << floor << "¥��"<<endl;
	}
	else
	{
		ofstream fout(output, ios::app);  //���ܵ���
		fout << "���ܵ�����" << time << "ʱ��ͣ��" << floor << "¥��"<<endl;
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
		cout << "������������������������" << endl;
	}
	for (int i = 1; i < arc; i++)
	{
		string temp = "txt";
		
	}
	int count = 0;
	ReadData(argv[1]);
	int currentTime = -1;
	/* ����Ϊ���ݴ��  */
	for (int i = 0; i < totalRequest; i++)   // ���������ÿ�����ݵ�vector��
	{
		if (p[i].getInitialFloor() % 2 == 0 && p[i].getDestination() % 2 == 0) // ����¥���Ŀ�ĵؾ���ż��
		{
			evenLift.v_destination.push_back(p[i].getDestination());
			evenLift.v_initial_floor.push_back(p[i].getInitialFloor());
			evenLift.v_request_time.push_back(p[i].getRequestTime());
			evenLift.state[i] = 0; // Ĭ�ϳ˿�״̬δ�ϵ���
			oddRequest++;
		}
		else if (p[i].getInitialFloor() % 2 != 0 && p[i].getDestination() % 2 != 0)  //��������¥
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
			/*�����жϵ����Ƿ���빤��״̬*/
			if (!oddLift.start)  // �������ݲ��ڹ���״̬
			{
				for (j = oddLift.v_request_time.begin(); j != oddLift.v_request_time.end(); ++j) // ��������
				{
					if (*j <= currentTime)
					{
						oddLift.start = true;   // ��1������ͽ��빤��
						break;
					}
				}
			}
			if (!evenLift.start)  //ż�����ݲ��ڹ���״̬
			{
				for (j = evenLift.v_request_time.begin(); j != evenLift.v_request_time.end(); ++j) // ż������
				{
					if (*j <= currentTime)
					{
						evenLift.start = true;   // ��1������ͽ��빤��
						break;
					}
				}
			}
			if (!elevator.start)   // ���ܵ��ݲ��ڹ���״̬
			{
				for (j = elevator.v_request_time.begin(); j != elevator.v_request_time.end(); ++j) // ��������
				{
					if (*j <= currentTime)
					{
						elevator.start = true;   // ��1������ͽ��빤��
						break;
					}
				}
			}
			/*�����жϵ����Ƿ���빤��״̬*/

			/*�����ж���Щ�˿Ϳ����ϵ���*/
			int ifStop = 0;
			for (j = oddLift.v_request_time.begin(); j != oddLift.v_request_time.end(); ++j) // ��������
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
			for (j = evenLift.v_request_time.begin(); j != evenLift.v_request_time.end(); ++j) // ż������
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
			for (j = elevator.v_request_time.begin(); j != elevator.v_request_time.end(); ++j) // ���ܵ���
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
			/*�����ж��ϵ���*/
		/*�����ж��Ƿ������µ���*/
			for (j = oddLift.v_request_time.begin(); j != oddLift.v_request_time.end(); ++j) // ��������
			{
				if (oddLift.state[count] == 1 && oddLift.v_destination[count] == oddLift.getCurrentFloor()) // �ж��Ƿ��г˿��µ���
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
			for (j = evenLift.v_request_time.begin(); j != evenLift.v_request_time.end(); ++j) // ż������
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
			for (j = elevator.v_request_time.begin(); j != elevator.v_request_time.end(); ++j) // ���ܵ���
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
			/*�����ж��Ƿ������µ���*/
			/*�����жϵ������Ƿ����� ����ֹͣ*/
			if (oddLift.population == 0)  oddLift.start = false;
			if (evenLift.population == 0)  evenLift.start = false;
			if (elevator.population == 0)   elevator.start = false;
			/*���µ��ݵ�����*/
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
			/*���ϵ��ݵ�����*/
		   /*�����ǵ��ݵĸ��ķ���*/
			if ((oddLift.getCurrentFloor() == 9 && oddLift.getDirection() == 1) || (oddLift.getCurrentFloor() == 1 && oddLift.getDirection() == 0))
				oddLift.changeDirection(oddLift.getDirection());
			if ((evenLift.getCurrentFloor() == 10 && evenLift.getDirection() == 1) || (evenLift.getCurrentFloor() == 1 && evenLift.getDirection() == 0))
				evenLift.changeDirection(evenLift.getDirection());
			if ((elevator.getCurrentFloor() == 10 && elevator.getDirection() == 1)|| (elevator.getCurrentFloor() == 1 && elevator.getDirection() == 0))
				elevator.changeDirection(elevator.getDirection());
			/*�����Ǹı���ݵķ���*/
			/*�������˳��ж�*/
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
	

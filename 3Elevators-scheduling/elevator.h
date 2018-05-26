#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Elevator
{
private:
	int currentFloor;   // ���ݵ�ǰ¥�� 
	int direction;    // 1 ��������  ��0 ��������
public:
	Elevator(string type ,int dir = 1, int floor = 1, int pp = 0 );  // ���ݳ�ʼ������ ,�ҵ����ڵ�1��
	~Elevator();
	vector<int> v_request_time;  // �û�����ʱ��
	vector<int> v_initial_floor;  //����¥��
	vector<int> v_destination;  // Ŀ�ĵ�
	int state[500]; // // 0 ����δ�ϵ��� 1�������˵���  -1��������г� �û�״̬
	bool start = false;  // ��start == true ����ݿ�ʼ�˶�
	string type;
	int population;
	void changeDirection(int dir);  // �ı�������з���
	void move(int dir ,string tp);  // ���ݵ��ƶ�
	int getCurrentFloor(); // ���ݵ�ǰ¥��
	int getDirection();
};


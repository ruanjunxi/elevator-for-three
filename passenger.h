class Passenger
{
private:
	int requestTime;
	int initialFloor;
	int destination;
public:
	int flag;  // 0 ����δ�ϵ��� 1�������˵���  -1��������г�
	void setRequestTime(int request_time);
	void setInitialFloor(int floor);
	void setDestination(int dest);
	int getRequestTime();  //��������ʱ��
	int getInitialFloor();   // ��������¥��
	int getDestination();  // ����Ŀ�ĵ�
};


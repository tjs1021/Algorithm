#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Deque {
	int front = 0;
	int back = 0;
	int data[MAX_SIZE];

public:
	int empty() { //���� ���� ���� �Լ�
		return (front == back); //front�� back�� ���ٸ� �������
	}
	
	int full() { //��ȭ ���� ���� �Լ�
		return (front == ((back + 1) % MAX_SIZE)); //back�� �� ĭ �Ѿ�� front��� �� ������
	}
	void push_front(int item) { //front�� ���� �Լ�
		if (full())
			cout << "���� ��ȭ �����Դϴ�" << endl;
		else {
			data[front] = item;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}
	void push_back(int item) { //back�� ���� �Լ�
		if (full())
			cout << "���� ��ȭ �����Դϴ�" << endl;
		else {
			back = (back + 1) % MAX_SIZE;
			data[back] = item;
		}
	}
	void pop_front() { //front ���� �Լ�
		if (empty())
			cout << "���� ���� �����Դϴ�" << endl;
		else {
			front = (front + 1) % MAX_SIZE;
		}
	}
	void pop_back() { //back ���� �Լ�
		if (empty())
			cout << "���� ���� �����Դϴ�" << endl;
		else {
			back = (back - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}
	void print_deque() { //deque ��� �Լ�
		//front+1���� back������ ����ؾ���
		int index = (front + 1) % MAX_SIZE;
		while (index != back) {
			cout << data[index] << " ";
			index = (index + 1) % MAX_SIZE;
		}
		cout << data[back];
	}
};

int main() {
	Deque dq;
	dq.push_front(3);
	dq.push_front(2);
	dq.push_back(1);
	dq.push_front(5);
	dq.pop_back();
	dq.push_back(6);
	dq.pop_front();
	dq.print_deque();
}
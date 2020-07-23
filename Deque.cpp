#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Deque {
	int front = 0;
	int back = 0;
	int data[MAX_SIZE];

public:
	int empty() { //공백 상태 검출 함수
		return (front == back); //front와 back이 같다면 비어있음
	}
	
	int full() { //포화 상태 검출 함수
		return (front == ((back + 1) % MAX_SIZE)); //back이 한 칸 넘어가서 front라면 꽉 차있음
	}
	void push_front(int item) { //front에 삽입 함수
		if (full())
			cout << "현재 포화 상태입니다" << endl;
		else {
			data[front] = item;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}
	void push_back(int item) { //back에 삽입 함수
		if (full())
			cout << "현재 포화 상태입니다" << endl;
		else {
			back = (back + 1) % MAX_SIZE;
			data[back] = item;
		}
	}
	void pop_front() { //front 삭제 함수
		if (empty())
			cout << "현재 공백 상태입니다" << endl;
		else {
			front = (front + 1) % MAX_SIZE;
		}
	}
	void pop_back() { //back 삭제 함수
		if (empty())
			cout << "현재 공백 상태입니다" << endl;
		else {
			back = (back - 1 + MAX_SIZE) % MAX_SIZE;
		}
	}
	void print_deque() { //deque 출력 함수
		//front+1부터 back까지만 출력해야함
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
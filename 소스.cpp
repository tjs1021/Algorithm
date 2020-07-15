#include <iostream>
#include <cstring>
using namespace std;
/*
push X : 정수 X를 스택에 넣는 연산이다.
pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
size : 스택에 들어있는 정수의 개수를 출력한다.
empty : 스택이 비어있으면 1, 아니면 0을 출력한다.
top : 스택의 가장 위에 있는 정수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
*/
#define MAX_STACK_SIZE 100
int top = -1;
int stack[MAX_STACK_SIZE];

int empty() {  //스택이 비어있다면 1 리턴
	if (top <= -1)
		return 1;
	else
		return 0;

}

int full() { //스택이 꽉 찼다면 1 리턴
	if (top == (MAX_STACK_SIZE - 1))
		return 1;
	else
		return 0;

}

void push(int a) {
	if (full())
		cout << "스택이 꽉 찼습니다";
	else
	    stack[++top] = a;

}

void pop() {
	if (empty())
		cout << "스택이 비었습니다";
	else
		stack[top--];
}

int peek() {
	if (empty()) {
		cout << "스택이 비어있습니다";
		return 0;
	}
	else
		return stack[top];
}


int main() {
	int check_empty;
	int check_top;
	int x;
	while (true) {
		char input[100];
		cout << "명령을 입력하세요>>";
		cin >> input;
		if (strcmp(input, "push") == 0) {
			cin >> x;
			push(x);
		}
		else if (strcmp(input, "pop") == 0)
			pop();
		else if (strcmp(input, "size") == 0)
			cout << top + 1 << endl;
		else if (strcmp(input, "empty") == 0) {
			check_empty = empty();
			cout << check_empty << endl;
		}
		else if (strcmp(input, "top") == 0) {
			check_top = peek();
			cout << check_top<<endl;
		}
		else
			cout << "제대로입력하세요\n";
			

	}
	
}
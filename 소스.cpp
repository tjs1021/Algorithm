#include <iostream>
#include <cstring>
using namespace std;
/*
push X : ���� X�� ���ÿ� �ִ� �����̴�.
pop : ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
size : ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top : ������ ���� ���� �ִ� ������ ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
*/
#define MAX_STACK_SIZE 100
int top = -1;
int stack[MAX_STACK_SIZE];

int empty() {  //������ ����ִٸ� 1 ����
	if (top <= -1)
		return 1;
	else
		return 0;

}

int full() { //������ �� á�ٸ� 1 ����
	if (top == (MAX_STACK_SIZE - 1))
		return 1;
	else
		return 0;

}

void push(int a) {
	if (full())
		cout << "������ �� á���ϴ�";
	else
	    stack[++top] = a;

}

void pop() {
	if (empty())
		cout << "������ ������ϴ�";
	else
		stack[top--];
}

int peek() {
	if (empty()) {
		cout << "������ ����ֽ��ϴ�";
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
		cout << "����� �Է��ϼ���>>";
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
			cout << "������Է��ϼ���\n";
			

	}
	
}
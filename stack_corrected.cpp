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
int top = -1;
int stack[10001];

int empty() {  //������ ����ִٸ� 1 �����Ѵ�
	if (top <= -1)
		return 1;
	else
		return 0;

}

int full() { //������ �� á�ٸ� 1�� �����Ѵ�
	if (top == (10001 - 1))
		return 1;
	else
		return 0;

}

void push(int a) { //������ �� á���� üũ�ϰ� push�Ѵ�
	if (full())
		cout << "������ �� á���ϴ�"<<endl;
	else
		stack[++top] = a;

}

void pop() { //������ ����ִ��� üũ�ϰ� pop�Ѵ�
	if (empty())
		cout << "������ ������ϴ�"<<endl;
	else
		stack[top--];
}

int peek() { //������ ���� ���� ������ �����Ѵ�
	if (empty()) {
		cout << "������ ����ֽ��ϴ�" << endl;
		return 0;
	}
	else
		return stack[top];
}


int main() {
	int n; //����� ��
	int x; //push x
	int check_empty;
	int check_top;

	cout << "����� ���� �Է��ϼ���>>";
	cin >> n;
	for (int i = 0; i < n; i++) { //�Է¹��� ����� ����ŭ for���� ����
		char input[100];
		cout << "����� �Է��ϼ���>>";
		cin >> input;
		if (strcmp(input, "push") == 0) { //stack���� push�� �Ѵ�
			cin >> x;
			push(x);
		}
		else if (strcmp(input, "pop") == 0) //stack���� pop�� �Ѵ�
			pop();
		else if (strcmp(input, "size") == 0) //stack�� size�� ����Ѵ�
			cout << top + 1 << endl;
		else if (strcmp(input, "empty") == 0) { //stack�� ����ִ��� üũ�Ѵ�(����ִٸ� 1 ���)
			check_empty = empty();
			cout << check_empty << endl;
		}
		else if (strcmp(input, "top") == 0) { //stack�� ���� ���� ���� ����Ѵ�
			check_top = peek();
			cout << check_top << endl;
		}

	}
	cout << "�Է��� �� �ִ� ����� ���� �������ϴ�" << endl;

}
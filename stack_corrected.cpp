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
int top = -1;
int stack[10001];

int empty() {  //스택이 비어있다면 1 리턴한다
	if (top <= -1)
		return 1;
	else
		return 0;

}

int full() { //스택이 꽉 찼다면 1을 리턴한다
	if (top == (10001 - 1))
		return 1;
	else
		return 0;

}

void push(int a) { //스택이 꽉 찼는지 체크하고 push한다
	if (full())
		cout << "스택이 꽉 찼습니다"<<endl;
	else
		stack[++top] = a;

}

void pop() { //스택이 비어있는지 체크하고 pop한다
	if (empty())
		cout << "스택이 비었습니다"<<endl;
	else
		stack[top--];
}

int peek() { //스택의 가장 위의 정수를 리턴한다
	if (empty()) {
		cout << "스택이 비어있습니다" << endl;
		return 0;
	}
	else
		return stack[top];
}


int main() {
	int n; //명령의 수
	int x; //push x
	int check_empty;
	int check_top;

	cout << "명령의 수를 입력하세요>>";
	cin >> n;
	for (int i = 0; i < n; i++) { //입력받은 명령의 수만큼 for문이 실행
		char input[100];
		cout << "명령을 입력하세요>>";
		cin >> input;
		if (strcmp(input, "push") == 0) { //stack에서 push를 한다
			cin >> x;
			push(x);
		}
		else if (strcmp(input, "pop") == 0) //stack에서 pop을 한다
			pop();
		else if (strcmp(input, "size") == 0) //stack의 size를 출력한다
			cout << top + 1 << endl;
		else if (strcmp(input, "empty") == 0) { //stack이 비어있는지 체크한다(비어있다면 1 출력)
			check_empty = empty();
			cout << check_empty << endl;
		}
		else if (strcmp(input, "top") == 0) { //stack의 가장 위에 값을 출력한다
			check_top = peek();
			cout << check_top << endl;
		}

	}
	cout << "입력할 수 있는 명령의 수가 끝났습니다" << endl;

}
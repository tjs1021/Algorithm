//연결리스트 문제(백준1406번)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef char element;
typedef struct ListNode { //이중연결리스트
	element data;
	struct ListNode* llink;
	struct ListNode* rlink;
}ListNode;


void insert(ListNode* head,element value) {
	ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = value;
	newnode->llink = head;
	newnode->rlink = head->rlink;
	head->rlink->llink = newnode;
	head->rlink = newnode;

}

void print(ListNode* head) {
	ListNode* p;
	for (p = head->rlink; p != head;p= p->rlink)
		cout << p->data;
}

class Editor {
	ListNode *head; //첫번째문자의 왼쪽
	ListNode *tail; //마지막 문자의 오른쪽
	ListNode *cursor; //커서
		
public:
	void start() { //입력받은 문자열을 연결리스트로 만들고 첫번째문자열의 왼쪽에 헤드를,
		          // 마지막문자열의 오른쪽에 테일을 연결시킴
		head = (ListNode*)malloc(sizeof(ListNode));
		head->llink = head;
		head->rlink = head; //head노드

		tail = (ListNode*)malloc(sizeof(ListNode));
		tail->llink = head;
		tail->rlink = head->rlink;
		head->rlink->llink = tail;
		head->rlink = tail; //tail노드

		string str; //입력받은 문자열
		cin >> str;

		for (int i = str.size() - 1; i >= 0; i--) {	//입력한 문자를 이중연결리스트 노드로 insert
			insert(head, str.at(i));
		}
		cursor = (ListNode*)malloc(sizeof(ListNode)); //커서를 테일 노드로 설정
		cursor = tail;
	}
	void print() {
		ListNode* p;
		for (p = head->rlink; p != head; p = p->rlink)
			cout << p->data;
		cout << endl;
	}
	void L() { //커서를 왼쪽으로 한칸 옮김
		if(cursor!=head) //커서가 문장의 맨 앞이면 무시
		cursor = cursor->llink;
		//cout << "cursor=" << cursor->data << endl;
	}
	void D() { //커서를 오른쪽으로 한칸 옮김
		if (cursor != tail) //커서가 문장의 맨 뒤면 무시
			cursor = cursor->rlink;
		//cout << "cursor=" << cursor->data << endl;
	}
	void B() { //커서 왼쪽에 있는 문자 삭제함
		ListNode *removenode;
		if (cursor != head && cursor!=head->rlink) { //커서가 문장의 맨 앞이면 무시
			removenode = cursor->llink;
			removenode->llink->rlink = cursor;
			cursor->llink = removenode->llink;
			free(removenode);
		}
	//	print();
	}
	void P(char c) { //c라는 문자를 커서 왼쪽에 추가함
		ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
		newnode->data = c;
		if (cursor == head) { //커서가 head에 있을 때 
			//새로운 노드를 커서 왼쪽에 만들고 헤드를 그 노드 왼쪽으로 옮겨야함
			newnode->llink = head;
			newnode->rlink = head->rlink;
			head->rlink->llink = newnode;
			head->rlink = newnode;			
		}
		else {
			newnode->rlink = cursor;
			newnode->llink = cursor->llink;
			cursor->llink->rlink = newnode;
			cursor->llink = newnode;
		}
	//	print();
	}

};


int main() {
	string input; //입력 명령어
	int count; //입력할 횟수
	char c; //추가할 문자
	Editor e;
	e.start();
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> input;
		if (input == "L")
			e.L();
		else if (input == "print")
			e.print();
		else if (input == "D")
			e.D();
		else if (input == "P") {
			cin >> c;
			e.P(c);
		}
		else if (input == "B")
			e.B();		
	}
	e.print();
	
}



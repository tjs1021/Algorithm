//���Ḯ��Ʈ ����(����1406��)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef char element;
typedef struct ListNode { //���߿��Ḯ��Ʈ
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
	ListNode *head; //ù��°������ ����
	ListNode *tail; //������ ������ ������
	ListNode *cursor; //Ŀ��
		
public:
	void start() { //�Է¹��� ���ڿ��� ���Ḯ��Ʈ�� ����� ù��°���ڿ��� ���ʿ� ��带,
		          // ���������ڿ��� �����ʿ� ������ �����Ŵ
		head = (ListNode*)malloc(sizeof(ListNode));
		head->llink = head;
		head->rlink = head; //head���

		tail = (ListNode*)malloc(sizeof(ListNode));
		tail->llink = head;
		tail->rlink = head->rlink;
		head->rlink->llink = tail;
		head->rlink = tail; //tail���

		string str; //�Է¹��� ���ڿ�
		cin >> str;

		for (int i = str.size() - 1; i >= 0; i--) {	//�Է��� ���ڸ� ���߿��Ḯ��Ʈ ���� insert
			insert(head, str.at(i));
		}
		cursor = (ListNode*)malloc(sizeof(ListNode)); //Ŀ���� ���� ���� ����
		cursor = tail;
	}
	void print() {
		ListNode* p;
		for (p = head->rlink; p != head; p = p->rlink)
			cout << p->data;
		cout << endl;
	}
	void L() { //Ŀ���� �������� ��ĭ �ű�
		if(cursor!=head) //Ŀ���� ������ �� ���̸� ����
		cursor = cursor->llink;
		//cout << "cursor=" << cursor->data << endl;
	}
	void D() { //Ŀ���� ���������� ��ĭ �ű�
		if (cursor != tail) //Ŀ���� ������ �� �ڸ� ����
			cursor = cursor->rlink;
		//cout << "cursor=" << cursor->data << endl;
	}
	void B() { //Ŀ�� ���ʿ� �ִ� ���� ������
		ListNode *removenode;
		if (cursor != head && cursor!=head->rlink) { //Ŀ���� ������ �� ���̸� ����
			removenode = cursor->llink;
			removenode->llink->rlink = cursor;
			cursor->llink = removenode->llink;
			free(removenode);
		}
	//	print();
	}
	void P(char c) { //c��� ���ڸ� Ŀ�� ���ʿ� �߰���
		ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
		newnode->data = c;
		if (cursor == head) { //Ŀ���� head�� ���� �� 
			//���ο� ��带 Ŀ�� ���ʿ� ����� ��带 �� ��� �������� �Űܾ���
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
	string input; //�Է� ��ɾ�
	int count; //�Է��� Ƚ��
	char c; //�߰��� ����
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



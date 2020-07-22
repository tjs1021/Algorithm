#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> dq;
	int n; //ť��ũ��
	int m; //�̾Ƴ����� �ϴ� ���� ����
	int index; //�̾Ƴ����� ���� index
	int count = 0; //���� �̵�, ������ �̵��� �� Ƚ��
	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++) //n���� ���� 1~n ���� push
		dq.push_back(i);
	
	for (int i = 0; i < m; i++) {
		cin >> index; //�̾Ƴ� ��ġ�� �Է�

		//front�� ������� back�� ������� ��
		int dist_front, dist_back;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == index) { 
				dist_front = (i+1) - 1;
				dist_back = dq.size() - (i+1);
				break;
			}
		}

		if (dist_front <= dist_back) { //front�� �� ����� ���
			while(dq.front()!=index) { //front�� ���� �� ������ �� ������ ���ѷ���
				int front = dq.front(); 
				dq.pop_front();
				dq.push_back(front); //�������� �� ĭ �̵�
				count++;
			}
		}

		else { //back�� �� ����� ���
			while(dq.front()!=index) {
				int back = dq.back();
				dq.pop_back();
				dq.push_front(back); //���������� �� ĭ �̵�
				count++;
			}
		}
		dq.pop_front();

	}
	cout << count << endl;
}
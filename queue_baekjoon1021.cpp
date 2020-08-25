#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> dq;
	int n; //큐의크기
	int m; //뽑아내려고 하는 수의 개수
	int index; //뽑아내려는 수의 index
	int count = 0; //왼쪽 이동, 오른쪽 이동을 한 횟수
	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++) //n개를 덱에 1~n 각각 push
		dq.push_back(i);
	
	for (int i = 0; i < m; i++) {
		cin >> index; //뽑아낼 위치를 입력

		//front랑 가까운지 back과 가까운지 비교
		int dist_front, dist_back;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == index) { 
				dist_front = (i+1) - 1;
				dist_back = dq.size() - (i+1);
				break;
			}
		}

		if (dist_front <= dist_back) { //front와 더 가까울 경우
			while(dq.front()!=index) { //front가 내가 뺄 정수가 될 때까지 무한루프
				int front = dq.front(); 
				dq.pop_front();
				dq.push_back(front); //왼쪽으로 한 칸 이동
				count++;
			}
		}

		else { //back과 더 가까울 경우
			while(dq.front()!=index) {
				int back = dq.back();
				dq.pop_back();
				dq.push_front(back); //오른쪽으로 한 칸 이동
				count++;
			}
		}
		dq.pop_front();

	}
	cout << count << endl;
}

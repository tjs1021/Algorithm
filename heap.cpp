#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int min1, min2, mix;
	priority_queue<int,vector<int>,greater<int>> pq; //오름차순 정렬
	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);
	while (pq.top()<K) {
		min1 = pq.top();
		pq.pop();

		min2 = pq.top();
		pq.pop();

		mix = min1 + min2 * 2;
		pq.push(mix);
		answer++;
	}
	return answer;
}

int main() {
	int answer;
	vector<int> scoville = { 1,2,3,9,10,12};
	answer=solution(scoville,7);
	cout << answer;
}

#include <iostream>
#include <string>
#include <vector>
#define MAX 200
using namespace std;

//int cycle = 0;

bool dfs(int start, vector<vector<int>>& computers) {
	if (!computers[start][start]) 
		return false; //방문했으면 false

	computers[start][start] = 0; //방문한곳은 0으로 바꿔줌

	for (int i = 0; i < computers.size(); i++) {
		if (computers[start][i])  //연결되어 있다면
			dfs(i, computers);
	}
	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (dfs(i,computers)) //방문했던곳이 아니라면 answer++
			answer++;
	}
	return answer;
}

/*
void dfs(int start, vector<vector<int>> computers, int visited[]) {
	visited[start] = 1;

	for (int i = 0; i < computers.size(); i++)
		if (computers[start][i] && visited[i] != 1) {
			cycle++;
			dfs(i, computers, visited);
		}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int visited[MAX];
	int check = 0; //0이면 하나도 안이져있음


	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < n) { //하나도 안이어진 정점이 있는지 체크
			if (i != j && computers[i][j]) {
				check = 1;
				break;
			}
			j++;
		}
		cout << i << "정점의 check:" << check << endl;
		dfs(i, computers, visited);
		if (cycle != 0) { //다른 정점이랑 이어졌을 때 이어진 것들을 모두 한 그룹으로 묶음
			answer++;
			cycle = 0;
		}

		else if (check == 0) { //하나도 안이어져있는 정점이 있을 때 한 그룹으로 묶음
			answer++;
		}
		check = 0;
	}
	cout << answer << endl;
	return answer;
}

int main() {
	int visited[MAX];
	vector<vector<int>> computers = { {1,0,1,0,0},{0,1,0,0,0},{1,0,1,0,1},{0,0,0,1,0},{0,0,1,0,1} };

	solution(5, computers);

}
*/
#include <iostream>
#include <string>
#include <vector>
#define MAX 200
using namespace std;

//int cycle = 0;

bool dfs(int start, vector<vector<int>>& computers) {
	if (!computers[start][start]) 
		return false; //�湮������ false

	computers[start][start] = 0; //�湮�Ѱ��� 0���� �ٲ���

	for (int i = 0; i < computers.size(); i++) {
		if (computers[start][i])  //����Ǿ� �ִٸ�
			dfs(i, computers);
	}
	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (dfs(i,computers)) //�湮�ߴ����� �ƴ϶�� answer++
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
	int check = 0; //0�̸� �ϳ��� ����������


	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < n) { //�ϳ��� ���̾��� ������ �ִ��� üũ
			if (i != j && computers[i][j]) {
				check = 1;
				break;
			}
			j++;
		}
		cout << i << "������ check:" << check << endl;
		dfs(i, computers, visited);
		if (cycle != 0) { //�ٸ� �����̶� �̾����� �� �̾��� �͵��� ��� �� �׷����� ����
			answer++;
			cycle = 0;
		}

		else if (check == 0) { //�ϳ��� ���̾����ִ� ������ ���� �� �� �׷����� ����
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
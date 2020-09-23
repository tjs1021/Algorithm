#include <iostream>
#include <vector>
using namespace std;
#define INF -1
#define MAX 100

//vector<vector<int>> graph;
//vector<pair<int, int>> graph;
//vector<pair<int, int> > graph[MAX];
int graph[MAX][MAX];
int dist[MAX];
int visited[MAX] = { false };
int v; //정점의 개수

int find_shortest_node(int v) { //간선의 거리가 가장 작은 노드 리턴
	int min = -1;
	int min_distance = 100;
	
	for (int i = 1; i <= v; i++) {
		if (visited[i] == true) continue;
		if (dist[i] < min_distance) {
			min = i;
			min_distance = dist[i];
		}
	}
	return min;
}

void update_dist(int node,int v) {
	for (int i = 1; i <= v; i++) {		
		dist[i] = graph[node][i];
		if (visited[i] == true) continue;
		if (dist[i] > dist[node] + graph[node][i])
			dist[i] = dist[node] + graph[node][i];
	}
}

int digkstra(int start,int v) {
	int shortest_distance = 0;
	for (int i = 1; i <= v; i++)
		dist[i] = graph[start][i];
	dist[start] = 0;
	visited[start] = true;
	cout << start << "->";
	for (int i = 0; i < v - 1; i++) {
		int newnode = find_shortest_node(v);
		visited[newnode] = true;
		shortest_distance += graph[start][newnode];
		update_dist(newnode,v);		
		cout << newnode << "->"<<endl;
		cout << "dis=" << shortest_distance << endl;
	}
	return shortest_distance;
}


int main() {
	int N; //정점의 개수
	int E; //간선의 개수
	
	int v1, v2; //반드시 가야하는 정점 1,2
	int shortest_distance;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		graph[start][end] = weight;
		graph[end][start] = weight;

		//graph[start].push_back({ end,weight });
		
	}
	//cin >> v1 >> v2;
	cout << digkstra(1,N);
}




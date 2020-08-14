#include <iostream>
#include <vector>
using namespace std;
#define MAX_VERTICES 100 //최대 정점개수

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
};
int visited[MAX_VERTICES];

class Graph {
public:

	GraphType *g;
	int diameter = 0;
	int size;

	void set_size(int n) {
		size = n;
	}

	void init() {
		g = (GraphType*)malloc(sizeof(GraphType));
		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				g->adj_mat[i][j] = 0;
	}

	void insert_edge(int start, int end, int weight) { //간선 삽입 함수
		g->adj_mat[start][end] = weight; 
		g->adj_mat[end][start] = weight;
	}

	void find_diameter(int vertex) {
		visited[vertex] = true;
		int max_weight = 0; //이어져있는 정점 중 가장 먼 거리 저장
		int max_weight_vertex; //이어져있는 정점 중 가장 거리가 먼 정점
		vector<int> v;

		//cout << "g->adj_mat[1][2]= " << g->adj_mat[1][2] << endl;
		//cout << "visited[2]="<<visited[2] << endl;

		for (int i = 1; i <= size; i++) {
			if (g->adj_mat[vertex][i] != 0 && visited[i]==0) //vertex와 이어져있고 방문하지 않았으면
				v.push_back(i); //이어져있는 정점 v에 저장
		}
		if (!v.empty()) {
			for (int i = 0; i < v.size(); i++) { //가장 먼 거리 저장
				if (max_weight <= g->adj_mat[vertex][v[i]]) {
					max_weight = g->adj_mat[vertex][v[i]];
					max_weight_vertex = v[i];
				}
			}
			diameter += max_weight;
			find_diameter(max_weight_vertex);
		}

	}

	void init_graph() {
		diameter = 0;
		for (int i = 0; i < MAX_VERTICES; i++)
			if (visited[i] != 0)
				visited[i] = 0;
	}

};

int main() {
	Graph graph;
	
	int vertex_size;
	int start_vertex;
	int end_vertex=0;
	int weight;
	int diamter = 0;
	cin >> vertex_size;
	graph.set_size(vertex_size);
	
	graph.init();

	for (int i = 0; i < vertex_size; i++) {
		end_vertex = 0;
		cin >> start_vertex;
		while (end_vertex != -1) {
			cin >> end_vertex;
			if (end_vertex != -1) {
				cin >> weight;
				graph.insert_edge(start_vertex, end_vertex, weight);
			}
			else
				break;
		}
		
	}
	for (int i = 1; i <= vertex_size; i++) {
		graph.find_diameter(i);
		if (diamter <= graph.diameter)
			diamter = graph.diameter;
	}
	
	cout << diamter;
	
	
	
}


#include <iostream>
#include <vector>
using namespace std;
#define MAX_VERTICES 100 //�ִ� ��������

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

	void insert_edge(int start, int end, int weight) { //���� ���� �Լ�
		g->adj_mat[start][end] = weight; 
		g->adj_mat[end][start] = weight;
	}

	void find_diameter(int vertex) {
		visited[vertex] = true;
		int max_weight = 0; //�̾����ִ� ���� �� ���� �� �Ÿ� ����
		int max_weight_vertex; //�̾����ִ� ���� �� ���� �Ÿ��� �� ����
		vector<int> v;

		//cout << "g->adj_mat[1][2]= " << g->adj_mat[1][2] << endl;
		//cout << "visited[2]="<<visited[2] << endl;

		for (int i = 1; i <= size; i++) {
			if (g->adj_mat[vertex][i] != 0 && visited[i]==0) //vertex�� �̾����ְ� �湮���� �ʾ�����
				v.push_back(i); //�̾����ִ� ���� v�� ����
		}
		if (!v.empty()) {
			for (int i = 0; i < v.size(); i++) { //���� �� �Ÿ� ����
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


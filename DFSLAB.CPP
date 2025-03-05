#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &graph, bool visited[]) {
    visited[node] = true;
    cout << node << "  ";

    for (int i : graph[node]) {
        if (!visited[i]) {
            dfs(i, graph, visited);
        }
    }
}

int main() {
    int n = 7;
    vector<vector<int>> graph(n);
    bool visited[n] = {false};

    
    graph[0] = {1, 3};
    graph[1] = {4, 5};
    graph[2] = {};
    graph[3] = {2, 6};
    graph[4] = {3, 6};
    graph[5] = {};
    graph[6] = {5};
//0 1 4 3 2 6 5 
system("cls");
    cout << "DFS Traversal: \n";
    dfs(0, graph, visited);

    return 0;
}
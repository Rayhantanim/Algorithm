#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>> &graph, int st) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[st] = true;
    q.push(st);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i : graph[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u); 
    }

    int st;
    cout << "Enter the starting node: ";
    cin >> st;

    cout << "BFS starting from node " << st << ": ";
    BFS(graph, st);

    return 0;
}
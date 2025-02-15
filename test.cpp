#include <bits/stdc++.h>
using namespace std;

const int vertices = 8; 
vector<int> graph[vertices];
bool visited[vertices] = {false};
stack<int> Stack; 
void dfs(int node) {
    visited[node] = true;
    for(int i : graph[node]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    Stack.push(node);
}

void topologicalSort() {
    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    cout << "Topological Sort: ";
    while(!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

int main() {
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);
    graph[1].push_back(4);
    graph[3].push_back(4);
    graph[4].push_back(6);
    graph[4].push_back(5);
    graph[5].push_back(6);
    graph[6].push_back(7);
    topologicalSort();
    return 0;
}

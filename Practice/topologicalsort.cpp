#include <bits/stdc++.h>
#include<iostream>
using namespace std;

const int n = 6;
vector<int> g[n];
bool v[n] = {0};
stack <int> s;


void dfs(int nd){
    v[nd] = 1;
    for(int i : g[nd])
    {
        if(!v[i]) dfs(i);
    }
    s.push(nd);
}

void tsort(){
    for(int i=0; i<n; i++){
        if(!v[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    g[0] = {1,4,5};
    g[1] = {2,4};
    g[2] = {4,5};
    g[3] = {3};
    g[4] = {2,1};
    g[5] = {2,5,3};
    
    tsort();

    while(!s.empty()){
        cout << s.top() << "  ";
        s.pop();
    }
    return 0;
}
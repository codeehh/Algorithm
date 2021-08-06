#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 5;
vector<int> adj[N];
bool visited[N] = {false};
void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    cout << node << ' ';
    for (auto x : adj[node])
        dfs(x);
}

int main(void)
{
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(0);
    adj[4].push_back(1);
    adj[4].push_back(2);
    cout << "DFS" << endl;
    dfs(0);
    return 0;
}

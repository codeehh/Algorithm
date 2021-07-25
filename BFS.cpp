#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 5;
vector<int> adj[N];
bool visited[N] = {false};
int dist[N];
void bfs(int node)
{
    queue<int> q;
    cout << node << ' ';
    visited[node] = true;
    dist[node] = 0;
    q.push(node);

    while (!q.empty())
    {
        int now_node = q.front();
        q.pop();
        for (auto x : adj[now_node])
        {
            if (visited[x])
                continue;
            cout << x << ' ';
            visited[x] = true;
            dist[x] = dist[now_node] + 1;
            q.push(x);
        }
    }
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
    cout << "BFS" << endl;
    bfs(0);
    return 0;
}
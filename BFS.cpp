#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 5;
vector<int> adj[N];
bool visited[N] = {false};
int dist[N];
void bfs(int first_node)
{
    queue<int> q;
    dist[first_node] = 0;
    q.push(first_node);
    while (!q.empty())
    {
        int now_node = q.front();
        q.pop();
        if (visited[now_node])
            continue;
        visited[now_node] = true;
        cout << now_node << ' ';
        for (auto x : adj[now_node])
        {
            if (visited[x])
                continue;
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

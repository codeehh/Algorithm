#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
vector<pair<int, int>> adj[5];
priority_queue<pair<int, int>> pq;
int n = 5;
int dist[5];
int determined[5] = {false};

void Dijkstra(int x)
{
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
    }
    dist[x] = 0;
    pq.push({-dist[x], x});

    while (!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();
        if (determined[a])
            continue;
        determined[a] = true;
        for (auto aa : adj[a])
        {
            int b = aa.first;
            int w = aa.second;
            if (dist[b] > dist[a] + w)
            {
                dist[b] = dist[a] + w;
                pq.push({-dist[b], b});
            }
        }
    }
}

int main(void)
{
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 3});
    adj[0].push_back({3, 7});
    adj[1].push_back({0, 2});
    adj[1].push_back({3, 3});
    adj[1].push_back({4, 5});
    adj[2].push_back({0, 3});
    adj[2].push_back({3, 1});
    adj[3].push_back({0, 7});
    adj[3].push_back({1, 3});
    adj[3].push_back({2, 1});
    adj[3].push_back({4, 2});
    adj[4].push_back({1, 5});
    adj[4].push_back({3, 2});
    Dijkstra(0);
    cout << "Dijkstra" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << dist[i] << ' ';
    }
    return 0;
}
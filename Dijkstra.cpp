#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 5;
const int INF = 987654321;
vector<pair<int, int>> adj[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int dist[N];
int determined[N] = {false};

void Dijkstra(int x) {
    for (int i = 0; i < N; ++i)
        dist[i] = INF;
    dist[x] = 0;
    pq.push({dist[x], x});

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (determined[cur])
            continue;
        determined[cur] = true;
        for (auto link : adj[cur]) {
            int next = link.first;
            int weight = link.second;
            if (dist[next] > dist[cur] + weight) {
                dist[next] = dist[cur] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main(void) {
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
    for (int i = 0; i < N; ++i)
        cout << dist[i] << ' ';
    return 0;
}

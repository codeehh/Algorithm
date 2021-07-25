#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int INF = 987654321;
vector<tuple<int, int, int>> edges;
int n = 5;
int dist[5];

void BellmanFord(int x)
{
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
    }
    dist[x] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        bool finished_check = true; //거리 변화있으면 finished_check = false;
        for (auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            int min_temp = min(dist[b], dist[a] + w);
            if (dist[b] != min_temp)
            {
                dist[b] = min_temp;
                finished_check = false;
            }
        }
        if (finished_check)
            break;
    }
}

int main(void)
{
    edges.push_back({0, 1, 2});
    edges.push_back({0, 2, 3});
    edges.push_back({0, 3, 7});
    edges.push_back({1, 0, 2});
    edges.push_back({1, 3, 3});
    edges.push_back({1, 4, 5});
    edges.push_back({2, 0, 3});
    edges.push_back({2, 3, 1});
    edges.push_back({3, 0, 7});
    edges.push_back({3, 1, 3});
    edges.push_back({3, 2, 1});
    edges.push_back({3, 4, 2});
    edges.push_back({4, 1, 5});
    edges.push_back({4, 3, 2});
    BellmanFord(0);
    cout << "BellmanFord" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << dist[i] << ' ';
    }
    return 0;
}

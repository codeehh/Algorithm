#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
const int NUM_NODES = 6;
//tuple 비교함수
struct Cmp
{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<2>(a) < get<2>(b);
    }
};

//Union-find 자료구조
struct Union_find
{
    int link[NUM_NODES];
    int size[NUM_NODES];
    Union_find()
    {
        for (int i = 0; i < NUM_NODES; ++i)
        {
            link[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        while (x != link[x])
            x = link[x];
        return x;
    }
    int find2(int x) // 경로압축
    {
        if (x == link[x])
            return x;
        return link[x] = find2(link[x]);
    }
    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (size[a] < size[b])
            swap(a, b);
        link[b] = a;
        size[a] += size[b];
    }
};
void Kruskal(const vector<tuple<int, int, int>> &edges, vector<pair<int, int>> &min_span_tree, Union_find &uf)
{
    for (auto x : edges)
    {
        int a = get<0>(x);
        int b = get<1>(x);
        if (!uf.same(a, b))
        {
            uf.unite(a, b);
            min_span_tree.push_back({a, b});
        }
    }
}
void ShowMST(const vector<pair<int, int>> &min_span_tree)
{
    for (auto x : min_span_tree)
    {
        cout << x.first << ' ' << x.second << endl;
    }
}
int main(void)
{
    vector<tuple<int, int, int>> edges;
    vector<pair<int, int>> min_span_tree;
    Union_find uf;
    edges.push_back({0, 1, 3});
    edges.push_back({0, 4, 5});
    edges.push_back({1, 0, 3});
    edges.push_back({1, 2, 5});
    edges.push_back({1, 4, 6});
    edges.push_back({2, 1, 5});
    edges.push_back({2, 3, 9});
    edges.push_back({2, 5, 3});
    edges.push_back({3, 2, 9});
    edges.push_back({3, 5, 7});
    edges.push_back({4, 0, 5});
    edges.push_back({4, 1, 6});
    edges.push_back({4, 5, 2});
    edges.push_back({5, 2, 3});
    edges.push_back({5, 3, 7});
    edges.push_back({5, 4, 2});

    sort(edges.begin(), edges.end(), Cmp());
    Kruskal(edges, min_span_tree, uf);
    ShowMST(min_span_tree);
    return 0;
}

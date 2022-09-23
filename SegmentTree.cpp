#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int n = 5;
int arr[n] = {1, 2, 3, 4, 5};

vector<int> segTree;

int makeSegTree(int node, int lo, int hi) {
    if (lo == hi) {
        return segTree[node] = arr[lo];
    }
    int mid = (lo + hi) / 2;
    segTree[node] += makeSegTree(2 * node, lo, mid);
    segTree[node] += makeSegTree(2 * node + 1, mid + 1, hi);
    return segTree[node];
}

int sumSegTree(int node, int lo, int hi, int left, int right) {
    if (hi < left || right < lo)
        return 0;
    if (left <= lo && hi <= right)
        return segTree[node];
    int mid = (lo + hi) / 2;
    int ret = 0;
    ret += sumSegTree(2 * node, lo, mid, left, right);
    ret += sumSegTree(2 * node + 1, mid + 1, hi, left, right);
    return ret;
}

void updateSegTree(int node, int lo, int hi, int idx, int num) {
    if (idx < lo || hi < idx)
        return;
    if (lo <= idx && idx <= hi)
        segTree[node] += num;
    if (lo == hi)
        return;
    int mid = (lo + hi) / 2;
    updateSegTree(2 * node, lo, mid, idx, num);
    updateSegTree(2 * node + 1, mid + 1, hi, idx, num);
}

void printSegTree(vector<int> segTree) {
    int cnt = 1;
    while (cnt != segTree.size()) {
        for (int i = 0; i < cnt; i++) {
            cout << segTree[cnt + i] << ' ';
        }
        cout << '\n';
        cnt <<= 1;
    }
}

int main(void) {
    int h = (int)ceil(log2(n));
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);
    makeSegTree(1, 0, n - 1);
    updateSegTree(1, 0, n - 1, 2, 10);
    printSegTree(segTree);
    cout << sumSegTree(1, 0, n - 1, 0, 4);
    return 0;
}
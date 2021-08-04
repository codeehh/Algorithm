#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
const int LOW_BOUND = 0;
const int HIGH_BOUND = 999;
int arr[1000];
int BS_value(int x) //x값의 인덱스를 찾는 함수
{
    int lo = LOW_BOUND;
    int hi = HIGH_BOUND;
    int mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            lo = mid + 1;
        else if (arr[mid] > x)
            hi = mid - 1;
    }
    return -1;
}
bool Judge(int x)
{
    if (x * x < 250000)
        return true;
    return false;
}
int BS_optimum() //Judge가 true인 인덱스의 최대값을 찾는 함수 (최소값 찾을때는 return lo)
{
    if (!Judge(LOW_BOUND)) //Judge(LOW_BOUND)는 true여야 함
        return -1;
    int lo = LOW_BOUND;
    int hi = HIGH_BOUND;
    int mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (Judge(arr[mid]))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return hi;
}

int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < 1000; ++i)
        arr[i] = rand() % 1000;
    sort(arr, arr + 1000);
    int x = 723;
    if (BS_value(x) != -1)
        cout << "x index : " << BS_value(x) << '\n';
    else
        cout << "No Value\n";
    if (BS_optimum() != -1)
        cout << "Maximum Index Satisfying Judge : " << BS_optimum() << '\n';
    else
        cout << "No Index\n";
    return 0;
}
#include <iostream>
using namespace std;

int pi[10000];

void kmp(string pat) {
    int n = pat.length();
    int i = -1, j = 0;
    pi[j] = i;
    while (j < n) {
        if (i == -1 || pat[i] == pat[j])
            pi[++j] = ++i;
        else
            i = pi[i];
    }
}

void findPattern(string str, string pat) {
    int n = str.length();
    int m = pat.length();
    int i = 0, j = 0;
    while (i < n) {
        if (j == -1 || str[i] == pat[j])
            i++, j++;
        else
            j = pi[j];

        if (j == m) {
            printf("The matching %d\n", i - m);
            j = pi[j];
        }
    }
}

int main(void) {
    string str = "ababab";
    string pat = "abab";
    kmp(pat);
    findPattern(str, pat);

    return 0;
}
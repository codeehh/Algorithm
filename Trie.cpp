#include <iostream>
using namespace std;

struct Trie {
    Trie* node[26];
    bool end;

    Trie() {
        for (int i = 0; i < 26; i++) {
            node[i] = NULL;
        }
        end = false;
    }

    void regist(string str) {
        Trie* cur = this;
        for (int i = 0; i < str.length(); i++) {
            Trie*& next = cur->node[str[i] - 'a'];
            if (next == NULL) {
                next = new Trie();
            }
            cur = next;
        }
        cur->end = true;
    }
    bool find(string str) {
        Trie* cur = this;
        for (int i = 0; i < str.length(); i++) {
            Trie*& next = cur->node[str[i] - 'a'];
            if (next == NULL) {
                return false;
            }
            cur = next;
        }
        return cur->end;
    }
};

int main(void) {
    Trie trie;
    trie.findAndPrint("abc");
    trie.regist("abc");
    trie.findAndPrint("abc");

    trie.findAndPrint("abd");
    trie.regist("abd");
    trie.findAndPrint("abd");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    string st;
    string sr;
    unordered_set<string> &d;

    void DFS(int pos, string st, string cur) {
        if (pos == sr.length()) {
            std::unordered_set<std::string>::const_iterator got = d.find(st);
            if (got != d.end()) {
                res.push_back(cur.substr(1, cur.length()-1));
            }
            return;

        }
        st += sr[pos];
        DFS(pos + 1, st, cur);
        std::unordered_set<std::string>::const_iterator got = d.find(st);
        if (got != d.end()) {
            DFS(pos + 1, "", cur + " " + st);
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        d = dict;
        sr = s;
        DFS(0, "", "");
        return res;
    }
};

int main()
{
    Solution sol;

}

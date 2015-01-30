#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int num[26] = {2, 2, 2, 3, 3 ,3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

string s;

int main() {

    cin >> s;
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res += num[s[i] - 'A'] + 1;
    }
    cout << res;

}

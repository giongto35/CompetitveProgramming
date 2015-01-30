#include <cstdio>
#include <iostream>

using namespace std;

long long n;
long long p[16];

long long  Count(long long n, int i) {
    long long ret = (i+1LL)*(n/p[i]);
    n %= p[i];
    if (n == 0) return ret;
    return ret + min(Count(n, i-1), i+1 + Count(p[i]-n, i-1));
}

int main() {

    // freopen("I.txt", "r", stdin);

    p[0] = 1;
    for (int i = 0; i < 16; i++)
        p[i] = p[i-1]*10 + 1;

    cin >> n;
    cout << Count(n, 15);

    return 0;
}

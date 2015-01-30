#include <unordered_map>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std;

long long a,b,c;
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    map <long long, int> m;
    cin>>a>>b>>c;
    long long x = 1;
    m[x] = 0;
    for (int i = 1; i <= 2 * 10000000; i++)
    {
        x = (a * x + x % b) % c;
/*        if (i >= 1000000)
        {
            map <long long, int>::iterator it = m.end();
            cout<<(*it).first<<' '<<(*it).second<<endl;
            m.erase(it);
        }*/
        if (m.find(x) != m.end())
        {
            cout<<i<<endl;
            return 0;
        }
        if (i <= 500000)
        m[x] = i;
    }
    cout<<-1;
}

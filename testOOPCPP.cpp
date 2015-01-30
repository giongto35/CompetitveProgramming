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

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

class ParentClass {
public:
    virtual void run() {
        cout<< "Parent" << endl;
    }

    explicit ParentClass() {
    }

    ~ParentClass() {
        cout<< "Parent Destructor" << endl;
    }
};

class ChildClass : public ParentClass {
public:
    void run() {
        cout<< "Child" << endl;
    };

    ~ChildClass() {
        cout<< "Child Destructor" << endl;
    }
};

class Base
{
public:
    virtual void  Todo() = 0;
};

class Derive : protected Base
{
    void Todo() {cout<<"ABC"<<endl;}
};

int main()
{
    freopen("","r",stdin);
    freopen("","w",stdout);
    ParentClass *c1 = new ChildClass();
    ChildClass *c2 = new ChildClass();
    c1->run();
    c2->run();
    c1.ParentClass::run();
    cout<<" c1"<<endl;
    delete(c1);
    cout<<" c2"<<endl;
    delete(c2);

    Base *d = new Derive();
    d->Todo();
    fclose(stdin);
    fclose(stdout);
    return 0;
}


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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
string s[4];
int T;
bool notcom;

void process()
{
        FOR(i,0,3)
        {
            int SX=0;
            int SO=0;
            int ST=0;
            FOR(j,0,3)
            {
                SX=SX+(s[i][j]=='X');SO=SO+(s[i][j]=='O');ST=ST+(s[i][j]=='T');
            }
            if ((SX==3&&ST==1)||(SX==4))
            {
                cout<<"X won";
                return;
            }
            if ((SO==3&&ST==1)||(SO==4))
            {
                cout<<"O won";
                return;
            }
        }

        FOR(i,0,3)
        {
            int SX=0;int SO=0;int ST=0;
            FOR(j,0,3)
            {
                SX=SX+(s[j][i]=='X');SO=SO+(s[j][i]=='O');ST=ST+(s[j][i]=='T');
            }
            if ((SX==3&&ST==1)||(SX==4))
            {
                cout<<"X won";
                return;
            }
            if ((SO==3&&ST==1)||(SO==4))
            {
                cout<<"O won";
                return;
            }
        }

        int SX=0;int SO=0;int ST=0;
        FOR(i,0,3)
        {
            SX=SX+(s[i][i]=='X');SO=SO+(s[i][i]=='O');ST=ST+(s[i][i]=='T');
        }
        if ((SX==3&&ST==1)||(SX==4))
            {
                cout<<"X won";
                return;
            }
       if ((SO==3&&ST==1)||(SO==4))
            {
                cout<<"O won";
                return;
            }

        SX=0;SO=0;ST=0;
        FOR(i,0,3)
        {
            SX=SX+(s[i][3-i]=='X');SO=SO+(s[i][3-i]=='O');ST=ST+(s[i][3-i]=='T');
        }
            if ((SX==3&&ST==1)||(SX==4))
            {
                cout<<"X won";
                return;
            }
            if ((SO==3&&ST==1)||(SO==4))
            {
                cout<<"O won";
                return;
            }
        notcom=false;
        FOR(i,0,3)FOR(j,0,3) if (s[i][j]=='.') notcom=true;
        if (notcom)
        cout<<"Game has not completed";
        else
        cout<<"Draw";
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("TicTacToe.out","w",stdout);
    cin>>T;
        scanf("\n");
    FOR(st,1,T)
    {
        FOR(i,0,3) getline(cin,s[i]);
        scanf("\n");
        cout<<"Case #"<<st<<": ";
        process();
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


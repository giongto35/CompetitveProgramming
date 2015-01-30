#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))

string s[1000], S, r[1000];
int n, m;
char st[1000];
int top;
int st2[1000];
int P[1000];

int cal(string s) {
    int r=0;
    FOR(i, 0, s.length()-1) r=r*10+(s[i]-'0');
    return r;
}
int main() {
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    P['*']=P['/']=2;
    P['+']=P['-']=1;
    P['(']=P[')']=0;
    while (true) {
        n=0;
        getline(cin, S); S=S+" ";
        if (S.length()==1) break;
        FOR(i, 0, S.length()-1) if (i==0 || S[i-1]==' ') {
            n++; s[n]="";
            int j=i;
            while (S[j]!=' ') s[n]=s[n]+S[j], j++;
        }
        top=0; m=0;
        FOR(i, 1, n) {
            char c=s[i][0];
            if (c=='(') st[++top]=c;
            else if (c==')') {
                while (st[top]!='(') {
                    r[++m]=st[top];
                    top--;
                }
                top--;
            } else if (c>'9' || c<'0') {
                while (top>0 && P[c]<=P[st[top]]) r[++m]=st[top], top--;
                st[++top]=c;
            } else r[++m]=s[i];
        }
        DOW(i, top, 1) r[++m]=st[i];
        FOR(i, 1, m) cout << r[i] << " ";
        cout << endl;
        int res=0;
        top=0;
        FOR(i, 1, m) {
            if (r[i][0]>='0' && r[i][0]<='9') st2[++top]=cal(r[i]);
            else {
                int x=st2[top-1], y=st2[top];
                top-=2;
                if (r[i]=="+") x+=y;
                else if (r[i]=="-") x-=y;
                else if (r[i]=="*") x*=y;
                else if (r[i]=="/") x/=y;
                st2[++top]=x;
            }
        }
        cout << st2[1] << endl << endl;
    }
    //system("pause");
    return 0;
}

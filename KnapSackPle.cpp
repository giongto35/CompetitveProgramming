#include <bits/stdc++.h>

using namespace std;

const int maxn = 200+10;
const int maxp = 1000000+10;
int n,p;
vector<int> a[maxn];
int c[maxn];
vector<int> st;
bool F[maxn][maxp];
int LCA[maxn][maxn];
int par[maxn];
int cnt;
bool used[maxn];
int in[maxn];
int out[maxn];
int D[maxn];
int res,u,v;

void DFSLCA(int u)
{
    cnt++;
    used[u] = true;
    D[u] = D[par[u]] + c[u];
    in[u] = cnt;

    for (int i = 0; i < a[u].size(); i++)
    {
        DFSLCA(a[u][i]);
    }
    out[u] = cnt;
}

void FindLCA()
{
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (used[i] == false)
            DFSLCA(i);
    for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++)
    {
        int u = i;
        while (u != 0)
        {
            if (in[u] <= in[i] && out[i] <= out[u] && in[u] <= in[j] && out[j] <= out[u])
            {
                LCA[i][j] = u;
                LCA[j][i] = u;
                break;
            }
            u =  par[u];
        }
    }
}

void DFS(int u)
{
    st.push_back(u);
    used[u] = true;
    for (int j = 0; j <= p; j++ )
    {
        for (int k = 0; k < st.size(); k++)
        {
            int v = st[k];
            if (LCA[v][u] == 0)
                F[u][j] = F[u][j] | F[v][j];
            else
            if (j >= (D[u] - D[LCA[v][u]]))
            {
                cout<<u<<' '<<v<<' '<<j<<' '<<j - (D[u] - D[LCA[v][u]])<<' '<<F[v][j - (D[u] - D[LCA[v][u]])]<<endl;
                F[u][j] = F[u][j] | F[v][j - (D[u] - D[LCA[v][u]])];
            }
        }
    }

    for (int i = 1; i < a[u].size(); i++)
    {
        DFS(a[u][i]);
    }
}

int main()
{
    freopen("ple.inp", "r", stdin);
    //freopen("ple.out", "w", stdout);
    scanf("%d %d",&n,&p);
    for (int i =1; i <= n; i++)
    {
        scanf("%d %d",&u,&v);
        if (u+1 != i)
        {
            a[u+1].push_back(i);
            par[i] = u+1;
        }
        c[i] = v;
    }
    FindLCA();
    memset(F,false,sizeof(F));
    st.push_back(0);
    for (int i = 1; i <= n; i++) cout<<D[i]<<endl;
    F[0][0] = true;
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++)
        if (used[i] == false)
            DFS(i);
    for (int i = 1; i <= n; i++)
    for (int j = p; j >= 0; j--)
        if (F[i][j])
    {
        res = j;
        break;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
const long long INF=1LL<<60;
int g[maxn][maxn];
int n;
long long min_dist=INF;
bool vis[maxn]={0};

bool times[10000]={0};
void output() {
    int x=clock()/CLOCKS_PER_SEC;
    if (!times[x]) {
        times[x]=1;
        cout<<x<<','<<min_dist<<endl;
    }
}

void dfs(int start,int u,int step,long long dist) {
    output();
    if (dist>min_dist) return;
    if (start==u&&step<=n&&step>1) return;
    if (step>n&&start==u) {
        min_dist=min(min_dist,dist);
    } else {
        for (int i=1;i<=n;++i) if (!vis[i]) {
            output();
            vis[i]=1; 
            dfs(start,i,step+1,dist+g[u][i]);
            vis[i]=0;
        }
    }
}

int main() {
    int index; cin>>index;
    string F="../../data/tsp/"+to_string(index)+".in";
    string G=to_string(index)+".csv";
    freopen(F.c_str(),"r",stdin);
    freopen(G.c_str(),"w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i) 
        for (int j=1;j<=n;++j) cin>>g[i][j];
    for (int i=1;i<=n;++i) {
        dfs(i,i,1,0);
    }    
    cout<<min_dist<<endl;
}
#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
const long long INF=1LL<<30;
int g[maxn][maxn];
int n;
long long min_dist=INF;
int p[maxn]={0};

bool vis[maxn];

bool times[10000]={0};
void output() {
    int x=clock()/CLOCKS_PER_SEC;
    if (!times[x]) {
        times[x]=1;
        cout<<x<<','<<min_dist<<endl;
    }
}

long long solve(int tmp) {
    memset(vis,0,sizeof(vis));
    int s=tmp;
    vis[s]=1;
    long long ans=0;
    ////cout<<s<<',';
    for (int t=1;t<n;++t) {
        output();
        int min_u=0;
        long long min_dis=INF;
        for (int i=1;i<=n;++i) if (!vis[i]){
            output();
            if (g[s][i]<min_dis) {
                min_dis=g[s][i];
                min_u=i;
            }
        }
        //cout<<min_u<<',';
        ans+=min_dis;
        s=min_u;
        assert(vis[s]==0&&s!=0);
        vis[s]=1;
    }
    //cout<<endl;
    for (int i=1;i<=n;++i) assert(vis[i]==1);
    return ans+g[s][tmp];
}

int main() {
    int index; cin>>index;
    string F="../../data/tsp/"+to_string(index)+".in";
    string G=to_string(index)+".csv";
    freopen(F.c_str(),"r",stdin);
    //freopen(G.c_str(),"w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i) 
        for (int j=1;j<=n;++j) cin>>g[i][j];
    for (int i=0;i<=n;++i) g[i][0]=g[0][i]=(1<<30);
    for (int i=1;i<=n;++i) {
        output();
        min_dist=min(min_dist,solve(i));
        //cout<<solve(i)<<endl;
    }
    cout<<min_dist<<endl;
    return 0;
}
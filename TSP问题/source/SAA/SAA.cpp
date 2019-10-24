#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
const long long INF=1LL<<60;
int g[maxn][maxn];
int n;

const double eps=1e-8;

vector<int> p;

long long min_dist=INF;

bool times[10000]={0};
void output() {
    int x=clock()/CLOCKS_PER_SEC;
    if (!times[x]) {
        times[x]=1;
        cout<<x<<','<<min_dist<<endl;
    }
}


long long f(const vector<int> &p) {
    long long ans=0;
    for (int i=1;i<p.size();++i) {
        ans+=g[p[i-1]][p[i]];
    }
    ans+=g[p[p.size()-1]][p[0]];
    return ans;
}

long long update(const vector<int> &s,vector<int> &t) {
    t=s;
    int a=rand()%s.size(),b=rand()%s.size();
    while (a==b) b=rand()%s.size();
    swap(t[a],t[b]);
    return f(t);
}

int main() {
    srand(time(NULL));
    int index; cin>>index;
    string F="../../data/tsp/"+to_string(index)+".in";
    string G=to_string(index)+".csv";
    freopen(F.c_str(),"r",stdin);
    freopen(G.c_str(),"w",stdout);
    
    cin>>n;
    for (int i=1;i<=n;++i) 
        for (int j=1;j<=n;++j) cin>>g[i][j];
    
    for (int i=1;i<=n;++i) p.push_back(i);

    long long now_value=INF;
    vector<int> s;
    for (int i=0;i<10000;++i) {
        random_shuffle(p.begin(),p.end());
        long long value=f(p);
        if (value<now_value) {
            now_value=value;
            s=p;
        }
    }
   
    for (double t=1000000;t>eps||(clock()/CLOCKS_PER_SEC<=60);t*=0.99) {
        output();
        for (int i=0;i<1000;++i) {
            vector<int> tmp;
            long long new_value=update(s,tmp);
            if (new_value<now_value|| (rand()/double(RAND_MAX))<exp((now_value-new_value)/t) ) {
                now_value=new_value;
                s=tmp;
            }
            if (now_value<min_dist) {
                min_dist=now_value;
            }
            output();
        }
    }
    cout<<min_dist<<endl;
    return 0;
}
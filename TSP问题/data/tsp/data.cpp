#include<bits/stdc++.h>
using namespace std;

const int maxn=1000+5;
const int maxdist=1000;
string out_name;
int index,n;
int g[maxn][maxn]={0};

int main() {
    srand(time(NULL));
    cin>>index>>n;
    out_name=to_string(index)+".in";
    freopen(out_name.c_str(),"w",stdout);
    cout<<n<<endl;
    for (int i=1;i<=n;++i) {
        for (int j=i;j<=n;++j) {
            if (i==j) g[i][j]=0; else g[i][j]=g[j][i]=rand()%maxdist+1;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) cout<<g[i][j]<<' '; 
        cout<<endl;
    }
    return 0;
}
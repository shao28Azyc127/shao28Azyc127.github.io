#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXM 100005

int c,t;

int n,m,k;
long long d;
long long f[MAXN],mf[MAXN];

struct Clg{
    int l,r;
    long long v;
}clg[MAXM];

int rx,ry;
long long rv;

vector<Clg> vl[MAXN];

bool cmpl(Clg a,Clg b){
    return a.r<b.r;
}

void run(){
    memset(f,0,sizeof(f));
    memset(mf,0,sizeof(mf));

    cin>>n>>m>>k>>d;

    for(int i=1;i<=n;i++){
        vl[i].clear();
    }

    for(int i=1;i<=m;i++){
        cin>>rx>>ry>>rv;

        if(ry>k){
            continue;
        }

        clg[i].l=rx-ry+1;
        clg[i].r=rx;
        clg[i].v=rv;

        vl[clg[i].l].push_back(clg[i]);
    }

    for(int i=1;i<=n;i++){
        sort(vl[i].begin(),vl[i].end(),cmpl);
    }

    for(int nr=1;nr<=n;nr++){
        long long vnow=0;
        for(int nl=nr;nl>=1&&(nr-nl+1)<=k;nl--){
            for(auto c:vl[nl]){
                if(c.r>nr){
                    break;
                }
                vnow+=c.v;
            }
            if(nl>=3){
                f[nr]=max(f[nr],vnow-(long long)(nr-nl+1)*d+mf[nl-2]);
            }else{
                f[nr]=max(f[nr],vnow-(long long)(nr-nl+1)*d);
            }
        }
        mf[nr]=max(mf[nr-1],f[nr]);
    }

    printf("%lld\n",mf[n]);

    return;
}

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    ios::sync_with_stdio(false);

    cin>>c>>t;

    for(int i=1;i<=t;i++){
        run();
    }

    return 0;
}

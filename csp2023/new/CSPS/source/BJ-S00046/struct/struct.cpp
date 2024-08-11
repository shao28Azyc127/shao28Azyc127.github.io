#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define y1 y114514
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mk make_pair
#define gc getchar
#define pc putchar
#define TIME 1e3*clock()/CLOCKS_PER_SEC
ll rd() {
    ll x=0,f=0;
    char c=gc();
    while(!isdigit(c)) f=(c=='-'?1:0),c=gc();
    while(isdigit(c)) x=x*10+c-48,c=gc();
    if(f==1) return -x;
    return x;
}
void wr(ll x) {
    if(x<0) pc('-'),wr(-x);
    if(x>9) wr(x/10);
    pc(x%10+'0');
}
bool Mst;

int n,ed,cnt;
map<int,pair<string,string>> mpi;
map<pair<string,string>,int> mps;
map<string,pair<ll,int>> mpv;
vector<int> e[10005];
string s,t,p;
map<string,pair<ll,ll>> qu;
map<string,string> shou;

bool Med;
int main() {
 //   fprintf(stderr,"%.3lf MB\n",(&Mst-&Med)/1048576.0);

    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    /*
    cin>>n;
    rep(i,1,n) {
        int op;
        cin>>op;
        if(op==1) {
            int edn=0,x=0,y=0;
            int k;
            cin>>s>>k;
            ++cnt;
            mps[s]=cnt;
            mpi[cnt]=s;
            int now=cnt;
            rep(j,1,k) {
                cin>>t>>p;
                if(mps[t]) {
                    if(j==1) shou[k]=shou[t];
                    int z=shou[t];
                    ++cnt;
                    int xx=mpv[t].fi,yy=mpv[t].se;
                    y=max(yy,y);
                    if(shou=="byte") {

                    }
                    if(shou=="short") {
                         if(edn%2!=0) edn++;
                    }
                    if(shou=="int") {
                                                while(edn%4!=0) edn++;
                    }
                    if(shou=="long") {
                         while(edn%8!=0) edn++;
                    }
                    edn+=mpv[t].fi;
                    e[now].pb(cnt);
                } else {
                    if(t=="byte") {
                        y=max(y,1);
                        ++cnt;
                        mps[p]=cnt;
                        qu[p]={edn,edn};
                        edn++;
                    }
                    if(t=="short") {
                        y=max(y,2);
                        ++cnt;
                        mps[p]=cnt;
                        if(edn%2!=0) edn++;
                        qu[p]={edn,edn+1};
                        edn+=2;
                    }
                    if(t=="int") {
                        y=max(y,4);
                        ++cnt;
                        mps[p]=cnt;
                        while(edn%4!=0) edn++;
                        qu[p]={edn,edn+3};
                        edn+=4;
                    }
                    if(t=="long") {
                        y=max(y,8);
                        ++cnt;
                        mps[p]=cnt;
                        while(edn%8!=0) edn++;
                        qu[p]={edn,edn+7};
                        edn+=8;
                    }
                    e[now].pb(cnt);
                    if(j==1) shou[k]=t;
                }
            }
        }
        if(op==2) {

        }
        if(op==3) {

        }
        if(op==4) {

        }
    }
    */


   // cerr<<'\n'<<TIME;
    return 0;
}

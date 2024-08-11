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

int n,a[10];
map<vector<int>,int> mp[10];
vector<int> v;

bool Med;
int main() {
//    fprintf(stderr,"%.3lf MB\n",(&Mst-&Med)/1048576.0);

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    rep(i,1,n) {
        rep(j,1,5) cin>>a[j];
        rep(j,1,5) {
            rep(k,1,9) {
                int lst=a[j];
                a[j]+=k;
                a[j]%=10;
                v.clear();
                rep(l,1,5) v.pb(a[l]);
                if(i==1||mp[i-1][v]==1) mp[i][v]=1;
                a[j]=lst;
            }
        }
        rep(j,1,4) {
            rep(k,1,9) {
                int lst1=a[j],lst2=a[j+1];
                a[j]+=k,a[j]%=10,a[j+1]+=k,a[j+1]%=10;
                v.clear();
                rep(l,1,5) v.pb(a[l]);
                if(i==1||mp[i-1][v]==1) mp[i][v]=1;
                a[j]=lst1,a[j+1]=lst2;
            }
        }
    }
    cout<<mp[n].size();

//    cerr<<'\n'<<TIME;
    return 0;
}

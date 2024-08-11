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
#define ull unsigned ll
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

const int N=2e6+5;
int n;
ll dp[N];
char s[N];
const ll bas1=131,bas2=1331,mod1=998244353,mod2=1e9+7;
/*
ll ksm(ll x,ll y) {
    ll res=1;
    while(y) {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
*/
ll pw1[N],pw2[N],pre1[N],suf1[N],pre2[N],suf2[N],inv1[N],inv2[N];
bool ck(int l1,int r1,int l2,int r2) {
   bool ok=1;
    ll a=pre1[r1]-pre1[l1-1]*pw1[r1-l1+1]%mod1;
    a%=mod1;
    a+=mod1;
    a%=mod1;
    ll b=suf1[l2]-suf1[r2+1]*pw1[r2-l2+1]%mod1;
    b%=mod1;
    b+=mod1;
    b%=mod1;
    if(a!=b) ok=0;
    /*
    a=pre2[r1]-pre2[l1-1]*pw2[r1-l1+1]%mod2;
    a%=mod2;
    a+=mod2;
    a%=mod2;
    b=suf2[l2]-suf2[r2+1]*pw2[r2-l2+1]%mod2;
    b%=mod2;
    b+=mod2;
    b%=mod2;
    if(a!=b) ok=0;
        */
   return ok;
}
bool work(int l,int r) {
    bool ok=0;
    int mid=(l+r)/2;
    int l1=l,r1=mid,l2=mid+1,r2=r;
    if((r1-l1+1)%2==0&&(r2-l2+1)%2==0) {
        mid=(l1+r1)/2;
        bool ok1=ck(l1,mid,mid+1,r1);
        mid=(l2+r2)/2;
        bool ok2=ck(l2,mid,mid+1,r2);
        if(ok1&&ok2) ok=1;
    }
    return ok;
}
ll res;
void solve(int l,int r) {

}
stack<char> st;

bool Med;
int main() {
  //  fprintf(stderr,"%.3lf MB\n",(&Mst-&Med)/1048576.0);

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s+1;
    rep(l,1,n) {
     //   st.clear();
        while(st.size()) st.pop();
        rep(i,l,n) {
            st.push(s[i]);
            while(st.size()>=2) {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(a==b) {}
                else {
                    st.push(b);
                    st.push(a);
                    break;
                }
            }
            if(!st.size()) res++;
        }
        //if(!st.size()) res++;
    }
  //  rep(i,1,n) res+=dp[i];
    cout<<res;

  //  cerr<<'\n'<<TIME;
    return 0;
}

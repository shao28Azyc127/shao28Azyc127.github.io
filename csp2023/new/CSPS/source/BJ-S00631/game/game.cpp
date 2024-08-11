#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define LL long long
#define mem(a,n) memset(a,n,sizeof(a))

inline int read(){
    int s=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) s=s*10+c-'0';
    return s*f;
}

const int N=2e3+5;
int hw[2*N];string s1;
inline void manacher(string s){
    //printf("1***\n");
    int ct=1;
    s1[0]=s1[1]='|';int l=s.size();//printf("%d\n",l);
    //printf("3***\n");
    rep(i,0,l-1) s1[++ct]=s[i],s1[++ct]='|';
    //printf("2***\n");
    int mid=0,r=-1;
    rep(i,1,2*l+1){
        hw[i]=1;
        if(r<i) while(s1[i+hw[i]]==s1[i-hw[i]]) hw[i]++;
        else {
            hw[i]=min(r-i,hw[2*mid-i]);
            while(s1[i+hw[i]]==s1[i-hw[i]]) hw[i]++;
        }
        if(i+hw[i]-1>r) r=i+hw[i]-1,mid=i;
    }
    //printf("2***\n");
}

int n;
string s;
const int M=1005;
bool f[M][M];
namespace baoli{
    int ans;
    inline void solve(){
        //printf("2***\n");
        int l=s.size();
        rep(i,1,l) rep(j,i+1,l){
            int x=2*i+1,y=2*j+1;
            rep(k,3,hw[x]){
                if(y<x+k-1) break;
                if(y-hw[y]+1<=x+k-1){
                    f[(x-k+2)/2][(2*y-x-k)/2]=1;
                    //printf("%d %d %d\n",x,y,k);
                }
            }
        }
        ans=0;
        rep(i,1,l) rep(j,i+1,l) if(f[i][j]) ans++;
        printf("%d\n",ans);
    }


}


int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    manacher(s);
    //cout<<s<<endl;
    //printf("*%d\n",n);

    if((int)s.size()<=805) baoli::solve();
    return 0;
}


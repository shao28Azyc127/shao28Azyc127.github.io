#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r)for(int i=(l);i>=(r);--i)
#define m_p make_pair
#define pi pair<int,int>
#define p_b push_back
#define p1 first
#define p2 second
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
inline ll read(){
    ll x=0;
    short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}vector<pi>v[maxn];
int n,m,k,dis[maxn][105];
void bfs(int val){
    up(i,1,n)up(j,0,k-1)dis[i][j]=-1e9;
    dis[n][0]=val;
    queue<pi>q;
    q.push(m_p(n,0));
    while(!q.empty()){
        int x=q.front().p1,w=q.front().p2;
        q.pop();
        for(auto f:v[x]){
            int y=f.p1,kk=f.p2;
            if(kk+1<=dis[x][w]){
                if(dis[y][(w-1+k)%k]==int(-1e9)){
                    dis[y][(w-1+k)%k]=dis[x][w]-1;
                    q.push(m_p(y,(w-1+k)%k));
                }
            }
        }
    }
}bool chk(int x){
    bfs(x);
    if(dis[1][0]==int(-1e9))return 0;
    return 1;
}
void slv(){
    n=read(),m=read(),k=read();
    while(m--){
        int x=read(),y=read(),w=read();
        v[y].p_b(m_p(x,w));
    }int l=-1,r=1e9/k;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid*k))r=mid;
        else l=mid;
    }if(chk(r*k))cout<<r*k<<'\n';
    else cout<<"-1\n";
}int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
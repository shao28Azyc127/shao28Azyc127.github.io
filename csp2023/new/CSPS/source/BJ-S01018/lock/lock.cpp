#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define p_b push_back
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int a[10][6],b[6],n,ret;
int dis(int x,int y){
    return (y-x+10)%10;
}
bool chk(){
    up(i,1,n){
        int cnt=0;
        up(j,1,5){
            if(a[i][j]!=b[j])cnt++;
        }if(cnt!=1&&cnt!=2)return 0;
        if(cnt==2){
            vector<int>g;
            up(j,1,5)if(a[i][j]!=b[j])g.p_b(j);
            if(g[1]-g[0]!=1)return 0;
            if(dis(a[i][g[1]],b[g[1]])!=dis(a[i][g[0]],b[g[0]]))return 0;
        }
    }return 1;
}
void dfs(int x){
    if(x>5){
        if(chk())ret++;
        return;
    }up(i,0,9){
        b[x]=i;
        dfs(x+1);
    }
}void slv(){
    n=read();
    up(i,1,n)up(j,1,5)a[i][j]=read();
    dfs(1);
    cout<<ret<<'\n';
}int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
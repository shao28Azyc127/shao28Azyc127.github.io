#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
void read(int &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void lread(long long &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void print(LL number){
    if(number<0){
        putchar('-');
        number=-number;
    }
    if(number>9){
        print(number/10);
    }
    putchar((number%10)^48);
}
const int N=1e5+9;
LL lst[N],a[N];
int fa[N],du[N],b[N],c[N],dp[1050000],bt[1050000];
vector<int> g[N];
struct node{
    int id;
    bool operator <(const node &cmp) const{
        return lst[id]<lst[cmp.id];
    }
};
priority_queue<node> p;
void dfs(int u,int fr){
    fa[u]=fr;
    du[u]=0;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fr)continue;
        dfs(g[u][i],u);
        ++du[u];
    }
}
int js(int x,int y){
	LL res,fjx;
    int l=y,r=1e9,mid;
    if(c[x]<0){
		fjx=b[x]/(-c[x]);
		if(b[x]%(-c[x])==0);
		--fjx;
	}
    while(l<r){
        mid=l+r>>1;
        res=0;
        if(c[x]>=0||mid<=fjx){
            res=1ll*b[x]*(mid-y+1)+(1ll*c[x]*(mid+y)*(mid-y+1))/2;
        }
        else{
            if(y>fjx){
                res=mid-y+1;
            }
            else{
                res=1ll*b[x]*(fjx-y+1)+(1ll*c[x]*(fjx+y)*(fjx-y+1))/2;
                res+=mid-fjx;
            }
        }
        //cout<<mid<<' '<<res<<endl;
        if(res>=a[x])r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    int n,x,y;
    bool A=1,B=1,D=1;
    read(n);
    for(int i=1;i<=n;i++){
        lread(a[i]),read(b[i]),read(c[i]);
        if(c[i])A=0;
    }
    for(int i=1;i<n;i++){
        read(x),read(y);
        g[x].push_back(y),g[y].push_back(x);
        if(x!=i||y!=i+1)B=0;
        if(x!=1)D=0;
    }
    if(A){
        int l=n,r=1e9,mid,res;
        while(l<r){
            mid=l+r>>1;
            dfs(1,0);
            for(int i=1;i<=n;i++){
                lst[i]=mid-ceil(1.0*a[i]/b[i])+1;
            }
            while(!p.empty())p.pop();
            for(int i=1;i<=n;i++)if(du[i]==0)p.push({i});
            int cnt=n;
            bool flag=1;
            while(!p.empty()){
                res=p.top().id;
                p.pop();
                if(cnt>lst[res]){
                    flag=0;
                    break;
                }
                --cnt;
                --du[fa[res]];
                if(du[fa[res]]==0){
                    p.push({fa[res]});
                }
            }
            if(flag)r=mid;
            else l=mid+1;
        }
        print(l);
        return 0;
    }
    if(B){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,js(i,i));
        }
        print(ans);
        return 0;
    }
    if(n<=20){
        dfs(1,0);
        memset(dp,0x7f,sizeof(dp));
        for(int i=1;i<(1<<n);i++)bt[i]=bt[i>>1]+(i&1);
        dp[1]=js(1,1);
        for(int i=1;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if((i&(1<<j))==0&&(i&(1<<(fa[j+1]-1)))){
                    dp[i|(1<<j)]=min(dp[i|(1<<j)],max(dp[i],js(j+1,bt[i]+1)));
                }
            }
        }
        //cout<<js(2,4);
        print(dp[(1<<n)-1]);
        return 0;
    }
    if(D){

        return 0;
    }

    return 0;
}

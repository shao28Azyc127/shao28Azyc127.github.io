#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int now[200030];
int t;
int mat[200030];
struct OP{
    int op,x,y;
}T[200300];
int u[200300];
inline int chk(){
    for(int i=1;i<=n;i++)
        u[i]=now[i];
    for(int i=1;i<=q;i++){
            int x=T[i].x,y=T[i].y,op=T[i].op;
        if(op==1)u[x]=1;
        else if(op==2)u[x]=-1;
        else if(op==3)u[x]=0;
        else if(op==4)u[x]=u[y];
        else u[x]=-u[y];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(u[i]!=now[i])return -1;
    else cnt+=u[i]==0;
    return cnt;
}
int res;
inline void dfs(int dep){
    if(dep==n+1){
        int c=chk();
        if(c>=0)res=min(res,c);
        return ;
    }
    now[dep]=-1;
    dfs(dep+1);
    now[dep]=1;
    dfs(dep+1);
    now[dep]=0;
    dfs(dep+1);
}
int f[200300];
inline int ff(int x){
return f[x]==x?x:f[x]=ff(f[x]);}
inline void merge(int x,int y){
    f[ff(x)]=ff(y);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==1||c==2){
            mat['T']=1;
            mat['F']=2;
            mat['U']=3;
            mat['+']=4;
            mat['-']=5;
        while(t--){
            cin>>n>>q;
            res=n;
            for(int i=1;i<=q;i++){
                char s;
                cin>>s;
                int op=mat[s];
                int x=0,y=0;
                cin>>x;
                if(op>=4)cin>>y;
                T[i]={op,x,y};
            }
            dfs(1);
            cout<<res<<endl;
        }
    }
    else{
        while(t--){
            cin>>n>>q;
            for(int i=1;i<=2*(n+1);i++)
                    f[i]=i,now[i]=i;
            while(q--){
                char op;
                int x;
                cin>>op>>x;
                if(op=='T')
                    now[x]=n+1;
                else if(op=='T')
                    now[x]=-n-1;
                else if(op=='U')now[x]=0;
                else if(op=='+'){
                    int y;
                    cin>>y;
                    now[x]=now[y];
                }
                else {
                    int y;
                    cin>>y;
                    now[x]=-now[y];
                }
            }
            for(int x=1;x<=n;x++)
                if(now[x]==0)
                merge(x,x+n+1);
                else if(now[x]>0){
                    merge(x,now[x]);
                    merge(x+n+1,now[x]+n+1);
                }
                else{
                    now[x]*=-1;

                    merge(x,now[x]+n+1);
                    merge(x+n+1,now[x]);
                }
                int cnt=0;
            for(int x=1;x<=n;x++)
                if(ff(x)==ff(x+n+1))
                cnt++;
            cout<<cnt<<endl;
        }
    }
    cout.flush();
    return 0;
}

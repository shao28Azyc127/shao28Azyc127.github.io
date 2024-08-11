#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=1e5+10;
int trans(char x){
    if(x=='T') return 1;
    if(x=='F') return 0;
    return -1;
}
int rev(int x){
    if(x==0) return 1;
    if(x==1) return 0;
    return -1;
}
int a[N];
char o[N];
int ox[N],oy[N],oo[N],ck[N];
int n,m;
int ans;
int cnt(){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(oo[i]==-1) sum++;
    }
    return sum;
}
void dfs(int x){
    //cout<<x<<endl;
    if(x==n+1){
        for(int i=1;i<=n;i++){
            ck[i]=oo[i];
        }
        for(int i=1;i<=m;i++){
            if(o[i]=='+') ck[ox[i]]=ck[oy[i]];
            else if(o[i]=='-') ck[ox[i]]=rev(ck[oy[i]]);
            else ck[ox[i]]=trans(o[i]);
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(ck[i]!=oo[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans=min(ans,cnt());
        }
        return;
    }
    oo[x]=0;
    dfs(x+1);
    oo[x]=1;
    dfs(x+1);
    oo[x]=-1;
    dfs(x+1);
}
bool u[N];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==1||c==2){
        while(t--){
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                cin>>o[i];
                if(o[i]=='+'||o[i]=='-'){
                    cin>>ox[i]>>oy[i];
                }else{
                    cin>>ox[i];
                }
            }
            ans=0x3f3f3f3f;
            dfs(1);
            cout<<ans<<endl;
        }
        return 0;
    }
    if(c==3||c==4){
        while(t--){
            cin>>n>>m;
            int sum=0;
            for(int i=1;i<=m;i++){
                char opt;
                int tmp;
                cin>>opt>>tmp;
                if(opt=='U') sum++;
            }
            cout<<sum<<endl;
        }
        return 0;
    }
    if(t==5||t==6){
        while(t--){
            memset(u,false,sizeof(u));
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char opt;
                cin>>opt;
                int x,y;
                if(opt=='+'){
                    cin>>x>>y;
                    if(u[y]) u[x]=true;
                    if(!u[y]) u[x]=false;
                }else{
                    cin>>x;
                    u[x]=true;
                }
            }
            int sum=0;
            for(int i=1;i<=n;i++){
                if(u[i]) sum++;
            }
            cout<<sum<<endl;
        }
        return 0;
    }
    return 0;
}

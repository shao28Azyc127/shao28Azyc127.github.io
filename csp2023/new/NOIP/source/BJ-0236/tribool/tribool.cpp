#include <bits/stdc++.h>
using namespace std;
int n,m;
int id,t;
const int N=1e5+5;
char op[N];
int x[N],y[N];
int a[N],b[N],c[N];
int ans,cnt;

void dfs(int cur){
    if(cur>n){
        for(int i=1;i<=n;i++) c[i]=b[i];
        for(int i=1;i<=m;i++){
            if(op[i]=='U'){
                c[x[i]]=3;
            }
            else if(op[i]=='T'){
                c[x[i]]=1;
            }
            else if(op[i]=='F'){
                c[x[i]]=2;
            }
            else{
                if(op[i]=='+'){
                    c[x[i]]=c[y[i]];
                }
                else{
                    if(c[y[i]]==3) c[x[i]]=3;
                    else c[x[i]]=3-c[y[i]];
                }
            }
        }
        bool flag=1;
        for(int i=1;i<=m;i++){
            if(c[i]!=b[i]){
                flag=0;
                break;
            }
        }
        if(flag==1) ans=min(ans,cnt);
        return ;
    }
    b[cur]=1;
    dfs(cur+1);
    b[cur]=2;
    dfs(cur+1);
    b[cur]=3;
    cnt++;
    dfs(cur+1);
    cnt--;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>id>>t;
    while(t--){
        cin>>n>>m;
        memset(a,-1,sizeof(a));
        bool flag=1;
        for(int i=1;i<=m;i++){
            cin>>op[i];
            if(op[i]=='U'){
                cin>>x[i];
                a[x[i]]=3;
            }
            else if(op[i]=='T'){
                cin>>x[i];
                a[x[i]]=1;
            }
            else if(op[i]=='F'){
                cin>>x[i];
                a[x[i]]=2;
            }
            else{
                flag=0;
                cin>>x[i]>>y[i];
            }
        }
        ans=0;
        if(flag==1){
            for(int i=1;i<=n;i++){
                if(a[i]==3) ans++;
            }
            cout<<ans<<endl;
        }
        else{
            ans=1e9;
            dfs(1);
            cout<<ans<<endl;
        }
    }
}
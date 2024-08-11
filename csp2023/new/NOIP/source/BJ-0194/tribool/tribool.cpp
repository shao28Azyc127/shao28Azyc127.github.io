#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,ans=INT_MAX;
char a[N],b[N];
struct node{
    int f;
    char g;
    int x,y;
}z[N];
struct bian{
    int f;
    int x;
}po[N];
bool check(){
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=m;i++){
        if(z[i].f==0)b[z[i].x]=z[i].g;
        else if(z[i].f==1)b[z[i].x]=b[z[i].y];
        else{
            if(b[z[i].y]=='T')b[z[i].x]='F';
            else if(b[z[i].y]=='F')b[z[i].x]='T';
            else b[z[i].x]='U';
        }
    }
    for(int i=1;i<=n;i++)
        if(b[i]!=a[i])return 0;
    return 1;
}
void dfs(int step,int k){
    if(k>ans)return;
    if(step==n+1){
        if(check())ans=min(ans,k);
        return;
    }
    a[step]='T';
    dfs(step+1,k);
    a[step]='F';
    dfs(step+1,k);
    a[step]='U';
    dfs(step+1,k+1);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==1||c==2){
        while(t--){
            ans=INT_MAX;
            scanf("%d%d",&n,&m);
            for(int i=1;i<=m;i++){
                char o;
                int x,y;
                cin>>o;
                if(o=='T'||o=='F'||o=='U'){
                    scanf("%d",&x);
                    z[i]={0,o,x,0};
                }else{
                    scanf("%d%d",&x,&y);
                    if(o=='+')z[i]={1,'a',x,y};
                    else z[i]={2,'a',x,y};
                }
            }
            dfs(1,0);
            cout<<ans<<endl;
        }
    }else if(c==3||c==4){
       while(t--){
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++)a[i]='a';
            for(int i=1;i<=m;i++){
                char o;
                int x;
                cin>>o>>x;
                a[x]=o;
            }
            ans=0;
            for(int i=1;i<=n;i++)if(a[i]=='U')ans++;
            cout<<ans<<endl;
       }
    }else{
        while(t--){
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++)a[i]='a';
            for(int i=1;i<=m;i++){
                char o;
                int x,y;
                cin>>o;
                if(o=='U'){
                    cin>>x;
                    a[x]='U';
                }else{
                    cin>>x>>y;
                    a[x]=a[y];
                }
            }
            ans=0;
            for(int i=1;i<=n;i++)if(a[i]=='U')ans++;
            cout<<ans<<endl;
        }

    }
    return 0;
}

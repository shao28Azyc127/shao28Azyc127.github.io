#include<bits/stdc++.h>

using namespace std;
const int N=15;
int n,m;
int c,t;
struct nd{
    string v;
    int x,y;
}op[N];
int a[N];
int b[N];
int ans;
bool chk(){

    for(int i=1;i<=n;i++)
        if(a[i]!=b[i]) return 0;
    return 1;

}
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++)
            b[i]=a[i];
        int cnt=0;
        for(int i=1;i<=m;i++){
            int x=op[i].x,y=op[i].y;
            if(op[i].v=="+"){
                b[x]=b[y];
            }
            if(op[i].v=="-"){
                b[x]=b[y]*(-1);
            }
            if(op[i].v=="T"){
                b[x]=1;
            }
            if(op[i].v=="F"){
                b[x]=-1;
            }
            if(op[i].v=="U"){
                b[x]=0;
            }
        }

        if(chk()){
            for(int i=1;i<=n;i++)
            if(a[i]==0) cnt++;
            ans=min(ans,cnt);
        }
        return ;
    }
    a[x]=-1;
    dfs(x+1);
    a[x]=0;
    dfs(x+1);
    a[x]=1;
    dfs(x+1);
}

int main(){
  //   freopen("dat","r",stdin);
    freopen("tribool.in","r",stdin);
 freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&m);
        string v;
        int x,y;
        for(int i=1;i<=m;i++){
            cin>>v>>x;
            y=0;
            if(v=="+"||v=="-") cin>>y;
            op[i]={v,x,y};
        }
        ans=1000000;
        dfs(1);
        cout<<ans<<endl;


    }

    return 0;
}

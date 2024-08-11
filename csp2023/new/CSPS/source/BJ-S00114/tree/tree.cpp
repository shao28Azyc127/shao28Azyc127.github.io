#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
struct dk{
    lint a;
    int b,c;
}l[502];
bool s[502][502];
lint high[502];
int n;

bool zs(lint date){
    bool ok=1;
    for(int i=1;i<=n;i++){
        if(high[i]>-1){
            high[i]+=max(l[i].b+date*l[i].c,(lint)1);
            ok=ok&&(high[i]>=l[i].a);
        }
    }
    return ok;
}
void ht(lint date){
    for(int i=1;i<=n;i++){
        if(high[i]>-1){
            high[i]-=max(l[i].b+date*l[i].c,(lint)1);
        }
    }
}
lint dfs(lint date){
    lint ans=0x3f3f3f3f;
    int ok=0;

    /*
    for(int i=1;i<=n;i++){
        cout<<high[i]<<' ';
    }
    cout<<endl;
    */
    for(int i=1;i<=n;i++){
        if(high[i]==-1)
            continue;

        ok=(high[i]>-1);
        for(int j=1;j<=n;j++){
            if(s[i][j]){
                if(high[j]>-1)
                    ok++;
                else{
                    high[j]=0;
                    if(zs(date))
                        return date+1;
                    ans=min(ans,dfs(date+1));
                    high[j]=-1;
                    ht(date);
                }
            }
        }
        if(ok>=n){
            ans=min(ans,dfs(date+1));
            break;
        }
    }
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i].a>>l[i].b>>l[i].c;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        s[u][v]=1;
    }

    memset(high,-1,sizeof(high));
    high[1]=l[1].b+l[1].c;

    cout<<dfs(2);
    return 0;
}

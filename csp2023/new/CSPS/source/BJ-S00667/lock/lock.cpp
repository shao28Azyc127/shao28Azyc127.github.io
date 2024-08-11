#include<bits/stdc++.h>
using namespace std;
int n,p[10],ans,cnt;
struct node{
    int a[6];
}f[10];
void dfs(int m){
    if(m==6){
        bool ok=1;
        for(int i=1;i<=n;i++){
            int diff=0,c[6],d[6];
            for(int j=1;j<=5;j++){
                if(p[j]!=f[i].a[j]){
                    d[++diff]=j;
                    if(p[j]>f[i].a[j]) c[diff]=p[j]-f[i].a[j];
                    else c[diff]=10+p[j]-f[i].a[j];
                }
            }
            if(diff>2||diff==0){
                ok=0; break;
            }
            if(diff==2){
                if(c[1]!=c[2]||d[2]-d[1]!=1){
                    ok=0; break;
                }
            }
        }
        if(ok) ans++;
        return ;
    }
    for(int i=0;i<=9;i++){
        p[m]=i;
        dfs(m+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i].a[1]>>f[i].a[2]>>f[i].a[3]>>f[i].a[4]>>f[i].a[5];
    }
    dfs(1);
    cout<<ans;
    return 0;
}

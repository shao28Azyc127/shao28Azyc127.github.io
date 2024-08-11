#include<bits/stdc++.h>
using namespace std;
int n,a[10][6],ans,cr[6],c[6],cnt;
bool flag[6],ok;
void dfs(int step){
    if(step==6){
        ok=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                if(a[i][j]!=cr[j])
                    flag[j]=true;
                else
                    flag[j]=false;
                c[j]=(a[i][j]-cr[j]+10)%10;
            }
            cnt=0;
            for(int j=1;j<=4;j++){
                if(flag[j]==true){
                    cnt++;
                    if(flag[j+1]==true&&c[j]==c[j+1])
                        flag[j+1]=false;
                }
            }
            if(flag[5]==true)
                cnt++;
            if(cnt>1){
                    ok=false;
                break;
            }
        }
        if(ok==true)
            ans++;
        return;
    }
    for(int i=0;i<=9;i++){
        cr[step]=i;
        dfs(step+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    }
    dfs(1);
    printf("%d",ans-n);
    return 0;
}

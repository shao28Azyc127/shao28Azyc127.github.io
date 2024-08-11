#include<bits/stdc++.h>
using namespace std;
int n;
int a[15][10];
int p[10];
long long ans;
bool check(){
    for(int i=1;i<=n;i++){
        int cnt=0,pos=0;
        for(int j=1;j<=5;j++){
            if(a[i][j]!=p[j]){
                if(!pos){
                    pos=j;
                }
                cnt++;
            }
        }
        if(cnt==0||cnt>2){
            return 0;
        }
        if(cnt==1){
            continue;
        }
        bool f=0;
        for(int j=1;j<10;j++){
            int t1=(p[pos]+j)%10,t2=(p[pos+1]+j)%10;
            if(t1==a[i][pos]&&t2==a[i][pos+1]){
                f=1;
                break;
            }
        }
        if(!f){
            return 0;
        }
    }
    return 1;
}
void dfs(int step){
    if(step>5){
        if(check()){
            ans++;
        }
        return;
    }
    for(int i=0;i<10;i++){
        p[step]=i;
        dfs(step+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}

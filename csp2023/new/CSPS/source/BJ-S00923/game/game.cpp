#include<bits/stdc++.h>
using namespace std;
int n,x;
char a[2000005];
char b[2000005],h=0;
int q[2000005];
long long ans=0;
bool dfs(long long z){
    printf("%d:%d_%d_%s\n",x,z,h,b);
    if(x>n){
        if(h==0){
            return 0;
        }else{
            return 1;
        }
    }
    if(h==0){
        b[++h]=a[x];
        q[h]=x;
        ++x;
    }
    if(b[h]==a[x]){
        --h;
        if(h==0){
            ans+=z;
        }
        if(q[h+1]+1!=x){
            return 1;
        }
        ++x;
        dfs(z+1);
        return 1;
    }else{
        ++x;
        if(dfs(0)==1){
            ans+=z;
            dfs(z+1);
        }else{
            return 0;
        }
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",a+1);
    if(n<10000){
        for(int i=1;i<n;++i){
            h=0;
            b[++h]=a[i];
            for(int j=i+1;j<=n;++j){
                if(b[h]==a[j]){
                    --h;
                    if(h==0){
                        ++ans;
                    }
                }else{
                    b[++h]=a[j];
                }
            }
        }
        printf("%lld",ans);
    }else{
        x=1;
        dfs(0);
        printf("%lld",ans);
    }
    return 0;
}

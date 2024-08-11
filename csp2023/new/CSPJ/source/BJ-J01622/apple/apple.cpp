#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a[1000001],n,cnt=0,ans,f;
    scanf("%d",&n);
    for(int i=1;i<=n+0;i++){
        a[i]=1;
    }
    for(int i=1;i<=n;i++){
            cnt=2;
            f=1;
            for(int j=i;j<=n;j++){
                if(a[j]==1){
                    cnt++;
                    if(cnt==3){
                        cnt=0;
                        a[j]=0;
                        if(j==n){
                            ans=i;
                        }
                    }
                }
            }
            for(int j=i;j<=n;j++){
                if(a[j]==1){
                    f=0;
                    break;
                }
            }
            if(f==1){
                printf("%d ",i);
                printf("%d",ans);
                return 0;
            }
    }
    return 0;
}
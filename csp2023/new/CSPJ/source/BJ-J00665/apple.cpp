#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n;
int a[maxn],ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int fa2=false;
    while(true){
        ans1++;
        if(fa2==false){
            ans2++;
        }
        int sum=2;
        for(int i=ans1;i<=n;i++){
            if(a[i]==0){
                sum++;
            }
            if(sum==3){
                a[i]=1;
                sum=0;
            }
        }
        int f=false;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                f=true;
                break;
            }
        }
        if(a[n]==1){
            fa2=true;
        }
        if(f==false){
            printf("%d %d",ans1,ans2);
            break;
        }
    }
}

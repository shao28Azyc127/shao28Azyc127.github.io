#include<bits/stdc++.h>
using namespace std;
int n,t,f,ans,tt;
bool a[100000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    t=n;
    while(t){
        f=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                f++;
                if(f%3==1){
                    a[i]=1;
                    t--;
                    if(i==n){
                        tt=ans;
                    }
                }
            }
        }
        ans++;
    }
    printf("%d %d",ans,tt+1);
    return 0;
}

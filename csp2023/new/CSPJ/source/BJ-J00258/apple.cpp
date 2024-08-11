#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1,ans2=1,l;
    scanf("%d",&n);
    int a[n];
    for(int i=1;i<=n;i++){
        a[n-1]=i;
    }
    l=n;
    while(l>0){
        ans1++;
        for(i=0;i<n;i+=3){
            if(a[i]!=0){
                if(i==n){
                    ans2=ans1;
                    a[i]=0;
                }else{
                    a[i]=0;
                }
                a[i]=0;
                l--;
            }else{
                i++;
            }
        }
    }
    printf("%d %d",ans1,ans2);
    return 0;
}

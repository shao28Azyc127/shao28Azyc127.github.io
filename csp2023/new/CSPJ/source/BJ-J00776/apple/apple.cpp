#include<bits/stdc++.h>
using namespace std;
int n,a[100000010],d,ans,sum,s,w,f;
int main(){
    freeopen("apple.in","r",stdin);
    freeopen("apple.out","w",stdout);
    scanf("%d",&n);
    s=n;
    while(s!=0){
        d++;
        int sum=s/3;
        if(s%3!=0){
            if(s%3!=1&&f==0){
                ans=d+1;
            }
            else{
                ans=d;
                f=1;
            }
            sum=sum+1;
        }
        s=s-sum;
    }
    if(n%3==1){
        ans=1;
    }
    printf("%d %d",d,ans);
    return 0;
}

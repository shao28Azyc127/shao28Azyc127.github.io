#include<bits/stdc++.h>
using namespace std;
long long n,s,ans1,ans2,pd,cnt;
int a[500000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    s=n;
    while(n>0){
        if(n%3==1||n%3==2) n-=n/3+1;
        else if(n%3==0) n-=n/3;
        ans1++;
    }
    if(s%3==1) ans2=1;
    else{
        for(int i=1;i<=ans1;i++){
            pd=0;
            for(int j=1;j<=s;j++){
                if(a[j]==0&&pd==0){
                    a[j]=1;
                    cnt=0;
                    pd=1;
                }
                else if(a[j]==0&&pd==1) cnt++;
                if(cnt==3){
                    a[j]=1;
                    cnt=0;
                }
                if(a[s]==1){
                    ans2=i;
                    cout<<ans1<<" "<<ans2<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

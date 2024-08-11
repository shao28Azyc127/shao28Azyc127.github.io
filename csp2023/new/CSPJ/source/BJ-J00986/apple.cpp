#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long n,m,day=0,day2=0,numa=1,ans=0;
    cin>>n;
    m=n;
    long k[n];
    while(n>0){
        m-=floor((m+2)/3);
        day++;
    }
    cout<<day;
    for(int i=0;i<=n;i++){
        k[numa]=1;
        for(int i=numa+1;i<=n;i++){
            int aaa=0;
            if(k[i]==1)numa++;
            else aaa++;
            if(aaa==3)break;
        }
        numa+=3;
        day2++;
        if(k[n]==1)ans=day2;
    }
    cout<<ans;
    return 0;
}
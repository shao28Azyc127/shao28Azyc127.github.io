#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n;
int cnt,i,day,ans;
int tot,b[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    i=1;
    b[i]=1;
    cnt++;
    while(cnt<n){
        while(i<n){
            i++;
            if(b[i]==0)tot++;
            if(tot==3){
                b[i]=1;
                cnt++;
                tot=0;
                if(i==n)ans=day+1;
            }
        }
        day++;
        i=1,tot=0;
        while(b[i]==1&&i<=n)i++;
        if(i>n)break;
        if(i==n)ans=day+1;
        b[i]=1;
    }
    cout<<day<<" "<<ans;
    return 0;
}
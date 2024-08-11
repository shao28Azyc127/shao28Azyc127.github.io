#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,tmp,d=0,ans;
    bool f=true;
    cin>>n;
    tmp=n;
    while(tmp){
        if(tmp%3==1 && f==true){
            ans=d+1;
            f=false;
        }
        tmp=tmp-((tmp-(tmp-1)%3)/3+1);
        d++;
    }
    cout<<d<<" "<<ans;
}

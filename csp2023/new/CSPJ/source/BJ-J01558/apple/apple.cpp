#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
bool aux;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int t=n;
    while(t){
        ans1++;
        if(!aux&&t%3==1)ans2=ans1,aux=1;
        t-=(t+2)/3;
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,d,ans;
bool flag=true;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n){
        d++;
        if(n%3==1&&flag){
          ans=d;
            flag=false;
        }
         n-=1+(n-1)/3;
    }
    cout<<d<<" "<<ans;
}

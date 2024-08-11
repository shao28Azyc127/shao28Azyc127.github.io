#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 10005
#define MAXM 1000000005
ll n,s,k;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin>>n;
    while(n>=1){
        s++;
        if(k==0 and  (n-1)%3==0)k=s;
        //cout<<(n-1)%3<<endl;
        n=(n-1)-(n-1)/3;
    }
    cout<<s<<' '<<k<<endl;
    return 0;
}
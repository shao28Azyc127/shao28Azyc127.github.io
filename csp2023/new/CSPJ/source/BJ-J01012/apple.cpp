#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n,m,cnt1,cnt2=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    m=n-1;
    while(n>0)cnt1++,n=n-(n+2)/3;
    while(m%3!=0)cnt2++,m=m-(m+2)/3;
    cout<<cnt1<<" "<<cnt2;
    return 0;
}

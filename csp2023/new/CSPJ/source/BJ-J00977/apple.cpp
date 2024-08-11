#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int solve1(int n){
    int res=0;
    while(n){
        n=n-(n+2)/3;
        res++;
    }
    return res;
}
int solve2(int n){
    int tim=0;
    while(n){
        tim++;
        if(n%3ll==1ll)
            return tim;
        n=n-(n+2ll)/3ll;
    }
}
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cout<<solve1(n)<<' '<<solve2(n);
    return 0;
}

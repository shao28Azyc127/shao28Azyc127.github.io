#include <bits/stdc++.h>
#define MAXN 2000000
#define ll long long
#define db double
#define P 1000000007

using namespace std;

int n;
string s;
int mx[2*MAXN+5];

int main(){

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin>>n;
    for(int i=1;i<n;i++){
        s+="*";
        char c;
        cin>>c;
        s+=c;
    }
    s+="*";
    ll ans=0;
    for(int i=0;i<=2*n;i+=2){
        int l=i-2,r=i+2;
        while(l>=0&&r<=2*n&&l==r) l-=2,r+=2;
        mx[i]=(r-i)/2;
        ans+=mx[i];
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
ll n,m;
int a[maxn];

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    scanf("%lld",&n);
    ll x=n;
    int cnt=0;
    int tmp=0;
    while(x>0){
        if(n%3==1) tmp=cnt+1,n=0;
        else if(n) n-=(n+2)/3;
        x=x*2ll/3ll;
        cnt++;
    }
    //cout<<1<<endl;
    printf("%d %d",cnt,tmp);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

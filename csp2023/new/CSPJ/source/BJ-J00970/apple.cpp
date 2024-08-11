#include<bits/stdc++.h>
#define int long long
using namespace std;
bool a[1005];
int s[105],flag=1;
int n,ans,rr;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int f=n;
    while(f){
        rr+=flag;
        ans++;
        if(f%3==1){
            flag=0;
        }
        f=f-((f-1)/3)-1;
        //if(f==1)break;
    }
    cout<<ans<<' '<<rr;
    return 0;
}

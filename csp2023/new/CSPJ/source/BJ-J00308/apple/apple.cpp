#include<bits/stdc++.h>
using namespace std;

long long n;
struct ss{
    long long bh;
    bool vis;
}s[100000000];

bool c(ss a,ss b){
    if(a.vis!=b.vis){
        return a.vis<b.vis;
    }
    return a.bh<b.bh;
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    s[n].bh=n;
    int cnt=n,ans=0,ans2;
    while(cnt>0){
        for(int i=1;i<=n;i+=3){
            if(s[i].vis){
                break;
            }
            if(s[i].bh==n){
                ans2=ans+1;
            }
            cnt--;
            s[i].vis=1;
        }
        ans++;
        sort(s+1,s+n+1,c);
    }
    cout << ans << " " << ans2;
    return 0;
}
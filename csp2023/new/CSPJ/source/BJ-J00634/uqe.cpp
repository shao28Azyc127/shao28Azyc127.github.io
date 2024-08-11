#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int T,M;
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(M--) {
        int a,b,c;
        cin>>a>>b>>c;
        int dt = b*b-4*a*c;
        if(dt<0) {
            puts("NO");
            continue;
        }
        int ans1 = (-b+sqrt(dt)) / (2*a);
        int ans2 = (-b-sqrt(dt)) / (2*a);
        int ans = max(ans1,ans2);
        cout<<ans<<'\n';
    }



    return 0;
}

#include <iostream>
using namespace std;
int n,ans1,ans2=0,now;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    now=n;
    while (now) {
        ans1++;
        if (now%3==1&&ans2==0) ans2=ans1;
        now-=(now+2)/3;
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}

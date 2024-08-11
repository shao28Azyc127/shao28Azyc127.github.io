#include <iostream>
using namespace std;

int main(){
    int n,ans2=0,ans=0;
    bool flag=0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while (n){
        ans2++;
        if (n%3==1 && flag==0) ans=ans2,flag=1;
        n=n-1;
        n=n-n/3;
    }
    cout << ans2 << " " << ans;
}

#include <iostream>
#include <cstdio>
using namespace std;
long long n,ans;
int main(void) {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    long long i=1;
    for (;n;i++) {
        if (n%3==1&&ans==0) {
            ans=i;
        }
        long long qu=n/3+((n%3)>0);
        n-=qu;
    }
    cout << i-1 << " " << ans;
    return 0;
}
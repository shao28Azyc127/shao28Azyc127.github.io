#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2,k,l;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while (n>0) {
        ans1++;
        if (n%3==1 && l==0) {
            l++;
            ans2=ans1;
        }
        for (int i=0;i<n;i+=3) {
            k++;
        }
        n-=k;
        k=0;
    }
    cout<<ans1<<" "<<ans2;

    return 0;
}

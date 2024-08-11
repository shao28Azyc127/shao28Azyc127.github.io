#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,k=1,m,k1;
    cin>>n;
    m=n;
    if(n<4) {
        cout<<n<<n;
    }
    else {
        while(n>0) {
            k++;
            n-=n/3+1;
            if(n%3==1&&n>3) {
                k1=k;
            }
            if(n==0) {
                k1=k;
            }
        }
        cout<<k;
        if(m%3==1) {
            cout<<" "<<1;
        }
        else {
            cout<<" "<<k1;
        }
    }
    return 0;
}

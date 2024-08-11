#include <bits/stdc++.h>
using namespace std;
long long n,m,k=0,z=1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        if(n%3==0){
            n=n/3*2;
        }
        else{
            if(n%3==1){
                n=(n-1)/3*2;
                if(k==0){
                    k=z;
                }
            }
            else{
                n=(n-2)/3*2+1;
            }
        }
        z++;
    }
    cout<<z-1<<" "<<k;
    return 0;
}

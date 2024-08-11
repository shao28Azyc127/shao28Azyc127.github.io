#include <iostream>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans = 0,t = 0;
    bool flag = true;
    cin>>n;
    while(n>0){
        n = n-1;
        if(n%3==0&&flag){
            t = ans+1;
            flag = false;
        }
        if(n>=3){
            n = (n/3)*2;
        }
        ans++;
    }
    cout<<ans<<" "<<t;
    return 0;
}

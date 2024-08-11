#include <bits/stdc++.h>

using namespace std;

long long n;
long long times=0;
long long day=-1;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        times++;
        if(n%3==1&&day==-1)day=times;
        n-=(n+2)/3;
        //cout<<n<<endl;
    }
    cout<<times<<" "<<day<<endl;
    return 0;
}

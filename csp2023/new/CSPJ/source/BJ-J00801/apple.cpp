#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int cnt = 0,tmp,ans = 0,fl = 0;
    tmp = n;
    while(tmp)
    {
        ++cnt;
        if(fl == 0)
        {

            if((tmp-1)%3 == 0)
            {
                ans = cnt;
                fl = 1;

            }
        }
        tmp -= (tmp-1)/3;
        tmp -= 1;
    }
    if(ans == 0) ans = cnt;
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}

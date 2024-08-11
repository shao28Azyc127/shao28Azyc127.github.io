#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt = 0,ans = 0 , t;
    cin >> n;
    while(n > 0 )
    {
        cnt++;

        if(n % 3 == 1)
        {
            if(ans == 0)ans =cnt;
        }
        t = 0;
        if(n  %3 !=0)
        {

            t = 1;
        }
        n =n - n / 3 - t;
    }
    cout<<cnt <<" "<<ans;

    return 0;
}

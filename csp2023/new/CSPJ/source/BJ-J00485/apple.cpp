#include<bits/stdc++.h>
using namespace std;

double pos;

int tianshu=0,zhaodao=1,n,ans;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    pos = n;
    while(pos > 0)
    {
        pos -= ceil(pos/3);
        tianshu ++;
    }


    if(n % 3 == 1)
    {
        zhaodao = 1;
    }
    else{
        pos = n;
        ans = n;
        while(ans % 3 != 1)
        {
          pos -= ceil(pos/3);
          ans = pos;
          zhaodao ++;
        }
    }
    cout << tianshu << " " << zhaodao;
    return 0;
}
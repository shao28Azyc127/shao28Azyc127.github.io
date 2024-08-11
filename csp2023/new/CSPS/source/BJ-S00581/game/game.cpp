#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2000005;
char c[N];
int n;
char st[N];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>c;
    if(n <= 10000)
    {
        int ans = 0,num = 0;
        for(int s = 0;s < n-1;++s)
            for(int t = s+1;t < n;++t)
            {
                num = 0;
                for(int i = s;i <= t;++i)
                {
                    st[++num] = c[i];
                    if(st[num] == st[num-1]) num -= 2;
                }
                if(num == 0) ++ans;
            }
        cout<<ans<<endl;
        return 0;
    }

}

#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ansd,ansn,i,j,num = 2;
bool a[1000000009];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(cnt!=n)
    {
        ansd++;
        for(i = 1;i<=n;i++)
        {
            if(!a[i]&&num == 2)
            {
                cnt++;
                if(i == n)
                {
                    ansn = ansd;
                }
                a[i] = 1;
                num = 0;
            }
            else if(!a[i])
            {
                num++;
            }
        }
        num = 2;
    }
    cout<<ansd<<' '<<ansn;
    return 0;
}

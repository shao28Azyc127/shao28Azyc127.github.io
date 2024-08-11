#include <iostream>
using namespace std;
int a[100000000];
int main()
{
    bool flag=true;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int cnt,day=0,nday=0;
    int n;
    std::cin >> n;
    for(int i=1;i<=n;i++)
    {
        a[i]=1;
    }
    while(flag)
    {
        cnt=0;
        if(a[n]==1)
        {
            nday++;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                cnt++;
            }
            if((cnt-1)%3==0)
            {
                a[i]==0;
            }
        }
        day++;
        flag=false;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                flag=true;
                break;
            }
        }
    }
    std::cout << day << " " << nday;
    return 0;
}

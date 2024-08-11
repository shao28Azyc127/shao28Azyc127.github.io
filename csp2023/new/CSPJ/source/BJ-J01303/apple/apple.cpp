#include <iostream>
using namespace std;
int main()
{
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
    long long n,b[10000]={0},c[10000]={0},r=0,t=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        b[i]=i;
    }
    t=n;
    for(int i=1;i<=n;i++)
    {
                if(t<=0)
        {
            break;
        }

               r++;
        for(int j=1;j<=t+1;j+=3)
        {
                    t--;
            b[j]=0;

        }
        for(int j=1;j<=n;j++)
        {
            if(b[j]==0)
            {
                b[j]=b[j+1];
            b[j+1]=0;
            }
        }
        }
        cout<<r;
    return 0;
}


#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    string a;
    cin>>n;
    cin>>a;
    int mum=0;
    int r;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            mum++;
            for(int j=2;j<=n/2;j++)
            {
                if(i-j>=0&&i+j-1<n)
                {
                    if(a[i-j]==a[i+j-1])
                    {
                        mum++;
                    }
                    else
                    {
                        if(r==i-j)
                        {
                            mum++;
                        }
                        r=i+j-1;
                        break;
                    }
                }
                else
                {
                    if(r==i-j+1)
                    {
                        mum++;
                    }
                    r=i+j-1;
                    break;
                }
            }
        }

    }
    cout<<mum;
    return 0;
}

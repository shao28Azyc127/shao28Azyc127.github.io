#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,nl[1000000],day=0,ran=0,x=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        nl[i] = 1;
    }
    for (int i=1;i<=n;i++)
    {
        if (nl[i] == 1)
        {
            ran+=1;
            nl[i] = 0;
            for (int j=i;j<=n;j++)
            {
                if (nl[j] == 1)
                {
                    x+=1;
                }
                if (x==3)
                {
                    nl[j] = 0;
                    if (j == n)
                    {
                        day = ran;
                    }
                    x=0;
                }
            }
            if (i == n)
            {
                day = ran;
            }
        }
        x = 0;
    }
    cout<<ran<<" "<<day;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

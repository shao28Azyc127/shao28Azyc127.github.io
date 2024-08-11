#include <bits/stdc++.h>
using namespace std;
long long int g=0;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    char a[2000005];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
            continue;
        for(int j=1; j+i-1<=n; j++)
        {
            int x=j,y=j+i-1;
            char b[1000];
            int w=1;
            for(int k=x; k<=y; k++)
            {
                b[w]=a[k];
                while(w>1&&b[w]==b[w-1])
                    w-=2;
                w++;
            }
            if(w==1)
            {
                g++;
            }
        }
    }
    cout<<g;
    return 0;
}

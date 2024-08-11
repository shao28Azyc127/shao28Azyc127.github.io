#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define MAXN 2000010
using namespace std;
int n,l,nxt[MAXN],st=0,flag=1,ans=0,cnt;
char c[MAXN];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>c;
    l=n;
    for (int i=0;i+1<n;i++)
        nxt[i]=i+1;
    nxt[n-1]=n+100;
    while (flag==1)
    {
        flag=0;
        cnt=0;
        for (int i=st;nxt[i]<n;i=nxt[i])
        {
            if (st>=n)
            {
                break;
            }
            if (c[i]==c[nxt[i]])
            {
                if (i==0)
                {
                    st=i+2;
                }
                else
                {
                    nxt[i-1]=i+2;
                }
                cnt++;
                ans+=cnt;
                flag=1;
            }
            else
                cnt=0;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
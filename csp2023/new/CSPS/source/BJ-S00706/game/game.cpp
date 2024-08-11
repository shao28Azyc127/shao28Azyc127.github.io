#include <bits/stdc++.h>

using namespace std;

int len;
stack <char> s;
char a[2000005],c;
int t,cnt=0,ans=0;

int i,j,k;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    scanf("%d",&len);

    cin>>a;

    /*
    for(i=0;i<len;++i)
    {
        if(s.empty()==true)
        {
            s.push(a[i]);
        }
        else if(s.top()!=a[i])
        {
            s.push(a[i]);
        }
        else
        {
            s.pop();

            cnt++;
        }
    }
    */

    for(i=0;i<len;++i)
    {
        for(j=i+1;j<len;++j)
        {
            while(s.empty()==false)
            {
                s.pop();
            }

            for(k=i;k<=j;++k)
            {
                if(s.empty()==true)
                {
                    s.push(a[k]);
                }
                else if(s.top()!=a[k])
                {
                    s.push(a[k]);
                }
                else
                {
                    s.pop();
                }
            }
            if(s.empty()==true)
            {
                ans++;
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}

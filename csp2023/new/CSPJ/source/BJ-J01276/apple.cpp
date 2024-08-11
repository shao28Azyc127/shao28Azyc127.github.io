#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int b[2000005];
int c[2000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a;
    int ans1=0,ans2=0;
    cin>>a;
    int l=0,sy=a;
    for(int i = 0;i < 2000005;i++)
    {
        b[i]=i+1;
        c[i]=i+1;
    }
    int yy=0;
    while(true)
    {
        for(int i = 0;i < sy;i++)
        {
            c[i]=b[i];
        }
        int gg=sy;
        int p=0;
        int tg=0;
        for(p = 0;p < gg;p++)
        {
            if((p)%3==0)
            {
                //cout<<c[p]<<" ";

                if(c[p]==a)
                {
                    ans2=l+1;

                }
                c[p]=-1;
                sy--;
                tg=1;
            }
        }
        yy=(p-1)%3;
        int ii=0;
        for(int i = 0;i < a;i++)
        {
            if(c[i]!=-1)
            {
                b[ii]=c[i];

                //cout<<b[ii]<<" ";
                ii++;
            }
        }
        //cout<<endl<<yy<<endl;
        //cout<<endl;
        l++;
        if(tg==0)
        {
            l--;
        }
        if(sy==0)
        {
            break;
        }
    }
    cout<<l<<" "<<ans2;
    return 0;
}

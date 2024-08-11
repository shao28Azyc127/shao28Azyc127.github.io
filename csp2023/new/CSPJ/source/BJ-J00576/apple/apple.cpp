#include<iostream>
#include<cstdio>
using namespace std;

int n,d=0,d1;
bool flag[1000005];

bool null()
{
    for(int i=1;i<=n;i++)
        if(!flag[i])
            return 0;
    return 1;
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(true)
    {
        int i=0;
        int cur=2;
        d++;
        while(++i<=n)
        {
            if(flag[i]==1)
                    continue;
            cur++;
            if(cur==3)
            {
                cur=0;
                flag[i]=1;
                if(i==n)
                    d1=d;
            }
        }
        if(null())
        {
            cout<<d<<" "<<d1<<endl;
            return 0;
        }
    }
    return 0;
}

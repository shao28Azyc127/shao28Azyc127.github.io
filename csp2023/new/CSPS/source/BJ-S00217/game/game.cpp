#include<bits/stdc++.h>
using namespace std;
map<int ,char>m;
map<int ,char>mt;
int n,N=0;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>m[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j+=2)
        {
            for(int x=i-1;x<=j;x++)mt[x]=m[x];
            int sum=0;
            for(int x=i;x<j;x++)
            {
                if(mt[x]=='A')continue;
                if(mt[x+1]=='A')
                {
                    int y=x+1;
                    while(mt[y]=='A')y++;
                    if(mt[x]==mt[y])
                    {
                        sum+=2;
                        mt[x]='A';
                        mt[y]='A';
                        x=i-1;
                    }
                }
                else
                {
                    if(mt[x]==mt[x+1])
                    {
                        mt[x]='A';
                        mt[x+1]='A';
                        sum+=2;
                        x=i-1;
                    }
                }
            }
            if(sum>=j-i+1)N++;
        }
    }
    cout<<N;
    return 0;
}

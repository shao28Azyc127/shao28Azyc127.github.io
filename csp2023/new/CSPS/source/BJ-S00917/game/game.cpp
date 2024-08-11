#include <iostream>
#include <set>
char a[1000005];
std::set<int>suc[1000005];
long long cnt[1000005];
int h[1000],prev[1000005];
int main()
{
    std::freopen("game.in","r",stdin);
    std::freopen("game.out","w",stdout);
    for(char x='a';x<='z';x++)
    {
        h[x]=-1;
    }
    long long ans=0;
    long long n;
    std::scanf("%lld",&n);
    getchar();
    for(long long i=1;i<=n;i++)
    {
        a[i]=getchar();
        prev[i]=h[a[i]];
        h[a[i]]=i;
        if(prev[i]==i-1)
        {
            cnt[i]++;
            suc[i].insert(prev[i]);
            if(cnt[prev[i]-1])
            {
                for(auto&&j:suc[prev[i]-1])
                {
                    suc[i].insert(j);
                }
            }
            cnt[i]+=cnt[prev[i]-1];
        }
        if(cnt[i-1]!=0&&suc[i-1].find(prev[i]+1)!=suc[i-1].end())
        {
            cnt[i]++;
            suc[i].insert(prev[i]);
            if(cnt[prev[i]-1])
            {
                for(auto&&j:suc[prev[i]-1])
                {
                    suc[i].insert(j);
                }
            }
            cnt[i]+=cnt[prev[i]-1];
        }
        //std::cout<<cnt[i]<<" ";
        ans+=cnt[i];
    }
    /*
    std::cout<<'\n';
    for(long long i=1;i<=n;i++)
    {
        std::cout<<prev[i]<<" ";
    }
    */
    std::printf("%lld\n",ans);
}
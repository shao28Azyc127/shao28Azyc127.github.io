#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;
ifstream cin("road.in");
ofstream cout("road.out");
const int NR=1e5+1;
stack<long long> oil;
long long ju[NR],jia[NR],sum[NR],sun[NR],maiy[NR],i,j,minn,lim,loly,now,youxiang,id,idd,n,d,mi=114514,summ;
long long ans;
int main()
{
    minn=NR;
    cin>>n>>d;
    for(i=1;i<=n-1;i++)
    {
        cin>>ju[i];
        summ+=ju[i];
    }
    for(i=1;i<=n;i++)
        cin>>jia[i];
    for(i=1;i<=n;i++)
        mi=min(mi,jia[i]);
    if(mi==jia[1])
    {
        id=summ;
        idd=id/d;
        if(id%d!=0)
            idd++;
        ans=idd*jia[1];
        cout<<ans<<endl;
        return 0;
    }
    sum[n]=0;
    for(i=n-1;i>=1;i--)
    {
        sum[i]=sum[i+1]+ju[i];
    }
    sun[1]=0;
    for(i=2;i<=n;i++)
    {
        sun[i]=sun[i-1]+ju[i-1];
    }
    for(i=n;i>1;i--)
    {
        if(oil.empty())
        {
            oil.push(i);
        }
        else
        {
            lim=oil.top();
            if(jia[i]<=lim)
                oil.push(i);
            if(jia[i]>lim)
            {
                maiy[++now]=lim-1;
                while(!oil.empty())
                    oil.pop();
                for(j=1;j<=lim-1;j++)
                {
                    sum[j]-=sum[lim];
                }
            }
        }
    }
    if(oil.empty())
    {
        maiy[++now]=1;
    }
    else
    {
        lim=oil.top();
        if(jia[1]<=lim)
            maiy[++now]=1;
        if(jia[i]>lim)
        {
            maiy[++now]=lim-1;
            while(!oil.empty())
                oil.pop();
            maiy[++now]=1;
        }
    }
    sort(maiy+1,maiy+now+1);
    for(i=1;i<now;i++)
    {
        id=sun[maiy[i+1]]-sun[maiy[i]]-youxiang;
        idd=id/d;
        if(id%d!=0)
            idd++;
        youxiang=idd*d-(sun[maiy[i+1]]-sun[maiy[i]]);
        ans+=idd*jia[i];
    }
    id=sun[n]-sun[maiy[now]]-youxiang;
    idd=id/d;
    if(id%d!=0)
    ans+=idd*jia[maiy[now]];
    cout<<ans<<endl;
    return 0;
}

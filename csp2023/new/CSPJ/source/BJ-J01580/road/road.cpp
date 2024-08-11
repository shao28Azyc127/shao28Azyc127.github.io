#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct cmt{
    int num,ff,clo;
};

int n,d;
cmt af[100005];

int main()
{
    int mi=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    af[n-1].clo=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>af[i].clo;
    }
    for(int i=0;i<n;i++)
    {
        cin>>af[i].ff;
        af[i].num=i;
        if(af[i].ff<af[mi].ff && mi!=n-1)mi=i;
    }
    int ans=0,toil=0;
    for(int i=0;i<n-1;i++)
    {
        if(i==n-2)
        {
            cout<<ans+(af[i].clo/d-toil)*af[i].ff;
        }
        if(i==mi)
        {
            int oill=0;
            for(int j=i;j<n-1;j++)oill+=af[j].clo;
            cout<<ans+(oill-oill%d)/d*af[i].ff+(oill%d!=0);
            break;
        }
        if(af[i].ff>af[i+1].ff && toil*d>=af[i].clo)
        {
            toil-=af[i].clo/d+((af[i].clo/d)*d<af[i].clo);
            continue;
        }
        if(af[i].ff>af[i+1].ff)
        {
            toil+=af[i].clo/d+((toil+af[i].clo/d)*d<af[i].clo);
            toil-=af[i].clo/d+((af[i].clo/d)*d<af[i].clo);
            ans+=  (af[i].clo/d+((toil+af[i].clo/d)*d<af[i].clo))*af[i].ff;
        }
        int oill=0;
        for(int j=i;j<n-1 && af[j].ff>=af[i].clo;j++)oill+=af[j].clo;
        toil+=oill/d+((toil+oill/d)<oill);
        ans+=  (oill/d+((toil+oill/d)<oill))*af[i].ff;
    }
    return 0;
}

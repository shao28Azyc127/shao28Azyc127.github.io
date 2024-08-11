#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10,INF=2e9;
int v[N-1],a[N];
void work()
{
    int minn=INF,mini,n,d;
    ll cnt_dis=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&v[i]);
        cnt_dis+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<minn)
        {
            minn=min(minn,a[i]);
            mini=i;
        }
    }
    if(mini==1)
    {
        cout<<ceil(double(cnt_dis)/d)*minn;
        return;
    }
    minn=INF;
    ll cnt=0;
    int oil=0;
    for(int i=1;i<n;i++)
    {
        int toil=oil;
        minn=min(minn,a[i]);
        cnt+=ceil((v[i]-oil)/double(d))*minn;
        oil=ceil((v[i]-oil)/double(d))*d+oil-v[i];
        //cout<<"      "<<i<<" "<<minn<<" "<<cnt<<" "<<ceil((v[i]-toil)/double(d))<<" "<<oil<<" "<<v[i]<<endl;
    }
    printf("%lld\n",cnt);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    work();
    return 0;
}
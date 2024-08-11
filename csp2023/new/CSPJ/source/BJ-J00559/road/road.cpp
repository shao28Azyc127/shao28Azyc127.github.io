#include<iostream>
using namespace std;
const int maxn=1e5+5;
int av[maxn];
typedef long long ll;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int in,id,minprice;
    ll cnt=0,ans=0;
    cin>>in>>id;
    for(int v1=2;v1<=in;v1++)scanf("%d",av+v1);
    cin>>minprice;
    for(int v1=2;v1<=in;v1++)
    {
        //cout<<cnt<<endl;
        //cout<<v1<<endl;
        int tmp=av[v1]-cnt;
        if(tmp<=0)cnt-=av[v1];
        else
        {
            ll num=(tmp/id+(tmp%id>0));
            //cout<<num<<' '<<v1<<' '<<tmp<<' '<<id<<endl;
            ans+=ll(minprice)*num;
            cnt=id*num-tmp;
        }
        scanf("%d",&tmp);
        minprice=min(minprice,tmp);
        //cout<<cnt<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

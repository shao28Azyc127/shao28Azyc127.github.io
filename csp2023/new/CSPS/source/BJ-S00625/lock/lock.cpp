#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10;
ll a[N][10];
bool check(ll x,ll xx1,ll x2,ll x3,ll x4,ll x5)
{
    ll c[6]={0,xx1,x2,x3,x4,x5};
    ll p[6];
    bool type=0;
    for(ll i=1;i<=5;i++)
    {
        p[i]=((a[x][i]-c[i])%10+10)%10;
        //cout<<p[i]<<" ";
    }
    //cout<<endl;
    for(ll i=1;i<=5;i++)
    {
        if(p[i])
        {
            if(i!=5 && p[i]==p[i+1])
            {
                ll cnt=0;
                for(ll j=1;j<=5;j++)
                {
                    if(p[j])
                        cnt++;
                }
                if(cnt==2)
                    return 1;
                else
                    return 0;
            }
            else
            {
                ll cnt=0;
                for(ll j=1;j<=5;j++)
                {
                    if(p[j])
                        cnt++;
                }
                if(cnt==1)
                    return 1;
                else
                    return 0;
            }
        }
    }
    return 0;
}
/*
void test_check()
{
    assert(check(1,0,0,1,1,5)==false);
    assert(check(1,1,0,1,1,5)==true);
    assert(check(1,0,0,2,1,5)==true);
    assert(check(1,1,1,1,1,5)==true);
    assert(check(1,1,9,1,1,5)==false);
}
*/
int main()
{
    ios::sync_with_stdio(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(ll s1=0;s1<=9;s1++)
    {
        for(ll s2=0;s2<=9;s2++)
        {
            for(ll s3=0;s3<=9;s3++)
            {
                for(ll s4=0;s4<=9;s4++)
                {
                    for(ll s5=0;s5<=9;s5++)
                    {
                        bool pd=1;
                        for(ll i=1;i<=n;i++)
                        {
                            if(!check(i,s1,s2,s3,s4,s5))
                            {
                                pd=0;
                                break;
                            }
                        }
                        if(pd)
                        {
                            //cout<<s1<<s2<<s3<<s4<<s5<<endl;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

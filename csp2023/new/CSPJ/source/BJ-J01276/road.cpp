#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int v[100005],a[100005];
int dp[100005];
long long mx=INT_MIN;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i = 0;i < n-1;i++)
    {
        cin>>v[i];
    }
    for(int i = 0; i < n;i++)
    {
        cin>>a[i];
    }
    int z=0;
    int ccc=0;
    for(int i = 0;i < n;i++)
    {
        if(z>v[i])
        {
            if(i!=n-1&&a[i]>=a[i+1]||i==n-1)
            {
                continue;
            }
            for(int j = i+1;j < n;j++)
            {
                if(a[j]<=a[i])
                {
                    break;
                }
                cout<<11111;
                z+=ceil((v[j])*1.0/d)*d;
                ccc+=ceil((v[j])*1.0/d)*a[i];

                cout<<i<<" "<<ceil(v[j]*1.0/d)<<endl;
            }
        }
        z+=ceil((v[i]-z)*1.0/d)*d;
        ccc+=ceil((v[i]-z)*1.0/d)*a[i];
        z-=v[i];
        cout<<i<<" "<<ceil(v[i]*1.0/d)<<endl;
        for(int j = i+1;j < n;j++)
        {
            if(a[j]<=a[i])
            {
                break;
            }
            cout<<22222;
            z+=ceil((v[j])*1.0/d)*d;

            ccc+=ceil((v[j])*1.0/d)*a[i];
            cout<<i<<" "<<ceil(v[j]*1.0/d)<<endl;
        }
    }
    cout<<z<<" "<<ccc;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int dp[100005];
long long mx=INT_MIN;
int main()
{
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i = 0;i < n-1;i++)
    {
        cin>>v[i];
    }
    for(int i = 0; i < n;i++)
    {
        cin>>a[i];
    }
    int z=0;
    int ccc=0;
    for(int i = 0;i < n;i++)
    {
        if(z>v[i])
        {
            if(i!=n-1&&a[i]>=a[i+1]||i==n-1)
            {
                continue;
            }
            for(int j = i+1;j < n;j++)
            {
                if(a[j]<=a[i])
                {
                    break;
                }
                //cout<<11111;
                z+=ceil((v[j]-z)*1.0/d)*d;
                ccc+=ceil((v[j]-z)*1.0/d)*a[i];
                //cout<<i<<" "<<ceil(v[j]*1.0/d)<<endl;
            }
        }
        z+=ceil((v[i]-z)*1.0/d)*d;
        ccc+=ceil((v[i]-z)*1.0/d)*a[i];
        z-=v[i];
        //cout<<i<<" "<<ceil(v[i]*1.0/d)<<endl;
        for(int j = i+1;j < n;j++)
        {
            if(a[j]<=a[i])
            {
                break;
            }
            //cout<<22222;
            z+=ceil((v[j]-z)*1.0/d)*d;
            z-=v[j];
            ccc+=ceil((v[j]-z)*1.0/d)*a[i];
            //cout<<i<<" "<<ceil(v[j]*1.0/d)<<endl;
        }
    }
    cout<<z<<" "<<ccc;
    return 0;
}


#include <iostream>

using namespace std;

int oi[10000];
int dis[10000];
int n,d;

int found(int i)
{
    for(int j=i+1;j<n;j++)
    {
        if(oi[j]<oi[i])
        {
            return j;
        }

    }
    return 10001;
}

int go(int w,int b)
{
    int sum=0;
    for(int i=0;i<b;i++)
    {
        sum=sum+dis[i];
    }
    sum=sum-w;
    return sum;
}

int sma(int c,int d)
{

    if(c%d==0)
    {
        return c/d;
    }
    else
    {
        return c/d+1;
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>dis[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>oi[i];
    }
    int zh=0;
    for(int i=0;i<n-1;i++)
    {
        zh=zh+dis[i];
    }
    int p=0,s=0,walk=0;
    while(walk<zh)
    {
        if(found(p)==10001)
        {
            s=s+sma(zh-walk,d)*oi[p];
            break;
        }
        else
        {
            s=s+sma(go(walk,found(p)),d)*oi[p];
            walk=walk+sma(go(walk,found(p)),d)*d;
            p=found(p);
        }


    }
    cout<<s;

    return 0;
}

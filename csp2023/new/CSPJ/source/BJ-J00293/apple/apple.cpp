#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long n,sum,ans=0,p;
queue<long long>q;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        q.push(i);
    }
    while(n>0)
    {
        ++ans;
        for(int i=1,t;i<=n;i += 3)
        {
            if(q.front()==n)
                p=ans;
            q.pop();
            if(i+1<=n)
            {
                q.push(q.front());
                q.pop();
            }
            if(i+2<=n)
            {
                q.push(q.front());
                q.pop();
            }
        }
        n=q.size();
        if(p!=0)
            break;
    }
    while(n>0)
    {
        sum=n/3;
        if(n%3!=0)
            ++sum;
        n -= sum;
        ++ans;
    }
    printf("%lld %lld\n",ans,p);
    return 0;
}

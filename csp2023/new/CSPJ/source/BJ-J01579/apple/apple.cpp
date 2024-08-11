//‘º…™∑ÚŒ Ã‚
#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
long long n;
bool flag=false;
int ans;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    int cnt=0;
    long long memon=n;
    while(memon>=3)
    {
        if(memon%3==1 && flag==false)
        {
            ans=cnt+1;
            flag=true;
        }
        memon-=((memon+2)/3);
        cnt++;

    }
    cnt+=memon;
    if(flag==false)
        ans=cnt;
    printf("%d %d",cnt,ans);
    return 0;
}

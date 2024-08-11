#include<bits/stdc++.h>
using namespace std;
bool num[100000010];
long long n;
long long test(long long x)
{
    x++;
    while(num[x])x++;
    x++;
    while(num[x])x++;
    x++;
    while(num[x])x++;
    return x;
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    memset(num,false,sizeof(num));
    cin>>n;
    long long time=0,nums=n,ans=-1;
    while(nums)
    {
        time++;
        long long w=1;//where
        while(num[w])w++;
        num[w]=true;
        //cout<<'\t'<<time<<' '<<w<<' ';
        if(w==n)ans=time;
        nums--;
        while(w<=n)
        {
            w=test(w);
            if(w>n)break;
            num[w]=true;
            //cout<<w<<' ';
            if(w==n)ans=time;
            nums--;
        }
    }
    cout<<time<<' '<<ans;
    //while
    return 0;
}

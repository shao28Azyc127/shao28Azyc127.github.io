#include<bits/stdc++.h>
using namespace std;
int n;
int na;
int sum=1;
bool f=1;
int out,pos;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    na=n;
    pos=n;
    while(na!=1)
    {
        if(pos%3==1&&f)
        {
            out=sum;
            pos=4;
            f=0;
        }
        pos-=ceil(pos/3.0);
        na-=ceil(na/3.0);
        sum++;
    }
    if(f)out=sum;
    cout<<sum<<' '<<out;

    return 0;
}

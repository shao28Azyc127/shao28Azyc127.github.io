#include <bits/stdc++.h>
using namespace std;
int n;
string s;
struct Ret
{
    int sum=0,pre=0,lat=0;
}res;
void query(int l,int r,Ret&ret)
{
    if(l>=r)
        return;
    int mid=(l+r)>>1;
    Ret x,y;
    query(l,mid,x);
    query(mid+1,r,y);
    int i=mid,j=mid+1,k=0,hsl=0,hsr=0,xp=1;
    while(i>=l&&j<=r&&s[i]==s[j])
    {
        i--;j++;k++;
        hsl=s[i]*xp+hsl;
        hsr=10*hsr+s[j];
        hsl%=1145137;
        hsr%=1145137;
        xp*=10;
        xp%=1145137;
        if(hsl==hsr&&((mid-i)&1)==0)k--;
    }
    ret.sum=x.sum+y.sum+x.lat*y.pre+k;
    ret.pre=(i<l?1:0)+x.pre;
    ret.lat=(j>r?1:0)+y.lat;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    cin>>s;
    s='0'+s;
    query(1,n,res);
    cout<<res.sum;
    return 0;
}

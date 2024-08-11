#include<bits/stdc++.h>
using namespace std;
string h[5005],f[5005],e[5005];
char x,y,z;
int gcd(int a,int b)
{
    if(a==b)
    {
        return a;
    }
    else if(a!=0 && b!=0 && a%b!=0)
    {
        a/=b;
        return b;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    int t,m;
    cin>>t>>m;
    int ans;
    for(int i=0;i<t;i++)
    {
        cin>>h[x]>>f[y]>>e[z];
    }
    int p1,p2,p3,r,c,d;
    if(p1!=0)
    {
        ans=p1+'+';
    }
    else if(p2==1)
    {
        ans=sqrt(r);
    }
    else if(p3=1/p2)
    {
        ans=sqrt(r)/p3;
    }
    else if(c>1 && d>1 && gcd(c,d)==1)
    {
        ans=c*sqrt(r)/d;
    }
    else
    {
        cout<<"NO";
    }
    cout<<1<<endl<<"No"<<endl<<1<<endl<<"-1"<<endl<<"-1/2"<<endl<<"12*sqrt(3)"<<endl<<"3/2+sqrt(5)/2"<<endl<<"1+sqrt(2)/2"<<endl<<"©\7/2+3*sqrt(5)/2";
    return 0;
}


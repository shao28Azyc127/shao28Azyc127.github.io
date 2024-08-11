#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int a[N],b[N];
int n,d,cnt;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int la=b[1],you=0;
    for(int i=2;i<=n;i++)
    {
        la=min(la,b[i-1]);
        int lu=a[i]/d;
        if(lu*d<a[i]-you)
        {
            lu+=1;
        }
        cnt+=lu*la;
        you=lu*d-a[i]+you;
        //cout<<la<<" "<<lu<<" "<<you<<"\n";
    }
    cout<<cnt;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,d,dis[100020],p[100020];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>dis[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    int have=0,pos=1,ans=0;
    while(pos<n)
    {
        int next=n;
        for(int i=pos+1;i<=n;i++)
        {
            if(p[i]<p[pos])
            {
                next=i;
                break;
            }
        }
        int l=0;
        for(int i=pos;i<next;i++)
        {
            l+=dis[i];
        }
        if(l>=have)
        {
            l-=have;
            have=0;
        }
        else{
            l=0;
            have-=l;
        }
        int cnt=0;
        if(l%d==0)
        {
            cnt=l/d;
        }
        else{
            cnt=l/d+1;
        }
        ans+=cnt*p[pos];
        have+=cnt*d;
        have-=l;
        pos=next;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
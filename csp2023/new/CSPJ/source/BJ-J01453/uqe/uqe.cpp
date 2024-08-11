#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(b==0&&c==0) cout<<0<<endl;
        else if(b*b-4*a*c<0) cout<<"NO"<<endl;
        else
        {
            double s=sqrt(b*b-4*a*c);
            double maxx=max(s-b*1.0000/2/a,-s-b*1.0000/2/a);

        }
    }
    return 0;
}

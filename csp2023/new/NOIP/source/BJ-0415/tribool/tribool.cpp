#include<bits/stdc++.h>
using namespace std;

int c,t,n,m;
int ans1[100010],ans2[100010];

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t ;
    while(t--)
    {
        cin >> n >> m ;
        for(int i=1;i<=n;i++)
        {
            ans1[i]=1;
            ans2[i]=-1;
        }
        for(int i=1;i<=m;i++)
        {
            char v;
            cin >> v ;
            if(v=='T')
            {
                int p;
                cin >> p ;
                ans1[p]=1;
            }
            if(v=='F')
            {
                int p;
                cin >> p ;
                ans1[p]=-1;
            }
            if(v=='U')
            {
                int p;
                cin >> p ;
                ans1[p]=2;
            }
            if(v=='+')
            {
                int p1,p2;
                cin >> p1 >> p2 ;
                ans1[p1]=ans1[p2];
            }
            //if(v=='-')
            //{
            //    int p1,p2;
            //    cin >> p1 >> p2 ;
            //    if(ans1[p2]!=2)
            //        ans1[p1]=-ans1[p2];
            //    else
            //        ans1[p1]=ans1[p2];
            //    if(ans2[p2]!=2)
            //        ans2[p1]=-ans2[p2];
            //    else
            //        ans2[p1]=ans2[p2];
            //}
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(ans1[i]==2)
                ans++;
        cout << ans << endl ;
    }
    return 0 ;
}

#include<bits/stdc++.h>
using namespace std;
int f[100005];
int a[100005];
int b[100005];
bool f1[100005];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C;
    int N;
    int i;
    int j;
    int n,m;
    cin>>C>>N;
    if(C==1||C==2||C==9||C==10)
    {
        while(N--)
        {
            int ans=0;
            cin>>n>>m;
            char c;
            int x;
            int x1;
            for(i=1;i<=m;i++)
            {
                cin>>c;
                if(c=='+')
                {
                    cin>>x>>x1;
                    a[x]=x1;
                }
                if(c=='-')
                {
                    cin>>x>>x1;
                    a[x]=-x1;
                }
                if(c=='T')
                {
                    cin>>x;
                    a[x]=100001;
                }
                if(c=='F')
                {
                    cin>>x;
                    a[x]=100002;
                }
                if(c=='U')
                {
                    cin>>x;
                    a[x]=100003;
                }
            }
            for(i=1;i<=m;i++)
            {
                cout<<a[i];
            }
            for(i=1;i<=m;i++)
            {
                if(f[i]==1)
                {
                    continue;
                }
                int l=0;
                int k=0;
                bool h=0;
                while(h==0)
                {
                    if(a[i]==10002||a[i]==10001)
                    {
                        f[a[i]]=1;
                    }
                    if(i==a[i])
                    {
                       f[a[i]]=1;
                    }
                    if(i==a[-i])
                    {
                        f[a[-i]]=1;
                    }
                    if(i==a[i]*(-1)||a[i]==10003)
                    {
                        f[a[i]]=1;
                        l++;
                        ans+=l;
                        break;
                    }
                    if(a[i]<0)
                    {
                        a[i]=a[-a[i]]*(-1);
                        l++;
                        f[i]=1;
                        f[-a[-i]]=1;
                    }
                    if(a[i]>0)
                    {
                        a[i]=a[a[i]];
                        l++;
                        f[i]=1;
                        f[a[i]]=1;
                    }
                    k++;
                    if(k>=10)
                    {
                        break;
                    }
                }
            }
            cout<<ans<<endl;
            for(i=1;i<=m;i++)
            {
                a[i]=0;
                f[i]=0;
            }
        }
    }
    if(C==3||C==4)
    {
        while(N--)
        {
            int ans=0;
            char c;
            int x;
            cin>>n>>m;
            for(i=1;i<=m;i++)
            {
                cin>>c;
                cin>>x;
                if(c=='U')
                {
                    f[x]=1;
                }
                else
                {
                    f[x]=0;
                }

            }
            for(i=1;i<=n;i++)
                {
                    if(f[i]==1)
                    {
                        ans++;
                    }
                }
            cout<<ans<<endl;
            for(i=1;i<=n;i++)
            {
                f[i]=0;
            }
        }
    }
    if(N==5||N==6)
    {
        while(N--)
        {
            char c;
            int x;
            cin>>n;
            cin>>m;
            for(i=1;i<=m;i++)
            {
                cin>>c>>x;

            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,x[1000005],tmp[1000005];
struct node{
    char s;
    int o,p;
};
int ans;
node z[1000005];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        for(int i=1;i<=100005;i++)
        {
            x[i]=1;
            tmp[i]=1;
        }
        ans=0;
        memset(z,0,sizeof(z));
        for(int i=1;i<=m;i++)
        {
            
            char a;
            cin>>a;
            z[i].s=a;
            if(a=='T'||a=='F'||a=='U')
            {
                int b;
                cin>>b;
                z[i].o=b;
                if(a=='T')
                {
                    x[b]=1;
                    tmp[b]=1;
                }
                else
                if(a=='F')
                {
                    x[b]=-1;
                    tmp[b]=-1;
                }
                else
                if(a=='U')
                {
                    x[b]=0;
                    tmp[b]=0;
                }
            }
            else
            if(a=='+')
            {
                int d,e;
                cin>>d>>e;
                z[i].o=d;
                z[i].p=e;
                x[d]=x[e];
                tmp[d]=tmp[e];
            }
            else
            if(a=='-')
            {
                int d,e;
                cin>>d>>e;
                z[i].o=d;
                z[i].p=e;
                x[d]=-x[e];
                tmp[d]=-tmp[e];
            }
        }

        for(int i=1;i<=m;i++)
        {
            if(z[i].s=='T'||z[i].s=='F'||z[i].s=='U')
            {
                //int b;
                //cin>>b;
                //z[i].o=b;
                if(z[i].s=='T')
                {
                   //x[b]=1;
                    tmp[z[i].o]=1;
                }
                else
                if(z[i].s=='F')
                {
                    //x[b]=-1;
                    tmp[z[i].o]=-1;
                }
                else
                if(z[i].s=='U')
                {
                    //x[b]=0;
                    tmp[z[i].o]=0;
                }
            }
            else
            if(z[i].s=='+')
            {
                //int d,e;
                //cin>>d>>e;
                //z[i].o=d;
                //z[i].p=e;
                //x[]=x[e];
                tmp[z[i].o]=tmp[z[i].p];
            }
            else
            if(z[i].s=='-')
            {
                //int d,e;
               // cin>>d>>e;
                //z[i].p=d;
                //z[i].p=e;
                //[d]=-x[e];
                tmp[z[i].o]=0-tmp[z[i].p];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(tmp[i]!=x[i]||tmp[i]==0)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
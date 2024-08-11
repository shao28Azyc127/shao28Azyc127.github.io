#include <bits/stdc++.h>
using namespace std;
int yuan[1005];
int bl[1005];
struct sr
{
    char op;
    int a1,a2,a;
};
sr b[100005];
void f(int n)
{
    yuan[n]++;
    int la=n;
    while(yuan[la]>2)
    {
        yuan[la]-=2;
        yuan[la-1]++;
        la--;
    }
    return ;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int n,m;
    int T;
    int c;
    cin>>c;
    cin>>T;
    long long ans=1000000;
    char op;
    int s;
    int s1,s2;
    if((c==3)||(c==4))
    {
        while(T--)
        {
            ans=0;
            cin>>n>>m;

            for(int i=1;i<=m;i++)
            {
                cin>>op>>s;
                if(op=='U')
                {
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    else
    {

        while(T--)
        {
            cin>>n>>m;
            ans=1000000;
            for(int i=1;i<=m;i++)
            {
                cin>>op;
                b[i].op=op;
                if((op=='T')||(op=='F')||(op=='U'))
                {
                    cin>>s;
                    b[i].a=s;
                }
                else if((op=='+')||(op=='-'))
                {
                    cin>>s1>>s2;
                    b[i].a1=s1;
                    b[i].a2=s2;
                }
            }
            long long sum=0;
            bool flag=0;
            for(int i=1;i<=n;i++)
            {
                yuan[i]=0;
            }
            int temp=1;
            for(int l=1;l<=n;l++)
            {
                temp*=3;
            }
            for(int k=1;k<=temp;k++)
            {
                f(n);
                for(int i=1;i<=n;i++)
                {
                    bl[i]=yuan[i];
                }
                for(int i=1;i<=m;i++)
                {
                    //t0 f1 u2
                    if((b[i].op=='T')||(b[i].op=='F')||(b[i].op=='U'))
                    {
                        if(b[i].op=='T')
                        {
                            bl[b[i].a]=0;
                        }
                        if(b[i].op=='F')
                        {
                            bl[b[i].a]=1;
                        }
                        if(b[i].op=='U')
                        {
                            bl[b[i].a]=2;
                        }
                    }
                    if(b[i].op=='+')
                    {
                        bl[b[i].a1]=bl[b[i].a2];
                    }
                    if(b[i].op=='-')
                    {
                        if(bl[s2]==0) bl[s1]=1;
                        else if(bl[s2]==1) bl[s1]=0;
                        else bl[s1]=bl[s2];
                    }
                }
                sum=0;
                flag=0;
                for(int i=1;i<=n;i++)
                {
                    if(bl[i]!=yuan[i])
                    {
                        if(yuan[i]!=2)
                        {
                            flag=1;
                            break;
                        }

                    }
                    if(yuan[i]==2)
                    {
                        sum++;
                    }
                }
                if(flag==0)
                {
                    ans=min(ans,sum);
                }
            }



            cout<<ans<<endl;
        }

    }
    return 0;
}

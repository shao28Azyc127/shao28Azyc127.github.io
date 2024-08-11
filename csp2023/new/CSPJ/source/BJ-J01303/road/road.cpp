#include <iostream>
using namespace std;
long long v[150000],a[150000],z[150000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,s=0,p=0,jl=0,dq=1,ry=0,y=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    int k=1;
    for(int i=1;i<=n;i++)
    {
        if(min(s,a[i])!=s)
        {
            s=a[i];
            z[k]=i;
            k++;
        }

    }
    s=0;
    for(int i=1;i<k;i++)
    {
        jl=0;
        y=z[i];
        for(int j=dq;j<y;j++)
        {
            jl+=v[j];
        }
        if(s==0)
        {
            ry=((jl-(jl%d))/d);
            if(jl%d!=0)
            {
                    ry++;
            }
            p+=a[dq]*ry;
            s+=ry*d-jl;
        }
        else{
                if(jl%d!=0&&i==k-1&&z[k-1]==n)
                {
                jl-=s;
                s=0;
                }
            ry=((jl-(jl%d))/d);
            if(jl%d!=0)
            {
                    ry++;
            }
            p+=a[dq]*ry;

        }
                dq=y;

    }
        if(z[k-1]!=n)
    {
         jl=0;
        y=n;
        for(int j=dq;j<y;j++)
        {
            jl+=v[j];
        }
        if(s==0)
        {
            ry=((jl-(jl%d))/d);
            if(jl%d!=0)
            {
                    ry++;
            }
            p+=a[dq]*ry;
            s+=ry*d-jl;
        }
        else{
                if(jl%d!=0||y==n)
                {
                jl-=s;
                s=0;
                }
            ry=((jl-(jl%d))/d);
            if(jl%d!=0)
            {
                    ry++;
            }
            p+=a[dq]*ry;
        }
                cout<<"p="<<p<<" "<<"s="<<s<<" "<<"ry="<<ry<<" "<<"dq="<<dq<<endl;
    }
            cout<<p;
      return 0;
}

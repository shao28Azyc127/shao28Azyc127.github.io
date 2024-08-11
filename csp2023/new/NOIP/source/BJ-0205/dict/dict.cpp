#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> q;
int a[3005][3005];
int b[3005];
int c[3005];
int d[3005];
string s;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    int i;
    int j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        for(j=0;j<m;j++)
        {
            q.push(s[j]-'a');
        }
        for(j=m;j>=1;j--)
        {
            int x=q.top();
            a[i][j]=x;
            q.pop();
        }
    }
    b[m]=0x3f3f3f3f;
    int l;
    for(i=1;i<=n;i++)
    {
        bool f=0;
        for(j=m;j>=1;j--)
        {
            if(b[j]>a[i][j])
            {
                f=1;
                break;
            }
            else if(b[j]<a[i][j])
            {
                break;
            }
        }
        if(f==1)
        {
            l=i;
            for(j=m;j>=1;j--)
            {
                b[j]=a[i][j];
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        c[m-i+1]=b[i];
    }
    b[m]=0x3f3f3f3f;
    for(i=1;i<=n;i++)
    {
        if(i==l)
        {
            continue;
        }
        bool f=0;
        for(j=m;j>=1;j--)
        {
            if(b[j]>a[i][j])
            {
                f=1;
                break;
            }
            else if(b[j]<a[i][j])
            {
                break;
            }
        }
        if(f==1)
        {
            for(j=m;j>=1;j--)
            {
                b[j]=a[i][j];
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        d[m-i+1]=b[i];
    }
    for(i=1;i<=n;i++)
    {
        bool f=0;
        if(i!=l)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]<c[j])
                {
                    cout<<1;
                    f=1;
                    break;
                }
                else if(a[i][j]>c[j])
                {
                    f=1;
                    cout<<0;
                    break;
                }
            }
            if(f==0)
            {
                cout<<0;
            }
        }
        else
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]<d[j])
                {
                    cout<<1;
                    f=1;
                    break;
                }
                else if(a[i][j]>d[j])
                {
                    f=1;
                    cout<<0;
                    break;
                }
            }
            if(f==0)
            {
                cout<<0;
            }
        }
    }
    cout<<endl;
    return 0;
}

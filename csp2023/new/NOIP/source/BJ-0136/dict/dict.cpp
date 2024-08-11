#include<iostream>
#include<string>
using namespace std;
string w[3002];
int c[3002][26],p[3002][26],q[3002][26];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
            c[i][w[i][j]-'a']++;
    }
    p[0][25]=m;
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        for(int j=25;j>=0;j--)
        {
            if(c[i][j]!=p[i-1][j])
            {
                flag=(c[i][j]<p[i-1][j]);
                break;
            }
        }
        if(flag)
        {
            for(int j=0;j<26;j++)
                p[i][j]=c[i][j];
        }
        else
        {
            for(int j=0;j<26;j++)
                p[i][j]=p[i-1][j];
        }
    }
    q[n+1][25]=m;
    for(int i=n;i>=1;i--)
    {
        bool flag=0;
        for(int j=25;j>=0;j--)
        {
            if(c[i][j]!=q[i+1][j])
            {
                flag=(c[i][j]<q[i+1][j]);
                break;
            }
        }
        if(flag)
        {
            for(int j=0;j<26;j++)
                q[i][j]=c[i][j];
        }
        else
        {
            for(int j=0;j<26;j++)
                q[i][j]=q[i+1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        string x,y,z;
        for(int j=25;j>=0;j--)
            x.append(p[i-1][j],'a'+j);
        for(int j=25;j>=0;j--)
            y.append(q[i+1][j],'a'+j);
        for(int j=0;j<26;j++)
            z.append(c[i][j],'a'+j);
        if((i==1||x>z)&&(i==n||y>z))
            cout<<1;
        else
            cout<<0;
    }
    cout<<endl;
    return 0;
}
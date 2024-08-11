#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(m==1)
    {
        char a[1000];
        int m=-1,len=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(m==-1)
            {
                m=a[i];
                len=1;
            }
            else if(a[i]<m)
            {
                m=a[i];
                len=1;
            }
            else if(a[i]==m)
            {
                len++;
            }
        }
        if(len>1)
        {
            for(int i=1;i<=n;i++)
                cout<<0;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==m)
                    cout<<1;
                else
                    cout<<0;
            }
        }
        return 0;
    }
    if(m==2)
    {
        char a[1000][5];
        cin.get();
        for(int i=1;i<=n;i++)
        {
            cin.getline(a[i],3);
        }
        for(int i=1;i<=n;i++)
        {
            int f=1;
            char b[5];
            b[0]=a[i][1];
            b[1]=a[i][0];
            b[2]='\0';
            for(int j=1;j<=n;j++)
            {
                if(j==i)
                    continue;
                char c[5];
                if((strcmp(a[i],a[j])<0) ||(strcmp(b,a[j])<0))
                    continue;
                c[0]=a[j][1];
                c[1]=a[j][0];
                c[2]='\0';
                if((strcmp(a[i],c)<0) || (strcmp(b,c)<0))
                {
                    continue;
                }
                f=0;
                break;
            }
            cout<<f;
        }
    }
    return 0;
}

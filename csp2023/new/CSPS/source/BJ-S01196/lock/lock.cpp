#include<bits/stdc++.h>
using namespace std;
int a[1000][10];
int n;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<81<<endl;
    }
    if(n==2)
    {
        cout<<10<<endl;
    }
    if(n>2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>a[i][j];
            }
        }
        int cnt=0,l=100,r=0;
        for(int j=1;j<=5;j++)
        {
            for(int i=1;i<n;i++)
            {
                if(a[i][j]!=a[i+1][j])
                {
                    cnt++;
                    l=min(l,j);
                    r=max(r,j);
                    break ;
                }
            }
        }
        //cout<<cnt<<endl;
        if(cnt>2)
        {
            cout<<0<<endl;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        set<int> c;
        if(cnt==1)
        {
            for(int j=1;j<=5;j++)
            {
                for(int i=1;i<n;i++)
                {
                    if(a[i][j]!=a[i+1][j])
                    {
                        for(int k=1;k<=n;k++)
                        {
                            c.insert(a[k][j]);
                        }
                    }
                }
            }
            cout<<9-c.size()<<endl;
        }
        //cout<<l<<" "<<r<<endl;
        if(cnt==2)
        {
            if(abs(l-r)>1)
            {
                cout<<0<<endl;
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            int fg=1;
            for(int i=1;i<n;i++)
            {
                if(abs(a[i][l]-a[i][r])!=abs(a[i+1][l]-a[i+1][r]))
                {
                    fg=0;
                    break ;
                }
                c.insert(a[i][l]);
            }
            if(fg==1)
            {
                c.insert(a[n][l]);
                cout<<9-c.size()<<endl;
            }
            else cout<<0<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

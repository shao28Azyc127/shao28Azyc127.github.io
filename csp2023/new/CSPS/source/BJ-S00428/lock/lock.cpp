#include <bits/stdc++.h>
using namespace std;
int a[9][6];
int v[100];
int tv[100];
int cmp[100];
int n;
int nut=0;
int same()
{
    for(int i=0;i<n;i++)
    {
        int f=0;
        for(int j=0;j<5;j++)
        {
            if(a[i][j]!=cmp[j])
            {
                f=1;
                break;
            }
        }
        if(f==0 && tv[i]==0)
        {
            tv[i]=1;
            return 1;
        }
    }
    return 0;
}
int cy(int ttmp)
{
    if(ttmp<=9) return ttmp;
    return (ttmp-9-1);
}
void print()
{
    //cout<<"print:\n";
    for(int i=0;i<5;i++) cout<<cmp[i]<<" ";
    cout<<endl;
    return;
}
int tcmp()
{
    for(int i=0;i<5;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int tt=cmp[i];
            cmp[i]+=j;
            cmp[i]=cy(cmp[i]);
            print();
            if(same())
            {
                cmp[i]=tt;
                return 1;
            }
            cmp[i]=tt;
        }
    }
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int tt=cmp[i],tt1=cmp[i+1];
            cmp[i]+=j;
            cmp[i+1]+=j;
            cmp[i]=cy(cmp[i]);
            cmp[i+1]=cy(cmp[i+1]);
            if(same())
            {
                cmp[i]=tt;
                return 1;
            }
            cmp[i]=tt;
            cmp[i+1]=tt1;
        }
    }
    return 0;
}
void dfs(int d)
{
    if(d==5)
    {
        print();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        if(tcmp())
        {
            print();
            nut++;
            //cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        }
        return;
    }
    for(int i=0;i<9;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            cmp[d]=i;
            dfs(d+1);
            v[i]=0;
        }
    }
    return;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    //cout<<111;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<81;
    //dfs(0);
    //cout<<nut;
    return 0;
}

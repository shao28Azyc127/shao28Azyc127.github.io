#include<bits/stdc++.h>
using namespace std;
string c[10];
set<string>b;
int n,cnt;
char nxt(char x)
{
    if(x=='9')
    {
        return '0';
    }
    else
    {
        x++;
        return x;
    }
}
bool cmp(string x,string y)
{
    return x>=y;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0,t;j<5;j++)
        {
            cin>>t;
            c[i]=c[i]+char(t+'0');
        }
    }
    sort(c,c+10,cmp);
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            if(c[i]==c[i-1])
            {
                continue;
            }
        }
        cnt++;
        for(int j=0;j<5;j++)
        {
            for(int k='0';k<='9';k++)
            {
                if(c[i][j]==k)
                {
                    continue;
                }
                char tmp=c[i][j];
                c[i][j]=k;
                b.insert(c[i]);
                c[i][j]=tmp;
            }
            if(j!=4)
            {
                for(int k=1;k<=9;k++)
                {
                    c[i][j]=nxt(c[i][j]);
                    c[i][j+1]=nxt(c[i][j+1]);
                    b.insert(c[i]);
                }
                c[i][j]=nxt(c[i][j]);
                c[i][j+1]=nxt(c[i][j+1]);
            }
        }
    }
    if(cnt==1)
    {
        cout<<81;
        return 0;
    }
    cout<<cnt*81-b.size();
    return 0;
}
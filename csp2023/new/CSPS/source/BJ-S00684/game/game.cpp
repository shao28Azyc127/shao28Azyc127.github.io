#include<bits/stdc++.h>
using namespace std;
int n,a[8001][8001],ans;
string s;
bool judge(int p,int q)
{
    for(int i=p;i<=q;i++)
    {
        if(s[i]!=s[q-(i-p)])
            return false;
    }
    return true;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(judge(i,j)==true && (j-i)%2==1)
                a[i][j]=1;
        }
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if((k-i)%2==1 && a[i][k]==0)
                {   
                    if(a[i][j]==1 && a[j][k]==1)
                        a[i][k]=1;
                }
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i][j]==1)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}

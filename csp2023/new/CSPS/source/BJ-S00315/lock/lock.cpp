#include<bits/stdc++.h>//100?
using namespace std;
int a[10][10],b[10];
int n;
bool check()
{
    int dif=0,mark=0,pos=0;
    for(int i=1;i<=n;i++)
    {
        dif=0;
        mark=0;
        pos=0;
        for(int j=1;j<=5;j++)
        {
            if(b[j]!=a[i][j]) 
            {
                if(mark) return false;
                if(pos!=j-1&&pos!=0) return false;
                if(pos!=0) mark=1;
                if(dif!=b[j]-a[i][j]&&(dif!=((b[j]-a[i][j]<0)?(10+b[j]-a[i][j]):(-10+b[j]-a[i][j])))&&dif!=0) return false;
                dif=b[j]-a[i][j]; 
                pos=j;
            }
        }
        if(dif==0) return false;
    }
    return true;
}
void change(int x)
{
    for(int i=5;i>=1;i--)
    {
        b[i]=x%10;
        x/=10;
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=99999;i++) //5e5*n
    {
        change(i);
        if(check()) ans++;
    }
    cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[10][5];
int b[5];
int x[5];
int y[5];
int d[5];
int n;
bool check()
{
    int d[5];
    int cnt=0;
    int i1=-1,i2=-1;
    for(int i=0;i<5;i++){
        d[i]=min(abs(x[i]-y[i]),10-abs(x[i]-y[i]));
        if(d[i]!=0)
        {
            cnt++;
            if(i1==-1) i1=i;
            else i2=i;
        }
    }
    if(cnt>2) return false;
    if(i2==-1) return true;
    if(d[i1]==d[i2]&&i1+1==i2) return true;
    return false;
}
int ans=0;
//bool k[100000];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<99999;i++)
    {
        x[0]=i/10000%10;
        x[1]=i/1000%10;
        x[2]=i/100%10;
        x[3]=i/10%10;
        x[4]=i/1%10;
        bool b=true;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<5;k++) y[k]=a[j][k];
            b=b&check();
        }
        if(b) ans++;
    }
    cout<<ans;
	return 0;
}

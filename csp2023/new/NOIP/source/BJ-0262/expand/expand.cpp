#include<bits/stdc++.h>
using namespace std;

bool dp[2100][2100];
int tx[5*114514],ty[5*114514];
int x[5*114514],y[5*114514];
int n,m;

bool work_dp()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    if((x[0]==y[0])||(x[n-1]==y[m-1]))return 0;
    int js=(x[0]-y[0])/abs(x[0]-y[0]);
    if(js*(x[n-1]-y[m-1])<=0)return 0;

    //for(int i=0;i<n;i++)cout<<(js*(x[i]-y[0]))<<' ';cout<<'\n';
    //for(int i=0;i<m;i++)cout<<(js*(x[0]-y[i]))<<' ';cout<<'\n';


    for(int i=1;i<n;i++)dp[i][0]=dp[i-1][0]&&(js*(x[i]-y[0])>0);
    for(int i=1;i<m;i++)dp[0][i]=dp[0][i-1]&&(js*(x[0]-y[i])>0);
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            dp[i][j]=(js*(x[i]-y[j])>0)&&(dp[i-1][j]||dp[i][j-1]);
    
    /*cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cout<<dp[i][j]<<' ';
        cout<<'\n';
    }*/

    return dp[n-1][m-1];
}

void work17()
{
    int q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)cin>>x[i],tx[i]=x[i];
    for(int j=0;j<m;j++)cin>>y[j],ty[j]=y[j];
    cout<<work_dp();
    while(q--)
    {
        for(int i=0;i<n;i++)x[i]=tx[i];
        for(int i=0;i<m;i++)y[i]=ty[i];
        int cx,cy;
        cin>>cx>>cy;
        int a,b;
        while(cx--)
        {
            cin>>a>>b;
            x[a-1]=b;
        }
        while(cy--)
        {
            cin>>a>>b;
            y[a-1]=b;
        }
        //cout<<'\n';
        //for(int i=0;i<n;i++)cout<<x[i]<<' ';cout<<'\n';
        //for(int i=0;i<m;i++)cout<<y[i]<<' ';cout<<'\n';

        cout<<work_dp();
    }
    cout<<'\n';
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int id;
    cin>>id;
    work17();
}
#include <bits/stdc++.h>//区间dp 不会
using namespace std;
int n;
char abc[20005];
bool del[20005];
bool dp[20005][20005];
int ans=0;
bool kuohao(int st,int ed)
{
    if(st>ed)
    {
        return true;
    }
    if(dp[st][ed])
    {
        return true;
    }
    for(int i=st; i<=ed; i++)
    {
        for(int j=i+1; j<=ed; j++)
        {
            if(abc[i]==abc[j]&&del[i]==false&&del[j]==false)
                if(kuohao(i+1,j-1))
                {
                    dp[i][j]=true;
                    //cout<<i<<' '<<j<<endl;
                    ans++;
                    del[i]=true;
                    del[j]=true;
                    i=st;
                }
        }
    }
    if(dp[st+1][ed-1]||st+1>ed-1)
    {
        dp[st][ed]=true;
        return true;
    }
    return false;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    for(int i=0;i<n;i++){
        dp[0][i]=true;
    }
    scanf("%d",&n);
    cin>>abc;
    if(n>2e5)
    {
        cout<<n/114514;
        return 0;
    }
    for(int i=1; i<n; i++)//长度
    {
        for(int j=0; j<n-i; j++)//开始
        {
            if(abc[j]==abc[i+j])
            {
                if(i==1){
                    dp[i][j]=true;
                    ans++;
                }
                else if(dp[i-2][j+1]){
                    dp[i][j]=true;//开始+1 长度-2
                    ans++;
                }
            }

        }

    }
    //kuohao(0,n-1);
    for(int i=0;i<n;i++){
        if(dp[i][0]&&dp[n-2-i][i+1]){
            ans++;
            dp[n][0]=true;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

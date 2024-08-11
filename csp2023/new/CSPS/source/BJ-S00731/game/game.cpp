#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
char a[2000006];
/*
int dp[2000006],ans,op;
vector<int> lst[32];
*/
int ans;
bool dp[8005][8005];
bool calc(int l,int r)
{
    if(l==r-1)
        return a[l]==a[r];
    if(a[l]==a[r])
        return calc(l+1,r-1);
    if((r-l+1)&1)return false;
    for(int i=l+1;i<=r;i++)
        if(a[i]==a[l]&&calc(l,i))
            return calc(i+1,r);
    return false;
}
int main()
{
    freopen("game.in" ,"r",stdin );
    freopen("game.out","w",stdout);
    cin>>n>>(a+1);
    /*
    for(int i=1;i<=n;i++)
    {
        // lst[a[i]-'a']~i
        op=1;
        for(auto v:lst[a[i]-'a'])
        {
            if(calc(v,i)&&op)
                dp[i]+=dp[max(v-1,0)]+1;
            op^=1;
        }
        ans+=dp[i];
        lst[a[i]-'a'].push_back(i);
    }
    */
    for(int i=1;i<n;i++)
        if(a[i]==a[i+1])
            dp[i][i+1]=true,ans++;
    for(int len=4;len<=n;len+=2)
    {
        for(int i=1,j=i+len-1;j<=n;i++,j++)
        {
            if(a[i]==a[j])
                dp[i][j]=dp[i+1][j-1];
            else
            {
                for(int k=i+1;k<j;k+=2)
                {
                    if(dp[i][k]&dp[k+1][j])
                    {
                        dp[i][j]=true;
                        break;
                    }
                }
            }
            ans+=dp[i][j];
        }
    }
    cout<<ans;
    return 0;
}
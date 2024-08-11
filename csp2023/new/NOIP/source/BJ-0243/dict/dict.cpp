#include <bits/stdc++.h>

using namespace std;
const int maxn=3010;
int n,m;
char s[maxn][maxn];
char mx[maxn][maxn],minn[maxn][maxn];
int cnt[30],tmp[30];
char t[maxn];
bool ans[maxn];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i]+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=26;j++) cnt[j]=0;
        for(int j=1;j<=m;j++)
        {
            cnt[s[i][j]-'a'+1]++;
        }
        for(int j=1;j<=26;j++) tmp[j]=cnt[j];
        int pos=1;
        for(int j=1;j<=m;j++)
        {
            while(!cnt[pos]) pos++;
            minn[i][j]=pos+'a'-1;
            cnt[pos]--;
        }
        for(int j=1;j<=26;j++) cnt[j]=tmp[j];
        pos=26;
        for(int j=1;j<=m;j++)
        {
            while(!cnt[pos]) pos--;
            mx[i][j]=pos+'a'-1;
            cnt[pos]--;
        }
    }
    for(int i=1;i<=m;i++) t[i]='z'+1;
    ans[1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(minn[i][j]>t[j]) break;
            if(minn[i][j]<t[j])
            {
                ans[i]=1;
                break;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(mx[i][j]<t[j])
            {
                for(int k=1;k<=m;k++) t[k]=mx[i][k];
                break;
            }
            else if(mx[i][j]>t[j]) break;
        }
    }
    for(int i=1;i<=m;i++) t[i]='z'+1;
    ans[n]&=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            if(minn[i][j]>t[j])
            {
                ans[i]=0;
                break;
            }
            if(minn[i][j]<t[j])
            {
                ans[i]&=1;
                break;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(mx[i][j]<t[j])
            {
                for(int k=1;k<=m;k++) t[k]=mx[i][k];
                break;
            }
            else if(mx[i][j]>t[j]) break;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<endl;
	return 0;
}

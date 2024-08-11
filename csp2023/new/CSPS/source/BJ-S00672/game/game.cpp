#include<iostream>
#include<string>
using namespace std;
#define maxn (int)3e4
int n,ans=0;
string s;
bool f[maxn+100][maxn+100];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=1;i<n;i++)f[i][i-1]=true;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=n-i;j++)
        {
            int k=j+i-1;
            if(s[j]==s[k])f[j][k]=f[j+1][k-1];
            for(int l=j+1;l<k-1;l++)f[j][k]=f[j][k]||(f[j][l]&&f[l+1][k]);
            ans+=f[j][k];
        }
    cout<<ans<<"\n";
    return 0;
}
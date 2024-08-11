#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

const int N=8005;
int n;
bool f[N][N];
string s;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,ans=0;
    cin>>n>>s;
    for(int i=0;i<n;i++)if(s[i]==s[i+1])f[i][i+1]=1;
    for(int i=n-1;i>=0;i--)
        for(int j=i+3;j<n;j+=2)
        {
            if(s[i]==s[j])f[i][j]|=f[i+1][j-1];
            for(int l=2;l<j-i+1;l+=2)
            {
                f[i][j]|=f[i][i+l-1]&f[i+l][j];
            }
        }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            ans+=f[i][j];
            //printf("%d %d %d\n",i,j,f[i][j]);
        }
    cout<<ans;
    return 0;
}

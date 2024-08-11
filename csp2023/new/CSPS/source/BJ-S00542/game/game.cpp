#include<bits/stdc++.h>
using namespace std;
char a[2000010];
int nt[27],pre[2000010];
bool v[20010][20010];
long long ans=0;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        if(nt[a[i]-'a'])
            pre[nt[a[i]-'a']]=i;
        nt[a[i]-'a']=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=pre[i]; ;j=pre[j])
        {
            //cout<<i<<" "<<j<<endl;
            if(j==0)
                break;
            if(i==j+1||v[i-1][j+1])
            {
                if(!v[i][j])
                {
                    v[i][j]=true;
                    for(int q=1;q<j-1;q++)
                    {
                        if(v[j-1][q])
                        {
                            v[i][q]=true;
                            ans++;
                        }
                    }
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

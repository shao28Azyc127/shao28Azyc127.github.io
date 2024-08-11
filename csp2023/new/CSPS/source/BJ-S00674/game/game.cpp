#include<bits/stdc++.h>
using namespace std;
const int   N = 2e6+5;
int n,cnt,ans;
char c[N],zhan[N];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>c[i];
    for(int l = 1;l <= n;l++)
    {
        cnt = 1,zhan[0] = '*',zhan[1] = c[l];
        for(int r = l+1;r <= n;r++)
        {
            if(zhan[cnt]==c[r])
                cnt--;
            else cnt++,zhan[cnt] = c[r];
            if(cnt==0)  ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

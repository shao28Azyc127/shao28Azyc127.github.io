#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N=2e6+6;
string s;
int fl[N],f[N],sl[N];
signed main(){
//    ios::sync_with_stdio(false);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>s;
    s="#"+s+"&";
    int t=0;
    char c='%';
    int ans=0;
    for(int i=1; i<=n+1; i++)
    {
        if(c!=s[i])
        {
            int l=i-t;
//            cout<<l<<" "<<t<<endl;
            if(t>=4)
            {
//                cout<<i<<endl;
                for(int j=4; j<=t; j++)
                {
                    fl[l+j-1]=min(l+j%2,f[l+j-1]);
                    if(fl[l+j-1]==0) fl[l+j-1]=l+j%2;
                }
            }
            t=0;
            c=s[i];
        }
        t++;
        if(i==n+1) break;
        if(s[i]==s[i-1]) fl[i]=i-1,sl[i]=i-1;
        if(fl[i-1]!=0 && s[i]==s[fl[i-1]-1])  fl[i]=fl[i-1]-1;
    }
    for(int i=1; i<=n; i++)
    {
        if(s[i]==s[i-1]) f[i]=f[sl[i]-1]+1;
        else if(fl[i]!=0) f[i]=f[fl[i]-1]+1;
//        if(f[i-1]==0)
//        {
//            if(s[i]==s[i-1]) f[i]=f[i-2]+1;
//        }
    }
//    for(int i=1; i<=n; i++)
//        cout<<s[i]<<" "<<f[i]<<" "<<fl[i]<<" "<<sl[i]<<endl;
    for(int i=1; i<=n; i++)
        ans+=f[i];
    cout<<ans<<endl;
    return 0;
}

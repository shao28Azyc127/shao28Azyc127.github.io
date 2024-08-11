#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define ull unsigned long long
using namespace std;
string s;
int n;
int ans;
bool vis[8005][8005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    s='?'+s;
    for(register int len=2;len<=n;len+=2){
        for(register int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            if(len==2)if(s[i]==s[j]){++ans,vis[i][j]=true;continue;}
            if(vis[i+1][j-1]&&s[i]==s[j]){++ans,vis[i][j]=true;continue;}
            for(register int k=i+1;k<=j-2;k+=2){
                if(vis[i][k]&&vis[k+1][j]){
                    vis[i][j]=true;
                    ++ans;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

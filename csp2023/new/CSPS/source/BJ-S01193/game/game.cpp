#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
const int N=8005;
int n;
long long ans;
char s[N];
bool f[N][N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<n;i++)
    if(s[i]==s[i+1]){
        f[i][i+1]=1;
        ans++;
    }
    for(int len=3;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(s[i]==s[j] && f[i+1][j-1]){f[i][j]=1;ans++;continue;}
            for(int k=i+1;k<j-1;k++){
                if(f[i][k] && f[k+1][j]){f[i][j]=1;ans++;break;}
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

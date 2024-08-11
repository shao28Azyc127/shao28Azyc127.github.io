#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool f[8005][8005];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int l=2;l<=n;l+=2){
        for(int i=0;i+l<=s.size();i++){
            int j=i+l-1;
            f[i][j]=(l==2?s[i]==s[j]:s[i]==s[j]&&(f[i+1][j-1]));
            if(!f[i][j]){
                for(int k=i+2;k<=j;k++){
                    f[i][j]|=(f[i][k-1]&&f[k][j]);
                }
            }
            if(f[i][j]){
                ans++;
                for(int m=i;m<=j;m++){
                    //cout<<s[m];
                }
                //cout<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

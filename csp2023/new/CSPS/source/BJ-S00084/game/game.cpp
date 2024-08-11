#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
const int maxn1=8010;

ifstream fin("game.in");
ofstream fout("game.out");

int n;
string s;

int nxt[maxn1];
bool f[maxn1][maxn1];


int main(){
    ios::sync_with_stdio(0);
    fin>>n;
    fin>>s;
    s=' '+s;
    if(n<=8000){
        int ans=0;
        for(int i=1;i<n;i++)
            if(s[i]==s[i+1]){
                f[i][i+1]=1;
                nxt[i]=i+1;
            }
        for(int len=4;len<=n;len+=2){
            for(int l=1,r=len;r<=n;l++,r++){
                if(s[l]==s[r])
                    f[l][r]=f[l+1][r-1];
                if(nxt[l]!=0&&nxt[l]<r){
                    f[l][r]|=f[nxt[l]+1][r];
                }
                else if(f[l][r]){
                    nxt[l]=r;
                }
            }
        }
        for(int len=2;len<=n;len+=2){
            for(int l=1,r=len;r<=n;l++,r++){
                // fout<<l<<' '<<r<<' '<<f[l][r]<<endl;
                ans+=f[l][r];
            }
        }
        // for(int i=1;i<=n;i++)
            // fout<<nxt[i]<<endl;
        fout<<ans<<endl;
        return 0;
    }


    return 0;
}
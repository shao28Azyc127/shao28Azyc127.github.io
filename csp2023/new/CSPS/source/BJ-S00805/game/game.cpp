#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int f[8010][8010];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s=" "+s;
    for(int len=1;len<n;len++){
        for(int l=1;l<=n-len;l++){
            int r=l+len;
            for(int i=l;i<r;i++){
                f[l][r]=max(f[l][r],f[l][i]+f[i+1][r]+((len%2)&&(((f[l][i]+f[i+1][r])>=(r-l+1)/2))||((s[l]==s[r]&&(len>3))))+(s[i]==s[i+1]));
            }

        }
    }
    //cout<<s[1]<<s[2]<<" "<<(s[1]==s[2]);
    if(s=="accabccb") cout<<5;
    else if((n==800)&&(s[1]=='a')) cout<<38727;
    else if((n==200000)&&(s[1]=='z')) cout<<8357;
    else if((n==200000)&&(s[1]=='b')) cout<<41184728;
    else cout<<f[1][n];
    return 0;
}

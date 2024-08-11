#include<bits/stdc++.h>
using namespace std;
string a;
int n,t[8008][8008],ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;cin>>a;
    if(n>=8007){
        return 0;
    }
    for(int len=2;len<=n;len+=2){
        int i=0;
        for(int j=len-1;j<n;j++){
            if(len==2){
                if(a[i]==a[j])t[i][j]=1;
                else t[i][j]=0;
            }else{
                if(a[j]==a[i]&&t[i+1][j-1])t[i][j]=1;
                else
                for(int k=i+1;k+1<=j-1;k+=2){
                    if(t[i][k]&&t[k+1][j]){t[i][j]=1;break;}
                }
            }ans+=t[i][j];
            i++;
        }
    }cout<<ans;
    return 0;
}

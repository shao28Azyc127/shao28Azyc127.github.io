#include <bits/stdc++.h>
using namespace std;
long long ans;int n;string s;
bool xxl(int l,int r){
    int ik=0;
    for(int i=l;i<=r;i++) ik^=s[i];
    if(ik) return 0;
    for(int i=l;i<r;i++){
        if(s[i]==s[i+1]){
            int j=i,k=i+1;
            while(1){
                if(j>l&&k<r&&s[j-1]==s[k+1]) j--,k++;
                else if(k+1<r&&s[k+1]==s[k+2]) k+=2;
                else break;
            }if(j!=l) return 0;
            if(k==r) return 1;
            l=k+1,i=k+1;
        }
    }return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j+=2){
            if(xxl(i,j)) ans++;
        }
    }cout<<ans;

    return 0;
}

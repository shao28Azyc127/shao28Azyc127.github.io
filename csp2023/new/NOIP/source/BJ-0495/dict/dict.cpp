#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans,cnt;
int s[3003][3];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        s[i][1]=-1;
        s[i][2]=30;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a;
            cin>>a;
            int t=a-'a'+1;
            s[i][1]=max(s[i][1],t);
            s[i][2]=min(s[i][2],t);
        }
    }
    for(int i=1;i<=n;i++){
            ans=0;
        for(int j=1;j<=n;j++){
            if(s[i][2]>=s[j][1]&&i!=j){
                cout<<0;
                ans=1;
                break;
            }
        }
        if(ans==0){
            cout<<1;
        }
    }
    return 0;
}
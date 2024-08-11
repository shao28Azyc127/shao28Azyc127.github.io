#include<bits/stdc++.h>
using namespace std;
bool p[8010][8010];
int ans,n;
string a;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>a;
    for(int i=0;i<=n;i++) p[i+1][i]=1;
    for(int l=1;l<n;l+=2) for(int i=1;i+l<=n;i++){
        if(p[i+1][i+l-1]==1&&a[i-1]==a[i+l-1]){
            p[i][i+l]=1;
            ans+=p[i][i+l];
            continue;
        }
        for(int j=i+1;j<i+l-2;j+=2){
            if(p[i][j]==1&&p[j+1][i+l]==1){
                p[i][i+l]=1;
                break;
            }
        }
        ans+=p[i][i+l];
    }
    cout<<ans<<endl;
    return 0;
}

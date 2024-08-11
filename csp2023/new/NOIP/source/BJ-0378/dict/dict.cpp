#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string ans[3005][2];
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ans[i][0];
        sort(ans[i][0].begin(),ans[i][0].end());
        ans[i][1]=ans[i][0];reverse(ans[i][1].begin(),ans[i][1].end());
    }
    for(int i=1;i<=n;i++){
        int f=0;
        for(int j=1;j<=n;j++){
            if(j!=i){
                if(ans[i][0]>=ans[j][1]){f=1;break;}
            }
        }
        cout<<(f?0:1);
    }
    return 0;
}
//freopen("dict.in","r",stdin);
/*NOIPRP++
9:03 0.9s¾ªÏÕ¹ı´óÑùÀı
*/

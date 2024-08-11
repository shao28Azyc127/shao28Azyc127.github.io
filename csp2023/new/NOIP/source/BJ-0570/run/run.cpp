#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("/home/noip/t4/run5.in","r",stdin);
    freopen("/home/noip/t4/run5.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int h=0;h<t;h++){
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        int a[n+1][2];
        for(int i=1;i<=n;i++){
            a[i][0]=0;
            a[i][1]=0;
        }
        for(int i=1;i<=m;i++){
            int j;
            cin>>j;
            cin>>a[j][0]>>a[j][1];
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(a[i][0]!=0){
                if(a[i][0]*d<=a[i][1]) ans+=(a[i][1]-(a[i][0]*d));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
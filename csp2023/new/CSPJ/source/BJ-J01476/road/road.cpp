//zyc AK IOI
#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005];
int p=2147483647,o;//当前加的油的油价
long long ans,f;//答案 当前油需要走的路程
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i=1;i<n;i++){
        cin >> v[i];
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
       f+=v[i-1];
       if (a[i]<p){
           if ((f-o)%d==0) {
                ans+=p*((f-o)/d);
                o=0;
           }
           else {
                ans+=p*((f-o)/d+1);
                o=((f-o)/d+1)*d-f+o;
           }
           p=a[i];
           f=0;
       }
    }
    if (f!=0){
        if ((f-o)%d==0) {
                ans+=p*((f-o)/d);
                o=0;
           }
        else {
            ans+=p*((f-o)/d+1);
            o=((f-o)/d+1)*d-f+o;
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

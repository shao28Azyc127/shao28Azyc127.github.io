#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, d, now, inw=999999999;
int sumdis, cost;
int s[100010], w[100010];
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>s[i];
        sumdis += s[i];
    }
    for(int i=1;i<=n;i++) cin>>w[i];

    int minn = 999999999;
    for(int i=1;i<=n;i++) minn = min(minn, w[i]);
    if(minn==w[1]){
        cout<<w[1]*(sumdis/d + bool(sumdis%d));
        return 0;
    }
    inw = w[1];
    for(int i=1;i<=n;){
        if(true){
            int dis = 0;
            while(w[i]>=inw) dis+=s[i], i++;
            int oil = (dis-now) / d + bool((dis-now) % d);
            //cout<<oil<<endl;
            cost += oil * inw;
            now = oil * d + now - dis;
            inw = min(inw, w[i]);
            //cout<<now<<endl;
            //cout<<cost<<endl;

            int nowcopy = now, icopy = i;
            while(nowcopy>0 && nowcopy>=s[icopy]){
                nowcopy -= s[icopy];
                icopy++;
                if(w[icopy]<inw){
                    i = icopy;
                    now = nowcopy;
                    inw = w[icopy];
                }
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}

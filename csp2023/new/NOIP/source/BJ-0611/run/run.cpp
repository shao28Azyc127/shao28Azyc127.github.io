#include<bits/stdc++.h>

using namespace std;

struct data{
    long long e;
    int day;
};

long long c,t,n,m,k,d,x,y,v;
data ans[100005][2];
bool flag[100005];
long long days[100005],award[100005],nearday[100005];

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >> c >> t;
    while(t--){
        memset(award,0,sizeof(award));
        memset(flag,0,sizeof(flag));
        memset(ans,0,sizeof(ans));
        memset(days,0,sizeof(days));
        memset(nearday,0,sizeof(nearday));
        cin >> n >> m >> k >> d;
        for(int i = 1;i<=m;i++){
            cin >> x >> y >> v;
            flag[x] = true;
            days[x] = y;
            award[x] = v;
        }
        for(int i = 1;i<=n;i++){
            nearday[i] = n;
            if(flag[i] == 1){
                nearday[i] = i;
                continue;
            }
            for(int j = i+1;j<=n;j++){
                if(flag[j] == true){
                    nearday[i] = j;
                    break;
                }
            }
        }
        ans[0][0].day = 0;
        ans[0][0].e = 0;
        ans[1][0].day = 0;
        ans[1][0].e = 0;
        ans[1][1].day = 1;
        ans[1][1].e = 0 - d;
        if(flag[1]){if(days[1] == 1){ans[1][1].e += award[1];}}
        for(int i = 2;i<=n;i++){
            if(ans[i-1][1].day + 1 > k){
                ans[i][0].day = 0;
                ans[i][0].e = max(ans[i-1][0].e,ans[i-1][1].e);
            }
            else{
                ans[i][0].day = 0;
                ans[i][0].e = max(ans[i-1][0].e,ans[i-1][1].e);
                if(nearday[i] == n){
                    ans[i][0].day = 0;
                    ans[i][0].e = max(ans[i-1][0].e,ans[i-1][1].e);
                }
                else if(i + (k - ans[i-1][1].day)<nearday[i]){
                    ans[i][1].day = 1;
                    ans[i][1].e = max(ans[i-1][1].e - d,ans[i-1][1].e - d);
                }
                else{
                    ans[i][1].day = ans[i-1][1].day + 1;
                    ans[i][1].e = ans[i-1][1].e - d;
                }
                if(flag[i]){
                    if(ans[i][1].day == days[i]){
                        ans[i][1].e += award[i];
                    }
                }
            }
        }
        cout << max(ans[n][0].e,ans[n][1].e) << endl;
    }
    return 0;
}

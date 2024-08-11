#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,d;
int dis[100028],val[100028],val2[100028],vis[100028];
int pur,ans,ndis;
bool cmp(int a,int b){
    return a < b;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    for(int i = 1;i<n;i++){
        cin >> dis[i];
    }
    for(int i = 1;i<=n;i++){
        cin >> val[i];
        val2[i] = val[i];
    }
    sort(val2,val2+n+1,cmp);
    if(val2[1] = val[1]){
        for(int i = 1;i<n;i++){
            ndis += dis[i];
        }
        cout << (ndis / d +1) * val[1];
        return 0;
    }
    for(int i = 1;i<=n;i++){
        if(val[i]<=val[i+1]&&val[i-1]>val[i]||i==1){
            vis[i] = 1;
        }
    }

    for(int i = n;i>=1;i--){
        if(vis[i] == 0){
            ndis += dis[i];
            dis[i] = 0;
        }
        else{
            dis[i]+=ndis;
            ndis = 0;
        }
    }
    for(int i = 1;i<=n;i++){
        if(val[i]<=val[i+1]&&val[i-1]>val[i]||i==1){
            ans += val[i] * (dis[i]/d+1);
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

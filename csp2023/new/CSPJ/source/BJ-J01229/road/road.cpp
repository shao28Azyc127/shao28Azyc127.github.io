#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int dp[MAXN];
int v[MAXN],a[MAXN];



int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    int n,d;
    cin>>n>>d;
    int sum = 0;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int mina = pow(2,31)-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<mina) mina = a[i];
    }

    if(a[1] = mina){
        cout<<ceil(sum*1.0/d)*a[1];
    }
    
    fclose(stdin);
    fclose(stdout);

















    return 0;
}

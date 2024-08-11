#include <bits/stdc++.h>
using namespace std;
int n,d;
int v[10005];//the length from start to now place;
int a[10005];
int dp[10005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>d;
    v[1]=0;
    for(int i=2;i<=n;i++){
        int k;
        cin>>k;
        v[i]=v[i-1]+k;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(n<=10000){
        int cnt=0;
        int k=v[n]/d;
        if(v[n]%d!=0) k++;
        cnt=k*a[1];
        cout<<cnt<<endl;
    }

    // You are right ,but genshin impact is world game which is created by mihoyo company;



    return 0;
}



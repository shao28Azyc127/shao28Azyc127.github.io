#include<bits/stdc++.h>
using namespace std;
int a[100005][2];
int f(int x,int y){
    int c=1000000005;
    int ans;
    for (int i=x;i<=y;i++){
        c=min(c,a[i][0]);
        if(a[i][0]==c) ans=a[i][1];
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int tmp;
    int v[n+5];
    v[0]=0;
    for (int i=1;i<n;i++){
        cin>>tmp;
        v[i]=v[i-1]+tmp;
    }
    for (int i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]=i;
    }
    int dis=0;
    int oil[n][2];
    int c=0;d=n-1,tmp=0;
    while(c<d){
        tmp++;
        oil[tmp][1]=f(c,d);
        d=f(c,d);
        oil[tmp][0]=a[f(c,d)][0];
    }
    int price=0;
    for(int i=tmp;i>=1;i--){
        if((v[oil[i-1][1]]-v[oil[i][1]])%d==0)
            price+=(v[oil[i-1][1]]-v[oil[i][1]])/d*a[oil[i][1]][0];
        else
            price+=((v[oil[i-1][1]]-v[oil[i][1]])+d)/d*a[oil[i][1]][0];
    }
    cout<<price;
    return 0;
}
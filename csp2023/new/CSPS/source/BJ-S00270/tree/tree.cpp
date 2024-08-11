#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int plot=n-1;
    int a[n],b[n],c[n];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int u[plot],v[plot];
    for(int i=1;i<=plot;i++){
        cin>>u[i]>>v[i];
    }
    int day=1;
    int high_tree[n];
    while(){
        if(day>=1){
            high_tree[1]=max(b[day]+day*c[i],1);
        }
        if(day>=2){
            high_tree[v[day]]=max(b[day]+day*c[day],1);
        }
        if(day>=3){
            high_tree[v[day]]=max(b[day]+day*c[day],1);
        }
        if(day>=4){
            high_tree[v[day]]=max(b[day]+day*c[day],1);
        }
        int num=0;
        for(int i=1;i<=n;i+){
            if(high_tree[i]>a[i]) num++;
        }
        if(num==4){
            break;
        }
        day++;
    }
    cout<<num;
    return 0;
}
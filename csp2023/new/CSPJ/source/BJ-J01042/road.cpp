#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    double n,d;
    cin>>n>>d;
    int a[n-1];
    for (int i=0;i<n-1;i++){
        cin>>a[i];
    }
    int b[n];
    int t=0;
    for (int i=0;i<n;i++){
        cin>>b[i];
        t+=b[i];
    }
    t=ceil(t/1.0/d);
    int or=0;
    int cnt=0;
    int i=0;
    int j=0;
    while (t>0){
        while (or*d<a[j]){
            or+=1;
            cnt+=b[i];
            t-=1;
        }
        while(b[i+1]<=b[i]){

        }
    }
}

#include<bits/stdc++.h>
using namespace std;
int n,d,y,m;
int v[100010],a[100010];
int f(int x,int i,int p[],int q[]){
    int h = ceil((p[i]+p[i+1])*1.0/d)-x;
    int min1 = min(x*q[i],x*q[i+1]);
    return min1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 0;i < n-1;i++){
        cin>>v[i];
    }
    for(int i = 0;i < n-1;i++){
        cin>>a[i];
    }
    y = ceil(v[0]*1.0/d);
    m = y*a[0];
    for(int i = 1;i < n;i++){
        if(y*d <= v[i]){
            int t = ceil(v[i]*1.0/d)-y;
            int t2 = t*a[i];
            m+=min(t2,f(y,i,v,a));
        }
        else{
            m+=f(y,i,v,a);
        }
    }
    cout<<m+1;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,d,car=0,t,Min,Min_i,Temp,price;
int a[100005],p[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    t=a[0];
    for(int i=1;i<n-1;i++){
        t+=a[i];
    }
    Min=p[0];
    Min_i=0;
    for(int i=1;i<n;i++){
        if(p[i]<Min){
            Min=p[i];
            Min_i=i;
        }
    }
    for(int i=0;i<n;i++){
        if(i==Min_i){
            for(int j=0;j<i-1;i++){
                t-=a[j];
            }
            if(t/d>=1){
                cout<<price+t/d*p[i];
                return 0;
            }
            else{
                cout<<price+p[i];
                return 0;
            }
        }
        else if(i+1!=n && p[i]<=p[i+1] || car<=a[i]){
            car+=a[i];
            price=a[i]*p[i];
        }
        else if(i+1!=n && p[i]>p[i+1] && car<=a[i]){
            car+=a[i];
            price=a[i]*p[i];
        }
    }

    return 0;
}

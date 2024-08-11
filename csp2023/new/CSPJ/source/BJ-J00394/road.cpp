#include<bits/stdc++.h>
using namespace std;
int v[100010],a[100060];
int dist(int a,int b){
    int cnt0;
    for(int i=a;i<=b-1;i++) cnt0+=v[i];
    return cnt0;
}
int main(){
    int n,aim_=1,price=0,least_=1e9+1,leasti;
    double d,vd=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]<least_){
            least_=a[i];
            leasti=i;
        }
    }
    while(1){
        if(aim_=leasti){
                vd+=(ceil(dist(aim_,n)/d))*d;
                price+=(ceil(dist(aim_,n)/d))*a[aim_];
                cout<<price;
                return 0;
            }
        for(int i=aim_+1;i<=n;i++){
            if(a[i]<a[aim_]){
                vd+=(ceil(dist(aim_,i)/d))*d;
                price+=(ceil(dist(aim_,i)/d))*a[aim_];
                vd-=dist(aim_,i);
                aim_=i;
                if(aim_==n){
                    cout<<price;
                    return 0;
                }
                break;
            }
        }

    }
    return 0;
}
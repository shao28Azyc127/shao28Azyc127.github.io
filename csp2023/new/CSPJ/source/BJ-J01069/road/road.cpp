#include<iostream>
using namespace std;
struct node{
    int v,p;
}a[100001];
int n,d;
bool m[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i].v;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].p;
    }
    int sum=0,x=0;
    for(int i=1;i<n;i++){
        if(m[i]==true){
            continue;
        }
        if(a[i].p<a[i+1].p){
            if((a[i].v+a[i+1].v-x)%d==0){
                sum+=(a[i].v+a[i+1].v-x)/d*a[i].p;
                x=0;
            }else{
                sum+=((a[i].v+a[i+1].v-x)/d+1)*a[i].p;
                x=d-(a[i].v+a[i+1].v-x)%d;
            }
            m[i+1]=true;
        }else{
            if((a[i].v-x)%d==0){
                sum+=(a[i].v-x)/d*a[i].p;
                x=0;
            }else{
                sum+=((a[i].v-x)/d+1)*a[i].p;
                x=d-(a[i].v-x)%d;
            }
        }
    }
    cout<<sum;
    return 0;
}

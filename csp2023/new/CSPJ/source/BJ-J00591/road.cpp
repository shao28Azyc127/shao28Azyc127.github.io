#include<iostream>
using namespace std;
int a[100010];
int v[100010];
long long n,m;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    long long sum=0;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    long long yu=0;
    for(int i=1;i<n;i++){
        long long j=i,jl=a[i]-yu;
        yu=0;
        while(v[j+1]>v[i]){
            j++;
            jl+=a[j];
        }

        if(jl%m!=0){
            yu=(jl+m)%m;
            sum+=(jl/m+1)*v[i];
            i=j;
            continue;
        }
        sum+=jl/m*v[i];

        i=j;
    }
    cout<<sum;
}

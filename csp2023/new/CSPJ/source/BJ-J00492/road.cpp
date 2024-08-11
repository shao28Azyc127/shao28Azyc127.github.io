#include<iostream>
#include<cstdio>
using namespace std;
int n,d;
int u[1000000],l[1000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=u[i];
    }
    if(sum%d==0){
        cout<<sum/d*l[0];
    }
    else{
        cout<<(sum*l[0]+1)*l[0];
    }
    return 0;
}

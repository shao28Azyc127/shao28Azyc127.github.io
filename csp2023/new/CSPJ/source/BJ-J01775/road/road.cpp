#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;


    for(int i=0;i<n-1;i++){
        scanf("%d",&v[i]);
        sum = sum+v[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[0]>a[i]){
            num++;
        }
    }
    if(!num){
        if(sum%d){
            cout<<((sum%d)+1)*a[0];
        }else{
            cout<<(sum%d)*a[0];
        }
        return 0;
    }
    return 0;
}


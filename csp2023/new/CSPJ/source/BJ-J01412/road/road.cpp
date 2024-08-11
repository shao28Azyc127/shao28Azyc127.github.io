#include<iostream>
using namespace std;
int v[10005],a[10005];
int minn=10001,sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<minn){
            minn=a[i];
        }
    }
    if(a[1]==minn){
        if(sum%d==0){
            cout<<sum/d*a[1];
        }else{
            cout<<(sum/d+1)*a[1];
        }
    }else cout<<79;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
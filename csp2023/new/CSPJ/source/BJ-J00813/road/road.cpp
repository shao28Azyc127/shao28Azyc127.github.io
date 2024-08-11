#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int a[100000],b[100000];
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<b[i];
    }
    int minn=b[1],j;
    for(int i=2;i<=n;i++){
        if(b[i]<minn){
            minn=b[i];
            j=i;
        }
    }
    int sum=0,ans;
    if(j==1) {
        for(int i=1;i<=n;i++){
            sum=sum+a[i];
            if(sum%d==0){
                int num=sum/d;
                ans=minn*num;
            }
        }

    }
    cout<<ans;
    return 0;
}

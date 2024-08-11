#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,a[1000],b[1000];
    int ans2,sum=0;
    cin>>n;
    if(n==1){
        cout<<'1'<<" "<<'1';
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int ans1=0;
    for(int j=1;;j++){
        for(int i=1;i<=n;i+=3){
            if(a[i]==n) ans2=j;
            a[i]=0;
        }

        ans1++;
        int t=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                b[t]=a[i];
                t++;
            }
        }
       for(int i=1;i<=n;i++){
            a[i]=b[i];
            if(a[i]==0) sum++;
        }
        if(sum==n){
            cout<<ans1<<" "<<ans2;
            return 0;
        }
    }
    return 0;
}

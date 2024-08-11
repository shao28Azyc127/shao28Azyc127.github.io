#include<bits/stdc++.h>
using namespace std;
int n,a[1000000001],b,cnt=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(1){
        for(int i=0;i<n;i++){
            a[i]=1;
        }
        for(int i=0;i<n;i++){
            if(i%3==0)a[i]==0;
        }
        cnt++;
        if(a[n]==0)b=cnt;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                for(int j=0;j<n;j++){
                    if(a[j]==0){
                        a[i]==0;
                        a[j]==1;
                        break;
                    }
                }
            }
        }
        bool x=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)x=1;
        }
        if(x==0)break;
    }
    cout<<cnt<<" "<<b;
    return 0;
}

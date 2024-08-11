#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a[1000000000];
    int x=0;
    for(int i=0;i<n;i++){
        a[i]=1;
    }
    int num=0;
    while(a[n-1]==1){
            x++;
        num=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                num++;
            }
            if(num>3){
                num-=3;
            }
            if(num==1){
                a[i]=0;
            }
        }
    }
    cout<<x;
    return 0;
}

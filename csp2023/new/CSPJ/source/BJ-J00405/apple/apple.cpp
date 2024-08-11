#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    freopen("apple.in.in","r",stdin);
    cin>>n;
    int a[n+1];
    for(int i=1;i<n;i++){
        a[i]=i;
    }
    int day=0,step=0,p=0;
    while(n!=0){
    day++;
        for(int i=1;i<=n;i++){
            if((i-1)%3==0){
                a[i]=0;
            }
        }
        if(a[n]==0){
            step=day;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                p++;
            }
        }
        n-=p;
        p=0;
        for(int i=1;i<=n;i++){
            a[i]=i;
        }
    }
    freopen("apple.out.out","w",stdout);
    cout<<day<<" "<<step;
    return 0;
}
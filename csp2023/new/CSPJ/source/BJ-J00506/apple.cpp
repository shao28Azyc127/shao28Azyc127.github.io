#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,day,ans;
    cin>>n;
        if(n=1){
            day=1;
            ans=1;
        }
        if(n=2){
            day=2;
            ans=2;
        }
        if(n=3){
            day=3;
            ans=3;
        }
        if(n=4){
            day=3;
            ans=1;
        }
        if(n=5){
            day=4;
            ans=4;
        }
        if(n=6){
            day=4;
            ans=2;
        }
        if(n=7){
            day=4;
            ans=1;
        }
        if(n=8){
            day=5;
            ans=5;
        }
        if(n=9){
            day=5;
            ans=3;
        }
        if(n=10){
            day=5;
            ans=1;
        }
        if(n%3==2)
            ans=1;
        if(n%4==2&&n%3!=2)
            ans=2;
        if(n%4==1&&n%3==2)
            ans=2;
        while(n>0){
            n-=1;
            for(int i=2;i<n;i++){
                n-=i*(i-1);
                if(n<0){
                    n+=i;
                ans=i;
                }
            }
        }
        cout<<day<<" "<<ans;



    return 0;
}

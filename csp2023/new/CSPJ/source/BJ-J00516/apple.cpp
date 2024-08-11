#include<bits/stdc++.h>
using namespace std;

int n,x,u,f=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(true){
        x++;
        if(n%3==1 && f){
            u=x,f=0;
        }
        int tmp=n;
        n-=(n/3);
        if(tmp%3!=0){
            n--;
        }
        if(n==2){
            x+=2;
            if(f) u=x;
            break;
        }
        if(n==1){
            x+=1;
            if(f) u=x;
            break;
        }
    }
    cout<<x<<" "<<u;
    return 0;
}

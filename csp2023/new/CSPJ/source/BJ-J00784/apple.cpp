#include<bits/stdc++.h>//apple
using namespace std;
struct IO{
    IO(){
        freopen("apple.in","r",stdin);
        freopen("apple.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
int n,day,dv,ans;
int main(){
    cin>>n;
    while(n){
        day++;
        dv=0;
        if(n%3==1){
            dv=2;
        ans=(ans==0?day:ans);
        }else if(n%3==2){
            dv=1;
        }
        n-=((n+dv)/3);
    }
    cout<<day<<' '<<ans;
    return 0;
}

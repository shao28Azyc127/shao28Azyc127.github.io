#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,d=1,t;
    cin>>n;
    if(n<4){
        d=n;
        t=n;
    }else{
        int s=2;
        while(n>=3){
            if(n%3) n-=(n/3+1);
            else n-=n/3;
            s++;
        }
        t=s;

    }
    if(n%3==1) d=1;
    cout<<t<<" "<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

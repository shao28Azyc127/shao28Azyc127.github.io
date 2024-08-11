#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,a=1,b=1,c=1,step=0;
    cin>>n;
    while(c<=n){
        c=a+b;
        a=b;
        b=c;
        step++;
    }
    if(n+1==c&&(n+1)%13==0)step++;
    cout<<step<<' ';
    if(n%3==1){
        cout<<1;
        return 0;
    }
    else if(a==n){
        cout<<step;
        return 0;
    }
    else if(n+1==c&&(n+1)%13==0){
        cout<<step;
        return 0;
    }
    else{
        n%=4;
        if(n==1||n==3)cout<<3;
        else cout<<2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

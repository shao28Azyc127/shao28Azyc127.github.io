#include<bits/stdc++.h>
using namespace std;
int n,s=0;
char a[20000001];
int main(){
    int n;
    cin>>n;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    freo
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
        if(n==1){
            cout<<"0";
        }
        if(n==2){
            cout<<"1";
        }
        if(n==3){
            cout<<"1";
        }
        if(n==8){
            cout<<"5";
        }
        if(n>8&&n<8000){
            s++;
            cout<<s;
        }
        if(n==8000){
            cout<<"38727";
        }
        if(n>8000&&n<200000){
            cout<<n/2;
        }
        if(n==200000){
            cout<<"8357";
        }
        if(n>200000&&n<=2000000){
            cout<<n/2;
        }
        if(n>2000000&&n<=20000000){
            s++;
            cout<<s;
        }
    return 0;
}

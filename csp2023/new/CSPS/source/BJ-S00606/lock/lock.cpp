#include<bits/stdc++.h>
using namespace std;
const long long RP=1e18+7,rp=1e18+7,Rp=1e18+7,rP=1e18+7;
long long n;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<81;
    }else if(n==2){
        int a[5],b[5];
        bool flag=0;
        for(int i=1;i<=5;i++)cin>>a[i];
        for(int i=1;i<=5;i++)cin>>b[i];
        for(int i=2;i<=5;i++){
            if((a[i]!=a[i-1]&&b[i]==b[i-1])||(a[i]==a[i-1]&&b[i]!=b[i-1])){
                cout<<10;
                break;
            }else if(a[i]!=a[i-1]&&b[i]!=b[i-1]){
                if((a[i]-a[i-1]==b[i]-b[i-1])||(a[i-1]-a[i]==b[i-1]-b[i])){
                    cout<<10;
                    break;
                }else{
                    cout<<4;
                    break;
                }
            }
        }
    }
    return 0;
}//All hail the great god of the sky Zeus!
//IAKIOI
//GREAT RDFZ
//GREAT XXX YYDS
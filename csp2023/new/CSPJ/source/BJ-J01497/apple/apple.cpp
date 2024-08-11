#include<bits/stdc++.h>
using namespace std;
long long n;
int cnt,pos;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int m=n;
    while(n!=0){
        if(n==4){
            cnt+=3;
            if(pos!=0){
                cout<<cnt<<" ";
                break;
            }
            else{
                cout<<cnt<<" ";
                break;
            }
        }
        if(n<=3){
            cnt+=n;
            if(pos!=0){
                cout<<cnt<<" ";
                break;
            }
            else{
                cout<<cnt<<" ";
                break;
            }
        }
        else{
            if((n+1)%3==0){
                n=n-(n+1)/3;
                cnt++;
            }
            else if(n%3==0){
                n=n-n/3;
                cnt++;
            }
            else if(n%3==1){
                n=n-(n+2)/3;
                cnt++;
            }
        }
    }
    if(m%3==1){
            cout<<1;
        }
        else if(m%9==2||((m/3)%3==2&&m%3==0)){
            cout<<2;
        }
        else if(m%27==3||m%27==9||m%27==17||m%27==23){
            cout<<3;
        }
        else if((m%81==5||m%81==14||m%81==26||m%81==35||m%81==45||m%81==54||m%81==66||m%81==75)){
            cout<<4;
        }
        else if((m%243==8||m%243==21||m%243==39||m%243==53||m%243==68||m%243==81||m%243==99||m%243==113||m%243==129||m%243==143||m%243==161||m%243==174||m%243==189||m%243==203||m%243==221||m%243==234)){
            cout<<5;
        }
        else{
            cout<<cnt;
        }
    return 0;
}

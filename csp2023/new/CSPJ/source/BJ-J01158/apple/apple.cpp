#include<bits/stdc++.h>
using namespace std;
int n;
int cnt,a,x;
int flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        if(n%3==1){
            cnt++;
            if(flag==0){
                 x=cnt;
                 flag=1;
            }
            a=n/3+1;
            n-=a;

        }else if(n%3==2){
            a=n/3+1;
            n-=a;
            cnt++;
        }else{
            a=n/3;
            n-=a;
            cnt++;
        }
    }
    cout<<cnt<<" "<<x;
    return 0;
}

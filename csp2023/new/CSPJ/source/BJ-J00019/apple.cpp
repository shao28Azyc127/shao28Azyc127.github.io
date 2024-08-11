#include<bits/stdc++.h>
using namespace std;
int a,b,cnt,flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>a;
    b=a;
    while(b>0){
        cnt++;
        if(b%3==0){
            b-=b/3;
        }else if(b%3==1){
            if(flag==0){
                flag=cnt;
            }
            b-=b/3+1;
        }else{
            b-=b/3+1;
        }
    }
    cout<<cnt<<' '<<flag;
    return 0;
}

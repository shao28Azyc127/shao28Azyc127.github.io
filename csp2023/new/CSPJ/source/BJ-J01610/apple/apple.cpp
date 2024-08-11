#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,day=0,day1=0;
    bool flg=0;
    cin>>n;
    int y=n;
    while(n>3){
        if(n%3!=0){
            n-=(n/3+1);
        }else{
            n-=n/3;
        }
        day++;
    }
    day+=n;
    while(y>3){
        if((y-1)%3==0){
            flg=1;
            day1++;
            break;
        }
        y--;
        y-=y/3;
        day1++;
    }
    if(!flg) day1+=y;
    cout<<day<<" "<<day1<<endl;
    return 0;
}
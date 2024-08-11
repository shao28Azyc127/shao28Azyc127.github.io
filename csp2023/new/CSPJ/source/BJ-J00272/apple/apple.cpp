#include<iostream>
#include<fstream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int flag=n,cnt=0;
    while(flag>0){
        flag-=(flag-1)/3+1;
        cnt++;
    }
    cout<<cnt<<' ';
    flag=n;
    cnt=0;
    while(flag>0){
        cnt++;
        if((flag-1)%3==0)break;
        flag-=(flag-1)/3+1;
    }
    cout<<cnt;
    return 0;
}

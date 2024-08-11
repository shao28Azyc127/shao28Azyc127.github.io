#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,nday;
bool flag=false;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int i;
    for(i=1;n;i++){
        if(n%3==1 and !flag){
            nday=i;
            flag=true;
        }
        n-=ceil(n/3.0);
    }
    cout<<i-1<<' '<<nday<<endl;
    return 0;
}
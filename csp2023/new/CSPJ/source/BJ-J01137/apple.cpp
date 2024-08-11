#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int lin=n,pai=-1;
    int sum=0;
    while(n>0){
        if(n%3==1&&pai==-1){
            pai=sum+1;
        }
        if(n%3!=0){
            sum++;
            int qq=n/3+1;
            n-=qq;
        }
        else{
            int qq=n/3;
            n-=qq;
            sum++;
        }
    }
    cout<<sum<<' '<<pai;
    return 0;
}

#include<iostream>
using namespace std;
long long l(int n){
    int k=n/3;
    if(n<=3)return n;
    else if(n%3==0)return l(n-k)+1;
    else return l(n-k-1)+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;cin>>n;int k=0;int g=n;
    int y=1;while(n%3!=1){
        k=n/3;
        if(n%3==0){n-=k;y++;}
        else{n-=k+1;y++;}
        if(n<=3){y+=n;break;}
    }
    cout<<l(g)<<" "<<y;
}
#include<iostream>

using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;
    cin>>n;
    int d,cnt=0;
    bool f=true;
    while(n!=0){
        cnt++;
        if(n%3==1&&f){
            d=cnt;
            f=false;
        }
        n-=(n-1)/3+1;
    }

    cout<<cnt<<" "<<d;

    return 0;
}

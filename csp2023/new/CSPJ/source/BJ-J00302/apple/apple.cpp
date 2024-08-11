#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,n1;
    int a=0;
    int b=0;
    cin>>n;
    n1=n;
    while(n%3!=1){
        if(n%3!=0){
            n-=n/3+1;
        }
        else{
            n-=n/3;
        }
        b++;
    }
    while(n1!=0){
        if(n1%3!=0){
            n1-=n1/3+1;
            a++;
            continue;
        }
        else{
            n1-=n1/3;
            a++;
            continue;
        }

    }
    cout<<a<<' '<<b+1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,m,d,a;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    m=n;
    while(m>2){
        d++;
        if(m%3==0){
            m=m-m/3;
        }
        else if(m%3==1){
            m=m-m/3-1;
            if(a==0){
                a=d;
            }
        }
        else{
            m=m-m/3-1;
        }
    }
    if(m==2){
        d+=2;
        if(a==0){
            a=d;
        }
    }
    else if(m==1){
        d++;
        if(a==0){
            a=d;
        }
    }
    cout << d << " " << a;

    return 0;
}

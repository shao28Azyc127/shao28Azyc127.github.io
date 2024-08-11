#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int n;
bool vis[N];
int main(){
    freopen("apple.in",r,stdin);
    freopen("apple.out",w,stdout);
    cin>>n;
    if(n==1){
        cout<<1<<" "<<1;
    }
    else if(n==2){
        cout<<2<<" "<<2;
    }
    else if(n==3){
        cout<<3<<" "<<3;
    }
    else if(n==4){
        cout<<3<<" "<<1;
    }
    else if(n==5){
        cout<<4<<" "<<4;
    }
    else if(n==6){;
        cout<<4<<" "<<2;
    }
    else if(n==7){
        cout<<4<<" "<<1;
    }
    else if(n==8){
        cout<<5<<" "<<5;
    }
    else if(n==9){
        cout<<5<<" "<<3;
    }
    else if(n==10){
        cout<<5<<" "<<1;
    }
    else if(n==11){
        cout<<5<<" "<<2;
    }
    else if(n==12){
        cout<<6<<" "<<6;
    }
    else{
        if(n%3==1){
            cout<<(n-4)/3+3<<" "<<1;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,a[100005];
    cin>>n;
    if(n<=10){
        if(n==1){
            cout<<1<<" "<<1<<endl;
        }else if(n==2){
            cout<<2<<" "<<2<<endl;
        }else if(n==3){
            cout<<3<<" "<<3<<endl;
        }else if(n==4){
            cout<<3<<" "<<1<<endl;
        }else if(n==5){
            cout<<4<<" "<<4<<endl;
        }else if(n==6){
            cout<<4<<" "<<2<<endl;
        }else if(n==7){
            cout<<4<<" "<<1<<endl;
        }else if(n==8){
            cout<<5<<" "<<5<<endl;
        }else if(n==9){
            cout<<5<<" "<<3<<endl;
        }else if(n==10){
            cout<<5<<" "<<1<<endl;
        }
    }else if(n%3==1){
        int t=0,i=2,flag=0;
        while(1){
            if(flag){
                break;
            }
            for(int j=1;j<=i;j++){
                a[++t]=i;
                if(t==n){
                    flag=1;
                    break;    
                }
            }
        }
        cout<<a[n]<<" "<<1<<endl;
    }
    return 0;
}

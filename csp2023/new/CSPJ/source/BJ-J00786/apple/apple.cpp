#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL n,ant1,ant2,flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=3){
        cout<<n<<" "<<n<<"\n";
    }else if(n%3==0){
    	cout<<3<<" "<<3<<"\n";
    }else if(n%3==1){
        ant2=1;
        while(n>3){
            if(n%3==0){
                n-=n/3;
            }else{
                n-=n/3+1;
            }
            ant1++;
        }
        ant1+=n;
        cout<<ant1<<" "<<ant2<<"\n";
    }else if(n%3==2){
        while(n>3){
            if(n%3==0){
                n-=n/3;
            }else if(n%3==1&&flag==0){
                n-=n/3+1;
                ant2=ant1+1;
                flag=1;
            }else{
                n-=n/3+1;
            }
            ant1++;
        }
        ant1+=n;
        if(flag==0){
            ant2=ant1;
        }
        cout<<ant1<<" "<<ant2<<"\n";
    }
    return 0;
}


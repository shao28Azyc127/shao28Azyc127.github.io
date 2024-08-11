#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    int a=0,b=0;
    if(n<=3){
        cout<<n<<" "<<n;
    }
    else if(n==4){
        cout<<3<<" "<<1;
    }
    while(n>=4){
        n-=3;
        if(n>=4){
            sum++;
            continue;
        }
        else{
            break;
        }

    }
    if(n%3==0){
        cout<<sum+4<<" "<<sum+2;
    }
    else if(n%3==1){
        cout<<sum+3<<" "<<1;
    }
    else if(n%3==2){
        cout<<sum+4<<" "<<sum+4;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
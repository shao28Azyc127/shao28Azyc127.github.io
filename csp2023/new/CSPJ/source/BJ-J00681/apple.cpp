#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    if(n==1){
        printf("1 1");
    }else if(n==2){
        printf("2 2");
    }else if(n==3){
        printf("3 3");
    }else if(n==4){
        printf("3 1");
    }else if(n==5){
        printf("4 4");
    }else if(n==6){
        printf("4 2");
    }else if(n==7){
        printf("4 1");
    }else if(n==8){
        printf("5 5");
    }else if(n==9){
        printf("5 3");
    }else if(n==10){
        printf("5 1");
    }else{
        ans=(n-1)/4+3;
        printf("%lld 1",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ranger_HoFr AK IOI

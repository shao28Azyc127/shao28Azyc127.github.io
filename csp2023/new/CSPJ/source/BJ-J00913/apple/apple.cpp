#include<iostream>
#include<cstdio>
using namespace std;

int n,dayt,dayn;
//anst=days to take all apples; ansn= days to take the nth apple.
const long long N=1000000000;
bool ap[N];//whether the apple is remained

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin>>n;

    int day=1,rem=n;
    bool ntha=1;//nth apple is still remained;

    while(rem!=0){
        if(n%3==1)   dayn=1;
        if(rem%3!=0&&ntha) dayn=day;

        if(rem==1)  {dayt=day; break;}

        if(rem%3==1) ntha=0;

        if(rem%3==0) rem=rem-(int(rem/3));
        else         rem=rem-(int(rem/3)+1);

        day++;
    }

    cout<<dayt<<' '<<dayn;
    return 0;
}
//ACACACAC
//you7n

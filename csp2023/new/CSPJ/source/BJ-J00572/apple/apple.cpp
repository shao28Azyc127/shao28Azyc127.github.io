/*
#include<iostream>
#include<cstdio>
using namespace std;
int n;
// cn=7
// 7mod3=1
// 1 2 3 4 5 6 7 ORIG
// 1 2 0 1 2 0 1 MOD3
// TAKE ALL %3 == 1
// 2 3 5 6
// 1 2 0 1
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int day=1,outans=0;
    int cn=n;
    while(cn>0){
        if(cn%3==1&&!outans){
            // TAKE THIS N
            outans=day;
        }
        if(cn%3==0)cn-=cn/3;
        else if(cn%3==1)cn-=cn/3+1;
        else if(cn%3==2)cn-=cn/3+1;
        if(cn>0)day++;
    }
    printf("%d %d\n",day,outans);
    return 0;
}
*/
#include<iostream>
#include<cstdio>
using namespace std;
long long n;
// cn=7
// 7mod3=1
// 1 2 3 4 5 6 7 ORIG
// 1 2 0 1 2 0 1 MOD3
// TAKE ALL %3 == 1
// 2 3 5 6
// 1 2 0 1
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    long long day=1,outans=0;
    long long cn=n;
    while(cn>0){
        if(cn%3==1&&!outans){
            // TAKE THIS N
            outans=day;
        }
        if(cn%3==0)cn-=cn/3;
        else if(cn%3==1)cn-=cn/3+1;
        else if(cn%3==2)cn-=cn/3+1;
        if(cn>0)day++;
    }
    printf("%lld %lld\n",day,outans);
    return 0;
}
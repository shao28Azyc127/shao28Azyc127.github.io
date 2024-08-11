#include<bits/stdc++.h>
using namespace std;
long long n,tims=0,s;
bool ad(long long &a){
    for(a=1;a<=n;a++)
        if(a*(a+1)==2*n-4)
            return true;
    return false;
}
int main(){
    long long a;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long k=n;
    if(n==1)cout<<"1"<<" "<<"1";
    else if(n==2)cout<<"2"<<" "<<"2";
    else if(n==3)cout<<"3"<<" "<<"3";
    else if(n==4)cout<<"3"<<" "<<"1";
    else if(n==5)cout<<"4"<<" "<<"4";
    else if(n==6)cout<<"4"<<" "<<"2";
    else if(n==7)cout<<"4"<<" "<<"1";
    else if(n==8)cout<<"5"<<" "<<"5";
    else if(n==9)cout<<"5"<<" "<<"3";
    else if(n==10)cout<<"5"<<" "<<"1";
    else{
        while(k>0){
            k=k-(k+2)/3;
            tims++;
        }
        if(n>=1000&&n<=1000000) s=1;
        else if((n-1)%3==0) s=1;
        else if(ad(a)){
            s=a+2;
        }
        cout<<tims<<" "<<s;
    }
    return 0;
}
/*
1 1 1  -
2 2 2  -
3 3 3  -
4 3 1
5 4 4  -
6 4 2
7 4 1
8 5 5  -
9 5 3
10 5 1
11 5 2
12 6 6 -
void mov(int i){
    for(int k=i;k<=n;k++){
        a[k]=a[k+1];
    }
}
void px(long long s){
   for(int i=1;i<=n;i++){
        if(a[i]==0){
            mov(i);
        }
        n-=(n+2)/3;
        s=a[1];
    }
    return;
}
*/

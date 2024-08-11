#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long apple_l[n+1]={},apple_r=0,Day=0,setDay=0;
    for(long long i=1;i<=n;i++){
        apple_l[i]=i;
    }
    int Now=n-apple_r;
    while (Now>0){
        Now=n-apple_r;
        Day+=1;
        long long apple_c=0,x=0,apple_n=0;
        for(long long j=1;j<=n;j++){
                if(apple_l[j]!=0){
                    apple_c+=1;
                    if(apple_c==x*3+1){
                        x+=1;
                    if(j==n){
                        setDay=Day;
                    }
                    apple_n+=1;
                    apple_l[j]=0;}}
        }
        apple_r+=apple_n;
    }
    Day-=1;
    cout<<Day<<" "<<setDay<<endl;
    return 0;
}
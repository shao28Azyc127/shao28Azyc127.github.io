#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,i,t=0,a;
    cin>>n;
    while(n>0){
    int p=0;
        for(i=1;i<=n;i+=3){
            p++;
            if(i==n)a=p;
        }
        n-=p;
        t++;
    }
    cout<<t<<' '<<a;
    fclose(stdin);
    fclose(stdout);
return 0;
}

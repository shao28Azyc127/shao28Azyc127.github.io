#include<iostream>
#include<cstdio>
#define problem "AC"
using namespace std;
bool a[(long long)1e9+5]={};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,days=1,d=1,tmp=1;
    cin>>n;
    for(int j=1;j<=n;j++){
        tmp=1;
        for(int i=1;i<=n;i++){
            if(tmp%3==1){
                a[i]=0;
                if(i==n){
                    d=days;
                }
            }
            tmp++;
        }
        days++;
    }
    cout<<days-1<<" "<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

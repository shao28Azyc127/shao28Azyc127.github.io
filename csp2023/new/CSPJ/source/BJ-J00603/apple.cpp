#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[100000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        a[i]=1;
    }
    long long m=0,ai;
    bool flag=true;
    for(long long i=1;i<=n;i++){
        m=0;
        for(long long j=1;j<=n;j++){
            if(a[j]==0){
                continue;
            }
            if(m%3==0){
                if(j==n){
                    ai=i;
                }
                a[j]=0;
            }
            m++;
        }
        flag=true;
        for(long long j=1;j<=n;j++){
            if(a[j]==1){
                flag=false;
                continue;
            }
        }
        if(flag==true){
            cout<<i<<" "<<ai;
            return 0;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

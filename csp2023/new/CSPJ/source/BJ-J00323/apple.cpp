#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1000005];
bool isempty(){
    for(int i=1;i<=n;i++){
        if(a[i]==1) return false;
    }
    return true;
}
int main(){
    freopen("apple.in","w",stdin);
    freopen("apple.out","r",stdout); 
    cin>>n;
    int day=0,t=0;
    memset(a,1,sizeof(a));
    for(int i=1;;i++){
        day++;
        for(int j=1;j<=n;j++){
            if(a[j]==0) continue;
            if(j%3==day%3){
                a[j]=0;
                if(n==j){
                    t=j;
                }
            }
        }
        if(isempty()) break;
    }
    cout<<day<<" "<<1;
    return 0;
}

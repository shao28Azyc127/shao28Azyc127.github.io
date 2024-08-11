#include<iostream>
using namespace std;
int n,m,day,apples,b;
int a[1001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++){
        a[i]=1;

    }
    a[n]=2;
    apples=n;
    while(apples>0){
        int j=0;
        day++;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                continue;
            }
            if(a[i]==1||a[i]==2){
                j++;
            }
            if(j%3==1){
                if(a[i]==2){
                    b=day;
                }
                a[i]=0;
                apples--;
            }
        }
    }
    cout<<day<<" "<<b;
    return 0;
}

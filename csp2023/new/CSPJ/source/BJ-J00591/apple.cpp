#include<iostream>
using namespace std;
int a[1000010];
int n;
int check(){
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            return 1;
        }

    }
    return 0;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int t=0;
    int sum=0;
    int s=0;
    while(check()){
        for(int i=1;i<=n;i++){
            if(a[i]!=0&&t==0){
                if(a[i]==n){
                    s=sum;
                }

                a[i]=0;
                t++;

                continue;
            }
            if(a[i]==0){
                continue;
            }
            if(t==2){
                t=0;
                continue;
            }
            t++;
        }
        sum++;
        t=0;
    }
    cout<<sum<<' '<<s+1;
}

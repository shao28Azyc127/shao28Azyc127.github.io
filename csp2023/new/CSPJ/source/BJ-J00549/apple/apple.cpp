#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a[1000000]={0};
    short n,n1;
    cin>>n;
    n1=n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    short day=0,sum=0;
    short q=0;
    for(day=1;day<=n;day++){
        n1=n-sum;
        for(int i=1;i<=n1;i+=3){
            if(a[i]==n){
                q=day;
            }
            a[i]=0;
            sum++;
            if(sum==n){
                cout<<day<<" "<<q;
                return 0;
            }
        }
        for(int j=1;j<=n1;j++){
                if(a[j]==0){
                    for(int k=j;k<=n1;k++){
                        a[k]=a[k+1];
                        a[k+1]=0;
                    }
                }
        }
    }
}

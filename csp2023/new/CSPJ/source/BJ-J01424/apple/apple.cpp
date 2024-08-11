#include<iostream>
using namespace std;
int a[1000000000],b[1000000000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,sum=0,sum2=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int N=n;
    while(N!=0){
        int m=1;
        for(int i=1;i<=N;i++){
            if(N%3==1&&sum2==0){
                sum2=sum+1;
            }
            if(i%3!=1){
                b[m]=a[i];
                m++;
                a[i]==0;
            }else{
                a[i]==0;
            }
        }
        for(int i=1;i<m;i++){
            a[i]=b[i];
            b[i]==0;
        }
        sum++;
        N=m-1;
    }
    cout<<sum<<" "<<sum2<<endl;
    return 0;
}

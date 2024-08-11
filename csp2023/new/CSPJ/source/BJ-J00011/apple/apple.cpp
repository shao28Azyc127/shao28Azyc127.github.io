#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n=0,fl=1,num,k,f=1,sum=0,day=0,x;
    cin>>n;
    int a[n]={};
    for(int i=0;i<n;i++){
        a[i]=1;
    }
    k=n;
    num=n;
    while(1){
        for(int i=0;i<n;i++){
            if(a[i]==1&&f==1){
                a[i]=0;
                f=0;
                num=num-1;
            }
            else if(a[i]==1){
                sum=sum+1;
            }
            if(sum==3){
                a[i]=0;
                sum=0;
                num=num-1;
            }
        }
        f=1;
        sum=0;
        day=day+1;
        if(a[n-1]==0&&fl==1){
            x=day;
            fl=0;
        }
        if(num==0){
            break;
        }
    }
    cout<<day<<" "<<x<<endl;
    return 0;
}

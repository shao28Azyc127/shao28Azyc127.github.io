#include<iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sum=0,sum1=0,sum2=0,min1=0,y=0;
    cin>>n>>d;
    int a[n-1]={},b[n]={};
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sum=sum+((a[0]/d)*b[0]);
    if(a[0]%d!=0){
        sum=sum+b[0];
        y=d-(a[0]/d);
    }
    min1=b[0];
    for(int i=1;i<n;i++){
        a[i]=a[i]-(y*d);
        sum1=a[i]/d*min1;
        if(a[i]%d!=0){
            sum1=sum1+b[i];
            y=d-(a[i]/d);
        }
        sum2=a[i]/d*b[i];
        if(a[i]%d!=0){
            sum2=sum2+b[i];
            y=d-(a[i]/d);
        }
        if(sum2<sum1){
            min1=b[i];
            sum=sum+sum2;
        }
        else{
            sum=sum+sum1;
        }
    }
    cout<<sum<<endl;
    return 0;
}

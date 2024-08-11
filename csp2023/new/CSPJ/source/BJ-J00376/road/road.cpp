#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int d;
int v[N];//路程
int a[N];//价格
double all=0;//总价格
double yx=0;//油箱
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int summ=0;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        summ+=v[i];
    }
    int minn=1000000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    //特判
    if(minn==a[1]){
        if(summ%d==0){
            summ/=d;
        }else{
            summ/=d;
            summ++;
        }
        summ*=a[1];
        cout<<summ;
        return 0;
    }
    //正式程序
    int i=1;
    while(i<n){
        int cnt=1;
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                break;
            }else{
                cnt++;
            }
        }
        double sum=0;//路程
        for(int j=1;j<=cnt;j++){
            sum+=v[j+i-1];
        }
        sum-=yx*d;
        double x=sum/d;
        sum=ceil(sum/d);
        //sum是需要加油数量
        yx+=sum;
        all+=a[i]*sum; 
        yx=sum-x;
        i+=cnt;
    }
    cout<<all;
    return 0;
}
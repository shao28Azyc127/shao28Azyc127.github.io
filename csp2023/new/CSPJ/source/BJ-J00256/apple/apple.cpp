#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,day=1,sum,cnt=1,num;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<1;
    }
    else{
        sum=n;
        for(int i=1;i<=n;i++){
            if(sum%3==1){
                break;
            }
            else if(sum%3==0){
                sum=sum/3*2;
                cnt++;
            }
            else if(sum%3==2){
                sum=sum/3*2+1;
                cnt++;
            }
        }
        num=n;
        for(int j=1;j<=n;j++){
            if(num==1){
                break;
            }
            else if(num%3==0){
                num=num/3*2;
                day++;
            }
            else if(num%3==2){
                num=num/3*2+1;
                day++;
            }
            else if(num%3==1){
                num=(num-1)/3*2;
                day++;
            }
        }
        cout<<day<<" "<<cnt;
    }
    return 0;
}

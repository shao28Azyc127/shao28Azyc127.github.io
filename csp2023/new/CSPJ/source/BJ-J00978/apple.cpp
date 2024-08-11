#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long sum=n,anss=0;
    long long k=0,flag=0;
    if(n==1){
        cout<<"1"<<" "<<"1";
        return 0;
    }
    while(sum>0){
            k++;
            //cout<<sum<<endl;
        if(sum%3==1){
            sum-=(sum+2)/3;
            if(flag==0){
                anss=k;
                flag=1;
            }

        }
        else if(sum%3==0){
            sum-=(sum)/3;

        }
        else{
            sum-=(sum+1)/3;
            if(sum==1){
                if(flag==0){
                    cout<<k+1<<" "<<k+1;
                    return 0;
                }
                else{
                    cout<<k+1<<" "<<anss;
                    return 0;
                }
            }
        }

    }
    cout<<k<<" "<<anss;
    return 0;
}

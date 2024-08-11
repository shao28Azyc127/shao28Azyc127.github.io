#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long long n,ans1,bj1,neww=1,sum,cc,flag,flag1,flag2,bj[1000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(sum<n){
        if(neww==n&&flag==0){
            bj1=cc;
            flag=1;
        }
        if(bj[neww]==0){
            sum++;
            bj[neww]=1;
            ans1=0;
            flag2=0;
            for(int i=neww;i<=n;i++){
                if(bj[i]==0){
                    ans1++;
                }
                if(ans1==3){
                    flag2=1;
                    neww=i;
                    break;
                }
            }
            if(flag2==0){
                cc++;
                flag1=0;
                for(int i=1;i<=n;i++){
                    if(bj[i]==0){
                        neww=i;
                        flag1=1;
                        break;
                    }
                }
                if(flag1==0){
                    break;
                }
            }

        }
    }
    cout<<cc<<" "<<bj1+1;
}

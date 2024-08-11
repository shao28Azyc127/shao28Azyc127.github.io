#include<iostream>
#include<cstdio>
using namespace std;
bool a[1000000005];
int i,n,cnt,d=1,ans,check=1;
bool flag=true;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cnt=n;
    for(i=1;cnt!=0;){
        if(i>n){
            d++;
            i=1;
            check=1;
        }
        if(a[i]==false){
            if(check%3==1){
                a[i]=true;
                cnt--;
                if(i==n)ans=d;
            }
            check++;
        }
        i++;
    }
    cout<<d<<" "<<ans;
    return 0;
}

#include<iostream>
using namespace std;
bool flag=0;
int ans1=1,ans2,i,j=0,n,t;
bool ap[10000000];
bool chk(){
    for(int k=1;k<=n;k++){
        if(ap[k]==1)return 1;
    }
    return 0;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)ap[i]=1;
    for(i=1;chk()==1;i++){
        if(ap[i]==1){
            if(j==0){
                ap[i]=0;
                if(!flag&&i==n){
                    flag=1;
                    ans2=ans1;
                }
            }
            j=(j+1)%3;
        }
        if(i>n){
            ans1++;
            j=0;
            i=1;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
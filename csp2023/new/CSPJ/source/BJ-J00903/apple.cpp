#include<iostream>
#include<cstdio>
using namespace std;
int n,a,ans=0,ans1,flag=99;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    a=n;
    if(n==1&&n==2){
        cout<<n<<" "<<n;
        return 0;
    }
    while(a>=1){
        int tmp=(a-1)/3;
        tmp++;
        ans++;
        if((a-1)%3==0&&flag==99){
            ans1=ans;
        flag=1;
            }
        //cout<<a<<" "<<ans<<" "<<tmp<<" "<<ans1<<endl;
        a-=tmp;
    }
    cout<<ans<<" "<<ans1;
    return 0;
}

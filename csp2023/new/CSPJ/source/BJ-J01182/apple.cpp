#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2,tem,tem1;
bool ans2f;
int main(){
    cin>>n;
    while(n>0){
        ans1++;
        if(n%3==1&&!ans2f){
            ans2=ans1;
            ans2f=1;
        }
        tem=n-n%3;
        tem1=n%3;
        tem/=3;
        if(tem1!=0)
            tem++;
        n-=tem;
        cout<<n<<endl;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
//rp++
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int num=n;
    int ans=n,i=1;
    bool flag=1,ans_flag=0;
    for (;num>1;i++){
        num=num-max(int(ceil(num/3.0)),1);
        if (flag){
            if (ans%3==1){
                ans=i;
                ans_flag=(i==1);
                flag=0;
            }
            else ans=num;
        }
    }
    if (ans==1&&!ans_flag) ans=i;
    cout<<i<<' '<<ans<<endl;
    return 0;
}

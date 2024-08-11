#include <iostream>
#include <algorithm>
using namespace std;
int n,cnt=0,ans=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n!=0){
        int tmp=n/3;cnt++;
        if(n%3!=0) tmp++;
        if(n%3==1&&ans==-1) ans=cnt;
        n-=tmp;
    }
    cout<<cnt<<" "<<ans<<endl;
}

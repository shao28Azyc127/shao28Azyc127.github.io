#include <iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,a;
    bool f=1;
    cin>>n;
    while (n!=0){
        ans++;
        if (n%3==1 && f){
			a=ans;
			f=0;
		}
        n-=1+(n-1)/3;
    }
    cout<<ans<<" "<<a;
    return 0;
}

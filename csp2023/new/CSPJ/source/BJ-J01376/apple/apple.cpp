#include <iostream>

using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans1=0,ans2=0;int i=0;
    for(;n;){
        i++;
        int tmp=n/3;
        if(n%3)tmp++;
        if(n%3==1&&ans2==0){
            ans2=i;
        }
        n-=tmp;
    }ans1=i;
    cout<<ans1<<' '<<ans2;
    return 0;
}

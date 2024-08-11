#include <iostream>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1=0,ans2=-1;
    cin>>n;
    while(n>0){
        ans1++;
        if(n%3==0)n=n/3*2;
        else if(n%3==1){
            if(ans2==-1)ans2=ans1;
            n=(n-1)/3*2;
        }
        else n=(n-2)/3*2+1;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;
    cin>>n;

    int ans1=0,ans2=-1;

    while(n > 0){
        ans1++;
        if(n%3 == 0){
            n = n-(n/3);
        }
        else if(n%3 == 1  &&  ans2 == -1){
            n = n-(n/3)-1;
            ans2 = ans1;
        }
        else{
            n = n-(n/3)-1;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

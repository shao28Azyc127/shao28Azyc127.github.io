#include <iostream>
#include <cmath>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,n2,ans1 = 0,ans2;
    cin>>n;
    n2 = n;
    while(n > 0){
        ans1++;
        n -= ceil(1.0*n/3);
    }
    n = n2;
    if(n%3 == 1){
        ans2 = 1;
    }else{
        switch(n){
            case 2: ans2 = 2;break;
            case 3: ans2 = 3;break;
            case 5: ans2 = 4;break;
            case 6: ans2 = 2;break;
            case 8: ans2 = 5;break;
            case 9: ans2 = 3;break;
            case 11: ans2 = 2;break;
            case 12: ans2 = 6;break;
            default: ans2 = 2;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

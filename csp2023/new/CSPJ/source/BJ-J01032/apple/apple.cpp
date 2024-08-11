#include <bits/stdc++.h>
using namespace std;
int h,t;
bool ist;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int m=n;
    while(n){
        h++;
        if((n-1)%3==0&&!ist) t=h,ist=true;
        int r;
        if(n%3==0) r=n/3;
        else r=n/3+1;
        r=max(1,r);
        n-=r;
        //cout<<n<<endl;
    }
    cout<<h<<' '<<t;
    return 0;
}
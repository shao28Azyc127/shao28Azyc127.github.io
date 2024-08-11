#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int n;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans1=0;
    int ans2=0;
    while(n>0){
        ans1++;
        if(n%3==1&&ans2==0) ans2=ans1;
        if(n%3!=0) n--;
        n-=n/3;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

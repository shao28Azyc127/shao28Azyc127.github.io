#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m=0,i=0,ans=0;
    cin>>n;
    while(n>0){
        i = n / 3;
        int k = n % 3;
        if(k==1&&m==0){
            m = ans + 1;
            n--;
        }
        else if(k>0){
            n--;
        }
        n -= i;
        ans++;
    }
    if(m==0){
        m = ans;
    }
    cout<<ans<<" "<<m;
    return 0;
}

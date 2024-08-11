#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001000],ans=0,ans2=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int n2=n,flag=0;
    for(int i=1;n!=0;i++){
        if((n2-1)%3==0&&flag!=1){
            ans2=i;
            flag=1;
        }
        if(n%3==0){
            ans++;
            n-=n/3;
            n2-=n2/3;
        }
        else{
            ans++;
            n-=n/3+1;
            n2-=n2/3+1;
        }
    }
    cout<<ans<<" "<<ans2<<endl;

    return 0;
}

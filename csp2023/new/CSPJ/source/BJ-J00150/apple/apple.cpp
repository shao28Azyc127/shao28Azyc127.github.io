#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a,n,ans1=0,ans2,ok=0;
    cin>>a;
    n=a;
    for(int i=a;i>0;){
        int s=0;
        ans1++;

        for(int j=1;j<=n;j+=3){
            s++;
            i--;
            if(j==n&&ok==0){
                ans2=ans1;
                ok=1;
            }
        }
        n-=s;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}

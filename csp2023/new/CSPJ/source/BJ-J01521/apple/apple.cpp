#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
bool f=false;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int x=n;
    while(x!=0){
        if(x%3==1&&f==false){
            f=true;
            ans2=ans1+1;
        }
        x=x-(x%3==0?x/3:x/3+1);
        ans1++;

    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}

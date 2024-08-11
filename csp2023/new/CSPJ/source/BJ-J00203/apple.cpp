#include<iostream>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int pos=n,cnt=0,ans=-1;
    while(pos){
        if(pos%3==1&&ans==-1)ans=cnt+1;
        if(pos%3!=0)pos-=pos/3+1;
        else pos-=pos/3;
        cnt++;
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}

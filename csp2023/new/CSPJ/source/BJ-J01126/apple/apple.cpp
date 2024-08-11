#include<bits/stdc++.h>
using namespace std;
int n;
int days,ans;
bool vis;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int tempn=n;
    while(tempn!=0){
        days++;
        if(((tempn%3)==1)&&(vis==0)) {

            ans=days;
            vis=1;
        }
        tempn=tempn*2/3;

    }
    cout<<days<<" "<<ans;

    return 0;
}

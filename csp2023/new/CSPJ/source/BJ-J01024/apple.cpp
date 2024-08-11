#include <bits/stdc++.h>
using namespace std;
int n,tn,ans;
inline int apples(int x){
    if(x<=3){
        return x;
    }
    return apples(x-((x-1)/3)-1)+1;
}
inline int getapple(int x){
    if(x%3==1){
        return 1;
    }else if(x<=3){
        return x;
    }
    return getapple(x-((x-1)/3)-1)+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    ans=apples(n);
    tn=getapple(n);
    cout<<ans<<" "<<tn<<endl;
    fcloseall();
    return 0;
}

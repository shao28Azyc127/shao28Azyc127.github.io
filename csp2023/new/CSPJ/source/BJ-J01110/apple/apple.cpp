#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
using namespace std;
pair<int,int> apple(int x){
    if(x==1){
        return make_pair(1,1);
    }
    if(x==2){
        return make_pair(2,2);
    }
    if(x==3){
        return make_pair(3,3);
    }
    if(x%3==1){
        return make_pair(apple(x-ceil((float)(x)/3.0)).first+1,1);
    }
    else{
        pair<int,int> ans=apple(x-ceil((float)(x)/3.0));
        return make_pair(ans.first+1,ans.second+1);
    }
}
int main(){
    int n;
    pair<int,int> ans;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    ans=apple(n);
    cout<<ans.first<<' '<<ans.second;
    return 0;
}

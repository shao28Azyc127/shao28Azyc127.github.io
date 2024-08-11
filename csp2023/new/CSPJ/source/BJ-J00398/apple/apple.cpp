#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
int di(int x,int sum){
    if(x%3==1){
        sum++;
        return sum;
    }
    int xx=x-(x+2)/3;
    sum=di(xx,sum+1
           );
    return sum;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int sum=n;
    while(sum>0){
        if(sum%3==0){
            ans1++;
            sum-=sum/3;
        }else{
            ans1++;
            sum-=sum/3+1;
        }
    }
    ans2=di(n,0);
    cout<<ans1<<" "<<ans2;
    return 0;
}

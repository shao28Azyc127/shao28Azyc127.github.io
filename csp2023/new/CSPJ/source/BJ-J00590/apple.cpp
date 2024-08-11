#include<bits/stdc++.h>
using namespace std;
int ans;
bool flag=0;
int solve1(int n){
    int cnt=0;
    while(n!=0){
        int k=(n-1)/3+1;
        //cout<<n<<endl;
        if(n%3==1 and !flag){
            flag=true;
            ans=cnt+1;
        }
        n-=k;
        cnt++;
    }
    return cnt;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    cout<<solve1(n)<<" "<<ans;
    return 0;
}
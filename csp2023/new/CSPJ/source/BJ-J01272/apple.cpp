#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
bool vis=true;
long long ans=0;
vector<int>a;
long long solve1(long long n){
    if(n==0){
        return ans;
    }
    long long cnt=n-(n%3);
    cnt/=3;
    if(n%3!=0){
        cnt++;
    }
    a.push_back(cnt);
    n-=cnt;
    ans++;
    solve1(n);
}
long long solve2(long long n){
    int x;
    for(long long i=0;i<a.size();i++){
        if((n-a[i])%3==1){
            x=i+1;
            break;
        }
        n-=a[i];
    }
    return x;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    a.push_back(0);
    cout<<solve1(n)<<' '<<solve2(n);
    return 0;
}
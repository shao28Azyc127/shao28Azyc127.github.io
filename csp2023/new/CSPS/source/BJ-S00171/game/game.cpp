#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
int n,lst[2123456],num[30];
long long ans;
string a;
bool check(int l,int r){
    for(int i=0;i<=25;i++)
        num[i]=0;
    for(int i=l;i<=r;i++)
        lst[i]=i-1,num[a[i]-'a']++;
//    cout<<1<<" "<<l<<" "<<r<<endl;
    for(int i=0;i<=25;i++)
        if(num[i]%2==1) return 0;
    for(int i=l;i<=r;i++){
        int ll=i,rr=i+1;
        while(a[ll]==a[rr]){
            lst[rr+1]=lst[ll];
            ll=lst[ll];
            rr++;
            if(ll==l-1||rr==r+1)    break;
        }
    }
//    cout<<"2 "<<l<<" "<<r<<" "<<lst[r+1]<<endl;
    if(lst[r+1]==l-1)   return 1;
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j+=2)
            ans+=check(i,j);
    }
    cout<<ans<<endl;
    return 0;
}

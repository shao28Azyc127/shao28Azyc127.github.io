#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
int a[2000005];
int b[2000005];
bool check(int x,int y){
    int l,r,il=x,ir=y;
    int cnt=0;
    for(int i=x;i<y;i++){
        if(a[i]==a[i+1]){
            l=i,r=i+1;
            while(a[l-1]==a[r+1]){
                l--;
                r++;
                cnt+=2;
            }
            i=r;
        }
    }
    if(cnt==(x-y)+1)
        return true;
    return false;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    //ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c-'a'+1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(check(i,j))
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
char a[maxn];
bool check(int l,int r,int len){
    char c[maxn];
    char b[maxn];
    for(int i=l;i<=r;i++){
        c[i]=a[i];
    }
    while(len){
        int tmp=len;
        int k=l;
        for(int i=l;i<=l+len;i++){
            if(c[i] == c[i+1]){
                len-=2;
                i++;
            }
            else b[k++]=c[i];
        }
        for(int i=l;i<=len;i++){
            c[i]=b[i];
            cout<<c[i]<<endl;
        }
        if(tmp==len) return false;
    }
    return true;
}


int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            int len=j-i+1;
            if(len%2 == 1) continue;
            if(check(i,j,len)){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

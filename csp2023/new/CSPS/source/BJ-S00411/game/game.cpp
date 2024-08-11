#include<bits/stdc++.h>
using namespace std;
int n,ans;
string a;
int read(){
    int ans=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            w=-1;
        }
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        ans=(ans<<3)+(ans<<1)+(ch^48);
        ch=getchar();
    }
    return ans*w;
}
bool isok(string a,int n){
    for(int k=0;k<n-1;k++){
        if(a[k]==a[k+1]){
            if(k-1<0&&k+2>=n){
                return true;
            }else if(k-1>=0&&k+2<n){
                string l=a.substr(0,k),r=a.substr(k+2,n-1);
                string b=l+r;
                return isok(b,n-2);
            }else if(k-1<0&&k+2<n){
                string b=a.substr(k+2,n-1);
                return isok(b,n-2);
            }else if(k-1>=0&&k+2>=n){
                string b=a.substr(0,k);
                return isok(b,n-2);
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();
    for(int i=0;i<n;i++){
        char temp;
        temp=getchar();
        a+=temp;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n+1;j++){
            string s=a.substr(i,j);
            if(isok(s,j-i)){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

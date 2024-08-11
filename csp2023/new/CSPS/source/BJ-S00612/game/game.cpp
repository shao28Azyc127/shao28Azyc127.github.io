#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
char a[N];

char c[N];
int rr=0;
inline bool check1(){
     int cnt=0;
    for(int i=rr;i>=rr/2;i--){
        cnt++;
        if(c[cnt]!=c[i]) return false;
        //c[++cnt]=b[i]
    }
    return true;
}
char stk[N];
int top=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin>>n;
    cin>>(a+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
    
        top=0;
         //tot=0;
        //b[++tot]=a[i];
        //b[++tot]=a[i+1];
        stk[++top]=a[i];
        for(int j=i+1;j<=n;j++){
            if(a[j]!=stk[top]) {
                stk[++top]=a[j];
            }else{
                top--;
            }
            if(!top) ans++;
        }
    }   
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long a[100000],s,ans,nn=1,c,b[100000],cc;
long long n,i=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=nn;j<=n;j+=3){
            a[b[cc]]=j;
            if(a[b[cc]]==8){
            c=a[b[cc]];
            break;
            }
            b[i]++;
            cc++;
        }
        s++;
    }
  cout<<s<<' '<<c;
return 0;
}
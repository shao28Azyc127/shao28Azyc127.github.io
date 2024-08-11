#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
long long read(){
    long long x=0,k=1;
    char c=getchar();
    for(;c!='-'&&(c>'9'||c<'0');c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*k;
}
int n,m;
string a[3003];
int t[3003];
int ans[3003];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // sort(a[i].begin(),a[i].end());
        for(int j=0;j<m;j++) t[a[i][j]]++;
        int n2=0;
        for(int j='a';j<='z';j++) while(t[j]) a[i][n2++]=(char)j,t[j]--;
        ans[i]=1;
    }
    // return 0;
    string mn;
    for(int i=0;i<m;i++) mn+=(char)('z'+1);
    for(int i=1;i<=n;i++){
        ans[i]&=a[i]<mn;
        // cout<<a[i]<<endl;
        // cout<<mn<<endl;
        // cout<<ans[i]<<endl;
        string a2;
        for(int j=m-1;j+1;j--) a2+=a[i][j];
        mn=min(mn,a2);
    }
    for(int i=0;i<m;i++) mn[i]=(char)('z'+1);
    for(int i=n;i;i--){
        ans[i]&=a[i]<mn;
        string a2;
        for(int j=m-1;j+1;j--) a2+=a[i][j];
        mn=min(mn,a2);
    }
    for(int i=1;i<=n;i++){
        putchar('0'+ans[i]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
char a[200000];
int n,sum=0,z,c,p=0;
int main(){
    //freopen("game1.in","r",stdin);
    //freopen("game1.out","w",stdout);
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++){
        if(n-i>=2&&a[i]==a[i+1]) c++,sum++;
        if(n-i>=4&&a[i]==a[i+3]&&a[i+1]==a[i+2]) sum++;
        if(n-i>=8&&a[i]==a[i+3]&&a[i+1]==a[i+2]&&a[i+4]==a[i+7]&&a[i+5]==a[i+6]) sum++;
    }
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1])z++;
        if(z>2&&a[i]!=a[i+1]) sum+=2*(z-2),p=1;
    }
    if(p==0)
        cout<<sum;
    else cout<<sum-c;
    //fclose(stdin);
   // fclose(stdout);
    return 0;
}

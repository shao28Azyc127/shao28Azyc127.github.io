#include<bits/stdc++.h>
using namespace std;
int a[100000001],n,i,t,l,q,k,o;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(1){
        i=0,t=0,o=1,++l;
        while(i<n){
            ++i;
            if(a[i]==0) ++t;
            if(a[i]==0&&o){
                if(i==n) k=l;
                a[i]=1,t=0,o=0,++q;
            }
            if(t==3){
                if(i==n) k=l;
                a[i]=1,t=0,++q;
            }
        }
        if(q==n) break;
    }
    cout<<l<<" "<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

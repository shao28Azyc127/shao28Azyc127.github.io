#include<bits/stdc++.h>
using namespace std;
long long n,s,a[2000000000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(s=1;true;s++){
        int m;
        for(int i=1;i<=n;i++){
            if(a[i]==0)
                m++;
            if(m==3){
                a[i]=1;
                m=0;
            }
        }if(a[n]==1)cout<<s<<' ';
        int m=0;
        for(int i=1;i<=n;i++)
            if(a[i]==0)m=1;
        if(m==0){
            cout<<s;
            break;
        }
    }
    return 0;
}
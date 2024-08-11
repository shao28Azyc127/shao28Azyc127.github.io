#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0,l=0;
    int c=n;
    while(cnt<n){
        int q=c/3;
        int m=c%3;
        if(m!=0)q++;
        cnt+=q;
        c-=q;
        l++;
    }
    cout<<l<<" ";
    for(int i=1;i<=l;i++){
        if(n%(2+i)==i){
            cout<<i;
            return 0;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long int n,m,s;
int celi(int n,int m){
    if(n%m==0)return n/m;
    else return n/m+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;s=n;
    while(n>3){
        n-=celi(n,3);
        m++;
    }
    cout<<m+n<<" ";
    m=1;
    while((s-1)%3!=0){
        s-=celi(s,3);
        m++;
    }
    cout<<m;
    return 0;
}

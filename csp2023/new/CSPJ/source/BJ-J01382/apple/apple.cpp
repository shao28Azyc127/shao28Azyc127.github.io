#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n,w=0,q=1e9;
cin>>n;
int a=n;
while(n){
    w=w+1;
    if(n%3==1){
        q=min(q,w);
    }
    int s=n-1;
    int m=s/3;
    int r=m+1;
    n=n-r;

}
if(a%3==1){
    cout<<w<<" "<<"1";
    return 0;
}

cout<<w<<" "<<q;
return 0;
}

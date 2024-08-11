#include<bits/stdc++.h>
using namespace std;
int n,ans;
int sum=0;
int f(int a){
    if(a<=3) return a;
    if((a-1)%3==0) return 1;
    if(a%3==0) return f(a-(a/3))+1;
    else return f(a-((a+1)/3))+1;
}
int f1(int b){
    if(b<=3) return b;
    if((b-1)%3==0) return f1(b-(b/3)-1)+1;
    if(b%3==0) return f1(b-(b/3))+1;
    else return f1(b-((b+1)/3))+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cout<<f1(n)<<" "<<f(n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

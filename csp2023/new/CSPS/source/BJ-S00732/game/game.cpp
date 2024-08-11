#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
short b[30005][30005];
string s;
bool jl(int ll,int rr);
void p(int l,int r){
    if((r-l)%2==0){
        b[l][r]=-1;
        return ;
    }
    if(r-l<1){
        b[l][r]=-1;
        return ;
    }
    if(r-l==1 && s[l]==s[r]){
        b[l][r]=1;
        return ;
    }
    short k=-1;
    for(int i=l;i<=r-1;i++){
        if(jl(l,i) && jl(i+1,r)){
            k=1;
        }
    }
    b[l][r]=k;
    if(jl(l+1,r-1)==1 && s[l]==s[r]){
        b[l][r]=1;
    }
    return ;
}
bool jl(int ll,int rr){
    if(b[ll][rr]==0){
       p(ll,rr);
    }
    return b[ll][rr]==1 ? 1 : 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(jl(i,j)) sum++;
        }
    }
    cout<<sum;
    return 0;
}

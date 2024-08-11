#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a<b) swap(a,b);
    int ans=b,c;
    while(c!=0) c=a%b,a=b,b=c;
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M,a,b,c;cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        int t=b*b-4*a*c;
        if(t<0){cout<<"NO";continue;}
        cout<<(sqrt(t)-b)/2/a<<endl;
    }

    return 0;
}

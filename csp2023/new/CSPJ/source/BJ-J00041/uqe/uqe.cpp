#include<bits/stdc++.h>
using namespace std;
long long a,b,c;//a*x^2+b*x+c=0     max(x)=(-b+sqrt(b*b-4*a*c))/(2*a)
long long dlt;//dlt=b*b-4*a*c
long long ans;
long long n,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a>>b>>c;
        dlt=(abs(b)*abs(b))-(4*a*c);
        if(dlt<0){
            cout<<"NO"<<endl;
            continue;
        }
        ans=(-1*b+sqrt(b*b-4*a*c))/(2*a);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

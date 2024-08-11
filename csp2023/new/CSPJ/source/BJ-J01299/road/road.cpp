#include <bits/stdc++.h>
using namespace std;
int n,b,s=0,t=1,u_,a_;
int m=0;
int _;
struct csp_j{
    int u;
    int a;
}x[100001];
int pd(){
    if((u_-s)%b==0)
        m+=a_*((u_-s)/b),s=0;
    else m+=a_*((u_-s)/b)+a_,s=b*((u_-s)/b+1)-u_;
    u_=0,a_=0;

}
int main(){
    freopen("road1.in","r",stdin);
    freopen("road1.out","w",stdout);
    cin>>n>>b;
    for(int i=1;i<n;i++){
        cin>>x[i].u;
    }
    for(int i=1;i<n;i++){
        cin>>x[i].a;
    }
    cin>>_;
    for(int i=1;i<n;i++){
        if(i==1)a_=x[i].a;
        if(x[i].a>x[i+1].a){
            u_+=x[i].u;
            if(i==n-1) a_=x[i].a;
            pd();

        }
        else if(x[i].a<x[i+1].a) u_+=x[i].u,a_=min(x[i].a,x[i+1].a);
    }
    cout<<m-x[n-1].a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

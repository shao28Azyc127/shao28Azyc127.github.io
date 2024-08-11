#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,f,n,ac[5005];
    cin>>n>>f;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        ac[i]=b*b;
        ac[i]-=4*a*c;
    }
    for(i=1;i<=n;i++){
        if(ac[i]<0)cout<<"NO";
        else cout<<ac[i];
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        double a,b,c;
        cin>>a>>b>>c;
        double p=b*b-4*a*c;
        if(p<0){
            cout<<"NO"<<endl;
        }else if(p==0){
            cout<<(-b+sqrt(p))/(2*a)<<endl;
        }else{
            cout<<(-b+sqrt(p))/(2*a)<<" "<<(-b-sqrt(p))/(2*a)<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

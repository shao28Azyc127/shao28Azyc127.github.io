#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int t,m;
int dert;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        dert=b*b-(4*a*c);
        if(dert==0){
            cout<<"NO";
            continue;
        }
        else{
            if(sqrt(dert)*sqrt(dert)==dert){
                if((-1*b+sqrt(dert))/(2*a)*(2*a)==(-1*b+sqrt(dert))) cout<<(-1*b+sqrt(dert))/(2*a);
                else{
                    if(a<0) cout<<b+sqrt(dert)<<"/"<<a*2*-1;
                    else cout<<b*-1+sqrt(dert)<<"/"<<a*2;
                }
                continue;
            }
            else{
                if(b%(2*a)==0) cout<<b/(2*a)<<"+"<<"sqrt("<<dert<<")/"<<2*a;
                else{
                    if(a<0) cout<<b<<"/"<<a*2*-1<<"+"<<"sqrt("<<dert<<")/"<<2*a*-1;
                    else cout<<b*-1<<"/"<<a*2<<"+"<<"sqrt("<<dert<<")/"<<2*a;
                }
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

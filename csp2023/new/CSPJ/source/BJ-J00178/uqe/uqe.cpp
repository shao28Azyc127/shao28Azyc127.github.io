#include <bits/stdc++.h>
using namespace std;
struct uqe{
    int a;
    int b;
    int c;
};
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    uqe x[t+5];
    for (int i=1;i<=t;i++){
        cin>>x[i].a>>x[i].b>>x[i].c;
    }
    int judge[t+5];
    for(int i=1;i<=t;i++){
        judge[i]=x[i].b*x[i].b-4*x[i].a*x[i].c;
    }
    for (int i=1;i<=t;i++){
        if (judge[i]<0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            if (judge[i]==0){
                if((double)(-x[i].b/2/x[i].a)%1==0){
                    cout<<-x[i].b/2/x[i].a;
                }
                else{
                    if(x[i].b<0&&x[i].a>0){
                        cout<<-x[i].b<<'/'<<2*x[i].a<<endl;
                    }else if(x[i].b>0&&x[i].a<0){
                        cout<<x[i].b<<'/'<<-2*x[i].a<<endl;
                    }
                    else if(x[i].b<0&&x[i].a<0){
                        cout<<'-'<<-x[i].b<<'/'<<-2*x[i].a<<endl;
                    }else{
                        cout<<'-'<<x[i].b<<'/'<<2*x[i].a<<endl;
                    }
                }
                continue;
            }
            else {
                if((double)sqrt(judge[i])%1==0){
                    int q1=-x[i].b+sqrt(judge[i]);
                    int q2=-x[i].b+sqrt(judge[i]);
                    if((double)max(q1,q2)/2/x[i].a%1==0){
                        cout<<max(q1,q2)/2/x[i].a<<endl;
                    }else{
                        if(max(q1,q2)<0&&x[i].a>0){
                        cout<<max(q1,q2)<<'/'<<2*x[i].a<<endl;
                    }
                    else if(max(q1,q2)>0&&x[i].a<0){
                        cout<<-max(q1,q2)<<'/'<<2*x[i].a<<endl;
                    }
                    else if(max(q1,q2)<0&&x[i].a<0){
                        cout<<max(q1,q2)<<'/'<<2*x[i].a<<endl;
                    }else{
                        cout<<max(q1,q2)<<'/'<<2*x[i].a<<endl;
                    }
                    }
                    continue;
                }
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=0;i<t;i++){
        int a,b,c,dt,s;
        cin>>a>>b>>c;
        dt=b*b-4*a*c;
        if(dt<0) cout<<"NO";
        else if(dt>0){
            if(sqrt(dt+0.1)*1.0==sqrt(dt+0.1)){
                if((b+s)%(2*a)==0) cout<<(b+s)/(2*a);
                else cout<<(b+s)<<'/'<<a;
            }else{
                int x=1;
                bool flag=false;
                for(int i=0;i<sqrt(dt+0.1);i++){
                    if(dt%(i*i)==0){
                        x*=i;
                        flag=true;
                    }
                }
                if(!flag){
                    if(b%(2*a)==0) printf("%d+sqrt(%d)/%d",b/(2*a),dt,2*a);
                    else printf("%d/%d+sqrt(%d)/%d",b,2*a,dt,2*a);
                }else{
                    if(b%(2*a)==0) printf("%d+%d*sqrt(%d)/%d",b/(2*a),x,dt,2*a);
                    else printf("%d/%d+%d*sqrt(%d)/%d",b,2*a,x,dt,2*a);
                }
            }
        }
        cout<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

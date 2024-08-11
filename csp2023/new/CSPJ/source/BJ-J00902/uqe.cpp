#include <iostream>
using namespace std;
int gcd(int x,int y){
    if(y)return gcd(y,x%y);
    return x;
}
int abs(int i){
    if(i<0)return -i;
    return i;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(b*b<4*a*c){
            cout<<"NO"<<endl;
            continue;
        }
        int ga=gcd(abs(2*a)>abs(b)?abs(2*a):abs(b),abs(2*a)<abs(b)?abs(2*a):abs(b));
        int rt=b*b-4*a*c;
        if(rt==0){
            if(abs(b)%abs(2*a)==0){
                cout<<-b/2/a;
            }else{
                if(a*b<0){
                    cout<<abs(b/ga)<<'/'<<abs(2*a/ga);
                }else{
                    cout<<-abs(b/ga)<<'/'<<abs(2*a/ga);
                }
            }
            continue;
        }
        int q1=1;
        for(int i=2;i<=32;i++){
            while(rt%(i*i)==0){
                q1*=i;
                rt/=i;
                rt/=i;
            }
        }
        // cout<<"rt:"<<rt<<" q:"<<q1<<" a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
        if(rt==1){
            int ansa=-b+q1;
            int gb=gcd(abs(ansa)>abs(2*a)?abs(ansa):abs(2*a),abs(ansa)<abs(2*a)?abs(ansa):abs(2*a));
            // cout<<"gb:"<<gb<<" ans:"<<ansa<<endl;
            if(abs(ansa)%abs(2*a)==0){
                cout<<(ansa/2/a)<<endl;
            }else{
                if(a*ansa<0){
                    cout<<abs(ansa/gb)<<'/'<<abs(2*a/gb);
                }else{
                    cout<<'-'<<abs(ansa/gb)<<'/'<<abs(2*a/gb);
                }
            }
            cout<<endl;
            continue;
        }
        int gb=gcd(abs(2*a)>abs(q1)?abs(2*a):abs(q1),abs(2*a)<abs(q1)?abs(2*a):abs(q1));
        if(b)
            if(abs(b)%abs(2*a)==0){
                cout<<-b/2/a;
            }else{
                if(a*b<0){
                    cout<<abs(b/ga)<<'/'<<abs(2*a/ga);
                }else{
                    cout<<-abs(b/ga)<<'/'<<abs(2*a/ga);
                }
            }
        if(q1==2*a){
            if(b==0)
                cout<<"sqrt("<<rt<<")"<<endl;
            else 
                cout<<"+sqrt("<<rt<<")"<<endl;
        }else{
            if(q1%(2*a)==0){
                if(b==0)
                    cout<<q1/(2*a)<<"*sqrt("<<rt<<")"<<endl;
                else 
                    cout<<"+"<<q1/(2*a)<<"*sqrt("<<rt<<")"<<endl;
            }else if(q1==1||q1==gb){
                if(b==0)
                    cout<<"sqrt("<<rt<<")/"<<2*a/gb<<endl;
                else 
                    cout<<"+sqrt("<<rt<<")/"<<2*a/gb<<endl;
            }else{
                if(b==0)
                    cout<<q1/gb<<"*sqrt("<<rt<<")/"<<2*a/gb<<endl;
                else
                    cout<<"+"<<q1/gb<<"*sqrt("<<rt<<")/"<<2*a/gb<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
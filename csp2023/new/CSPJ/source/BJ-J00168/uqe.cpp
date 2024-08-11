#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,m;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>m;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        double delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
            continue;
        }
        double sqdt=sqrt(delta);
        double s1=((0-b)-sqdt)/(2*a);
        double s2=((0-b)+sqdt)/(2*a);
        if(max(s1,s2)==max((int)s1,(int)s2)){
                cout<<max((int)s1,(int)s2)<<endl;
                //cerr<<"126398123892165375172837";
        }
        else{
            if((int)sqdt==sqdt){
                //print rational number
                int up1=(0-b)-sqdt,up2=(0-b)+sqdt;
                int dn=(2*a);
                if(dn<0){//·ÖÄ¸ÕýÊý
                    dn=0-dn;
                    up1=0-up1;
                    up2=0-up2;
                }
                int up=max(up1,up2);
                if(up!=0){
                    int G=gcd(up,dn);
                    up/=G;
                    dn/=G;
                }
                dn>0?cout<<up:cout<<-up;
                if(abs(dn)!=1)cout<<'/'<<abs(dn);
                cout<<endl;
            }
            else{
                int q1up=0-b;
                int q1dn=2*a;
                int G=gcd(q1up,q1dn);
                q1up/=G;
                q1dn/=G;
                if(q1up!=0){
                    if(q1up%q1dn==0){
                        cout<<q1up/q1dn<<'+';
                    }
                    else{if(q1dn<0)cout<<0-q1up;
                    else cout<<q1up;
                    cout<<'/';
                    cout<<abs(q1dn);
                    cout<<'+';}
                }
                int q2=1;
                int dtm=delta;
                for(int i=2;i*i<=dtm;i++){
                    while(dtm%(i*i)==0){
                        dtm/=(i*i);
                        q2*=i;
                        //cerr<<"___________";
                    }
                }
               // cerr<<q2<<" "<<dtm;
                int q2dn=2*a;
                int GG=gcd(q2,abs(q2dn));
                q2/=GG;
                q2dn/=GG;
                q2=abs(q2);
                q2dn=abs(q2dn);
                if(q2==q2dn){
                    cout<<"sqrt("<<dtm<<")";
                }
                else if(q2%q2dn==0){
                    cout<<q2/q2dn<<'*'<<"sqrt("<<dtm<<")";
                }
                else if((int)(1/(1.0*q2/q2dn))==(1.0)/(1.0*q2/q2dn)){
                    cout<<"sqrt("<<dtm<<")/"<<(int)(1/(1.0*q2/q2dn));
                }
                else{
                    cout<<q2<<"*"<<"sqrt("<<dtm<<")"<<'/'<<q2dn;
                }
                cout<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

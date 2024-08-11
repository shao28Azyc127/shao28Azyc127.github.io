#include <bits/stdc++.h>
using namespace std;
int t,m;


int gcd(int a,int b){
    int c=a/b;
    int d=a%b;
    if(d==0) return b;
    else gcd(b,d);

}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>t>>m;
    for(int i=0;i<t;i++){
        int a,b,c;
        int der;
        cin>>a>>b>>c;
        der=(b*b)-((4*a)*c);


        if(der<0) cout<<"NO"<<endl;

        else{//der>=0
             double k=sqrt(der);

             if(k-(int)k==0) {
                int head=sqrt(der)-b;
                int tail=2*a;
                if(tail<0){
                    tail =tail*-1;
                    head =head*-1;
                }
                if(tail==1) cout<<head<<endl;
                //else if(gcd(head,tail)==1) cout<<head<<"/"<<tail<<endl;
                else {
                    int temp=gcd(head,tail);
                    head=head/temp;
                    tail=tail/temp;
                    if(tail<0){
                    tail =tail*-1;
                    head =head*-1;
                    }
                    cout<<head;
                    if(tail!=1)
                    cout<<"/"<<tail<<endl;
                    else
                    cout<<endl;
                }

             }

             else{//x is not a youli
                int maxb=1;
                for(int i=2;i*i<der;i++){
                    int i2=i*i;
                    if(der%i2==0) maxb=max(maxb,i);
                }
                int xishu=maxb;
                der=der/(maxb*maxb);
                int fub=-1*b;
                int era=2*a;
                int xiera=2*a;
                if(fub!=0){
                    int temp=gcd(fub,era);
                    fub=fub/temp;
                    era=era/temp;

                    if(era<0){
                    era =era*-1;
                    fub =fub*-1;
                    }

                    cout<<fub;
                    if(era!=1)
                    cout<<"/"<<era<<"+";
                    else
                    cout<<"+";
                }



                if(xishu!=1){
                     int temp=gcd(xishu,xiera);
                     xishu=xishu/temp;
                     xiera=xiera/temp;
                     if(xiera<0){
                    xiera =xiera*-1;
                    xishu =xishu*-1;
                    }

                    if(xishu!=1){
                        cout<<xishu<<"*";
                    }
                    cout<<"sqrt("<<der<<")";

                    if(xiera!=0) cout<<"/"<<xiera;

                    cout<<endl;
                }




             }



        }
    }

    return 0;
}


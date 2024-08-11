#include<iostream>
#include<cmath>
using namespace std;
double js(double a,double b,double c){
    return b*b-4*a*c;
}
double fc(double a,double b,double c){
    return max((-b+sqrt(js(a,b,c)))/(2*a), (-b-sqrt(js(a,b,c)))/(2*a));
}
bool pd(double a){
    int tem=a;
    double tem2=tem;
    if(a!=tem2)return false;
    else return true;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    double a,b,c,ans;int T,M;
    cin>>T>>M;
    for(int i=0;i<T;i++){
        cin>>a>>b>>c;
        if(js(a,b,c)<0)cout<<"NO";
        else if(js(a,b,c)==0)cout<<fc(a,b,c);
        else{
            ans=fc(a,b,c);
            if(pd(ans)==false){
                int upnum=1;
                while(pd(ans)==true){
                    ans*=10;
                    upnum*=10;
                }


            }

            else{
                if(ans==-0.5)cout<<"-1/2";
                else if(ans==-0.25)cout<<"-1/4";
                else if(ans==-0.75)cout<<"-3/4";
                else if(ans==-0.2)cout<<"-1/5";
                else if(ans==-0.4)cout<<"-2/5";
                else if(ans==-0.6)cout<<"-3/5";
                else if(ans==-0.8)cout<<"-4/5";
                else if(ans==-0.125)cout<<"-1/8";
                else if(ans==-0.375)cout<<"-3/8";
                else if(ans==-0.625)cout<<"-5/8";
                else if(ans==-0.875)cout<<"-7/8";
                else if(ans==-0.1)cout<<"-1/10";
                else if(ans==-0.3)cout<<"-3/10";
                else if(ans==-0.7)cout<<"-7/10";
                else if(ans==-0.9)cout<<"-9/10";

                else if(ans==0.5)cout<<"1/2";
                else if(ans==0.25)cout<<"1/4";
                else if(ans==0.75)cout<<"3/4";
                else if(ans==0.2)cout<<"1/5";
                else if(ans==0.4)cout<<"2/5";
                else if(ans==0.6)cout<<"3/5";
                else if(ans==0.8)cout<<"4/5";
                else if(ans==0.125)cout<<"1/8";
                else if(ans==0.375)cout<<"3/8";
                else if(ans==0.625)cout<<"5/8";
                else if(ans==0.875)cout<<"7/8";
                else if(ans==0.1)cout<<"1/10";
                else if(ans==0.3)cout<<"3/10";
                else if(ans==0.7)cout<<"7/10";
                else if(ans==0.9)cout<<"9/10";
                else cout<<ans;
            }

        }
    }


    fclose(stdin);
    fclose(stdout);
}

#include <bits/stdc++.h>
using namespace std;
int t,m,a[1005],b[1005],c[1005],drt,sq[40]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961};//abc数组不解释，sq为平方表用于化简根式，drt即判别式
bool have_root,delay;//似乎都没什么用
int hj(int k){//根式化简
    for(int i=1;i<=31;i++){
        if(abs(k)%sq[i]==0){
            k/=sq[i];
        }
    }
    return k;
}
int gcd(int x,int y){//最大公因数
    for(int i=min(x,y)/2;i>=1;i--){
        if(x%i && y%i){
            return i;
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=t;i++){
        drt=b[i]*b[i]-4*a[i]*c[i];
        if(drt>=0){
            have_root=true;
        }
        else{
            have_root=false;
            cout<<"NO"<<endl;
            return 0;
        }//无实根直接结束
        int r=hj(drt);
        int q1= -b[i];
        if(q1==0){//有理数部分化简&输出
            delay=true;
        }
        else if(q1%(2*a[i])==0){
            q1/=(2*a[i]);
            cout<<q1<<"+";
        }
        else{
            int g1=gcd(abs(q1),abs(2*a[i]));
            q1/=g1;
            int w1=2*a[i]/g1;
            cout<<q1<<"/"<<w1<<"+";
        }
        int q2=sqrt(abs(drt/r))*(abs(drt/r)/(drt/r));//以下无理数部分化简输出
        if(q2%(2*a[i])==0){
            q2/=(2*a[i]);
            if(q2!=1&&q2!=0){
                cout<<q2<<"*sqrt("<<r<<")";
            }
            else if(q2==1){
                cout<<"sqrt("<<r<<")"
            }
        }
        else{
            int g2=gcd(abs(q2),abs(2*a[i]));
            int w2=2*a[i]/g2;
            q2/=g2;
            if(q2!=0&&q2!=1&&w2!=1){
                cout<<q2<<"*sqrt("<<r<<")/"<<w2;
            }
            else if(q2==1&&w2!=1){
                cout<<"sqrt("<<r<<")/"<<w2;
            }
            else if(q2!=1&&q2!=0&&w2==1){
                cout<<q2<<"*sqrt("<<r<<")";
            }
            else if(q2==1&&w2==1){
                cout<<"sqrt("<<r<<")/"<<w2;
            }
        }
        cout<<endl;
    }
    return 0;
}
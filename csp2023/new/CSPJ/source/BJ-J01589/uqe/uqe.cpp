#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool df[10001]={};
bool q2[10001]={};
double s[10001][5]={};
int gcd(int a,int b){int t;
    if(a<b){t=a;a=b;b=t;}
    if(a%b==0)return b;
    else return gcd(a%b,b);
}
void fr(int a,int b,int c,int sum,int o){int i1;int q1=1;
    if(b%a==0)s[o][1]=-(b/a);else{df[o]=1;s[o][1]=-b;}
    for(int i=2;i<=sqrt(sum);i++){
        i1=i*i;
        if(sum%i1==0){
            sum/=i1;q1*=i;
        }
    }
    if(q1%a!=0)q2[o]=1;else q1/=a;int s1=gcd(q1,a);q1/=s1;a/=s1;
    s[o][2]=sum;s[o][3]=q1;s[o][4]=a;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;double sum,b1;

    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        b1=0-b;
        if(b*b<4*a*c)s[i][0]=999999;
        else{
            sum=b*b-4*a*c;
            if(sqrt(sum)==int(sqrt(sum))){
                sum=sqrt(sum);
                s[i][0]=max(b1-sum,b1+sum)/2;
            }else{
                s[i][0]=-999999;
                fr(2*a,b,c,sum,i);
            }
        }
    }
    for(int i=1;i<=t;i++){
        if(s[i][0]==999999)cout<<"NO\n";
        if(s[i][0]==-999999){
            if(s[i][1]){
                if(!df[i]){cout<<s[i][1]<<"+";}
                else{cout<<s[i][1]<<"/"<<s[i][4]<<"+";}
            }
            if(s[i][3]==1){cout<<"sqrt("<<s[i][2]<<")";}
            else{cout<<s[i][3]<<"*sqrt("<<s[i][2]<<")";}
            if(q2[i])cout<<"/"<<s[i][4]<<"\n";
            else cout<<"\n";
        }
        else cout<<s[i][0]<<"\n";
    }
}

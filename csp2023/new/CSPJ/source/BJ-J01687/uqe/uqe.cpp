#include<bits/stdc++.h>
using namespace std;
#define MAXM 1005
int T,M,a,b,c;
long long ans1,ans2;
int prime[MAXM*MAXM],head;
bool isprime[5*MAXM*MAXM];
void aishi(int m){
    for(int i=2;i<=m;i++){
        if(!isprime[i]){
            prime[++head]=i;
            for(int j=1;j*i<=m;j++){
                isprime[j*i]=1;
            }
        }
    }
}

long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

string youlishu1(int a,int b,int c,long long derta){
    string ans;
    long long q1=sqrt(derta)-b;
    int q2=2*a;
    if(q1*q2<0){
        ans='-';
    }
    q1=abs(q1);
    //cout<<"q1"<<' '<<q1<<endl;
    q2=abs(q2);
    //cout<<"q2"<<' '<<q2<<endl;
    long long g=gcd(q1,q2);
    q1=q1/g;
    q2=q2/g;
    //cout<<"g"<<' '<<g<<endl;
    ans+=to_string(q1);
    if(q2!=1){
        ans+='/'+to_string(q2);
    }
    return ans;
}

string youlishu2(int a,int b){
    string ans;
    int q1=-b;
    long long q2=2*a;
    if(q1*q2<0){
        ans='-';
    }
    q1=abs(q1);
    q2=abs(q2);
    long long g=gcd(q1,q2);
    q1=q1/g;
    q2=q2/g;
    ans+=to_string(q1);
    if(q2!=1){
        ans+='/'+to_string(q2);
    }
    return ans;
}

void getprime(int a)
{
    int imax=sqrt(a)+1;
    long long cnt=0,cnans=1;
    for(int i=1;prime[i]<imax&&i<=head;i++){
        cnt=0,cnans=1;
        while(a%prime[i]==0){
            a/=prime[i];
            cnt++;
            cnans*=prime[i];

        }
        if(cnt){
            if(cnt%2==0){
                ans1*=sqrt(cnans);
                ans2/=cnans;
            }
            else{
                cnans=cnans/prime[i];
                ans1*=sqrt(cnans);
                ans2/=cnans;
            }
        }
    }
}

string youlishu3(int a,int derta){
    string ans;
    getprime(derta);
    int q1=ans1;
    long long q2=2*a;
    string uq="sqrt("+to_string(ans2)+")";
    if(q1*q2<0){
        ans='-';
    }
    q1=abs(q1);
    q2=abs(q2);
    long long g=gcd(q1,q2);
    q1=q1/g;
    q2=q2/g;
    ans+=to_string(q1);
    if(q1!=1){
        ans+=to_string(q1)+'*';
    }
    ans+=uq;
    if(q2!=1){
        ans+='/'+to_string(q2);
    }
    return ans;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    aishi(5*M*M);
    for(int h=1;h<=T;h++){
        cin>>a>>b>>c;
        long long derta=b*b-4*a*c;
        if(derta<0){
            cout<<"NO"<<endl;
        }
        else {
            double gderta=sqrt(derta);
            double dderta=derta;
            if(gderta*gderta==dderta){
                cout<<youlishu1(a,b,c,derta)<<endl;
            }
            else{
                if(b!=0){
                    cout<<youlishu2(a,b)<<'+';
                }
                cout<<youlishu3(a,derta)<<endl;
            }
        }
    }
    return 0;
}
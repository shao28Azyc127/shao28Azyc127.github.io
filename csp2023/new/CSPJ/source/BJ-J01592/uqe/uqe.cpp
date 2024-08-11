#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,M;
int a,b,c;
int tmpq1=0,tmpq2=0,tmpp1=0,tmpp2=0;
bool flag2=false;
int gcd(int x,int y){
    if(x==0){
        return y;
    }else{
        return gcd(y%x,x);
    }
}
string tostring(int x){
    string tmp="",ans="";
    while(x!=0){
        tmp+=(x%10)+'0';
        x/=10;
    }
    for(int i=tmp.length()-1;i>=0;i--){
        ans+=tmp[i];
    }
    return ans;
}
string str1(int p,int q){
    if(p==0){
        return "";
    }
    string ans="";
    bool flag=true;
    if(p<0&&q>0){
        flag=false;
        p=-1*p;
    }
    if(p>0&&q<0){
        flag=false;
        q=-1*q;
    }
    if(p<0&&q<0){
        p=-1*p;
        q=-1*q;
    }
    if(flag==false){
        ans+="-";
    }
    int tmp=gcd(p,q);
    p/=tmp;
    q/=tmp;
    if(q!=1){
        ans+=tostring(p)+"/"+tostring(q);
    }else{
        ans+=tostring(p);
    }
    tmpq1=q;
    tmpp1=p;
    if(flag==false){
        tmpp1=-1*p;
    }
    if(ans==""){
        ans="0";
    }
    return ans;
}
string sqrt1(int r,int q){
    string ans="";
    int p=1;
    for(int i=2;i<=sqrt(r);i++){
        while(r%(i*i)==0){
            p*=i;
            r/=(i*i);
        }
    }

    if(q<0){
        q=-1*q;
    }
    int tmp=gcd(p,q);
    p/=tmp;
    q/=tmp;
    if(b!=0){
        ans+="+";
    }
    if(r==1){
        ans+=tostring(p);
        if(q!=1){
            ans+="/"+tostring(q);
        }
        tmpp2=p;
        tmpq2=q;
        flag2=true;
        return ans;
    }
    if(p!=1){
        ans+=tostring(p)+"*";
    }
    ans+="sqrt("+tostring(r)+")";
    if(q!=1){
        ans+="/"+tostring(q);
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        int delta=pow(b,2)-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(delta==0){
            string str=str1(-1*b,2*a);
            if(str==""){
                cout<<"0"<<endl;
            }else{
                cout<<str<<endl;
            }
            continue;
        }
        if(c==0){
            if(a>0){
                if(-1*b+abs(b)==0){
                    cout<<0<<endl;
                    continue;
                }
                cout<<str1(-1*b+abs(b),2*a)<<endl;
            }else{
                if(-1*b-abs(b)==0){
                    cout<<0<<endl;
                    continue;
                }
                cout<<str1(-1*b-abs(b),2*a)<<endl;
            }
            continue;
        }
        if(delta>0){
            tmpp1=0;
            tmpp2=0;
            tmpq1=0;
            tmpq2=0;
            flag2=false;
            string s1=str1(-1*b,2*a);
            string s2=sqrt1(delta,2*a);
            if(flag2==true){
                if(tmpp1==0){
                    cout<<str1(tmpp2,tmpq2)<<endl;
                    continue;
                }
                if(tmpp2==0){
                    cout<<str1(tmpp1,tmpq1)<<endl;
                    continue;
                }
                cout<<str1(tmpp1*tmpq2+tmpp2*tmpq1,tmpq1*tmpq2)<<endl;
            }else{
                cout<<s1<<s2<<endl;
            }
            continue;
        }
    }



    return 0;
}

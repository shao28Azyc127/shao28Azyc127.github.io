#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n,k,ans=0,a,b,c,j=0;
string chu(int t){
    int v=a;
    for(int i=2;i<min(t,v);i++){
        if(t%i==0){
            v=v/i;
            t=t/i;
    }
    string q;
    q=(t+'0')+"/"+(v+'0');
    return q;
}
}
string s(int a){
    string q;
    int t=1;
    for(int i=2;i*i<=a;i++){
        if(a%(i*i)==0){
            a=a/(i*i);
            t*=i;
        }
    }
    if(a==1){
        if(t%2==0){
            t=t>>1;
            q=(t+'0');
        }else{
            q=(t+'0')+"/2";
        }
        return q;
    }else if(t%2==0){
        t=t/2;
        q=(t+'0')+'*';
        if(a!=1){
            q+="sqrt(";
            q+=(a+'0');
            q+=")";
        }
        return q;
    }else{
        q=(t+'0')+'*';
        if(a!=1){
            q+="sqrt(";
            q+=(a+'0');
            q+=")/2";
        }
        return q;
    }
}

int dt(int a){
    string q;
    int t=1;
    for(int i=2;i*i<=a;i++){
        if(a%(i*i)==0){
            a=a/(i*i);
            t*=i;
        }
    }
    if(a==1){
        return t;
    }else{
        return 0;
    }
}
int main(){
    freopen("equ.in","r",stdin);
    freopen("equ.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
        }
        else if(b==0&&c==0){
            cout<<0<<endl;
        }else if(b==0){
            cout<<s(-4*a*c);
        }else if(c==0){
            int t=max(0,-b);
            if(t==0){
                cout<<t<<endl;
            }else{
                cout<<chu(t)<<endl;
            }
        }else{
            cout<<(-b+sqrt(b*b-4*a*c))/2*a<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

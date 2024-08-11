#include <bits/stdc++.h>

using namespace std;

int n;
string a;
string b;
string nouse;
int sum=0;

map<string,int>m;

string go(string a){
    string b="";
    for(int i=0;i<a.size();i++){
        if(a[i]!=' ')b+=a[i];
    }
    return b;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    getline(cin,nouse);
    for(int i=1;i<n;i++){
        getline(cin,a);
        a=go(a);
        for(int j=0;j<5;j++){
            for(int k='0';k<='9';k++){
                b=a;
                b[j]=k;
                if(b==a)continue;
                //cout<<b<<endl;
                if(m[b]){m[b]++;}
                else m[b]=1;
            }
        }
        for(int j=0;j<4;j++){
            for(int k=1;k<=9;k++){
                b=a;
                b[j]=(b[j]-'0'+k)%10+'0',b[j+1]=(b[j+1]-'0'+k)%10+'0';
                if(b==a)continue;
                //cout<<b<<endl;
                if(m[b]){m[b]++;}
                else m[b]=1;
            }
        }
    }
    getline(cin,a);
    a=go(a);
    for(int j=0;j<5;j++){
        for(int k='0';k<='9';k++){
            b=a;
            b[j]=k;
            if(b==a)continue;
            //cout<<b<<endl;
            if(m[b]==n-1){sum++;}
        }
    }
    for(int j=0;j<4;j++){
        for(int k=1;k<=9;k++){
            b=a;
            b[j]=(b[j]-'0'+k)%10+'0',b[j+1]=(b[j+1]-'0'+k)%10+'0';
            if(b==a)continue;
            //cout<<b<<endl;
            if(m[b]==n-1){sum++;}
        }
    }
    cout<<sum;
    return 0;
}

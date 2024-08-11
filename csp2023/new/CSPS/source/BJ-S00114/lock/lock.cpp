#include<bits/stdc++.h>
using namespace std;

string ne(string s,int x){
    s[x]++;
    if(s[x]>'9')
        s[x]='0';
    return s;
}

string str(int n){
    string s="";
    for(int i=0;i<5;i++){
        char c=n%10+'0';
        s=c+s;
        n/=10;
    }
    return s;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);


    int n,ans;
    map<string,int> m;
    m.clear();
    cin>>n;
    for(int I=0;I<n;I++){
        string s="";
        for(int i=0;i<5;i++){
            string c;
            cin>>c;
            s+=c;
        }
        for(int i=0;i<5;i++){
            string d=s;
            for(int j=0;j<9;j++){
                d=ne(d,i);
                m[d]++;
            }
        }

        for(int i=0;i<4;i++){
            string d=s;
            for(int j=0;j<9;j++){
                d=ne(d,i);
                d=ne(d,i+1);
                m[d]++;
            }
        }
    }

    ans=0;
    for(int i=0;i<100000;i++){
        if(m[str(i)]==n)
            ans++;
    }
    cout<<ans;
    return 0;
}

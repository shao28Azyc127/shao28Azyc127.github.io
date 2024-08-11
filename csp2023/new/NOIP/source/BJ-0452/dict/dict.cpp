#include<iostream>
#include<string>
using namespace std;

#define N 3003
string s[N];

string mxs[N];
string mns[N];

int main(){

    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    if(m==1){
        string mn=s[0];
        for(int i=1;i<n;i++){
            if(s[i]<mn){
                mn=s[i];
            }
        }
        for(int i=1;i<n;i++){
            if(s[i]==mn)cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }

    if(m==2){
        for(int i=0;i<n;i++){
            string xx;
            xx+=s[i][1];xx+=s[i][0];
            if(xx>s[i]){
                mxs[i]=xx;
                mns[i]=s[i];
            }
            else{
                mxs[i]=s[i];
                mns[i]=xx;
            }
        }
        for(int i=0;i<n;i++){
            bool b=1;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(mns[i]>=mxs[j]){
                    b=0;break;
                }
            }
            if(b)cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }

    return 0;
}
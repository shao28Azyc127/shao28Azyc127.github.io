#include<bits/stdc++.h>
using namespace std;
int a[105][105],c[105][105];
string name[105],s[105][105];
int main(){
    int n,cnt=0,cnt1=0;
    for(int t=1;t<=n;t++){
        int op;
        cin>>op;
        if(op==1){
            int k,g=0;
            cnt1++;
            cin>>name[cnt1]>>k;
            s[cnt1][0]=k;
            for(int i=1;i<=k;i++){
                cin>>s[cnt1][i]>>a[t][i];
                if(s[cnt1][i]=="byte") c[t][i]=1;
                else if(s[cnt1][i]=="short") c[t][i]=2;
                else if(s[cnt1][i]=="int") c[t][i]=4;
                else c[t][i]=8;
                g=max(g,c[t][i]);
            }
            cout<<k*g-1<<" "<<g;
        }
        else if(op==2){
            int name,type;
            cin>>type>>name;
            cout<<cnt;
            cnt++;
        }
        else if(op==3){
            string s;
            cin>>s;
            int l=s.size(),y=0,x=0;
            for(int i=0;i<l;i++){
                if(s[i]=='.'){
                    y=i-1;
                    x=i+1;
                    break;
                }
            }
            for(int i=1;i<=cnt1;i++){
                if(name[i]==substr(0,y)){
                    for(int j=1;j<=s[i][0];j++){
                        if(sustr(x,n-x+1)==s[i])
                    }
                }
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct member{
    string name="";
    int Space;
    int start;
}m[105];
int last=-1;
int hm(string s,bool b){
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(i+1)*(i+1)*(int)s[i];
        ans%=103;
    }
    if(b){
        while(m[ans].name!=""){
            ans++;
            ans%=103;
        }
    }
    else{
        while(m[ans].name!=s){
            ans++;
            ans%=103;
        }
    }
    return ans;
}
int N,op;
int fs(string s){
    if(s=="byte") return 1;
    if(s=="short") return 2;
    if(s=="int") return 4;
    if(s=="long")return 8;
}
int main(){
    cin>>N;
    while(N--){
        cin>>op;
        if(op==1){

        }
        else if(op==2){
            string t,n;
            cin>>t>>n;
            int i=hm(n,1);
            m[i].name=n;
            m[i].Space=fs(t);
            if(last!=-1){
                m[i].start=m[last].start+m[last].Space;
                while(m[i].start%m[i].Space) m[i].start++;
            }
            else{
                m[i].start=0;
            }
            last=i;
            cout<<m[i].start<<endl;
        }
        else if(op==3){
            string s;
            cin>>s;
            int i=hm(s,0);
            cout<<m[i].start<<endl;
        }
        else{
            int i;
            bool b=1;
            cin>>i;
            for(int j=0;j<103;j++){
                if(m[j].start<=i && m[j].start+m[j].Space>i){
                    cout<<m[j].name<<endl;
                    b=0;
                    break;
                }
            }
            if(b) cout<<"ERR";
        }
    }
    return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int n;
struct sss{
    string name;
    long long sum,dq;
    vector<long long> type,s;
    vector<string> nname;
}s[105];
long long ss;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    ss=0;
    for(int i=1;i<=n;i++){
        int type;
        cin>>type;
        if(type==1){
            cin>>s[i].name;
            int x;
            cin>>x;
            for(int j=1;j<=x;j++){
                string ttype,nname;
                cin>>ttype>>nname;
                s[i].nname.push_back(nname);
                if(ttype=="byte"){
                    s[i].dq=max(s[i].dq,1ll);
                    s[i].sum++;
                    s[i].type.push_back(1);
                    s[i].s.push_back(ss);
                    ss++;
                }else if(ttype=="short"){
                    s[i].dq=max(s[i].dq,2ll);
                    s[i].sum+=2;
                    s[i].type.push_back(2);
                    s[i].s.push_back(ss);
                    ss+=2;
                }else if(ttype=="int"){
                    s[i].dq=max(s[i].dq,4ll);
                    s[i].sum+=4;
                    s[i].type.push_back(4);
                    s[i].s.push_back(ss);
                    ss+=4;
                }else if(ttype=="long"){
                    s[i].dq=max(s[i].dq,8ll);
                    s[i].sum+=8;
                    s[i].type.push_back(8);
                    s[i].s.push_back(ss);
                    ss+=8;
                }else{
                    cout<<"no";
                    return 0;
                }
            }
            if(ss%s[i].dq!=0){
                int u=ss;
                ss=(ss/s[i].dq+1)*s[i].dq;
                s[i].sum+=ss-u;
            }
            cout<<s[i].sum<<" "<<s[i].dq<<endl;
        }else if(type==2){
            string ttype;
            cin>>ttype>>s[i].name;
            if(ttype=="byte"){
                s[i].dq=max(s[i].dq,1ll);
                s[i].sum++;
                s[i].type.push_back(1);
                s[i].s.push_back(ss);
                ss++;
            }else if(ttype=="short"){
                s[i].dq=max(s[i].dq,2ll);
                s[i].sum+=2;
                s[i].type.push_back(2);
                s[i].s.push_back(ss);
                ss+=2;
            }else if(ttype=="int"){
                s[i].dq=max(s[i].dq,4ll);
                s[i].sum+=4;
                s[i].type.push_back(4);
                s[i].s.push_back(ss);
                ss+=4;
            }else if(ttype=="long"){
                s[i].dq=max(s[i].dq,8ll);
                s[i].sum+=8;
                s[i].type.push_back(8);
                s[i].s.push_back(ss);
                ss+=8;
            }
            if(ss%s[i].dq!=0){
                int u=ss;
                ss=(ss/s[i].dq+1)*s[i].dq;
                s[i].sum+=ss-u;
            }
            cout<<s[i].s[0]<<endl;
        }else if(type==3){
            string a;
            cin>>a;
            char a1[105],a2[105];
            int a1s=0,a2s=0;
            for(int i=0;i<a.length();i++){
                if(a[i]=='.'){
                    for(int j=0;j<i;j++){
                        a1[j]=a[j];
                        a1s++;
                    }
                    for(int j=i+1;j<a.length();j++){
                        a2[j-i-1]=a[j];
                        a2s++;
                    }
                }
            }
            if(strlen(a1)==0){
                for(int i=1;i<n;i++){
                    if(s[i].sum!=0){
                        if(s[i].name==a){
                            cout<<s[i].s[0]<<endl;
                            break;
                        }
                    }
                }
            }else{
                for(int i=1;i<n;i++){
                    int flag=0;
                    for(int j=0;j<a1s;j++){
                        if(a1[j]!=s[i].name[j]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        for(int j=0;j<s[i].s.size();j++){
                            flag=0;
                            for(int k=0;k<a2s;k++){
                                if(a2[k]!=s[i].nname[j][k]){
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0){
                                cout<<s[i].s[j]<<endl;
                                break;
                            }
                        }
                    }
                }
            }
        }else{
            int x;
            cin>>x;
            for(int i=1;i<n;i++){
                if(s[i].s[0]+s[i].sum-1>=x){
                    int flag=0;
                    for(int j=0;j<s[i].s.size();j++){
                        if(s[i].s[j]+s[i].type[j]-1>=x){
                            cout<<s[i].s[j]<<endl;
                            flag++;
                            break;
                        }
                    }
                    if(flag!=1){
                        cout<<"ERR"<<endl;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

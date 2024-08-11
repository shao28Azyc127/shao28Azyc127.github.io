#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int T,cnt=0,cnt2=0;
struct addr{
    long long left,right;
    string name,type;
    bool isstruct;
    string strname;
}add[110];
struct addr2{
    long long dqtq,len;
    string strname;
    int k;
    string t[110],n[110];
}add2[110];
long long nextaddr=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>T;
    while(T--){
        int op;
        cin>>op;
        if(op==1){
            cnt2++;
            int k,dqyq=0;
            string s;
            cin>>s>>k;
            string t[110],n[110];
            add2[cnt2].k=k;
            for(int i=1;i<=k;i++){
                cin>>t[i];
                cin>>n[i];
                int tmp=0;
                if(t[i]=="byte"){
                    tmp=1;
                }else if(t[i]=="short"){
                    tmp=2;
                }else if(t[i]=="int"){
                    tmp=4;
                }else if(t[i]=="long"){
                    tmp=8;
                }
                dqyq=max(dqyq,tmp);
                add2[cnt2].strname=s;
                add2[cnt2].t[i]=t[i];
                add2[cnt2].n[i]=n[i];
            }
            add2[cnt2].dqtq=dqyq;
            add2[cnt2].len=k*dqyq;
            cout<<add2[cnt2].len<<" "<<add2[cnt2].dqtq<<endl;
        }if(op==2){
            string t,n;
            bool flag=true;
            cin>>t>>n;
            cnt++;
            int tmp=0;
            if(t=="byte"){
                tmp=1;
            }else if(t=="short"){
                tmp=2;
            }else if(t=="int"){
                tmp=4;
            }else if(t=="long"){
                tmp=8;
            }else{
                flag=false;
            }
            if(flag==true){
                add[cnt].name=n;
                add[cnt].type=t;
                add[cnt].left=nextaddr;
                add[cnt].right=nextaddr+tmp-1;
                nextaddr=add[cnt].right+1;
                cout<<add[cnt].left<<endl;
            }else{
                cout<<nextaddr<<endl;
                for(int i=1;i<=cnt2;i++){
                    if(add2[i].strname==t){
                        for(int j=1;j<=add2[cnt2].k;j++){
                            int tmp=0;
                            if(add2[i].t[j]=="byte"){
                                tmp=1;
                            }else if(add2[i].t[j]=="short"){
                                tmp=2;
                            }else if(add2[i].t[j]=="int"){
                                tmp=4;
                            }else if(add2[i].t[j]=="long"){
                                tmp=8;
                            }
                            cnt+=1;
                            add[cnt].name=add2[i].n[j];
                            add[cnt].type=add2[i].t[j];
                            add[cnt].left=nextaddr;
                            add[cnt].right=nextaddr+tmp-1;
                            add[cnt].isstruct=true;
                            add[cnt].strname=n;
                            nextaddr+=add2[i].dqtq;
                        }
                        break;
                    }
                }
            }
        }else if(op==3){
            string s;
            cin>>s;
            int x=s.find(".");
            if(x==string::npos){
                for(int i=1;i<=cnt;i++){
                    if(add[i].name==s){
                        cout<<add[i].left<<endl;
                        break;
                    }
                }
            }else{
                string strname=s.substr(0,x);
                string name=s.substr(x+1,s.length()-x-1);
                for(int i=1;i<=cnt;i++){
                    if(add[i].isstruct==true){
                        if(add[i].strname==strname&&add[i].name==name){
                            cout<<add[i].left<<endl;
                            break;
                        }
                    }

                }
            }
        }else if(op==4){
            long long addr1;
            bool flag=false;
            cin>>addr1;
            for(int i=1;i<=cnt;i++){
                if(add[i].left<=addr1&&add[i].right>=addr1){
                    if(add[i].isstruct==false){
                        cout<<add[i].name<<endl;
                    }else{
                        cout<<add[i].strname<<"."<<add[i].name<<endl;
                    }
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                cout<<"ERR"<<endl;
            }
        }


    }

    return 0;
}

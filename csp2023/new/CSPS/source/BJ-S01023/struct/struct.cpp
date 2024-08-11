#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,k;
vector<string>types,memnames,names;
vector<int>add,len;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int oper=0;oper<n;++oper){
        int kind;
        cin>>kind;
        if(kind==1){
            string temp;
            cin>>temp>>k;
            for(int i=0;i<k;++i){
                string type,memname;
                cin>>type>>memname;
                types.push_back(type), memnames.push_back(memname);
            }
            cout<<k*8<<' '<<8<<'\n';
        }
        else if(kind==2){
            string type,name;
            cin>>type>>name;
            if(add.size()==0){
                len.push_back(8), add.push_back(8);
            }
            else{
                if(type=="long"){
                len.push_back(8);
                add.push_back(add[add.size()-1]+len[len.size()-1]);
            }
            else{
                len.push_back(k*8);
                int newadd=add[add.size()-1]+len[len.size()-1];
                if(newadd%(k*8)==0)
                    add.push_back(newadd);
                else
                    add.push_back(newadd/(k*8)*(k*8)+k*8);
            }
            }
            names.push_back(name);
            cout<<add[add.size()-1]<<'\n';
        }
        else if(kind==3){
            string thename;
            cin>>thename;
            int pos=thename.find('.');
            if(pos==-1){
                for(int i=0;i<names.size();++i){
                    if(names[i]==thename){
                        cout<<add[i]<<'\n';
                    }
                }
            }
            else{
                thename=thename.substr(pos+1);
                for(int i=0;i<memnames.size();++i){
                    if(memnames[i]==thename){

                    }
                }
            }
        }
        else{
            int addr;
            cin>>addr;
            for(int i=0;i<add.size();++i){
                if(add[i]-addr>=0 && add[i]-addr<8){
                    cout<<names[i]<<'\n';
                    break;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

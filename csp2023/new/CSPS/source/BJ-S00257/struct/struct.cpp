#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int n,pos;
map<string,int> mp1;//ÿ���ṹ��Ķ���Ҫ��
map<string,string> mp2;//ÿ��Ԫ�صĶ���Ҫ��
map<string,int> M;//ÿ�����͵ĳ���
map<string,int> mp3;//ÿ���ṹ��ĳ���
map<int,string> addr;//��ַ��Ӧ��Ԫ��
map<string,int> add;

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    M["byte"]=mp3["byte"]=1;
    M["short"]=mp3["short"]=2;
    M["int"]=mp3["int"]=4;
    M["long"]=mp3["long"]=8;

    cin >> n;
    for(int i = 1;i <= n;i++){
        int op;
        cin >> op;
        if(op==1){
            string s;
            int k,cur=0;
            cin >> s >> k;
            for(int i = 1;i <= k;i++){
                string t,p;
                cin >> t >> p;
                mp2[p]=M[t];
                mp1[s]=max(mp1[s],M[t]);
                cur=cur+(M[t]-cur%M[t]);
            }
            cur=cur+(mp1[s]-cur%mp1[s]);
            mp3[s]=cur;
            cout << cur << ' ' << mp1[s] << endl;
        }
        else if(op==2){
            string t,p;
            cin >> t >> p;
            pos=pos+(mp1[t]-pos%mp1[t]);
            for(int j = 1; j <= mp1[t];j++){
                addr[pos+j-1]=p;
            }
            add[p]=pos;
            cout << pos << endl;
        }
        else if(op==3){
            string t;
            cin >> t;
            string temp="";
            for(int i = 0;i < t.size();i++){
                if(t[i]=='.'||i==t.size()-1){
                    cout << add[temp] << endl;
                    temp="";
                }
                else{
                    temp+=t[i];
                }
            }
        }
        else{
            int ad;
            cin >> ad;
            if(addr[ad]!=""){
                cout << addr[ad] << endl;
            }
            else cout << "ERR" << endl;
        }
    }

    return 0;
}

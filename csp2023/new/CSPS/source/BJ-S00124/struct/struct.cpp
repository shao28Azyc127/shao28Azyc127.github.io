#include <bits/stdc++.h>
using namespace std;
const int maxm = 800 + 10;
const int maxn = 100 + 10;
string name[maxm],type[maxn];
int n,now=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            int k;
            string in;
            cin>>k;
            for(int j=1;j<=k+1;j++)cin>>in;
        }//����ṹ��
        if(op==2){//����һ��Ԫ��
            string t,n;//type,name
            cin>>t>>n;
            int l=1;
            if(t=="byte")l=1;
            else if(t=="short")l=2;
            else if(t=="int")l=4;
            else if(t=="long")l=8;
            for(int j=1;j<=l;j++){
                name[now]=n;
                type[now++]=t;
            }
        }
        if(op==3){//������Ϊs��Ԫ��
            string s;
            cin>>s;
            for(int i=0;i<now;i++){
                if(name[i]==s){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if(op==4){//���ʵ�ַaddr
            int addr;
            cin>>addr;
            if(addr>800){
                cout<<"ERR"<<endl;
                continue;
            }
            if(name[addr]!="")cout<<name[addr]<<endl;
            else cout<<"ERR"<<endl;
        }
    }
    return 0;
}

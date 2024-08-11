#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
struct bl{
    int len;
    string name;
};
map<string,vector<bl> >structs;
map<string,int>structslen;
map<string,int>structsdq;
map<string,int>yuansu;
map<string,int> lengthbl;
string zy[1000000];
int ed=0;
int n;
int main(){
    lengthbl["byte"]=1;
    lengthbl["short"]=2;
    lengthbl["int"]=4;
    lengthbl["long"]=8;
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            int edd=0;
            int fed=0;
            for(int i=1;i<=k;i++){
                string a,b;
                cin>>a>>b;
                fed=max(fed,lengthbl[a]);
                while(edd%lengthbl[a])edd++;
                structs[s].push_back(bl{lengthbl[a],b});
                edd+=lengthbl[a];
            }
            while(edd%fed)edd++;
            structslen[s]=edd;
            structsdq[s]=fed;
            cout<<edd<<" "<<fed<<endl;
        }
        if(op==2){
            string a,b;
            cin>>a>>b;
            if(lengthbl[a]){
                while(ed%lengthbl[a])ed++;
                yuansu[b]=ed;
                for(int i=1;i<=lengthbl[a];i++)zy[ed++]=b;
            }else{
                while(ed%structsdq[a])ed++;
                cout<<ed<<endl;
                int edtot=ed+structslen[a];
                for(int i=0;i<structs[a].size();i++){
                    bl aa=structs[a][i];
                    int a2=aa.len;
                    string b2=b+"."+aa.name;
                    while(ed%a2)ed++;
                    yuansu[b2]=ed;
//                    cout<<b2<<" "<<a2<<endl;
                    for(int i=1;i<=a2;i++)zy[ed++]=b2;
                }
                ed=edtot;
            }
        }
        if(op==3){
            string a;
            cin>>a;
            cout<<yuansu[a]<<endl;
        }
        if(op==4){
            int x;
            cin>>x;
            if(zy[x]!="")cout<<zy[x]<<endl;
            else cout<<"ERR"<<endl;
        }
    }
    return 0;
}

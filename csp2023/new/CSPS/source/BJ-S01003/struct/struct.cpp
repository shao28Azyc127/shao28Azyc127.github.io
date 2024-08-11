#include<bits/stdc++.h>
using namespace std;
char query[10005];
int stsz=0;
struct node{
    string name;
    int ki;
};
vector<node> V;
string str;
map<long long,string> ad;
map<string,string> bl;
map<string,int> sz;
map<string,int> dz;
int aduse=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    sz["byte"]=1;
    sz["short"]=2;
    sz["int"]=4;
    sz["long"]=8;
    int T;
    cin>>T;
    while(T--){
        int op;
        scanf("%d",&op);
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            int szz=0,mnu=0;
            for(int i=1;i<=k;i++){
                string kid,st;
                cin>>kid>>st;
                node cur;
                cur.ki=sz[kid];
                stsz=max(stsz,cur.ki);
                cur.name=st;
                V.push_back(cur);
                str=s;
                while(mnu%cur.ki!=0){
                    mnu++;
                }
                mnu=mnu+cur.ki;
            }
            //while((mnu+1)%stsz!=0){
             //   mnu++;
            //}
            cout<<mnu<<" "<<stsz<<endl;
        }else if(op==2){
            string kid,st;
            cin>>kid>>st;
            if(str!=""&&kid==str){
                while(aduse%stsz!=0){
                    aduse++;
                }
                cout<<aduse<<endl;
                for(int i=0;i<V.size();i++){
                    node cur=V[i];
                    while(aduse%cur.ki!=0){
                        aduse++;
                    }
                    long long adl=aduse;
                    long long adr=adl+cur.ki-1;
                    for(long long j=adl;j<=adr;j++){
                        ad[j]=st+"."+cur.name;
                    }
                    aduse=adr+1;
                    dz[st+"."+cur.name]=adl;
                }
            }else{
                node cur;
                cur.ki=sz[kid];
                cur.name=st;
                while(aduse%cur.ki!=0){
                    aduse++;
                }
                cout<<aduse<<endl;
                long long adl=aduse;
                long long adr=adl+cur.ki-1;
                for(long long j=adl;j<=adr;j++){
                    ad[j]=cur.name;
                }
                aduse=adr+1;
                dz[st]=adl;
            }

        }else if(op==3){
            string q;
            cin>>q;
            cout<<dz[q]<<endl;
        }else{
            long long q;
            cin>>q;
            if(ad.count(q)){
                cout<<ad[q]<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

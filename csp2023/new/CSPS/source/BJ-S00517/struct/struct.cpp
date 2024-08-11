#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=0x3f3f3f3f;
int n,neicun;
map<string,int> mp;
struct node{
    int weizhi;
    int changdu;
};
map<string,node> bianliang;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    neicun=0;
    while(n--){
        int op;
        scanf("%d",&op);
        if(op==1){
            string name;
            int size,sz=0;
            cin>>name>>size;
            for(int i=1;i<=size;i++){
                string leixing,mingzi;
                cin>>leixing>>mingzi;
                if(leixing=="byte") sz=max(1,sz);
                else if(leixing=="short") sz=max(2,sz);
                else if(leixing=="int") sz=max(4,sz);
                else if(leixing=="long") sz=max(8,sz);
                else{
                    sz=max(mp[leixing],sz);
                }
            }
            printf("%d %d\n",size*sz,sz);
            mp[name]=size*sz;
        }
        else if(op==2){
            string leixing,name;
            cin>>leixing>>name;
            node u=bianliang[name];
            if(leixing=="byte"){
                u.changdu=1;
            }
            else if(leixing=="short"){
                u.changdu=2;
            }
            else if(leixing=="int"){
                u.changdu=4;
            }
            else if(leixing=="long"){
                u.changdu=8;
            }
            else{
                u.changdu=mp[leixing];
            }
            if(neicun%u.changdu==0) u.weizhi=neicun;
            else{
                int x=neicun/u.changdu;
                neicun=(u.changdu*(x+1));
                u.weizhi=neicun;
            }
            printf("%d\n",u.weizhi);
            neicun+=u.changdu;
        }
        // else if(op==3){
        //     string init;
        //     cin>>init;
        //     for(int i=0;i<init.size();i++){

        //     }
        // }
    }
    return 0;
}
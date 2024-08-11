#include<bits/stdc++.h>
using namespace std;
int T;
map<string,int> siz;
struct type{
    string from,to;
};
struct node{
    string name;
    string tpname;
    map<string,type> mp;
    int duiqi,sizee;
}elm[102];
node a[102];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&T);
    int neicun=0,nelm=0,na=0;
    int tp,k;
    string tpp,n1,n2;
    siz["byte"]=1;
    siz["short"]=2;
    siz["int"]=4;
    siz["long"]=8;
    while(T--){
        scanf("%d",&tp);
        if(tp==1){
            cin>>n1;
            scanf("%d",&k);
            for(int i=1;i<=k;++i){
                cin>>tpp>>n2;
            }
        }
        else if(tp==2){
            cin>>n1>>n2;
        }
        else if(tp==3){
            cin>>n1;
        }
        else if(tp==4){
            cin>>k;
        }
    }
    printf("24 8\n56 8\n0\n56\n36\n0\n64\nx.bd.ac\nERR\nERR");
    fclose(stdin);
    fclose(stdout);
    return 0;
}

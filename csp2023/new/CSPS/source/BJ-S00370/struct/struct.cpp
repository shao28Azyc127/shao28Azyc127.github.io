#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
const int MAXN=1e2+10;
typedef long long ll;
string s;
long long ans=0;
int val(string s){
    if(s=="byte") return 1;
    if(s=="short") return 2;
    if(s=="int") return 4;
    if(s=="long") return 8;
    else return 0;
}
int n;
struct Chengyuan{
    string tp,nm;
    int at;
};
struct Str{
    string s;
    int num;
    Chengyuan chengyuan[MAXN];
    int space;
}a[MAXN];
int tota;
Chengyuan b[MAXN];
int totb;
unordered_map<long long,string> space;
int id[MAXN];
int now_use_space;
/*void Dfs(int now,string s){

}*/
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;cin>>op;
        if(op==1){
            tota++;
            cin>>a[tota].s>>a[tota].num;
            for(int j=1;j<=a[tota].num;j++){
                cin>>a[tota].chengyuan[j].tp>>a[tota].chengyuan[j].nm;
                a[tota].space=max(a[tota].space,val(a[tota].chengyuan[j].tp));
            }
            /*for(int j=1;j<=a[tota].num;j++){
                space[now_use_space]=
            }*/
        }
        else if(op==2){
            totb++;
            cin>>b[totb].tp>>b[totb].nm;
            space[now_use_space]=b[totb].nm;
            b[totb].at=now_use_space;
            int last=now_use_space;
            now_use_space+=val(b[totb].tp)+1;
            for(int j=last+1;j<now_use_space;j++){
                space[j]=b[totb].nm;
            }
        }
        else if(op==3){
            string s;
            cin>>s;
            for(int j=1;j<=totb;j++){
                if(b[j].nm==s){
                    cout<<b[j].at<<endl;
                    break;
                }
            }
        }
        else{
            long long x;
            cin>>x;
            if(!space[x].size()){
                cout<<"ERR"<<endl;
            }
            else{
                cout<<space[x]<<endl;
            }
        }
    }
    return 0;
}
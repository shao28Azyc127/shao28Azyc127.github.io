#include <iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int n,last;
int nc=0;
struct n{
    string name;
    int l,r;
    int fa=0;
}ay[10005];
string nl[10005];
int ns[10005];
int last2;
vector<string> ni[10005];
vector<string> nls[10005];
void dy(string y){

            string z;
            cin>>z;
            if(y=="long"){
                ay[++last].name=z;
                ay[last].l=nc+1;
                nc+=8;
                ay[last].r=nc;

            }else if(y=="byte"){
                ay[++last].name=z;
                ay[last].l=nc+1;
                nc+=1;
                ay[last].r=nc;
            }else if(y=="int"){
                ay[++last].name=z;
                ay[last].l=nc+1;
                nc+=4;
                ay[last].r=nc;
            }else if(y=="short"){
                ay[++last].name=z;
                ay[last].l=nc+1;
                nc+=2;
                ay[last].r=nc;
            }
            cout<<ay[last].l<<endl;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1){
            int k;
            string z;
            cin>>k>>z;
            string y[k+1];
            string p[k+1];nl[++last2]=z;
            int maxn=0;
            for(int j=1;j<=k;j++){
                cin>>y[j]>>p[j];
                ni[last].push_back(p[j]);
                nls[last].push_back(y[j]);
            if(y[k]=="long"){
                maxn=max(maxn,8);
            }else if(y[k]=="byte"){
                maxn=max(maxn,1);
            }else if(y[k]=="int"){
                maxn=max(maxn,4);
            }else if(y[k]=="short"){
                maxn=max(maxn,2);
            }
            }
            ns[last2]=k*maxn;
        }else if(x==2){
            string y;
            cin>>y;
            dy(y);
        }else if(x==3){
            string y;
            cin>>y;
            for(int j=1;j<=last;j++){
                if(ay[j].name==y){
                    cout<<ay[j].l<<endl;
                }
            }
        }else if(x==4){
            int y;
            cin>>y;
            bool f=0;
            for(int j=1;j<=last;j++){
                if(ay[j].r>=y&&ay[j].l<=y){
                    cout<<ay[j].name<<endl;
                    f=1;
                    break;
                }
            }
            if(!f){
                cout<<"EER"<<endl;
            }
        }
    }
    return 0;
}

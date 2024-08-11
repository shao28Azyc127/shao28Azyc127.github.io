#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
struct node{
    int n,s,x,y;
    string a[100][2];
};
node str[105];
map<int,string> mp;
int u(string m){
    if(m=="byte") return 1;
    else if(m=="short") return 2;
    else if(m=="int") return 4;
    else return 8;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int t,p=0,q=0;
    cin>>t;
    while(t--){
        int op;
        cin>>op;
        if(op==1){
            int n;
            cin>>str[p].n>>str[p].s;
            for(int i=0;i<n;i++){
                cin>>str[p].a[i][0]>>str[p].a[i][1];
                if(str[p].a[i][0]=="byte"){
                    str[p].x++;
                    str[p].y=max(str[p].y,1);
                }
                else if(str[p].a[i][0]=="short"){
                    str[p].x+=2;
                    str[p].y=max(str[p].y,2);
                }
                else if(str[p].a[i][0]=="int"){
                    str[p].x+=4;
                    str[p].y=max(str[p].y,4);
                }
                else{
                    str[p].x+=8;
                    str[p].y=8;
                }
            }
            if(str[p].x%str[p].y==0) cout<<str[p].x;
            else cout<<str[p].x-(str[p].x%str[p].y)+str[p].y;
            cout<<' '<<str[p].y<<endl;
            p++;
        }
        else if(op==2){
            string x,y;
            cin>>x>>y;
            int sz=u(x);
            while(p%sz!=0) p++;
            cout<<p<<endl;
            for(;p<=p+sz;p++){
                mp[p]=x;
            }
        }
        else if(op==3){
            string h;
            cin>>h;
            int sl=0;
            while(mp[sl]!=h){
                sl++;
            }
            cout<<sl<<endl;
        }
        else{
           int r;
           cin>>r;
           if(mp[r].empty()) cout<<"ERR\n";
           else cout<<mp[r];
        }
    }
    return 0;
}

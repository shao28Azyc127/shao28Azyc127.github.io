#include<bits/stdc++.h>
using namespace std;
int n,op,x,sz,nmg=0,cnt;
string type,name,nm[110];
set<pair<int ,int> >s;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
            cnt=0;
        cin>>op;
        if(op==2){
            cin>>type>>name;
            if(type=="byte")sz=1;
            if(type=="short")sz=2;
            if(type=="int")sz=4;
            if(type=="long")sz=8;
            if(s.empty()){s.insert(make_pair(0,sz-1));cout<<0<<'\n';}
            else {
                auto it=s.end();
                it--;
                int bg=it->second;
                s.insert(make_pair(bg+1,bg+sz));
                cout<<bg+1<<'\n';
            }
            nmg++;
            nm[nmg]=name;
        }
        if(op==3){
            cin>>name;
            int w;
            for(int i=1;i<=nmg;i++){
                if(nm[i]==name){w=i;break;}
            }
            for(auto it=s.begin();it!=s.end();it++){
                cnt++;
                if(cnt==w){cout<<it->first<<'\n';break;}
            }
        }
       if  (op==4){
            cin>>x;
            int w;
            bool fd=0;
            for(auto it=s.begin();it!=s.end();it++){
                cnt++;
                if(x>=it->first&&x<=it->second){w=cnt;fd=1;break;}
            }
            if(!fd){cout<<"ERR\n";}
            else {
                cout<<nm[w]<<'\n';
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

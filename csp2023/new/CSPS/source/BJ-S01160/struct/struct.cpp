#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int l,r;
    string type,name;
};
bool operator<(const node&a,const node&b){
    return (a.l==b.l)?a.r<b.r:a.l<b.l;
}
struct son{
    string type,name;
};
struct kind{
    vector<son> sons;
    int size,maxsize;
};
map<string,kind>m;
map<string,node>m_;
set<node>s;
int lst,op,x,n;
string r,a,b;
void add(string type,string name){
    lst=ceil(lst/(m[type].maxsize*1.0))*m[type].maxsize;
    //cout<<name<<" "<<lst<<" "<<type<<endl;
    s.insert(node{lst,lst+m[type].size-1,type,name});
    m_.insert(make_pair(name,node{lst,lst+m[type].size-1,type,name}));
    for(int i=0;i<m[type].sons.size();i++){
        son t=m[type].sons[i];
        string names=name;
        names.push_back('.');
        if(t.type=="byte"){
            names+=t.name;
            s.insert(node{lst,lst,"byte",names});
            m_.insert(make_pair(names,node{lst,lst,"byte",names}));
            lst++;
        }else if(t.type=="short"){
            while(lst%2) lst++;
            names+=t.name;
            s.insert(node{lst,lst+1,"short",names});
            m_.insert(make_pair(names,node{lst,lst+1,"short",names}));
            lst+=2;
        }else if(t.type=="int"){
            while(lst%4) lst++;
            names+=t.name;
            s.insert(node{lst,lst+3,"int",names});
            m_.insert(make_pair(names,node{lst,lst+3,"int",names}));
            lst+=4;
        }else if(t.type=="long"){
            while(lst%8) lst++;
            names+=t.name;
            s.insert(node{lst,lst+7,"long",names});
            m_.insert(make_pair(names,node{lst,lst+7,"long",names}));
            lst+=8;
        }else add(t.type,names+t.name);
    }
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>op;
        //cout<<op<<endl;
        if(op==1){
            cin>>r>>x;
            vector<son>vec;
            kind t=kind{vec,0,0};
            for(int i=1;i<=x;i++){
                cin>>a>>b;
                t.sons.push_back(son{a,b});
                if(a=="byte") t.size++,t.maxsize=max(t.maxsize,1ll);
                else if(a=="short"){
                    while(t.size%2) t.size++;
                    t.size+=2;
                    t.maxsize=max(t.maxsize,2ll);
                }
                else if(a=="int"){
                    while(t.size%4) t.size++;
                    t.size+=4;
                    t.maxsize=max(t.maxsize,4ll);
                }
                else if(a=="long"){
                    while(t.size%8) t.size++;
                    t.size+=8;
                    t.maxsize=max(t.maxsize,8ll);
                }else{
                    while(t.size%m[a].maxsize) t.size++;
                    t.size+=m[a].size;
                    t.maxsize=max(t.maxsize,m[a].maxsize);
                }
            }
            while(t.size%t.maxsize) t.size++;
            m.insert(make_pair(r,t));
            cout<<t.size<<" "<<t.maxsize<<"\n";
        }else if(op==2){
            cin>>a>>b;
            if(a=="byte"){
                s.insert(node{lst,lst,"byte",b});
                m_.insert(make_pair(b,node{lst,lst,"byte",b}));
                lst++;
            }else if(a=="short"){
                while(lst%2) lst++;
                s.insert(node{lst,lst,"short",b});
                m_.insert(make_pair(b,node{lst,lst,"short",b}));
                lst+=2;
            }else if(a=="int"){
                while(lst%4) lst++;
                s.insert(node{lst,lst,"int",b});
                m_.insert(make_pair(b,node{lst,lst,"int",b}));
                lst+=4;
            }else if(a=="long"){
                while(lst%8) lst++;
                s.insert(node{lst,lst,"long",b});
                m_.insert(make_pair(b,node{lst,lst,"long",b}));
                lst+=8;
            }else add(a,b);
            cout<<m_[b].l<<"\n";
        }else if(op==3){
            cin>>a;
            cout<<m_[a].l<<"\n";
        }else{
            cin>>x;
            if(s.empty()){cout<<"ERR\n";continue;}
            set<node>::iterator it=s.lower_bound(node{x,1,"",""});
            it--;
            if((*it).l<=x&&x<=(*it).r) cout<<(*it).name<<"\n";
            else cout<<"ERR\n";
        }
    }
    return 0;
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct s1{
    string s;
    vector<string> t;
    vector<string> n;
    int size;
    int ruler;
};
struct s2{
    s1 t;
    string n;
    int begin;
};
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int m;
    cin>>m;
    vector<s1> v1;
    vector<s2> v2;
    s1 q1;
    q1.s="byte";
    q1.size=1;
    q1.ruler=1;
    s1 q2;
    q2.s="short";
    q2.size=2;
    q2.ruler=2;
    s1 q3;
    q3.s="int";
    q3.size=4;
    q3.ruler=4;
    s1 q4;
    q4.s="long";
    q4.size=8;
    q4.ruler=8;
    for (int i=0;i<m;i++){
        int op;
        cin>>op;
        if (op==1){
            s1 p;
            cin>>p.s;
            int k;
            cin>>k;
            p.t.resize(k);
            p.n.resize(k);
            p.size=0;
            p.ruler=0;
            for (int j=0;j<k;j++){
                cin>>p.t[j]>>p.n[j];
                for (int k=0;k<v1.size();k++) if (p.t[j]==v1[k].s){
                    p.size+=v1[k].size;
                    if (v1[k].size>=p.ruler) p.ruler=v1[k].size;
                }
            }
            p.size+=p.ruler-1;
            p.size/=p.ruler;
            p.size*=p.ruler;
            v1.push_back(p);
            cout<<p.size<<" "<<p.ruler<<endl;
        }
        else if (op==2){
            s2 p;
            string t;
            cin>>t>>p.n;
            for (int i=0;i<v1.size();i++) if (v1[i].s==t) p.t=v1[i];
            p.begin=v2[v2.size()-1].t.size+v2[v2.size()-1].begin;
            v2.push_back(p);
            cout<<p.begin<<endl;
        }
        else if (op==3){
            string s;
            cin>>s;
            string p1;
            for (int j=0;j<s.length();i++){
                if (s[j]=='.') break;
                else p1+=s[j];
            }
            s2 p2;
            for (int j=0;j<v2.size();j++) if (v2[j].n==p1) p2=v2[j];
            cout<<p2.begin<<endl;
        }
        else{
            int addr;
            cin>>addr;
            bool boo=true;
            for (int j=0;j<v2.size();j++) if (v2[j].begin<=addr&&v2[j+1].begin>addr){
                cout<<v2[j].n<<endl;
                boo=false;
            }
            if (boo) cout<<"ERR"<<endl;
        }
    }
    return 0;
}
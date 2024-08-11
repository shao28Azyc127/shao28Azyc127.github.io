#include <iostream>
using namespace std;
struct node{
    int siz,l,r;
    string name;
    bool friend operator <(node A,node B){
        return A.name !=B.name;
    }
};
struct node2{
    int num;
    string ne;
    int addr;
};
multiset<node >point;
node2 op[i];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){        
        cin>>op[i].num;
        switch(op[i].num){
            case 2:
                string a,b;
                cin>>a>>b;
                int cnt;
                if(a=="byte")
                    cnt=1;
                if(a=="int")
                    cnt=4;
                if(a=="short")
                    cnt=2;
                if(a=="long")
                    cnt=8;
                point.push_back({cnt,b});
            case 3:
                string s;
                cin>>s;
        }
    }
    cout<<4;
    return 0;
}

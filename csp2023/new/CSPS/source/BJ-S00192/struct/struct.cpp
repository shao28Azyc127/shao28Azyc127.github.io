#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#define fr(xx,yy,zz) for(int xx=yy;xx<=zz;xx++)
#define int long long
#define pt printf
#define pii pair<int,int>
#define pot(x) cout<<#x<<" = "<<x<<"\n";
using namespace std;
const int N=200+33,inf=0x3f3f3f3f;////////////////////////
void rd() {} template<typename T,typename...args>inline void rd(T&x,args&...y) {
    bool f=0;
    char ch=getchar();
    for(; ch<'0'||'9'<ch; ch=getchar())if(ch=='-')f=1;
    for(x=0; '0'<=ch&&ch<='9'; ch=getchar() )x=(x<<1)+(x<<3)+ch-'0';
    if(f)x=-x;
    rd(y...);
}
int n;
struct E {
    string name,type;
};
struct Query {
    int op,cnt;
    long long addr;
    string name,type;
} q[N];
map<string,int> SZ;
vector<E> son(200);
namespace A {
int cnt=0;
class Element {
public:
    int l,r,sz;
    string name;
    void show() {
    }
} ele[N];
map<string,int> ID;

void New(string type,string name) {
    cnt++;
#define Cur ele[cnt]
    Cur.name=name;
    ID[Cur.name]=cnt;
    Cur.l=ele[cnt-1].r+1;
    Cur.sz=SZ[ type ];
    while(Cur.l%Cur.sz!=0)Cur.l++;
    Cur.r=Cur.l+Cur.sz-1;
}
int NewS(int sz,int firstsz,string type) {
    cnt++;
#define Cur ele[cnt]
    Cur.name="ERR";
    ID[type]=cnt;
    Cur.l=ele[cnt-1].r+1;
    Cur.sz=sz;
    while(Cur.l%Cur.sz!=0)Cur.l++;
    Cur.r=Cur.l-1;
    while((Cur.r+1)%firstsz!=0)Cur.r++;
    return Cur.l;
}
void so() {
    ele[0].r=-1;

    fr(i,1,n) {

        cin>>q[i].op;
        if(q[i].op==1) {

            cin>>q[i].type>>q[i].cnt;// Set a ( struct
           // pt("r%d\n",q[i].cnt);
         //   pt("555");
            int sz=0;
            fr(it,1,q[i].cnt) {
                cin>>son[it].type>>son[it].name;
           //     pt("6%d\n",i);
                sz=max(sz,SZ[ son[it].type ]);
            }
          //  pt("666");
          cnt++;
          ele[cnt].l=ele[cnt-1].r+1;
            int End=ele[cnt].l-1;
           // pt("777");
            fr(it,1,q[i].cnt) {
                New(q[i].type+"."+son[it].type,son[it].name);
            }

            cnt++;
            ele[cnt].l=End+1;
            ele[cnt].r=End;
        } else if(q[i].op==2) {

            cin>>q[i].type>>q[i].name;// Set a ( int x
        } else if(q[i].op==3) {

            cin>>q[i].name;//get Address
        } else if(q[i].op==4) {

            cin>>q[i].addr;//get Name
        }


        if(q[i].op==2) {
            New(q[i].type,q[i].name);
        } else if(q[i].op==3) {
            pt("%lld\n",ele[ ID[ q[i].name ] ].l);
        } else if(q[i].op==4) {
            bool ERR=1;
            fr(it,1,cnt) {
                if(ele[it].l<=q[i].addr&&q[i].addr<=ele[it].r) {
                    ERR=0;
                    cout<<ele[it].name<<"\n";
                    break;
                }
            }
            if(ERR) {
                pt("ERR\n");
            }
        }
    }

}
}

signed main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    /*
    byte,short,int,long
    */
    SZ["byte"]=1;
    SZ["short"]=2;
    SZ["int"]=4;
    SZ["long"]=8;
    //ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
//    fr(i,1,n){
//        cin>>q[i].op;

    A::so();

    return 0;
}

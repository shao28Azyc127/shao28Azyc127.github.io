#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
#define pii pair<int,int>
#define p1(A) A.first
#define p2(A) A.second
struct edge{
    int v;
    string nm;
};
vector<edge>SON[110];
map<string,int>mp;
int S[110];
int A[110];
int cnt=4;
inline void calc(int x){
    int now=0;
    for(edge e:SON[x]){
        A[x]=max(A[x],A[e.v]);
        while(now&(A[e.v]-1))now++;
        now+=S[e.v];
    }
    while(now&(A[x]-1))now++;
    S[x]=now;
}
inline int fd(string s){
    vector<string>T;
    string p;
    for(char x:s)
        if(x=='.')T.push_back(p),p.clear();
        else p.push_back(x);
    T.push_back(p);
    int cnt=0;
    int x=0;
    for(string s:T){
        int now=0;
        for(edge e:SON[x]){
            while(now&(A[e.v]-1))now++;
            if(e.nm==s){
                cnt+=now;
                x=e.v;
                break;
            }
            now+=S[e.v];
        }
    }
    return cnt;
}
inline string fd(int loc){
    int x=0;
    string res="";
    while(1){
        if(SON[x].empty())break;
        int p=x;
        int now=0;
        for(edge e:SON[x]){
            while(now&(A[e.v]-1))now++;
            if(now>loc)return ".ERR";
            if(now<=loc&&loc<now+S[e.v]){
                loc-=now;
                res+="."+e.nm;
                x=e.v;
                break;
            }
            now+=S[e.v];
        }
        if(x==p)return ".ERR";
    }
    if(res.empty())return ".ERR";
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("struct3.in","r",stdin);
    //freopen("struct3.out","w",stdout);
    freopen("struct.in","r",stdin);////////////////////////////////////////////////////////
    freopen("struct.out","w",stdout);//remember to update
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=3;
    mp["long"]=4;
    S[1]=A[1]=1;
    S[2]=A[2]=2;
    S[3]=A[3]=4;
    S[4]=A[4]=8;
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int k;
            string nam;
            cin>>nam>>k;
            ++cnt;
            mp[nam]=cnt;
            for(int i=1;i<=k;i++){
                string a,b;
                cin>>a>>b;
                SON[cnt].push_back({mp[a],b});
            }
            calc(cnt);
            cout<<S[cnt]<<" "<<A[cnt]<<endl;
        }
        else if(op==2){
            string a,b;
            cin>>a>>b;
            SON[0].push_back({mp[a],b});
            cout<<fd(b)<<endl;
            //fflush(stdout);
            //return 0;
        }
        else if(op==3){
            string s;
            cin>>s;
            cout<<fd(s)<<endl;
        }
        else{
            int loc;
            cin>>loc;
            string s=fd(loc);
            int k=s.size();
            for(int i=1;i<k;i++)
                cout<<s[i];
            cout<<endl;
        }
    }
    fflush(stdout);
    fflush(stdin);
    cout.flush();
    return 0;
}

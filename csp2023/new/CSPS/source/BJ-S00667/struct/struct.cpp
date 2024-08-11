#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    string c;
    int sz;
};
int n,op,num,lg[105],lst,l[105],r[105],cnt,k,add;
map<string,int> w,mp;
map<string,string> tp;
vector<node> vec[105];
string s,t,nm,is[105];
int big(string type){
    if(type=="byte") return 1;
    if(type=="short") return 2;
    if(type=="int") return 4;
    return 8;
}
bool base(string type){
    if(type=="byte"||type=="short"||type=="int"||type=="long") return 1;
    return 0;
}
bool str(string ss){
    for(int i=0;i<ss.size();i++){
        if(ss[i]=='.') return 1;
    }
    return 0;
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            cin>>s>>k;
            mp[s]=++num;
            int mx=0;
            for(int j=1;j<=k;j++){
                cin>>t>>nm;
                vec[num].push_back({nm,big(t)});
                mx=max(mx,big(t));
            }
            lg[num]=mx*k;
            cout<<lg[num]<<" "<<mx<<endl;
        }
        if(op==2){
            cin>>t>>nm;
            w[nm]=++cnt;
            tp[nm]=t;
            is[cnt]=nm;
            if(base(t)){
                l[cnt]=lst;
                r[cnt]=lst+big(t)-1;
                lst=r[cnt]+1;
            }
            else{
                int pos=mp[t];
                l[cnt]=lst;
                r[cnt]=lst+lg[pos]-1;
                lst=r[cnt]+1;
            }
            cout<<l[cnt]<<endl;
        }
        if(op==3){
            cin>>s;
            if(!str(s)){
                cout<<l[w[s]]<<endl;
            }
            else{
                string s1,s2;
                bool flag=0;
                for(int i=0;i<s.size();i++){
                    if(s[i]=='.') flag=1;
                    else if(!flag) s1+=s[i];
                    else s2+=s[i];
                }
                string type=tp[s1];
                int ty=mp[type];
                int sum=0,ps=w[s1];
                for(int j=0;j<vec[ty].size();j++){
                    if(vec[ty][j].c==s2){
                        cout<<l[ps]+sum<<endl;
                        break;
                    }
                    sum+=vec[ty][j].sz;
                }
            }
        }
        if(op==4){
            bool fl=0;
            cin>>add;
            if(lst<=add){
                cout<<"ERR"<<endl;
                continue;
            }
            for(int j=1;j<=cnt;j++){
                fl=0;
                if(l[cnt]<=add&&r[cnt]>=add){
                    string F=is[cnt];
                    if(base(tp[F])){
                        cout<<F<<endl;
                        fl=1;
                    }
                    else{
                        string type=tp[F];
                        int ps=mp[type],sum=0;
                        for(int pose=0;pose<vec[ps].size();pose++){
                            sum+=vec[ps][pose].sz;
                            if(sum>=add){
                            //  cout<<v<<" "<<sum<<" "<<cnt<<endl;
                              if(!fl){
                                cout<<F<<"."<<vec[ps][pose].c<<endl;

                                fl=1;
                                break;
                              }

                            }
                        }
                        if(fl) break;
                        if(sum<add){
                            cout<<"ERR"<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
ll dir=0;
struct jie{
    string name;
    ll k,sz=0,mx=0,ge=0;
    string t[105],n1[105];
};
map<string,jie>mp;
struct neicun{
    string lei,name;
    ll l;
};
map<string,neicun>mp2;
ll dfs(string s,ll di,string le){
    //cout<<s<<" "<<di<<" "<<le<<endl;
    if(s=="")return di;
    string l;
    int p=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            p=i;
            break;
        }
    }
    l=s.substr(0,p);
    if(p!=s.size())s=s.substr(p+1,s.size()-p-1);
    else s="";
    //cout<<l<<endl;
    for(int j=1;j<=mp[le].k;j++){
        if(mp[le].n1[j]==l){
            return dfs(s,di,mp[le].t[j]);
        }
        di+=mp[le].mx;
    }
}
string ans;
void dfs2(string le,ll di,int adder){
    if(mp[le].k==0){
        return;
    }
    for(int j=1;j<=mp[le].k;j++){
        if(di+mp[le].mx-1>=adder){
            ans+=(mp[le].n1[j]+".");
            dfs(le,di,mp[le].t[j]);
            break;
        }
        di+=mp[le].mx;
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp["byte"].sz=1,mp["byte"].mx=1,mp["byte"].k=0,mp["byte"].ge=1;
    mp["short"].sz=2,mp["short"].mx=2,mp["short"].k=0,mp["short"].ge=1;
    mp["int"].sz=4,mp["int"].mx=4,mp["int"].k=0,mp["int"].ge=1;
    mp["long"].sz=8,mp["long"].mx=8,mp["long"].k=0,mp["long"].ge=1;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            mp[s].k=k;
            for(int j=1;j<=k;j++){
                cin>>mp[s].t[j]>>mp[s].n1[j];
                mp[s].ge++;//problem
                mp[s].mx=max(mp[s].mx,mp[mp[s].t[j]].mx);
            }
            mp[s].sz=mp[s].mx*mp[s].ge;
            cout<<mp[s].sz<<" "<<mp[s].mx<<endl;
        }
        else if(op==2){
            string s,s2;
            cin>>s>>s2;
            mp2[s2].name=s2;
            mp2[s2].lei=s;
            mp2[s2].l=dir;
            cout<<dir<<"\n";
            dir+=mp[mp2[s2].lei].sz;
        }
        else if(op==3){
            string s;
            cin>>s;
            string lll;
            int p=s.size();
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'){
                    p=i;
                    break;
                }
            }
            lll=s.substr(0,p);
            if(p!=s.size())s=s.substr(p+1,s.size()-p-1);
            else s="";
            cout<<dfs(s,mp2[lll].l,mp2[lll].lei)<<endl;
        }
        else{
            ll addr;
            cin>>addr;
            if(addr>=dir)cout<<"ERR\n";
            else{
                ans="";
                for(auto i:mp2){
                    if(i.second.l<=addr&&i.second.l+mp[i.second.lei].sz-1>=addr){
                        //cout<<i.first<<" ";
                        ans+=i.first+".";
                        dfs2(i.second.lei,i.second.l,addr);
                        cout<<ans.substr(0,ans.size()-1)<<"\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

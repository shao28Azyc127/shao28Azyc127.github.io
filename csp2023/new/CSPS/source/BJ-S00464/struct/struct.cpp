#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000000+10;
struct SS{
    string s1,s2;int no;
};
struct sr{
    int sz,q;
    vector<SS>son;
}sr[N];
map<string,int>mp;int mpos=0;
map<int,string>mp2;
map<int,int>mp3;
int num[N],lst,n,kk;
string s;
SS t;
string tstr;

bool cmp(string s1,string s2){
    if(s1.length()>s2.length())return false;
    for(int i=0;i<s1.length();i++)if(s1[i]!=s2[i])return false;
    return true;
}

int calc(string s1,string tstr,int pos){
    int res=0;
    for(auto i:sr[pos].son){
        string tt=tstr+'.'+i.s2;
        //cout<<"\t"<<i.s1<<','<<i.s2<<','<<i.no<<','<<sr[mp[i.s1]].sz<<":  "<<s1<<','<<tt<<','<<res<<endl;
        if(cmp(tt,s1)){
            if(s1==tt)return res;
            return res+calc(s1,tt,mp[i.s1]);
        }
        else res+=sr[mp[i.s1]].sz+i.no;
    }
    return -1e9;
}

string calc2(string tstr,int lst,int pos,int fq){
    //cout<<"!!!!!!!!!!"<<tstr<<","<<lst<<","<<pos<<endl;
    if((pos>4&&sr[pos].sz-lst<sr[pos].son[sr[pos].son.size()-1].no)||(pos<=4&&sr[pos].sz-lst<fq-sr[pos].sz))return "ERR";
    //cout<<"????????"<<endl;
    if(pos<=4)return tstr;
    if(pos<=4)return "ERR";
    for(auto i:sr[pos].son){
        //cout<<"\t\t"<<pos<<","<<lst<<"-->"<<i.s2<<','<<i.no+sr[mp[i.s1]].sz<<endl;
        if(lst>i.no+sr[mp[i.s1]].sz)lst-=i.no+sr[mp[i.s1]].sz;
        else{
            tstr+='.'+i.s2;
            //cout<<"!!!!!!!!!!"<<endl;
            //if(lst==2)return "ERR";
            return calc2(tstr,lst,mp[i.s1],sr[pos].q);
        }
    }
    return "ERR";
}


////////////////////////////////////////////////////////////test////////////////////////////////////////////////////////////


void test(){
    cin>>n;
    mp["btye"]=1,mp["short"]=2,mp["int"]=3,mp["long"]=4;mpos=4;
    sr[1].sz=sr[1].q=1;sr[2].sz=sr[2].q=2;sr[3].sz=sr[3].q=4;sr[4].sz=sr[4].q=8;
    vector<int>tvc;lst=0;int useend=-1;
    while(n--){
        int op;cin>>op;
        if(op==1){
            cin>>s>>kk;
            mp[s]=++mpos;
            sr[mpos].sz=sr[mpos].q=0;
            while(kk--){
                cin>>t.s1>>t.s2;
                sr[mpos].son.push_back(t);
                sr[mpos].q=max(sr[mpos].q,sr[mp[t.s1]].q);
                //cout<<"\t"<<sr[mp[t.s1]].q<<": "<<sr[mpos].q<<endl;
                tvc.push_back(sr[mp[t.s1]].sz);
            }
            //cout<<sr[mpos].q<<endl;return;
            for(int j=0;j<tvc.size();j++){
                int i=tvc[j];
                //cout<<"\t"<<i<<endl;
                sr[mpos].sz+=(i+sr[mpos].q-1)/sr[mpos].q*sr[mpos].q;
                sr[mpos].son[j].no=(i+sr[mpos].q-1)/sr[mpos].q*sr[mpos].q-i;
            }
            cout << sr[mpos].sz <<" "<< sr[mpos].q <<endl;
            tvc.clear();
            //return;
        }else if(op==2){
            cin>>t.s1>>t.s2;
            cout<<useend+1<<endl;useend+=sr[mp[t.s1]].sz;num[++lst]=useend;mp2[lst]=t.s2;mp3[lst]=mp[t.s1];
        }else if(op==3){
            cin>>s;
            for(int i=1;i<=lst;i++){
                if(cmp(mp2[i],s)){
                    tstr=mp2[i];
                    if(s==tstr)cout<<num[i]-sr[mp3[i]].sz+1<<endl;
                    else cout<<num[i]-sr[mp3[i]].sz+1+calc(s,tstr,mp3[i])<<endl;
                    break;
                }
            }
            tstr.clear();
        }else{
            int addr;cin>>addr;
            //cout<<4<<": "<<addr<<endl;
            for(int i=1;i<=lst;i++){
                //cout<<"\t"<<i<<": "<<sr[mp3[i]].sz<<endl;
                if(addr>sr[mp3[i]].sz)addr-=sr[mp3[i]].sz;
                else{
                    tstr=mp2[i];
                    cout<<calc2(tstr,addr,mp3[i],sr[mp3[i]].q)<<endl;
                }
            }
        }
    }
}

signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    test();
    return 0;
}

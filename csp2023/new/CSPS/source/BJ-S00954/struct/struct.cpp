#include<bits/stdc++.h>
using namespace std;
struct struc{
    //long long pos;
    int siz;
    vector<struc> mem;
    vector<string>nam;//name
    int dis;//duiqiyaoqiu
};
unordered_map<string,struc>mp;
struct objc{
    struc st;
    string name;
    int pos;
};
vector<objc>my_mem;
int left_pos[100010];//left pos of each obj in memory
unordered_map<string,int>pos_mem;//pos in vector of binaliang
int getnxtpos(){
    if(my_mem.empty())return 0;
    int sz=my_mem.size();
    sz--;
    return my_mem[sz].pos+my_mem[sz].st.siz-1+1;
}
bool myequal(string s1,string s2){
    if(s1.length()!=s2.length())return 0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i])return 0;
    }return 1;
}
int getaddr(int thispos,struc st,string s){
    string tmp="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            //split
            string tmp2="";
            for(int j=i+1;j<=s.length();j++){
                tmp2+=s[j];
            }
            thispos--;
            struc fd;
            for(int j=0;j<st.nam.size();j++){
                if(tmp==st.nam[j]){
                    fd=st.mem[j];
                    break;
                }
                thispos+=st.dis;
            }
            if(thispos==-1)thispos=0;
            return getaddr(thispos,fd,tmp2);
        }tmp+=s[i];
    }//the last one;
    //thispos--;
    string s2="";
    for(int i=0;i<s.length()-1;i++){
        s2+=s[i];
    }s=s2;
    for(int j=0;j<st.nam.size();j++){
        if(myequal(s,st.nam[j])){
            break;
        }
        thispos+=st.dis;
    }
    return thispos;
}
string search2(struc st,int ad){
    string ans;
    if(st.mem.empty()){
            ans="";
            return ans;
    }
    int i=0;
    for(;i<st.mem.size();i++){
        if(st.dis*(i+1)>ad)break;
    }
    string s=search2(st.mem[i],ad);
    s='.'+st.nam[i];
    return s;
}
void search(string an,int ad,int x){
    objc ob=my_mem[x];
    // i=0;
    //for(;i<ob.st.mem.size();i++){
    //    if(ob.st.dis*(i+1)>ad){
     //       break;
    //    }
    //}
    cout<<an<<search2(ob.st,ad)<<'\n';
}
void findad(int ad){int i=0;
    for(;i<my_mem.size();i++){
        if(my_mem[i].pos>ad){
            break;
        }
    }
    if(i!=0)i--;
    search(my_mem[i].name,ad,i);
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    mp["byte"].siz=1;
    mp["byte"].dis=1;
    mp["int"].siz=mp["int"].dis=4;
    mp["short"].siz=mp["short"].dis=2;
    mp["long"].siz=mp["long"].dis=8;
    for(int _=1;_<=n;_++){
        int op;
        cin>>op;
        if(op==1){
            string s;int k;
            cin>>s>>k;
            struc tmp;
            int dis=0;
            for(int i=1;i<=k;i++){
                string ti,ni;
                cin>>ti>>ni;
                tmp.mem.push_back(mp[ti]);
                tmp.nam.push_back(ni);
                dis=max(dis,mp[ti].dis);
            }
            tmp.dis=dis;
            tmp.siz=dis*k;
            mp[s]=tmp;
            cout<<tmp.siz<<' '<<tmp.dis<<'\n';
        }else if(op==2){
            string t,n;
            cin>>t>>n;
            objc tmp;
            tmp.st=mp[t];
            tmp.name=n;
            int tpos=getnxtpos();
            if(tpos%tmp.st.dis){
                tpos+=tmp.st.dis-tpos%tmp.st.dis;
            }
            tmp.pos=tpos;
            my_mem.push_back(tmp);
            left_pos[my_mem.size()-1]=tmp.pos;
            cout<<tmp.pos<<'\n';
            pos_mem[n]=my_mem.size()-1;
        }else if(op==3){
            string s;
            cin>>s;
            string tmp1="";
            for(int i=0;i<s.length();i++){
                if(s[i]=='.'){
                    string tmp2="";
                    for(int j=i+1;j<s.length();j++){
                        tmp2+=s[j];
                    }
                    cout<<getaddr(my_mem[pos_mem[s]].pos,my_mem[pos_mem[s]].st,tmp2)<<endl;
                    break;
                }
                tmp1+=s[i];
            }
        }else{
            int ad;
            cin>>ad;
            findad(ad);
        }
    }
    return 0;
}

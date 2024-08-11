#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;

const int NMAX=1000+10;

struct Type{
    string name;
    map<string,pair<int,int> > member; //member name and type(int) and position in struct
    vector<int> memv; //type
    vector<string> memname;
    vector<long long> start;
    vector<long long> end;
    //int memCnt;
    long long order;
    long long length;
    bool basic;
};

struct Memory{
    string name;
    int type;
    long long start;
    long long end;
}mem[NMAX];
int memCnt=0;
long long endp=0;

Type types[NMAX];
map<string,int> typeIndex;
map<string,int> memIndex;
int typeCnt=0;

long long cal(long long x,long long y){
    if (x%y==0) return x;
    else return (x/y+1)*y;
}

void opt1(){
    int k;
    cin >> types[typeCnt].name >> k;
    string mtype,mname;
    types[typeCnt].order=0;
    //types[typeCnt].memCnt=k;
    int last=0;
    for (int i=0;i<k;i++){
        cin >> mtype >> mname;
        int mti=typeIndex[mtype];
        types[typeCnt].member[mname]=make_pair(mti,i);
        types[typeCnt].order=max(types[typeCnt].order,types[mti].order);
        types[typeCnt].memv.push_back(mti);
        types[typeCnt].memname.push_back(mname);
        types[typeCnt].start.push_back(cal(last,types[mti].order));
        types[typeCnt].end.push_back(types[typeCnt].start[i]+types[mti].length-1);
        //cout << '*' << types[typeCnt].start[i] << ' ' << types[typeCnt].end[i] << endl;
        last=types[typeCnt].end[i]+1;
    }
    typeIndex[types[typeCnt].name]=typeCnt;
    types[typeCnt].length=cal(last,types[typeCnt].order);
    types[typeCnt].basic=0;
    //cout << '*' << last << ' ' << types[typeCnt].order << endl;
    cout << types[typeCnt].length << ' ' << types[typeCnt].order << endl;
    typeCnt++;
}

void opt2(){
    string type;
    cin >> type >> mem[memCnt].name;
    mem[memCnt].type=typeIndex[type];
    mem[memCnt].start=cal(endp,types[mem[memCnt].type].order);
    mem[memCnt].end=mem[memCnt].start+types[mem[memCnt].type].length-1;
    endp=mem[memCnt].end+1;
    memIndex[mem[memCnt].name]=memCnt;
    cout << mem[memCnt].start << endl;
    memCnt++;
}

void opt3(){
    string s,t;
    cin >> s;
    bool fir=1;
    long long ans=-1;
    int type=-1,ind=-1;
    for (int i=0;i<s.size();i++){
        if (s[i]=='.'){
            //cout << '*' << t << endl;
            if (fir){
                ind=memIndex[t];
                ans=mem[ind].start;
                type=mem[ind].type;
                fir=0;
            }
            else{
                auto p=types[type].member[t];
                ind=p.second;
                ans=ans+types[type].start[ind];
                type=p.first;
            }
            //cout << '&' << ans << ' ' << types[type].name << ' ' << ind << endl;
            t="";
        }
        else t=t+s[i];
    }
    //cout << '*' << t << endl;
    auto p=types[type].member[t];
    ind=p.second;
    ans=ans+types[type].start[ind];
    type=p.first;
    //cout << '&' << ans << ' ' << types[type].name << ' ' << ind << endl;
    cout << ans << endl;
}

void func(int type,long long x,string add){
    //cout << types[type].name << ' ' << x << ' ' << add << endl;
    for (int i=0;i<types[type].memv.size();i++){
        if (types[type].start[i]>x){
            cout << "ERR" << endl;
            return;
        }
        if (types[type].start[i]<=x && types[type].end[i]>=x){
            if (types[types[type].memv[i]].basic){
                cout << add+"."+types[type].memname[i] << endl;
                return;
            }
            func(types[type].memv[i],x-types[type].start[i],
                add+"."+types[type].memname[i]);
            return;
        }
    }
    cout << "ERR" << endl;
}

void opt4(){
    long long x;
    cin >> x;
    for (int i=0;i<memCnt;i++){
        if (mem[i].start>x){
            cout << "ERR" << endl;
            return;
        }
        if (mem[i].start<=x && mem[i].end>=x){
            func(mem[i].type,x-mem[i].start,mem[i].name);
            return;
        }
    }
    cout << "ERR" << endl;
}

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin >> n;
    types[0].name="byte",types[0].length=1,typeIndex["byte"]=0,types[0].basic=1;
    types[1].name="short",types[1].length=2,typeIndex["short"]=1,types[1].basic=1;
    types[2].name="int",types[2].length=4,typeIndex["int"]=2,types[2].basic=1;
    types[3].name="long",types[3].length=8,typeIndex["long"]=3,types[3].basic=1;
    types[0].order=1;
    types[1].order=2;
    types[2].order=4;
    types[3].order=8;
    typeCnt=4;
    for (int i=0;i<n;i++){
        int opt;
        cin >> opt;
        //cout << i << '#' << endl;
        //cerr << opt << endl;
        switch (opt){
            case 1:
                opt1();
                break;
            case 2:
                opt2();
                break;
            case 3:
                opt3();
                break;
            case 4:
                opt4();
                break;
        }
        //cerr << "done" << endl;
    }
    return 0;
}

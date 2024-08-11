#include <bits/stdc++.h>
using namespace std;

#define ISDEBUG 1

// vars
int opcnt;

vector<string> tmpAllOff;
vector<int> tmpAllOffInt;
int tmpptr;

// class CustomStruct
class CS{
public:
    vector<CS> vars;// var index -> type
    vector<int> varsOff;// var index -> offset
    map<string,int> varsMap;// varName -> index
    vector<string> namesMap;// index -> varName
    int length = 0;
    int longest = 0;
    bool isBasic = false;
    string name;
    int ptr;// use in op34
    int offset;// use in op34

    int GetLength();

    CS(int l){
        length = l;
        // default

    }

    CS(){
        // opcode = 1
        GetLength();
    }

    void InitCS();

    void Print();

    void InitOffset(){
        int ptr = 0;
        if(isBasic){
            return;
        }
        for(int i=0;i<vars.size();i++){
            varsOff.push_back(0);
        }
        for(int i=0;i<vars.size();i++){
            varsOff[i] = ptr;
            CS c = vars[i];
            c.InitOffset();
            if(c.isBasic){
                ptr+=longest;
            }
            else{
                ptr+=c.GetLength();
            }
        }
        if(ptr!=GetLength()){
            cout<<"ERR read "<<ptr<<" expected "<<GetLength()<<endl;
        }
    }

    void GetAllOff(string thisNm){
        for(int i=0;i<vars.size();i++){
                CS c = vars[i];
            c.GetAllOff(thisNm+"."+name);
if(c.isBasic){
                tmpptr+=longest;
            }
            else{
                tmpptr+=c.GetLength();
            }
            tmpAllOff.push_back(thisNm+"."+name);
            tmpAllOffInt.push_back(tmpptr);
        }
    }
};



map<string,CS> defs;//jiegouti's name->Cs op2
vector<CS> cvars;
vector<int> cvarsAddr;
map<string,int> cnameMap;//bianliang's name->index //op34
vector<string> cnames;//bianliang's name->index //op34

CS getType(string s){
    CS tttt = defs[s];
    if(tttt.length==0){
        cout<<"ERR type "<<s<<" is not defined";
    }
    return tttt;
}

int CS::GetLength(){
        if(length!=0)
            return length;
        length = 0;
        longest = 0;
        for(int i=0;i<vars.size();i++){
            CS c = vars[i];
            if(c.isBasic && c.GetLength()>longest){
                longest = c.GetLength();
            }
        }
        for(int i=0;i<vars.size();i++){
            length+=longest;
        }
        return length;
    }

void CS::InitCS(){
    int cnt;
        cin>>cnt;
        for(int i=0;i<cnt;i++){
            string tp;
            string name;
            cin>>tp>>name;
            CS qqq = getType(tp);
            this->vars.push_back(qqq);
            // indexing
            this->varsMap[name] = vars.size()-1;
            this->namesMap.push_back(name);
        }

    // init length
    GetLength();
    InitOffset();

    cout<<GetLength()<<" "<<longest<<endl;
}

void CS::Print(){
        if(isBasic){
            cout<<"int"<<length<<endl;
            return;
        }
        for(int i=0;i<vars.size();i++){
            cout<<name<<"="<<GetLength()<<endl;
        }
    }

int main(){
    // default
    #if !ISDEBUG
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    #else
    freopen("struct1.in","r",stdin);
    #endif
    cin>>opcnt;


    // init basic vars
    CS bt = CS(1);
    CS st = CS(2);
    CS it = CS(4);
    CS ln = CS(8);
    bt.length = 1;
    bt.isBasic=true;
    bt.name = "byte";
    st.length = 2;
    st.isBasic=true;
    st.name = "short";
    it.length = 4;
    it.name = "int";
    it.isBasic=true;
    ln.length = 8;
    ln.name = "long";
    ln.isBasic=true;
    defs["byte"] = bt;
    defs["short"] = st;
    defs["int"] = it;
    defs["long"] = ln;


    //op_tools
    for(int i=0;i<opcnt;i++){
        int opcode=0;
        cin>>opcode;
        if(opcode == 1){
            // ding yi jie gou
            string stn;
            cin>>stn;
            CS ntp = CS();
            ntp.name=stn;
            ntp.InitCS();
            defs[stn] = ntp;
        }
        if(opcode == 2){
            // ding yi bian liang
            string tp;
            string nm;
            cin>>tp>>nm;

            // dizhi
            int pt= 0;
            for(CS c:cvars){
                pt+=c.GetLength();
            }
            cout<<pt<<endl;

            CS ctp = getType(tp);
            cvars.push_back(ctp);
            cvarsAddr.push_back(pt);
            cnameMap[nm] = cvars.size()-1;
            cnames.push_back(nm);


        }
        if(opcode == 3){
            // get nei cun di zhi
            // split with .
            vector<string> nav;
            char str[114514];
            char sub[114514];
            cin>>str;
            string aaa = string(str);
            int len =strlen(str);
            int spt = 0;
            for(int i=0;i<len;i++){
                if(str[i]=='.' || i==len-1){
                    string s = string(sub);
                    nav.push_back(s);
                    spt=i+1;
                    for(int i=0;i<len;i++){
                        sub[i]=0;
                    }
                }
                else{
                    sub[i-spt]=str[i];
                }
            }

            // gen ju nav zhao dao di zhi
            int index = cnameMap[nav[0]];
            int dizhi = 0;

        }
        if(opcode == 4){
            // get element name or ERR
            int req = 0;
            cin>>req;
            int index = -1;
            for(int i : cvarsAddr){
                if(req<i){
                    break;
                }
                index++;
            }
            vector<string> nav;
            nav.push_back(cnames[index]);
            cout<<cnames[index]<<".";
            //int ptr = cvarsAddr[index];// ji chu di zhi
            CS ttt = cvars[index];
            ttt.GetAllOff(cnames[index]);
            for(string s : tmpAllOff){
                cout<<s<<endl;
            }
        }
    }
    return 0;
}

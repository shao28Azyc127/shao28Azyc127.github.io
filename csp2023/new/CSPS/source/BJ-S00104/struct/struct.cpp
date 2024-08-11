#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int n;
int stk[111];
string stname[111];
int sttype[111][111];
string stmemname[111][111];
ll stmem[111][111];
int stcnt=0;
int stdq[111];
int stsize[111];
int op;
string varname[111];
string vartype[111];
int vark[111];
ll varmem[111][111][2];
int varcnt;
int mem=0;
void inline solve1(){
    string tmp="";
    int l=0;
    stcnt++;
    cin >> stname[stcnt] >> stk[stcnt];
    for(int i=1;i<=stk[stcnt];i++){
        cin >> tmp >> stmemname[stcnt][i];
        if(tmp=="byte") sttype[stcnt][i]=1;
        else if(tmp=="short") sttype[stcnt][i]=2;
        else if(tmp=="int") sttype[stcnt][i]=4;
        else if(tmp=="long") sttype[stcnt][i]=8;
        stdq[stcnt]=max(stdq[stcnt],sttype[stcnt][i]);
        while(l%sttype[stcnt][i]) l++;
        stmem[stcnt][i]=sttype[stcnt][i]-1;
        l=l+sttype[stcnt][i];
    }
    l--;
    while(l%stdq[stcnt]) l++;
    stsize[stcnt]=l;
    cout << stsize[stcnt] << ' ' << stdq[stcnt] << endl;
}
void inline solve2(){
    varcnt++;
    cin >> vartype[varcnt] >> varname[varcnt];
    int tmpst=0;
    if(vartype[varcnt]=="byte"){
        while(mem%1) mem++;
        vark[varcnt]=1;
        varmem[varcnt][1][0]=varmem[varcnt][1][1]=mem;
        mem+=1;
    }
    else if(vartype[varcnt]=="short"){
        while(mem%2) mem++;
        vark[varcnt]=1;
        varmem[varcnt][1][0]=mem;
        varmem[varcnt][1][1]=mem-1+2;
        mem+=2;
    }
    else if(vartype[varcnt]=="int"){
        while(mem%4) mem++;
        vark[varcnt]=1;
        varmem[varcnt][1][0]=mem;
        varmem[varcnt][1][1]=mem-1+4;
        mem+=4;
    }
    else if(vartype[varcnt]=="long"){
        while(mem%8) mem++;
        vark[varcnt]=1;
        varmem[varcnt][1][0]=mem;
        varmem[varcnt][1][1]=mem-1+8;
        mem+=8;
    }
    else {
        for(int i=1;i<=stcnt;i++){
            if(stname[i]==vartype[varcnt]){
                tmpst=i;
                break;
            }
        }
        vark[varcnt]=stk[tmpst];
        while(mem%stdq[tmpst]) mem++;
        for(int i=1;i<=stk[tmpst];i++){
            while(mem%sttype[tmpst][i]) mem++;
            varmem[varcnt][i][0]=mem;
            varmem[varcnt][i][1]=mem+stmem[tmpst][i];
            mem+=(stmem[tmpst][i]+1);
        }

    }
    cout << varmem[varcnt][1][0] << endl;
    //for(int i=1;i<=stk[tmpst];i++) cout << varmem[varcnt][i][0] << ' ';
    //cout << endl;
}
void inline solve3(){
    string tmp={};
    string ele={};
    string name={};
    bool dot=false;
    cin >> tmp;
    int len=tmp.length();
    int cnt=-1;
    int varbian=0,stbian=0,varnum=0;
    for(int i=0;i<len;i++){
        if(tmp[i]!='.'&&!dot) ele+=tmp[i];
        else if(tmp[i]=='.'){
            dot=true;
            continue;
        }
        else name+=tmp[i];
    }
    for(int i=1;i<=varcnt;i++){
        //for(int i=0;i<=ele.length();i++) cout << ele[i] << ' ';
        //cout << endl;
        if(ele==varname[i]){
            varbian=i;
            break;
        }
    }
    tmp=vartype[varbian];
    for(int i=1;i<=stcnt;i++){
        if(tmp==stname[i]){
            stbian=i;
            break;
        }
    }
    for(int i=1;i<=stk[stbian];i++){
        //cout << stmemname[stbian][i] << ' ' << name << endl;
        if(stmemname[stbian][i]==name){
            varnum=i;
            break;
        }
    }
    if(varnum==0) varnum=1;
    cout << varmem[varbian][varnum][0] << endl;
    //cout << varnum << endl;
}
void inline solve4(){
    ll x;
    cin >> x;
    //cout << varcnt << endl;
    for(int i=1;i<=varcnt;i++){
        //cout << vark[i] << endl;
        for(int j=1;j<=vark[i];j++){
            //cout << i << ' ' << j << ' ' << varmem[i][j][0] << ' ' << varmem[i][j][1] << endl;
            if(varmem[i][j][0]<=x&&varmem[i][j][1]>=x){
                if(vartype[i]=="int"||vartype[i]=="short"||vartype[i]=="byte"||vartype[i]=="long"){
                    cout << varname[i] << endl;
                    return;
                } else {
                    cout << varname[i] << ".";
                    for(int q=1;q<=stcnt;i++){
                        if(stname[q]==vartype[i]){
                            cout << stmemname[q][j] << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "ERR" << endl;
    return;
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
        cin >> op;
        if(op==1){
            solve1();
        }
        if(op==2){
            solve2();
        }
        if(op==3){
            solve3();
        }
        if(op==4){
            solve4();
        }
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct node{
    string name;
    int zj;
    int sum;
    string ct[105];
    string cn[105];
    int cnt=0;
}struc[105];

struct bl{
    string type;
    string name;
    int adr_beg;
    int len;
};

vector<bl>stru;


int n,op,str_num=4;

int get(string a){
    for(int i=1;i<=str_num;i++){
        if(struc[i].name==a)return i;
    }
    return 0;
}
int get2(string a){
    for(int i=1;i<=stru.size();i++){
        if(stru[i].name==a)return i;
    }
    return 0;
}
int get3(string a,node temp){
    for(int i=1;i<=temp.cnt;i++){
        if(temp.cn[i]==a)return i;
    }
    return 0;
}

void op1(){
    str_num++;
    string s;
    int k;
    cin>>s>>k;
    struc[str_num].name=s;
    int maxn=0;
    for(int i=1;i<=k;i++){
        cin>>struc[str_num].ct[i]>>struc[str_num].cn[i];
        maxn=max(maxn,struc[get(struc[str_num].ct[i])].sum);
    }
    struc[str_num].zj=maxn;
    struc[str_num].cnt=k;
    struc[str_num].sum=maxn*k;
    cout<<struc[str_num].sum<<" "<<struc[str_num].zj<<endl;
}

void op2(){
    string t,n;
    cin>>t>>n;
    int adr_now=0;
    for(int i=0;i<stru.size();i++){
        adr_now+=stru[i].len;
    }
    stru.push_back({t,n,adr_now,struc[get(t)].sum});
    cout<<stru.back().adr_beg<<endl;
}

void op3(){
    string a;
    cin>>a;
    string b="";
    int adress=0;
    int dot=0;
    bl temp;
    node tempnode;
    for(int i=0;i<a.length();i++){
        if(a[i]=='.'){
            dot++;
            if(dot==1){
                temp=stru[get2(b)];
                adress+=temp.adr_beg;
                tempnode=struc[get(temp.type)];
            }else{
                adress+=(get3(b,tempnode)-1)*tempnode.zj;
                tempnode=struc[get(tempnode.ct[get3(b,tempnode)])];
                //cout<<tempnode.name<<" "<<adress<<endl;
            }
            b="";
        }
        else b+=a[i];
    }
    adress+=(get3(b,tempnode)-1)*tempnode.zj;
    cout<<adress<<endl;
}

void op4(){
    int addr;
    cin>>addr;
    int i;
    for(i=0;i<stru.size();i++){
        if(addr>=stru[i].len)addr-=stru[i].len;
        else break;
    }
    if(i==stru.size()){cout<<"ERR"<<endl;return;}
    cout<<stru[i].name;
    node temp=struc[get(stru[i].type)];
    while(1){
        for(i=1;i<=temp.cnt;i++){
            if(addr>=temp.zj)addr-=temp.zj;
            else break;
        }
        cout<<"."<<temp.cn[i];
        if(temp.ct[i]=="byte"||temp.ct[i]=="short"||temp.ct[i]=="int"||temp.ct[i]=="long")break;
        temp=struc[get(temp.ct[i])];
    }
    cout<<endl;
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;

    struc[1]={"byte",1,1};
    struc[2]={"short",2,2};
    struc[3]={"int",4,4};
    struc[4]={"long",8,8};

    while(n--){
        cin>>op;
        if(op==1)op1();
        if(op==2)op2();
        if(op==3)op3();
        if(op==4)op4();
    }
    return 0;
}

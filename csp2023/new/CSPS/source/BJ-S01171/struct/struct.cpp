#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int N=110;
const int M=4e6+10;
struct st{
    int len;
    string name;
    int typ[N];
    int lenth;
    string idd[N];
    int fixx;
};
struct sstr{
    st data;
    int spt;
    int ftp;
    int strt;
    string rname;
};
vector<st> a;
vector<sstr> real;
int memr[M];
int n,op,iter;
void ipt1(){scanf("%lld",&n);}
void ipt2(){
    scanf("%lld",&op);
}
void opt1(){
    st tmp;
    cin>>tmp.name;
    scanf("%lld",&tmp.len);
    string ipttt;
    tmp.fixx=0;
    tmp.lenth=0;
    int diif=0;
    for(int i=1;i<=tmp.len;i++){
        cin>>ipttt;
        if(ipttt=="byte") tmp.typ[i]=1,tmp.fixx=max(tmp.fixx,1ll);
        else if(ipttt=="short") tmp.typ[i]=2,tmp.fixx=max(tmp.fixx,2ll);
        else if(ipttt=="int") tmp.typ[i]=4,tmp.fixx=max(tmp.fixx,4ll);
        else if(ipttt=="long") tmp.typ[i]=8,tmp.fixx=max(tmp.fixx,8ll);
        else{
            int len=a.size(),iddx;
            for(int i=0;i<a.size();i++){
                if(a[i].name==ipttt){
                    iddx=i;
                    break;
                }
            }
            tmp.typ[i]=10+iddx;
            tmp.fixx=max(tmp.fixx,a[iddx].fixx);
            diif++;
            tmp.lenth+=a[iddx].lenth;
        }
        cin>>tmp.idd[i];
    }
    tmp.lenth+=(tmp.len-diif)*tmp.fixx;
    a.push_back(tmp);
    printf("%lld %lld\n",tmp.lenth,tmp.fixx);
}
int fixiter(int nowfix,int lenthth){
    while(iter%nowfix!=0&&iter!=0){
        memr[iter]=-1;
        iter++;
    }
    printf("%lld\n",iter);
    int ret=iter;
    for(int i=1;i<=lenthth;i++){
        memr[iter]=1;
        iter++;
    }
    return ret;
}
void opt2(){
    string tt,tn;
    cin>>tt>>tn;
    sstr tmmp;
    tmmp.rname=tn;
    if(tt=="byte"){
        tmmp.spt=1;
        tmmp.ftp=1;
        tmmp.strt=fixiter(1,1);
            real.push_back(tmmp);
        return;
    }
    else if(tt=="short"){
        tmmp.spt=1;
        tmmp.ftp=2;
        tmmp.strt=fixiter(2,2);
            real.push_back(tmmp);
        return;
    }
    else if(tt=="int"){
        tmmp.spt=1;
        tmmp.ftp=4;
        tmmp.strt=fixiter(4,4);
            real.push_back(tmmp);
        return;
    }
    else if(tt=="long"){
        tmmp.spt=1;
        tmmp.ftp=8;
        tmmp.strt=fixiter(8,8);
            real.push_back(tmmp);
        return;
    }
    int len=a.size(),idxdx;
    for(int i=0;i<len;i++){
        if(a[i].name==tt){
            idxdx=i;
            break;
        }
    }
    tmmp.spt=0;
    tmmp.data=a[idxdx];
    tmmp.strt=fixiter(tmmp.data.fixx,tmmp.data.lenth);
        real.push_back(tmmp);
}
void opt3(){
    string s;
    cin>>s;
    int iiid=0;
    int ptr=0;
    string tar="";
    int lene=s.size();
    int fid;
    for(int i=0;i<lene;i++){
        tar+=s[i];
        if(s[i]=='.'||i==lene-1){
            if(iiid==0){
                iiid++;
                int tlen=real.size();
                //cout<<"debug"<<tlen<<endl;
                for(int j=0;j<tlen;j++){
                    //cout<<"debug"<<tar<<i<<real[j].rname<<endl;
                    if(real[j].rname==tar){
                            //cout<<"debug"<<endl;
                        fid=j;
                        break;
                    }
                }
                if(real[fid].spt==1){
                    printf("%lld\n",real[fid].strt);
                    return;
                }
            }
            else{
                st tmmp=real[fid].data;
                int idddx;
                int sum=0;
                for(int j=1;j<=tmmp.len;j++){
                    sum++;
                    if(tmmp.idd[j]==tar){
                        idddx=j;
                        break;
                    }
                }
                if(tmmp.typ[idddx]<10){
                    printf("%lld\n",sum*tmmp.fixx);
                    return;
                }
            }
            tar="";
        }
    }
}
void opt4(){
    int adrr;
    scanf("%lld",&adrr);
    if(memr[adrr]==-1){
        printf("ERR\n");
        return;
    }
    int tlen=real.size();
    for(int i=0;i<tlen;i++){
        //printf("%lld %lld %lld\n",real[i].spt,real[i].strt,real[i].strt+real[i].ftp);
        if(real[i].spt==1&&real[i].strt<=adrr&&real[i].strt+real[i].ftp>=adrr){
            cout<<real[i].rname<<endl;
            return;
        }
    }
}
void solve(){
    if(op==1) opt1();
    else if(op==2) opt2();
    else if(op==3) opt3();
    else if(op==4) opt4();
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ipt1();
    while(n--){
        ipt2();
        solve();
    }
    /*for(int i=0;i<a.size();i++){
        cout<<a[i].name<<",len:"<<a[i].len<<",fixx:"<<a[i].fixx<<",lenth:"<<a[i].lenth<<endl;
        for(int j=1;j<=a[i].len;j++){
            cout<<a[a[i].typ[j]-10].name<<' '<<a[i].idd[j]<<endl;
        }
    }*/
    //for(int i=0;i<iter;i++) printf("%lld ",memr[i]);
    //printf("\n");
    return 0;
}
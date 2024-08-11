#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,cnt,cmn,ope;
map<string,int> a;
map<int,string> fa;
string s,t;
struct node{
    int mem,k,mx;
    string d[105];
    int ml[105],mr[105],t[105];
}wyc[105];
int ys[105];
map<string,int> op;
string fop[105];
string ans;
ll adl[105],lo,adr[105],lx[105];
int flag=1;
void dfs(int jyf,int cz,int wjn){
    if(jyf<0){
        return ;
    }
    int fl=0;
    for(int i=1;i<=wyc[jyf].k;++i){
        if(wyc[jyf].ml[i]<=cz&&wyc[jyf].mr[i]>=cz){
                fl=1;
                ans+=wyc[jyf].d[i];
                ans+=".";
                dfs(wyc[jyf].t[i],cz,1);
                break;
        }
    }
    if(fl==0){
        flag=0;
        return;
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    a["byte"]=-1;
    a["short"]=-2;
    a["int"]=-3;
    a["long"]=-4;
    fa[-1]="byte";
    fa[-2]="short";
    fa[-3]="int";
    fa[-4]="long";
    while(n--){
        cin>>ope;

        if(ope==1){

            ++cnt;

            cin>>s>>wyc[cnt].k;
            a[s]=cnt;
            fa[cnt]=s;
            int tu=0,fi=0;

            for(int i=1;i<=wyc[cnt].k;++i){
                cin>>t>>wyc[cnt].d[i];
                wyc[cnt].t[i]=a[t];
                if(wyc[cnt].t[i]==-1){
                    tu=max(tu,1);
                    wyc[cnt].ml[i]=fi;
                    fi++;
                    wyc[cnt].mr[i]=fi;
                }else if(wyc[cnt].t[i]==-2){
                    tu=max(tu,2);

                    if(fi%2==1){
                        fi+=1;
                        wyc[cnt].ml[i]=fi;
                    }else{
                        wyc[cnt].ml[i]=fi;
                    }
                    fi+=2;
                    wyc[cnt].mr[i]=fi;
                }else if(wyc[cnt].t[i]==-3){
                    tu=max(tu,4);

                    if(fi%4==0){
                        fi+=4;

                    }else{
                        fi=fi/4*4+4;wyc[cnt].ml[i]=fi;
                        fi+=4;
                    }
                    wyc[cnt].mr[i]=fi;
                }else if(wyc[cnt].t[i]==-4){
                    tu=max(tu,8);

                    if(fi%8==0){
                        fi+=8;

                    }else{
                        fi=fi/8*8+8;
                        wyc[cnt].ml[i]=fi;
                        fi+=8;
                    }
                    wyc[cnt].mr[i]=fi;
                }else{
                    tu=max(tu,wyc[wyc[cnt].t[i]].mx);

                    if(fi%wyc[wyc[cnt].t[i]].mx==0){
                            wyc[cnt].ml[i]=fi;
                        fi+=wyc[wyc[cnt].t[i]].mem;

                    }else{
                        fi=fi/wyc[wyc[cnt].t[i]].mx*wyc[wyc[cnt].t[i]].mx+wyc[wyc[cnt].t[i]].mx;
                        wyc[cnt].ml[i]=fi;
                        fi+=wyc[wyc[cnt].t[i]].mem;
                    }
                    wyc[cnt].mr[i]=fi;
                }
                //cout<<a[t]<<" "<<fi<<endl;

            }
            wyc[cnt].mx=tu;
                if(fi%tu==0){
                    wyc[cnt].mem=fi;
                }else{
                    wyc[cnt].mem=fi/tu*tu+tu;
                }
                cout<<wyc[cnt].mem<<" "<<wyc[cnt].mx<<"\n";
        }else if(ope==2){
            cin>>t>>s;
            ++cmn;
            op[s]=cmn;
            fop[cmn]=s;
            if(t=="byte"){
                    lx[cmn]=-1;
                    adl[cmn]=lo;
                 cout<<lo;
                lo++;
            adr[cmn]=lo;
            }else if(t=="short"){
                lx[cmn]=-2;
                if(lo%2==1){
                    ++lo;
                    adl[cmn]=lo;
                    cout<<lo;
                }else{
                    adl[cmn]=lo;
                    cout<<lo;
                }
                lo+=2;
                adr[cmn]=lo;
            }else if(t=="int"){
                lx[cmn]=-3;
                if(lo%4==0){
                        adl[cmn]=lo;
                    cout<<lo;
                }else{
                    lo=lo/4*4+4;
                adl[cmn]=lo;
                    cout<<lo;
                }
                lo+=4;
                adr[cmn]=lo;
            }else if(t=="long"){
                lx[cmn]=-4;
                if(lo%8==0){
                        adl[cmn]=lo;
                    cout<<lo;
                }else{
                    lo=lo/8*8+8;
                adl[cmn]=lo;
                    cout<<lo;
                }
                lo+=8;
                adr[cmn]=lo;
            }else{
                 int ls=a[t];
                 lx[cmn]=ls;
                 if(lo%wyc[ls].mx==0){
                    adl[cmn]=lo;
                    cout<<lo;
                 } else{
                    lo=lo/wyc[ls].mx*wyc[ls].mx+wyc[ls].mx;
                    adl[cmn]=lo;
                    cout<<lo;
                 }
                 lo+=wyc[ls].mem;
                 adr[cmn]=lo;
            }
            cout<<"\n";
        }
        else if(ope==3){
            cin>>s;
            t="";
            int fla=1;
            int tfl=0,tfk;

            for(int i=0;i<s.size();++i){
                if(s[i]=='.'){
                        if(tfl==0&&fla){
                            tfl=adl[op[t]];
                            tfk=lx[op[t]];
                            fla=0;
                            //tfr=mr[op[t]];
                        }else{
                            for(int i=1;i<=wyc[tfk].k;++i){
                                if(wyc[tfk].d[i]==t){
                                        tfl+=wyc[tfk].ml[i];
                                    tfk=wyc[tfk].t[i];

//cout<<t<<" "<<tfl<<" "<<endl;
                                    break;
                                }
                            }
                        }
                    t="";
                continue;
                }
                t+=s[i];


            }
            //
            if(tfl==0&&fla){
                    tfl=adl[op[t]];
                    tfk=lx[op[t]];
                            //tfr=mr[op[t]];
            }else{
                for(int i=1;i<=wyc[tfk].k;++i){
                    if(wyc[tfk].d[i]==t){
                            tfl+=wyc[tfk].ml[i];
                        tfk=wyc[tfk].t[i];

                        //cout<<t<<" "<<tfk<<" "<<endl;
                        break;
                    }
                }
            }

            cout<<tfl<<"\n";
        }

        else{
            int addr;
            cin>>addr;
            int wy=1;
            //if(addr==42) cout<<"ccf"<<endl;
            for(int i=1;i<=cmn;++i){

                if(adl[i]<=addr&&adr[i]>=addr){
                    wy=0;
                    ans=fop[i];
                    ans+=".";
                    flag=1;
                    dfs(lx[i],addr,1);
                    if(flag==0){
                        cout<<"ERR";
                    }else{
                        for(int j=0;j<int(ans.size())-1;++j){
                            cout<<ans[j];
                        }
                    }
                    cout<<"\n";

                   break;
                }
            }
            if(wy==1){
                cout<<"ERR\n";
            }
        }
    }
    return 0;
}

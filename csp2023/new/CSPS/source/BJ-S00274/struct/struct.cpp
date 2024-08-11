#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
struct S{
    int spc;
    int cnte;
    int maxe;
    int tp[105];
    int poi[105];
    string na[105];
    int fas;
}stru[105];
map<string,int> m;
map<string,int> ts[105];
map<string,int> em;
map<int,string> eb;
struct E{
    int spc;
    int tp;
    int poi;
    int fas;
}elm[100005];
void wrte(int x){
    if(elm[x].fas!=0){
        wrte(elm[x].fas);
        cout<<'.'<<x;
    }else{
        cout<<eb[x];
    }
}
void fid(int x,int la,string s){
    //cout<<"E"<<eb[x]<<' ';
    int now=la;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            //cout<<"S"<<stru[elm[x].tp].poi[ts[elm[x].tp][s.substr(0,i)]]<<' ';
            now+=stru[elm[x].tp].poi[ts[elm[x].tp][s.substr(0,i)]];
            //cout<<s.substr(0,i)<<' ';
            fid(ts[x][s.substr(0,i)],now,s.substr(i+1,s.size()-i-1));
            return;
        }
    }
    cout<<la+stru[elm[x].tp].poi[ts[elm[x].tp][s]]<<endl;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    //ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int scnt=0;
    int sec=0;
    int spoi=0;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            scnt++;
            string s;
            int k;
            cin>>s>>k;
            m[s]=scnt;
            int smax=0;
            int poi=0;
            for(int j=1;j<=k;j++){
                stru[scnt].cnte++;
                string tp;
                cin>>tp;
                cin>>stru[scnt].na[stru[scnt].cnte];
                ts[scnt][stru[scnt].na[stru[scnt].cnte]]=stru[scnt].cnte++;
                if(tp=="byte"){
                    stru[scnt].tp[stru[scnt].cnte]=poi;
                    stru[scnt].tp[stru[scnt].cnte]=1;
                    smax=max(smax,1);
                    poi+=1;
                }else if(tp=="short"){
                    stru[scnt].tp[stru[scnt].cnte]=poi;
                    stru[scnt].tp[stru[scnt].cnte]=2;
                    smax=max(smax,2);
                    if(poi%2!=0){
                        poi+=1;
                    }
                    poi+=2;
                }else if(tp=="int"){
                    stru[scnt].tp[stru[scnt].cnte]=poi;
                    stru[scnt].tp[stru[scnt].cnte]=3;
                    smax=max(smax,4);
                    if(poi%4!=0){
                        poi+=4-(poi%4);
                    }
                    poi+=4;
                }else if(tp=="long"){
                    stru[scnt].tp[stru[scnt].cnte]=poi;
                    stru[scnt].tp[stru[scnt].cnte]=4;
                    smax=max(smax,8);
                    if(poi%8!=0){
                        poi+=8-(poi%8);
                    }
                    poi+=8;
                }else{
                    stru[scnt].tp[stru[scnt].cnte]=poi;
                    stru[scnt].tp[stru[scnt].cnte]=4+m[tp];
                    smax=max(smax,stru[m[tp]].maxe);
                    if(poi%stru[m[tp]].maxe!=0){
                        poi+=stru[m[tp]].maxe-(poi%stru[m[tp]].maxe);
                    }
                    poi+=stru[m[tp]].spc;
                }
                //cout<<"p"<<poi<<endl;
            }
            if(poi%smax!=0){
                poi+=smax-(poi%smax);
            }
            stru[scnt].spc=poi;
            stru[scnt].maxe=smax;
            cout<<stru[scnt].spc<<' '<<smax<<endl;
        }

        if(op==2){
            cout<<spoi<<endl;
            sec++;
            string t;
            string n;
            cin>>t>>n;
            em[n]=sec;
            eb[sec]=n;
            elm[sec].poi=spoi;
            if(t=="byte"){
                elm[sec].tp=1;
                elm[sec].spc=1;
                elm[sec].poi=spoi;
                spoi+=1;
            }else if(t=="short"){
                elm[sec].tp=2;
                if(spoi%2!=0){
                    spoi+=1;
                }
                elm[sec].spc=2;
                elm[sec].poi=spoi;
                spoi+=2;
            }else if(t=="int"){
                elm[sec].tp=3;
                if(spoi%4!=0){
                    spoi+=4-(spoi%4);;
                }
                elm[sec].spc=4;
                elm[sec].poi=spoi;
                spoi+=4;
            }else if(t=="long"){
                elm[sec].tp=4;
                if(spoi%8!=0){
                    spoi+=8-(spoi%8);
                }
                elm[sec].spc=4;
                elm[sec].poi=spoi;
                spoi+=8;
            }else{
                if(spoi%stru[m[t]].maxe!=0){
                    spoi+=stru[m[t]].maxe-(spoi%stru[m[t]].maxe);
                }
                elm[em[t]].fas=sec;
                elm[sec].spc=stru[m[t]].spc;
                elm[sec].poi=spoi;
                spoi+=stru[m[t]].spc;
                //cout<<"S"<<stru[m[t]].spc<<' ';
            }
            //cout<<spoi<<endl;
        }

        if(op==3){
            string s;
            cin>>s;
            //cout<<s<<endl;
            bool flag=0;
            for(int j=0;j<s.size();j++)
                if(s[j]=='.'){
                    flag=1;
                    break;
                }
            if(!flag){
                cout<<elm[em[s]].poi<<endl;
                continue;
            }
            for(int j=0;j<s.size();j++){
                if(s[j]=='.'){
                    //cout<<"S"<<s.substr(0,j)<<endl;
                    fid(em[s.substr(0,j)],0,s.substr(j+1,s.size()-j-1));
                    break;
                }
            }
        }
    }
    //long long
    return 0;
}

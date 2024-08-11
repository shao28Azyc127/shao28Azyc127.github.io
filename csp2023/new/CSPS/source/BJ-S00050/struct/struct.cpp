#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
int n,op,k,cnt=4,yscnt;
long long zhy[205]={0,1,2,4,8};
int dq[205]={0,1,2,4,8};
string s,nm[205]={"","byte","short","int","long"},cym,bl;
vector<int>gc[205];// leixing bianhao
vector<string>gm[205];//chengyvan mingcheng
vector<pair<int,int> >zy[205];//zhanyong jvti kong jian
int kjz,qs;
pair<long long,long long>cc[205];
int tp[205],tm;
string t,blm[205];
long long cq(long long ys,int d){
    if(ys%d==0)return ys;
    return ys+d-ys%d;
}
int fd(string str){
    int a=str.length();
    for(int i=0;i<a;i++)
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    gc[1].push_back(1);
    gc[2].push_back(2);
    gc[3].push_back(3);
    gc[4].push_back(4);
    while(n--){
        cin>>op;
        if(op==1){
            kjz=0;
            qs=0;
            cnt++;
            cin>>s>>k;
            nm[cnt]=s;
            for(int i=1;i<=k;i++){
                cin>>cym>>bl;
                for(int j=1;j<cnt;j++){
                    if(nm[j]==cym){
                        qs=kjz+dq[j]-kjz%dq[j];
                        if(kjz%dq[j]==0)qs=kjz;
                        gc[cnt].push_back(j);
                        dq[cnt]=max(dq[cnt],dq[j]);
                        zy[cnt].push_back(make_pair(qs,qs+zhy[j]-1));
                        kjz=qs+zhy[j];
                        break;
                    }
                }
                gm[i].push_back(bl);
            }
            if(kjz%dq[cnt]==0)zhy[cnt]=kjz;
            else zhy[cnt]=kjz+dq[cnt]-kjz%dq[cnt];
            cout<<zhy[cnt]<<' '<<dq[cnt]<<endl;
        }
    }
    return 0;
}

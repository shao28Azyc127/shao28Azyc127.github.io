#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<string,int> m,ss,id;//���룬ռ�ռ䣬��a.name���
map<string,pair<long long,long long> > re;//��mm���
struct num{//�ṹ�壨����1��
    string name;
    vector<string> v;//����
    vector<string> p;//����
    int dc;//����
    int sp;//�ռ�
}a[105];
struct dy{//����������2��
    string name;//����
    string ty;//����
    int dc;//����
    int sp;//�ռ�
}b[105];
map<pair<long long,long long>,string> mm;//������ʼ�볤�ȣ�����·��
int main(){
    ios::sync_with_stdio(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    m["byte"]=1;
    m["short"]=2;
    m["int"]=4;
    m["long"]=8;
    ss["byte"]=1;
    ss["short"]=2;
    ss["int"]=4;
    ss["long"]=8;
    int n;
    cin>>n;
    int cnt=0;
    int ct=0;
    long long fi=0;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            int k;
            cin>>a[++cnt].name>>k;
            int maxn=0;
            long long sum=0;
            for(int i=1;i<=k;i++){
                string tp1,tp2;
                cin>>tp1>>tp2;
                a[cnt].v.push_back(tp1);
                a[cnt].p.push_back(tp2);
                maxn=max(maxn,m[tp1]);
                sum+=ss[tp1];
            }
            a[cnt].dc=maxn;
            m[a[cnt].name]=maxn;
            a[cnt].sp=maxn*k;
            ss[a[cnt].name]=maxn*k;
            id[a[cnt].name]=cnt;
            cout<<maxn*k<<' '<<maxn<<'\n';
        }
        if(op==2){
            string t,nn;
            cin>>t>>nn;
            b[++ct].name=nn;
            b[ct].sp=m[t];
            b[ct].ty=t;
            b[ct].dc=ss[t];
            cout<<fi<<'\n';
            if(t!="byte"&&t!="int"&&t!="short"&&t!="long"){
                int d=id[t];
                for(int i=0;i<a[d].v.size();i++){
                    pair<long long,long long> p;
                    p.first=fi;
                    fi+=a[d].dc;
                    p.second=a[d].dc;
                    string ttp=nn;
                    ttp+='.';
                    ttp+=a[d].p[i];
                    mm[p]=ttp;
                    re[ttp]=p;
                }
            }
            else{
                pair<long long,long long> p;
                p.first=fi;
                fi+=m[t];
                p.second=m[t];
                mm[p]=nn;
                re[nn]=p;
            }
        }
        if(op==3){
            string r;
            cin>>r;
            cout<<re[r].first<<'\n';
        }
        if(op==4){
                long long abbr;
        cin>>abbr;
        bool su=false;
            for(auto i=mm.begin();i!=mm.end();i++){
                auto pp=*i;
                if(pp.first.first<=abbr&&pp.first.first+pp.first.second>=abbr){
                    cout<<pp.second<<'\n';
                    su=true;
                }
                if(pp.first.first>abbr){
                    break;
                }
            }
            if(!su){
                cout<<"ERR\n";
            }
        }
    }
    return 0;
}
/*rp+=inf*/

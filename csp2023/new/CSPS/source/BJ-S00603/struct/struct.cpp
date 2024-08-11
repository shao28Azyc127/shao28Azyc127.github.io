#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
struct Tao{
    int gz,siz;
    vector<pair<int,string> >q;//<id,name>
    vector<pair<int,int> >q_stat;//l,r
    int len;
    string nam;
}tao[N];
int tao_len=4;
map<string,int>tao_id;
struct Ele{
    int type;
    int l,r;
    string nam;
}ele[N];
int ele_cnt;
map<string,int>ele_id;
int now_size=0;
bool cmp(string s1,string s2){
    int len1=s1.size(),len2=s2.size();
    if(len1!=len2)return 0;
    for(int i=0;i<len1;i++){
        if(s1[i]!=s2[i])return 0;
    }
    return 1;
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    tao[1].gz=tao[1].siz=1;//byte
    tao[2].gz=tao[2].siz=2;//short
    tao[3].gz=tao[3].siz=4;//int
    tao[4].gz=tao[4].siz=8;//long
    tao[1].nam="byte";
    tao[2].nam="short";
    tao[3].nam="int";
    tao[4].nam="long";
    tao_id["byte"]=1;
    tao_id["short"]=2;
    tao_id["int"]=3;
    tao_id["long"]=4;
    while(n--){
        int op;
        scanf("%lld",&op);
        if(op==1){
            tao_len++;
            string s;
            cin>>s;
            tao[tao_len].nam=s;
            tao_id[s]=tao_len;
            int k;
            scanf("%lld",&k);
            int nowl=0;
            int max_x=0;
            for(int j=1;j<=k;j++){
                string t,nam;
                cin>>t>>nam;
                int id=tao_id[t];
                int gz=tao[id].gz,siz=tao[id].siz;
                max_x=max(max_x,tao[id].gz);
                nowl+=((-nowl)%gz+gz)%gz;
                tao[tao_len].q_stat.push_back(make_pair(nowl,nowl+siz-1));
                tao[tao_len].q.push_back(make_pair(id,nam));
                nowl=nowl+siz;
            }
            nowl+=((-nowl)%max_x+max_x)%max_x;
            tao[tao_len].siz=nowl;
            tao[tao_len].gz=max_x;
            tao[tao_len].len=k;
            cout<<nowl<<" "<<max_x<<"\n";
        }
        if(op==2){
            string taoo,nam;
            cin>>taoo>>nam;
            ele_cnt++;
            ele_id[nam]=ele_cnt;
            ele[ele_cnt].nam=nam;
            ele[ele_cnt].type=tao_id[taoo];
            int gz=tao[ele[ele_cnt].type].gz,siz=tao[ele[ele_cnt].type].siz;
            now_size+=((-now_size)%gz+gz)%gz;
            ele[ele_cnt].l=now_size;
            ele[ele_cnt].r=now_size+siz-1;
            now_size+=siz;
            cout<<ele[ele_cnt].l<<"\n";
        }
        if(op==3){
            string s;
            cin>>s;
            s+='.';
            int len=s.size();
            string t;
            t.clear();
            bool flag=0;
            int sum=0;
            int now_strid;
            for(int i=0;i<len;i++){
                if(s[i]=='.'){
                    if(!flag){
                        sum=ele[ele_id[t]].l;
                        now_strid=ele[ele_id[t]].type;
                    }
                    else{
                        for(int j=0;j<tao[now_strid].len;j++){
                            if(cmp(tao[now_strid].q[j].second,t)){
                                sum+=tao[now_strid].q_stat[j].first;
                                now_strid=tao[now_strid].q[j].first;
                                break;
                            }
                        }
                    }
                    t.clear();
                    flag=1;
                }
                else{
                    t+=s[i];
                }
            }
            cout<<sum<<"\n";
        }
        if(op==4){
            int pos;
            scanf("%lld",&pos);
            int now_strid=0;
            string ans;
            for(int i=1;i<=ele_cnt;i++){
                if(ele[i].r>=pos){
                    if(ele[i].l>pos){
                        break;
                    }
                    else{
                        int sizz=ele[i].nam.size();
                        for(int j=0;j<sizz;j++){
                            ans+=ele[i].nam[j];
                        }
                        pos-=ele[i].l;
                        now_strid=ele[i].type;
                        break;
                    }
                }
            }
            if(!now_strid){
                cout<<"ERR\n";
                continue;
            }
            if(now_strid<=4){
                int lenn=ans.size();
                for(int i=0;i<lenn;i++){
                    cout<<ans[i];
                }
                cout<<"\n";
                continue;
            }
            else{
                while(1){
                    if(now_strid<=4){
                        int lenn=ans.size();
                        for(int i=0;i<lenn;i++){
                            cout<<ans[i];
                        }
                        cout<<"\n";
                        break;
                    }
                    bool flag=0;
                    for(int i=0;i<tao[now_strid].len;i++){
                        //cout<<tao[now_strid].q_stat[i].first<<" "<<tao[now_strid].q_stat[i].second<<" ??\n";
                        if(tao[now_strid].q_stat[i].second>=pos){
                            if(tao[now_strid].q_stat[i].first>pos){
                                break;
                            }
                            else{
                                flag=1;
                                int sizz=tao[now_strid].q[i].second.size();
                                ans+='.';
                                for(int j=0;j<sizz;j++){
                                    ans+=tao[now_strid].q[i].second[j];
                                }
                                pos-=tao[now_strid].q_stat[i].first;
                                now_strid=tao[now_strid].q[i].first;
                                break;
                            }
                        }
                    }
                    if(!flag){
                        cout<<"ERR\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
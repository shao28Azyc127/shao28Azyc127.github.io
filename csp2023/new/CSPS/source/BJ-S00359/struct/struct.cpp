#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<string,ll> mp;//��¼ÿһ�����͵�ռ���ڴ�
unordered_map<string,ll> mpp;//��¼ÿһ�����͵Ķ���Ҫ��
struct node{
    string kd,nm;
    ll st;
};
unordered_map<string,vector<node> > mp1;//��¼ÿһ�������¶�Ӧÿһ�����ͼ�����
unordered_map<string,ll> mp2;//��Ŀ¼��ÿ����������ʼ�±�
unordered_map<string,unordered_map<string,int> > mp3;//ÿ��������ÿ�������ı��
unordered_map<string,string> mp4;//��Ŀ¼��ÿ������������
ll wh=0,tot=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp["byte"]=mpp["byte"]=1,mp["short"]=mpp["short"]=2,mp["int"]=mpp["int"]=4,mp["long"]=mpp["long"]=8;
    int q; cin>>q;
    while(q--){
        int o; scanf("%d",&o);
        if(o==1){
            string kd; ll t;
            cin>>kd>>t;
            ll mx=0;
            for(int i=0;i<t;i++){
                string k,nm; cin>>k>>nm;
                mx=max(mx,mpp[k]);
                mp1[kd].push_back({k,nm,0});
                mp3[kd][nm]=i;
            }
            ll sum=mp[mp1[kd].back().kd];
            mp1[kd][0].st=0;
            for(int i=1;i<t;i++){
                mp1[kd][i].st=mp1[kd][i-1].st+mp[mp1[kd][i-1].kd],sum+=mp[mp1[kd][i-1].kd];
                while(mp1[kd][i].st%mpp[mp1[kd][i].kd]) mp1[kd][i].st++,sum++;
            }
            while(sum%mx) sum++;
            mpp[kd]=mx;
            mp[kd]=sum;
            cout<<sum<<" "<<mx<<"\n";
        }
        else if(o==2){
            string k,nm; cin>>k>>nm;
            mp1[""].push_back({k,nm});
            cout<<wh<<"\n";
            mp2[nm]=wh,wh+=mp[k],mp4[nm]=k;
        }
        else if(o==3){
            string s; cin>>s;
            int sl=s.size(); ll ans=-1;
            string ts=""; string now="";
            for(int i=0;i<=sl;i++){
                if(i==sl){
                    if(ans==-1) ans=0;
                    //cout<<now<<" "<<ts<<" "<<mp3[now][ts]<<" "<<mp1[now][mp3[now][ts]].st<<"\n";
                    cout<<ans+mp1[now][mp3[now][ts]].st<<"\n";
                }
                else if(s[i]=='.'){
                    if(ans==-1) ans=0,ans+=mp2[ts],now=mp4[ts];
                    else ans+=mp1[now][mp3[now][ts]].st,now=mp1[now][mp3[now][ts]].kd;
                    ts="";
                }
                else ts=ts+s[i];
            }
        }
        else{
            ll x; scanf("%lld",&x);
            if(x>=wh){
                puts("ERR");
                continue;
            }
            string now; ll mx=-1;
            for(auto it:mp2){
                if(it.second<=x && mx<it.second) mx=it.second,now=it.first;
            }
            string ans="";
            ans+=now,x-=mx;
            now=mp4[now]; bool ok=0;
            while(now!="int"&&now!="short"&&now!="byte"&&now!="long"){
                ll l=0,r=mp1[now].size()-1,id;
                while(l<=r){
                    ll mid=(l+r)>>1;
                    if(mp1[now][mid].st<=x) id=mid,l=mid+1;
                    else r=mid-1;
                }
                if(mp1[now][id].st+mp[mp1[now][id].kd]<=x){
                    puts("ERR"); ok=1;
                    break;
                }
                ans+=".";
                ans+=mp1[now][id].nm;
                x-=mp1[now][id].st;
                now=mp1[now][id].kd;
            }
            if(ok) continue;
            cout<<ans;
            puts("");
        }
    }
    return 0;
}


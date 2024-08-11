#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
struct cls
{
    vector<int> mbt;
    vector<long long> mp;
    map<string,int> mbn;
    vector<string> mbrn;
    long long sz,aln;
};
//typ对应tpid,obj和offset对应vid
cls typ[102];
int obj[102];//object type
long long offset[102];//object start of memory
//string tpid[102],vid[102];
map<string,int> tpid,vid;
string varid[102];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int typcnt=4,objcnt=0;
    tpid["byte"]=1;
    typ[1].sz=typ[1].aln=1;
    tpid["short"]=2;
    typ[2].sz=typ[2].aln=2;
    tpid["int"]=3;
    typ[3].sz=typ[3].aln=4;
    tpid["long"]=4;
    typ[4].sz=typ[4].aln=8;
    for(int i=1;i<=4;i++)
        typ[i].mp.push_back(0);
    vector<int> pos;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            cin>>s;
            int k;
            cin>>k;
            typcnt++;
            tpid[s]=typcnt;
            long long cur=0;
            for(int i=1;i<=k;i++)
            {
                string typ_name,mbr_name;
                cin>>typ_name>>mbr_name;
                typ[typcnt].mbt.push_back(tpid[typ_name]);
                typ[typcnt].mbrn.push_back(mbr_name);
                typ[typcnt].mbn[mbr_name]=typ[typcnt].mbt.size()-1;
                if(cur!=0)
                    cur=(cur-1)/typ[tpid[typ_name]].aln+1;
                cur*=typ[tpid[typ_name]].aln;
                typ[typcnt].mp.push_back(cur);
                cur+=typ[tpid[typ_name]].sz;
                typ[typcnt].aln=max(typ[typcnt].aln,typ[tpid[typ_name]].aln);
            }
            cur=(cur-1)/typ[typcnt].aln+1;
            cur*=typ[typcnt].aln;
            typ[typcnt].sz=cur;
            cout<<typ[typcnt].sz<<' '<<typ[typcnt].aln<<endl;
            // for(int i=0;i<typ[typcnt].mp.size();i++)
            //     cout<<typ[typcnt].mp[i]<<' ';
            // cout<<endl;
        }
        else if(op==2)
        {
            string typ_name,obj_name;
            cin>>typ_name>>obj_name;
            objcnt++;
            obj[objcnt]=tpid[typ_name];
            offset[objcnt]=offset[objcnt-1]+typ[obj[objcnt-1]].sz;
            vid[obj_name]=objcnt;
            varid[objcnt]=obj_name;
            cout<<offset[objcnt]<<endl;
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            pos.clear();
            for(int i=0;i<s.length();i++)
                if(s[i]=='.')   pos.push_back(i);
            // for(int i=0;i<pos.size();i++)
            //     cout<<pos[i]<<' ';
            // cout<<endl;
            string obj_name=s.substr(0,pos[0]);
            long long addr=offset[vid[obj_name]];
            pos.push_back(s.length());
            string mbr_name;
            int typid=obj[vid[obj_name]];
            for(int i=0;i<pos.size()-1;i++)
            {
                mbr_name="";
                for(int j=pos[i]+1;j<pos[i+1];j++)
                    mbr_name.append(1,s[j]);
                //cout<<mbr_name<<endl;
                int mbid=typ[typid].mbn[mbr_name];
                addr+=typ[typid].mp[mbid];
                typid=typ[typid].mbt[mbid];
            }
            cout<<addr<<endl;
        }
        else
        {
            long long addr;
            cin>>addr;
            int obj_id=0;
            for(int i=1;i<objcnt;i++)
                if(offset[i]<=addr && addr<offset[i+1])    obj_id=i;
            if(obj_id==0)
            {
                if(addr<offset[objcnt]+typ[obj[objcnt]].sz)
                    obj_id=objcnt;
                else
                {
                    cout<<"ERR"<<endl;
                    continue;
                }
            }
            //cout<<obj_id<<endl;
            addr-=offset[obj_id];
            string ans;
            ans.append(varid[obj_id]);
            bool flag=1;
            int typid=obj[obj_id];
            //cout<<typid<<endl;
            while(addr>0 && typid>4)
            {
                //cout<<addr<<endl;
                int mbr_id=-1;
                for(int i=0;i<typ[typid].mbt.size()-1;i++)
                {
                    if(typ[typid].mp[i]<=addr && addr<typ[typid].mp[i+1])
                    {
                        mbr_id=i;
                        break;
                    }
                }
                if(mbr_id==-1)
                {
                    int mbcnt=typ[typid].mp.size();
                    if(addr<typ[typid].mp[mbcnt-1]+typ[typ[typid].mbt[mbcnt-1]].sz)
                        mbr_id=mbcnt-1;
                    else
                    {
                        cout<<"ERR"<<endl;
                        flag=0;
                        break;
                    }
                }
                //cout<<mbr_id<<endl;
                addr-=typ[typid].mp[mbr_id];
                //cout<<typid<<endl;
                ans.push_back('.');
                //cout<<ans<<endl;
                ans.append(typ[typid].mbrn[mbr_id]);
                //cout<<ans<<endl;
                typid=typ[typid].mbt[mbr_id];
            }
            if(flag)
                cout<<ans<<endl;
        }
    }
    return 0;
}
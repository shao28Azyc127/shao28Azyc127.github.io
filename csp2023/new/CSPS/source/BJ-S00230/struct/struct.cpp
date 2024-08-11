#include<bits/stdc++.h>
using namespace std;
struct aStruct {
    unordered_map<string,pair<long long,long long> > cr;
    long long sz, mreq;
    aStruct () {
        sz = 0;
        mreq = 0;
    }
};
unordered_map<string,aStruct> curr;
long long n,brd = 0;
unordered_map<string,pair<long long,aStruct> > variables;
vector<pair<long long,string> > variablenames;
int main () {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    aStruct tmp;
    tmp.sz = 1;
    tmp.mreq = 1;
    curr["byte"] = tmp;
    aStruct tmp2;
    tmp2.sz = 2;
    tmp2.mreq = 2;
    curr["short"] = tmp2;
    aStruct tmp3;
    tmp3.sz = 4;
    tmp3.mreq = 4;
    curr["int"] = tmp3;
    aStruct tmp4;
    tmp4.sz = 8;
    tmp4.mreq = 8;
    curr["long"] = tmp4;
    for(long long i = 0; i < n; i++) {
        long long op;
        cin >> op;
        if(op == 1) {
            long long k;
            aStruct currStruct;
            string s;
            cin >> s >> k;
            string typ,nm;
            for(long long j = 0; j < k; j++) {
                cin >> typ >> nm;
                long long cR = 0;
                if(j > 0) cR = currStruct.sz+1;
                long long tmp = (cR/curr[typ].mreq)*curr[typ].mreq;
                if(cR%curr[typ].mreq != 0) tmp += curr[typ].mreq;
                currStruct.cr[nm].first = tmp;
                currStruct.cr[nm].second = tmp+curr[typ].sz-1;
                currStruct.sz = tmp+curr[typ].sz-1;
                currStruct.mreq = max(currStruct.mreq,curr[typ].mreq);
            }
            if(currStruct.sz%currStruct.mreq != 0) currStruct.sz += currStruct.mreq;
            currStruct.sz = ((currStruct.sz)/currStruct.mreq)*currStruct.mreq;
            curr[s] = currStruct;
            cout << currStruct.sz << " " << currStruct.mreq << endl;
        }
        if(op == 2) {
            string typ,nm;
            cin >> typ >> nm;
            aStruct cS = curr[typ];
            long long cR = brd;
            if(cR%cS.mreq != 0) cR += cS.mreq;
            cR = (cR/cS.mreq)*cS.mreq;
            cout << cR << endl;
            brd = cR+curr[typ].sz;
            variables[nm] = make_pair(cR,cS);
            variablenames.push_back(make_pair(cR,typ));
        }
        if(op == 3) {
            string pth;
            cin >> pth;
            cout << variables[pth].first << endl;
        }
        if(op == 4) {
            long long addr;
            cin >> addr;
            long long lP = 0;
            while(lP < variablenames.size() && addr >= variablenames[lP].first) lP++;
            lP--;
            if(lP == -1) cout << "ERR" << endl;
            else {
                long long tlp = variablenames[lP].first;
                long long trp = variablenames[lP].first+curr[variablenames[lP].second].sz-1;
                if(addr >= tlp && addr <= trp) cout << variablenames[lP].second << endl;
                else cout << "ERR" << endl;
            }
        }
    }
    return 0;
}

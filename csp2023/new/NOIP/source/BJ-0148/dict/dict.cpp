#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
int n,m;
string s;
int maxs[6011][3011],mins[3011][3011];
deque<int> q;//mininum
bool inline cmpsmall(int a,int b){//maxs[a]<=maxs[b] return true;
    for(int i=1;i<=m;i++){
        if(maxs[a][i]>maxs[b][i]) return false;
        if(maxs[a][i]<maxs[b][i]) return true;
    }
    return true;
}
bool inline cmpbig(int a,int b){//mins[a]>=maxs[b] return true;
    for(int i=1;i<=m;i++){
        if(mins[a][i]<maxs[b][i]) return false;
        if(mins[a][i]>maxs[b][i]) return true;
    }
    return true;
}
bool inline cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            maxs[i][j+1]=mins[i][j+1]=s[j]-'a';
        }
        sort(mins[i]+1,mins[i]+m+1);
        sort(maxs[i]+1,maxs[i]+m+1,cmp);
        for(int j=1;j<=m;j++){
            maxs[n+i][j]=maxs[i][j];
        }
    }
    for(int i=1;i<=2*n-1;i++){
        while(!q.empty()&&q.front()<=i-n+1) q.pop_front();
        while(!q.empty()&&cmpsmall(i,q.back())){
            //cout << i << ' ' << q.back() << endl;
            q.pop_back();
        }
        q.push_back(i);
        if(i-n+1>=1){
            //cout << i << ' ' << i-n+1 << ' ' << q.front() << endl;
            if(cmpbig(i-n+1,q.front())) cout << 0;
            else cout << 1;
        }
    }
    cout << endl;

	return 0;
}
//passed sample(passed biggest)

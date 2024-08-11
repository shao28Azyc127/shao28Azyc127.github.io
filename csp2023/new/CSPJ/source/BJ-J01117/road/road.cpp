#include<iostream>
using namespace std;
int d[100005],m[100005],mn[100005],mni[100005],use[100005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,k,s = 0;
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        cin >> d[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> m[i];
    }
    mn[0] = 2147483647;
    m[0] = 2147483647;
    for(int i = 1; i < n; i++){
        if(mn[i-1] < m[i]){
            mni[i] = mni[i-1];
        }
        else{
            mni[i] = i;
        }
        mn[i] = min(mn[i-1],m[i]);
        //cout << mn[i] << " " << mni[i] << endl;
    }

    //for(int i = 1; i < n; i++){
    //    use[mni[i]] += d[i];
    //}
    int r = 0;
    for(int i = 1; i < n; i++){
        int add;
        int dis = d[i]-r;
        if(dis%k == 0){
            add = dis/k*m[i];
            r = 0;
        }
        else{
            add = (((int)(dis/k))+1)*m[mni[i]];
            r = ((int)(dis/k)+1)*k-dis;
        }
        //cout << add << endl;
        s += add;
    }
    cout << s;

    return 0;
}

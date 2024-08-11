#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct node{
    int i1,i2,i3,i4,i5;
};
node p[10];

bool check(node a,int j){
    vector<int>diff;
    int pa[5] = {p[j].i1,p[j].i2,p[j].i3,p[j].i4,p[j].i5},aa[5] = {a.i1,a.i2,a.i3,a.i4,a.i5};
    for(int i = 0; i < 5; i++){
        if(pa[i] != aa[i]){
            diff.push_back(i+1);
        }
    }
    //cout << diff.size() << endl;
    if(diff.size() == 1){
        return 1;
    }
    if(diff.size() == 2){
        int a = diff[0],b = diff[1];
        if(abs(a-b) == 1 && ((pa[a-1]+10 - aa[a-1])%10 == (pa[b-1]+10 - aa[b-1])%10)){
            return 1;
        }
        return 0;
    }
    return 0;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].i1 >> p[i].i2 >> p[i].i3 >> p[i].i4 >> p[i].i5;
    }
    int s = 0;
    for(int i1 = 0; i1 < 10; i1++){
        for(int i2 = 0; i2 < 10; i2++){
            for(int i3 = 0; i3 < 10; i3++){
                for(int i4 = 0; i4 < 10; i4++){
                    for(int i5 = 0; i5 < 10; i5++){
                        int cnt = 0;
                        for(int j = 0; j < n; j++){
                            if(check((node){i1,i2,i3,i4,i5},j)){
                                cnt++;
                            }
                        }
                        s += (cnt==n);
                    }
                }
            }
        }
    }
    cout << s;

    return 0;
}

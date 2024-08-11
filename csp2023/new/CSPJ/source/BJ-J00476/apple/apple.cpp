#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
int day;
vector<int> a;
vector<int> b;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        a.push_back(i);
    }
    int i=0;
    while(!a.empty()) {
        i++;
        b.clear();
        int k=0;
        for(int j=0;j<a.size();j++) {
            if(a[k]==n) {
                day=i;
            }
            if(k==j)
            {
                k+=3;
            }
            else
            {
                b.push_back(a[j]);
            }
        }
        a.clear();
        for(int j=0;j<b.size();j++) {
            a.push_back(b[j]);
        }
    }
    cout<<i<<" "<<day;
    return 0;
}

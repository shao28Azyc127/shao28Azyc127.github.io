#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int n;
int corr[11][5];
int incorr[82][5];
int poss;
bool mark[82];
int main() {
     freopen("lock.in","r",stdin);
     freopen("lock.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<5;j++) {
            cin>>corr[i][j];
        }
    }

    /*
    n=1;
    corr[0][0]=0;
    corr[0][1]=0;
    corr[0][2]=corr[0][3]=1;
    corr[0][4]=5;
    */
    int t[5];
    for(int i=0;i<5;i++) {
        for(int j=1;j<=9;j++) {
            for(int k=0;k<5;k++) {
                t[k]=corr[0][k];
            }
            t[i]+=j;
            t[i]%=10;
            for(int k=0;k<5;k++) {
                //cout<<t[k]<<" ";
                incorr[poss][k]=t[k];
            }
            //cout<<endl;
            poss++;
        }
    }
    for(int i=0;i<4;i++) {
        for(int j=1;j<=9;j++) {
            for(int k=0;k<5;k++) {
                t[k]=corr[0][k];
            }
            t[i]+=j;
            t[i]%=10;
            t[i+1]+=j;
            t[i+1]%=10;
            for(int k=0;k<5;k++) {
                //cout<<t[k]<<" ";
                incorr[poss][k]=t[k];
            }
            //cout<<endl;
            poss++;
        }
    }
    for(int l=1;l<n;l++) {
        for(int i=0;i<5;i++) {
            for(int j=1;j<=9;j++) {
                for(int k=0;k<5;k++) {
                    t[k]=corr[l][k];
                }
                t[i]+=j;
                t[i]%=10;
                for(int m=0;m<81;m++) {
                    if(t[0]==incorr[m][0] &&
                       t[1]==incorr[m][1] &&
                       t[2]==incorr[m][2] &&
                       t[3]==incorr[m][3] &&
                       t[4]==incorr[m][4]) {
                        mark[m]=1;
                    }
                }
                //cout<<endl;
            }
        }
        for(int i=0;i<4;i++) {
            for(int j=1;j<=9;j++) {
                for(int k=0;k<5;k++) {
                    t[k]=corr[l][k];
                }
                t[i]+=j;
                t[i]%=10;
                t[i+1]+=j;
                t[i+1]%=10;
                for(int m=0;m<81;m++) {
                    if(t[0]==incorr[m][0] &&
                       t[1]==incorr[m][1] &&
                       t[2]==incorr[m][2] &&
                       t[3]==incorr[m][3] &&
                       t[4]==incorr[m][4]) {
                        mark[m]=1;
                    }
                }
                //cout<<endl;
            }
        }
        for(int i=0;i<81;i++) {
            if(!mark[i] && incorr[i][0]!=-1) {
                for(int j=0;j<5;j++) {
                    incorr[i][j]=-1;
                }
                poss--;
            }
        }
    }
    cout<<poss<<endl;
    /*
    for(int i=0;i<81;i++) {
        if(incorr[i][0]==-1) {
            continue;
        }
        for(int j=0;j<5;j++) {
            cout<<incorr[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}

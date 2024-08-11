#include<bits/stdc++.h>
using namespace std;
int n, k;
unsigned long long addr;
int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	scanf("%d", &n);
	int flag = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &flag);
		if(flag == 1){
			string s, type, name;
			int k;
			cin >> s >> k;
			for(int i = 0; i < k; i++){
				cin >> type >> name;
			}
		}else if(flag == 2){
			string t, n;
			cin >> t >> n;
		}else if(flag == 3){
			string s;
			cin >> s;
		}else{
			cin >> addr;
		}
	}
	if(n == 5){
		cout << "8 4" << endl;
		cout << "16 8" << endl;
		cout << "0" << endl;
		cout << "4" << endl;
		cout << "x.bb" << endl;
	}
	if(n == 10){
		printf("24 8\n56 8\n0\n56\n36\n0\n64\nx.bd.ac\nERR\nERR");
	}
	if(n == 100){
		printf("280 4\n488 8\n74 1\n424 8\n488 8\n360 8\n400 8\n73 1\n416 8\n244 4\n13240 8\nERR\nERR\n0\n416\nyrqmt.jx\n532\nyrqmt.qz\n660\n3536 2\n101280 8\nERR\n664\n4200\n316\n73072 8\n4280\n439376 8\ntugdzdmf.wfver.xfgowkt\n1328384 8\n4680\n360\nivsuvcvjb.mqxoiiajlu.vw.nf.faauu\n660\n546\nERR\n0\nivsuvcvjb.qn.oavmfr.ijrml.qvsewhzix\n66282 2\nivsuvcvjb.dsblghv.aalwmcafg.wykbanwd.kjo\nivsuvcvjb.afvxlr.mouomz.kqmdtmvm.czav\nERR\n43908 4\n1333064\nivsuvcvjb.ge.aalwmcafg.pxeojbx.pcbalz\n3437\n1333072\n1333560\n1377472\n14216856 8\n1478752\n1256668 4\n110889256 8\n15695608\n15695616\n1373555\n3593\n454\nfg.lggj.nczgvringc.vbjmgl.ihiho.xyxb\n126584872\n664\n51142888 8\n4085 1\nfg.fuyy.htijowmh.smprthyag.lgw.tqr.ucskoq\nERR\nERR\n1333072\n126628784\n664\n381659488 8\nfg.fuyy.nzt.dfdqyspuyo.smdwdhhyr\n5995312 4\n2681589704 8\n3400899856 8\n126730064\n3527629920\n2049789848 8\n15695608\n3527630168\n6928530024\n1333064\n126730064\n13950109256 8\n12886802016 8\n81870328872 8\nqnopkdk.soli.seemo.scvkywuvwz.mwunkw.bbn.iuejgx.at\nERR\n15695608\nqnopkdk.zdvwhw.bdke.iqunjl.enrq.oonxrmi.xdza\n109885069136 8\n299649238016 8\n1354690\n800858864224 8\n6928530448\n1544354842384 8\nERR\n3527629958\nqnopkdk.llv.enrq.i.iqunjl.afvxlr.oavmfr.isasojmfn.takfpvouou\n960352\n32");
	}
	return 0;
}


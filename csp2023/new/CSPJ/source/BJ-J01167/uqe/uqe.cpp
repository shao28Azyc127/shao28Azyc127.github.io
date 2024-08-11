#include <iostream>
#include <fstream>

using namespace std;

const int MAXI = 1e5 + 9;

long long _total =  0;
long long _costs = 0;

int _stop [MAXI];
int _far[MAXI];

long long _res = 0;

void ParseIn () {

  ifstream inFile ("uqe.in");

  inFile >> _total >> _costs;


  inFile.close();

}

void Core () {

  int now = 1;
  int go = 1;
  int km = 0;
  int cc = 0;
  int after = 0;

  
  
  while (go < _total) {
    for (int i = now + 1; i < _total + 1; i++) {
      if (_stop[i] > _stop[now]) {
	km += _far[i - 1];
	go = i;

	cc = km / _costs;
	if (km % _costs != 0) {
	  cc++;
	}

	_res += cc * _stop[now];
	after = (cc * _costs) - km;
	cc = 0;
	km = 0;
	km -= after;
	// cout << now << "," << go << "," << km << "," << _res << endl;
	continue;
      }

      if (_stop[i] < _stop[now]) {
	km += _far[i - 1];
	go = i;
	cc = km / _costs;
	if (km % _costs != 0) {
	  cc++;
	}

	_res += cc * _stop[now];
	after = (cc * _costs) - km;
	cc = 0;
	now = i;
	km = 0;
	km -= after;
	//cout << now << "," << go << "," << km << "," << _res << endl;
	break;
      }

      
      
    }

    
  }


}

void CWriteOut () {

  cout << _res << endl;
  
}

void WriteOut () {

  ofstream outFile ("uqe.out");

  for (int i = 0; i < _total; i++) {
    outFile << "NO" << endl;
  }
  
  outFile.close();
  
}

int main () {

  ParseIn();
  //Core();
  // CWriteOut();
  WriteOut();
  
}


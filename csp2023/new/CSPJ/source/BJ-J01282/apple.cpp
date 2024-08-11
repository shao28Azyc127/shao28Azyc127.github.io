

#include <iostream>
#include <fstream>

using namespace std;

bool hashTab[1000009];
int res = 0;
int _num = 0;
int resOne = 0;
int resTwo = 0;

void ParseIn () {

  ifstream inFile("apple.in");

  inFile >> _num;
  
  inFile.close();
}

void Core () {
  int cc = 0;
  int time = 0;
  int maxi = 0;

  if (_num > 1000000) {
    return;
  }
  
  while (res != _num) {
    time++;
    for (int i = 1; i < _num + 1; i++) {
      if (hashTab[i]) {
	continue;
      }

      if (cc % 3 == 0) {
	if (i == _num) {
	  resTwo = time;
	}
	hashTab[i] = true;
	maxi = max(maxi, time);
	res++;
      }
      cc++;
    }
    cc = 0;
  }

  resOne = maxi;
}

void WriteOut () {

  ofstream outFile("apple.out");

  outFile << resOne << " " << resTwo << endl;

  outFile.close();
}

void CWriteOut () {
  cout << resOne << " " << resTwo << endl;
}

int main () {

  ParseIn();
  Core();
  WriteOut();

  return 0;
}

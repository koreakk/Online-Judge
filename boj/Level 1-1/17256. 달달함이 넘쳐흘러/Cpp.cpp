#include <iostream>
using namespace std;

int main(void) {
	int ax, ay, az;
	int cx, cy, cz;
	
	cin >> ax >> ay >> az;
	cin >> cx >> cy >> cz;
	
	// az + bx = cx
	int bx = cx - az;
	
	// ay * by = cy
	int by = cy / ay;
	
	// ax + bz = cz
	int bz = cz - ax;
	
	cout << bx << ' ' << by << ' ' << bz << endl; 
	
	return 0;
}
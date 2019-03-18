#include "../include/dice.h"
#include <iostream>
using namespace std;
int main(){
	set_rand();
	cout << roll(6) << endl;
	return 0;
}
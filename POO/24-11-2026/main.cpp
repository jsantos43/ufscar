#include <iostream>
#include "vetor.h"
using namespace std;

int main(void) {
	vetor<int> vetorInt;
	vetorInt.SetValor(0, 1);
	vetorInt.SetValor(1, 2);
	vetorInt.SetValor(2, 3);
	vetorInt.SetValor(3, 4);
	vetorInt.SetValor(4, 5);

	vetor<double> vetorDouble;
	vetorDouble.SetValor(0, 1.1);
	vetorDouble.SetValor(1, 2.2);
	vetorDouble.SetValor(2, 3.3);
	vetorDouble.SetValor(3, 4.4);
	vetorDouble.SetValor(4, 5.5);

	vetor<char> vetorChar;
	vetorChar.SetValor(0, 'a');
	vetorChar.SetValor(1, 'b');
	vetorChar.SetValor(2, 'c');
	vetorChar.SetValor(3, 'd');
	vetorChar.SetValor(4, 'e');

	int valorInt;
	double valorDouble;
	char valorChar;

	for (int index {0}; index < 5; index++) {
		vetorInt.GetValor(index, valorInt);
		vetorDouble.GetValor(index, valorDouble);
		vetorChar.GetValor(index, valorChar);


		cout << "Vetor INT[" << index << "]: " << valorInt << endl;
		cout << "Vetor DOUBLE[" << index << "]: " << valorDouble << endl;
		cout << "Vetor CHAR[" << index << "]: " << valorChar << endl;
	}


  return 0;
}


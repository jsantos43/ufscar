#include <iostream>
using namespace std;

template <typename T>

void printArray(T* Ptr, int tam) {
  for (int index = 0; index < tam; index++) {
    cout << "V[" << index << "]: " << Ptr[index] << endl;
  }
}

int main(void) {
  int tamanho;

  cout << "Digite o tamanho do vetor:";
  cin >> tamanho;

  int *vetorIntPtr = new int[tamanho];

  for (int index = 0; index < tamanho; index++) {
    cout << "Digite o elemento int[" << index << "]: ";
    cin >> vetorIntPtr[index];
  }

  printArray(vetorIntPtr, tamanho);

  delete [] vetorIntPtr;

  cout << endl << endl;

  double *vetorDoublePtr = new double[tamanho];

  for (int index = 0; index < tamanho; index++) {
    cout << "Digite o elemento double[" << index << "]: ";
    cin >> vetorDoublePtr[index];
  }

  printArray(vetorDoublePtr, tamanho);

  delete [] vetorDoublePtr;

  cout << endl << endl;

  double *vetorCharPtr = new double[tamanho];

  for (int index = 0; index < tamanho; index++) {
    cout << "Digite o elemento char[" << index << "]: ";
    cin >> vetorCharPtr[index];
  }

  printArray(vetorCharPtr, tamanho);

  delete [] vetorCharPtr;

  return 0;
}

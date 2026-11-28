#ifndef VETOR_H
#define VETOR_H

#include <iostream>

template <typename T>
class vetor {
   private:
      int tam;
      T* ptrvalores;
   public:
      vetor(int=10);
      ~vetor();
      int get_tamanho() const;
      bool SetValor(int pos, T val);
      bool GetValor(int pos, T& val) const;
      void imprime() const;
};

template <typename T>
vetor<T>::vetor(int t) {
   if (t > 0) tam = t;
   else tam = 10;

   ptrvalores = new T[tam];

   for (int i=0;i<tam;i++) {
      SetValor(i,T());
   }
}

template <typename T>
vetor<T>::~vetor() {
   delete [] ptrvalores;
}

template <typename T>
int vetor<T>::get_tamanho() const {
   return tam;
}

template <typename T>
bool vetor<T>::SetValor(int pos, T val) {
   if (pos >=0 && pos < tam) {
      ptrvalores[pos] = val;
      return true;
   } else return false;
}

template <typename T>
bool vetor<T>::GetValor(int pos, T& val) const {
   if (pos >= 0 && pos < tam) {
      val = ptrvalores[pos];
      return true;
   } else return false;
}

template <typename T>
void vetor<T>::imprime() const {
   T valor;
   for (int i=0;i<get_tamanho();i++) {
      GetValor(i, valor);
      std::cout << valor << " ";
   }

   std::cout << std::endl;
}

#endif

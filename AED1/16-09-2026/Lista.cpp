#include "Lista.h"

Lista::Lista() {
  primeiro = nullptr;
  atual = nullptr;
}

bool Lista::ler_primeiro(char &elemento) {
  atual = primeiro;
  return ler_proximo(elemento);
}

bool Lista::ler_proximo(char &elemento) {
  if (atual == nullptr) return false;
  elemento = atual->dado;
  atual = atual->next;

  return true;
}

bool Lista::vazia() {
  return (primeiro == nullptr);
}

bool Lista::existe(char procurado) {
  Node* p = primeiro;
  
  while (p != nullptr) {
    if (p->dado == procurado) return true;

    if (procurado < p->dado) return false;

    p = p->next;
  }

  return false;
}

bool Lista::inserir(char elemento_novo) {
  if (existe(elemento_novo)) return false;

  Node* novo = new Node{elemento_novo, nullptr};

  if (primeiro == nullptr || elemento_novo < primeiro->dado) {
    novo->next = primeiro;
    primeiro = novo;
    return true;
  }

  Node* ant = primeiro;
  while (ant->next != nullptr && ant->next->dado < elemento_novo) {
    ant = ant->next;
  }

  novo->next = ant->next;
  ant->next = novo;
  return true;
}

bool Lista::remover(char procurado) {
  if (primeiro == nullptr) return false;

  if (primeiro->dado == procurado) {
    Node* aux = primeiro;
    primeiro = primeiro->next;
    delete aux;
    return true;
  }

  Node* ant = primeiro;
  while (ant->next != nullptr && ant->next->dado != procurado) {
    ant = ant->next;
  }

  if (ant->next == nullptr) return false;

  Node* aux = ant->next;
  ant->next = aux->next;
  delete aux;
  return true;
}
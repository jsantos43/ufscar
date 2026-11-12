#include "ABB.h"

Node* criaNode(int value) {
  Node* no = new Node{value, nullptr, nullptr};

  return no;
}

bool insere(Node*& R, int value) {
  // Caso 1: Nó vazio
  if (R == nullptr) {
    R = criaNode(value);
    return true; 
  } 
  
  // Caso 2: Valor do Nó igual
  if (R->value == value) {
    return false;
  }

  // Caso 3: Valor a inserir menor que o do nó
  if (value < R->value) {
    return insere(R->left, value);
  }

  // Caso 4: Valor a inserir maior que o do nó
  if (value > R->value) {
    return insere(R->right, value);
  }

  return false;
}

Node* busca(Node* R, int value) {
  // Caso 1: Vazio
  if (R == nullptr) {
    return nullptr;
  }

  // Caso 2: Achou
  if (R->value == value) {
    return R;
  }

  // Caso 3: Valor procurado menor que o do nó
  if (value < R->value) {
    return busca(R->left, value);
  }

  // Caso 4: Valor procurado maior que o do nó
  if(value > R->value) {
    return busca(R->right, value);
  }

  return nullptr;
}

bool existe(Node* R, int value) {
  return busca(R, value) != nullptr;
}

bool vazia(Node* R) {
  return R == nullptr;
}

Node* criaRaiz() {
  return nullptr;
}

bool remove(Node*& R, int value) {
  // Caso 1: Nó está vazio
  if (R == nullptr) {
    return false;
  }

  // Caso 2: Valor a remover menor que o do nó
  if (value < R->value) {
    return remove(R->left, value);
  }

  // Caso 3: Valor a remover maior que o do nó
  if (value > R->value) {
    return remove(R->right, value);
  }

  // Caso 4: Achou, nó com 0 ou 1 filho
  if (R->left == nullptr || R->right == nullptr) {
    Node* aux = R;
  
    R = (R->left != nullptr) ? R->left : R->right;

    delete aux;
    return true;
  }

  // Caso 5: Achou, nó com 2 filhos (usa o sucessor)
  // Procura o menor valor da subárvore direita
  Node* suc = R->right;
  while (suc->left != nullptr) {
    suc = suc->left;
  }

  // Copia o valor do sucessor para o nó
  R->value = suc->value;

  // Remove o sucessor duplicado na subárvore direita
  return remove(R->right, suc->value);
}

void lista(Node* R) {
  if (R != nullptr) {
    std::cout << R->value << " ";
    lista(R->left);
    lista(R->right);
  }
}
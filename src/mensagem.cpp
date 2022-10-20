#include "mensagem.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

Mensagem::Mensagem (){
  setConteudo("0");
  setPrioridade(-1);
}

Mensagem::Mensagem (string conteudo, int prioridade){
	if (prioridade > 9 || prioridade < 0)
		throw "Prioridade inválida, insira um número entre 9 e 0!";
  setConteudo(conteudo);
  setPrioridade(prioridade);
}

string Mensagem::getConteudo(){
  return this->conteudo;
}

void Mensagem::imprimeConteudo(){
  cout << this->conteudo << endl;
}

void Mensagem::setConteudo(string novo){
  this->conteudo = novo;
}

int Mensagem::getPrioridade(){
  return this->prioridade;
}

void Mensagem::setPrioridade(int nova){
  this->prioridade = nova;
}

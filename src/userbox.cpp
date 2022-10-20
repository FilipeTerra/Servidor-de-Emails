#include <stdexcept>
#include <iostream>
#include "userbox.hpp"
#include "mensagem.hpp"

userBox::userBox(){
	setId(-1);
	setTam(-1);
	this->primeiro = new TipoMensagem();
	this->ultimo = this->primeiro;
}

userBox::userBox(int id){
	this->ID = id;
	this->tam = 0;
	this->primeiro = new TipoMensagem();
	this->ultimo = this->primeiro;
}

userBox::~userBox(){
	Limpa();
	this->primeiro = NULL;
}

void userBox::inserePosicao(Mensagem msg){
	TipoMensagem* aux, *nova;
	nova = new TipoMensagem();
	if (this->tam == 0){
		nova->msg = msg;
		nova->prox = primeiro->prox;
		primeiro->prox = nova;
	}
	else{
		aux = Posiciona(msg.getPrioridade());
		nova->msg = msg;
		nova->prox = aux->prox;
		aux->prox = nova;
	}
	
	this->tam++;

	if (nova->prox == NULL)
		ultimo = nova;
}

void userBox::removeInicio(){
	TipoMensagem* aux;
	
	if (this->tam == 0)
		throw "ERRO: Lista de emails vazia!";
	
	aux = primeiro->prox;
	primeiro->prox = aux->prox;
	this->tam--;
	
	if(primeiro->prox == NULL)
		ultimo = primeiro;
	
	delete aux;
}

TipoMensagem* userBox::Posiciona(int prioridade){
	TipoMensagem* aux = new TipoMensagem();
	aux = this->primeiro;
	
	if (prioridade > 9 || prioridade < 0)
		throw "ERRO: Prioridade inválida!";
	
	for (int i = 1; i <= this->tam; i++){
		if (prioridade <= aux->prox->msg.getPrioridade()){
			aux = aux->prox;
		}
		else{
			return aux;
		}
	}
	return aux;
}

int userBox::getTam(){
	return this->tam;
}

void userBox::Limpa(){
	TipoMensagem* aux;
	aux = this->primeiro->prox;

	while(aux != NULL){
		this->primeiro->prox = aux->prox;
		delete aux;
		aux = this->primeiro->prox;
	}
	this->ultimo = this->primeiro;
	this->tam = 0;
}

void userBox::leMsg(){
	if (this->tam == 0 || this->tam == -1)
		cout << "Caixa de entrada vazia!";
	else
		this->primeiro->prox->msg.imprimeConteudo();
}

void userBox::setId(int id){
	this->ID = id;
}

int userBox::getId(){
	return this->ID;
}

void userBox::setTam(int tam){
	this->tam = tam;
}
#include "mailContainer.hpp"

mailContainer::mailContainer(){
	this->tam = 0;
	this->primeiro = new TipoMailBox();
	this->ultimo = this->primeiro;
}

mailContainer::~mailContainer(){
	Limpa();
	this->primeiro = NULL;
}

void mailContainer::Limpa(){
	TipoMailBox *aux = new TipoMailBox();
	aux = primeiro->prox;
	
	while (aux != NULL){
		primeiro->prox = aux->prox;
		delete aux;
		aux = primeiro->prox;
	}
	
	this->ultimo = this->primeiro;
	this->tam = 0;
}

bool mailContainer::consultaID(int id){
	TipoMailBox* aux = new TipoMailBox();
	aux = this->primeiro->prox;
	bool existe = false;
	for (int i = 1; i <= this->tam; i++){
		if (aux->mailBox->getId() == id)
			existe = true;
		else 
			aux = aux->prox;
		}
	return existe;		
}

void mailContainer::removeID(int id){
	TipoMailBox *p, *q;

	if (consultaID(id)){
		p = Posiciona(id);
		q = p->prox;
		p->prox = q->prox;
		tam--;
		delete q;
		
		if (p->prox == NULL)
			ultimo = p;

		cout << "OK: CONTA " << id << " REMOVIDA" << endl;
	}
	else
		cout << "ERRO: CONTA ID " << id << " NÃO EXISTE" << endl;
}

void mailContainer::insereID(int id){
	if (id < 0 || id > 1000000)
		cout << "ERRO: VALOR PARA ID IRREGULAR" << endl;
	
	TipoMailBox *aux = new TipoMailBox();
	aux = this->primeiro;
	
	for (int i = 1; i <= this->tam; i++){
		aux = aux->prox;
		if (aux->mailBox->getId() == id){
			cout << "ERRO: CONTA " << id << " JÁ EXISTENTE" << endl;
			break;
		}
	}
	
	TipoMailBox *nova = new TipoMailBox();
	nova->mailBox = new userBox(id);
	nova->prox = primeiro->prox;
	primeiro->prox = nova;
	
	this->tam++;
	
	if(nova->prox == NULL)
		ultimo = nova;

	cout << "OK: CONTA " << id << " CADASTRADA" << endl;
}

int mailContainer::getTam(){
	return this->tam;
}

void mailContainer::consultaMsg(int id){
	if (consultaID(id)){
		TipoMailBox *aux = primeiro->prox;
		for (int i = 1; i <= tam; i++){
			if (id == aux->mailBox->getId()){
				if (aux->mailBox->getTam() == 0 || aux->mailBox->getTam() == -1){
					cout << "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA" << endl;
					break;
				}
				else {
					cout << "CONSULTA " << id << ": ";
					aux->mailBox->leMsg();
					aux->mailBox->removeInicio();
					break;
				}
			}
			else
				aux = aux->prox;
		}
	}
	else
		cout << "ERRO: CONTA " << id << " NÃO EXISTE" << endl;
}

void mailContainer::entregaMsg(int id, int prioridade, string conteudo){
	if (consultaID(id)){
		TipoMailBox* aux = this->primeiro;
		for (int i = 1; i <= tam; i++){
			aux = aux->prox;
			if (aux->mailBox->getId() == id){
				Mensagem msg = Mensagem(conteudo, prioridade);				
				aux->mailBox->inserePosicao(msg);
				cout << "ENTREGA " << id << " " << prioridade << ": " << conteudo << endl;
			}
		}
	}
	else
		cout << "ERRO: CONTA " << id << " NÃO EXISTE" << endl;
}

TipoMailBox* mailContainer::Posiciona(int id){
	TipoMailBox* aux = new TipoMailBox();
	aux = this->primeiro;
	for (int i = 1; i <= this->tam; i++){
		if (aux->prox->mailBox->getId() == id){
			return aux;
		}
		else{
			aux = aux->prox;
		}
	}
	return aux;
}
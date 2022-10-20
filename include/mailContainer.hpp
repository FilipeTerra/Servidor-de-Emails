#pragma once

#include "tipoMailBox.hpp"
#include <iostream>

class mailContainer{
  private:
		int tam;
		TipoMailBox* primeiro;
		TipoMailBox* ultimo;

  public:
		// construtor
		mailContainer();
		// destrutor
		~mailContainer();
		// boleano para sair se o ID existe ou não dentro da lista
    bool consultaID(int id);
		// procura e remove ID se existir
		void removeID(int id);
		// insere ID caso ela já não exista
		void insereID(int id);
		// retorna o tamanho da lista
		int getTam();
		// metodo limpa todos os componentes da lista menos a cabeça
		void Limpa();
		// consulta msg de um respectivo ID
		void consultaMsg(int id);
		// metodo para inserir uma msg em determinado ID e com determinada prioridade
		void entregaMsg(int id, int prioridade, string conteudo);
		// metodo da lista para posicionar antes da posição desejada
		TipoMailBox* Posiciona(int id); 
};
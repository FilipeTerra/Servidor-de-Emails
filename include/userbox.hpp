#pragma once

#include <string>
#include "tipoMensagem.hpp"

class userBox {
  private:
    int ID;
    int tam;
    TipoMensagem* primeiro;
    TipoMensagem* ultimo;

  public:
		userBox();
    userBox(int id);
    ~userBox();
    void Limpa();
		void leMsg(); // retorna a mensagem que está em primeiro de prioridade
		void inserePosicao(Mensagem msg);
		void removeInicio();
    int getTam();
		void setId(int id);
		int getId();
		void setTam(int tam);
		TipoMensagem* Posiciona(int prioridade);
};
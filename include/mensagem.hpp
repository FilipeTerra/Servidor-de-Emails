#pragma once

#include <string>

using namespace std;

class Mensagem {
  private:
    string conteudo;
    int prioridade;

  public:
    Mensagem();
    Mensagem(string conteudo, int prioridade);
    string getConteudo();
    void imprimeConteudo();
    void setConteudo(string novo);
    int getPrioridade();
    void setPrioridade(int nova);
};
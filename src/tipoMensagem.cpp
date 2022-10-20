#include "tipoMensagem.hpp"

TipoMensagem::TipoMensagem(){
  this->msg.setConteudo("0");
  this->msg.setPrioridade(-1);
  this->prox = NULL;
}
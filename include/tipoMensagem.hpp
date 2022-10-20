#include "mensagem.hpp"
#include <string>

class TipoMensagem {
  private:
    Mensagem msg;
    TipoMensagem* prox;
		friend class userBox;
    
  public:
    TipoMensagem();
};
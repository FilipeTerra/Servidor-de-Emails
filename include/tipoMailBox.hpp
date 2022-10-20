#pragma once

#include "userbox.hpp"

class TipoMailBox {
  private:
		friend class mailContainer;
		userBox *mailBox;
		TipoMailBox* prox;
		
  public:
		TipoMailBox();
};
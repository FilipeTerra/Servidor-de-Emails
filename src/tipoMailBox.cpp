#include "tipoMailBox.hpp"

TipoMailBox::TipoMailBox(){
	this->mailBox = new userBox();
	this->prox = NULL;
}
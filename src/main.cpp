#include "mailContainer.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// função para ler cada linha do documento txt
string leLinha(ifstream& file){
	string linha;
	getline(file, linha);
	return linha;
}

// função que executa todo o programa, linha por linha
void executa(ifstream& file){	
	mailContainer container = mailContainer();
	
	file.open("input.txt");
	string linha;

	if (file.good()){
		while(!file.eof()){
			linha = leLinha(file);
	
			std::size_t pos = linha.find(" ");
			string comando = linha.substr(0, pos);

			if (comando == "CADASTRA"){
				string aux = linha.substr(pos, pos+1);
				int id = stoi(aux);
				container.insereID(id);
			}

			if (comando == "REMOVE"){
				string aux = linha.substr(pos, pos+1);
				int id = stoi(aux);
				container.removeID(id);
			}

			if (comando == "ENTREGA"){
				int id = stoi(linha.substr(pos, pos+1));
				int prioridade = stoi(linha.substr(pos+2, pos+3));

				std::size_t fim = linha.find("FIM");
				string msg = linha.substr(pos+5, fim-1);
				container.entregaMsg(id, prioridade, msg);				
			}

			if (comando == "CONSULTA"){
				string aux = linha.substr(pos, pos+1);
				int id = stoi(aux);
				container.consultaMsg(id);
			}
		}
	}
	
	else {
			std::cout << "Não achei o arquivo!" << std::endl;
			exit(0);
	}
}

int main(int argc, char* argv[]) { 
	
	ifstream input(argv[1]);
	executa(input);
	
	return 0;
}
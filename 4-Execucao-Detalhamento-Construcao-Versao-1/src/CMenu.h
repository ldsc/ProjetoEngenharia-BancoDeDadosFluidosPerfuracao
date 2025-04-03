#ifndef CMenu_h
#define CMenu_h

#include <iostream>
#ifdef __linux

    #include <cstdlib>

#elif _WIN32
	#include <windows.h>///<para configurar a janela
	#include <stdlib.h>///<para system
#else

#endif

#include <string>
#include <sstream>
#include <vector>

using namespace std;
	
	///representa a classe com todos os menus
    class CMenu
		{
			public:
			     int resposta;///<representa a resposta do usu�rio
			     string resposta_str;///<representa a resposta do usu�rio convertida para string
				char ch;///<representa um caracter
			public:
			    int menu_inicio();///<m�todo referente ao menu de in�cio
			    int menu_banco_de_dados();///<m�todo referente ao menu que lista as fun��es referentes ao banco de dados
                int menu_exportar_dados();///<menu referente � gera��o de relat�rios
                int menu_banco_de_dados_pesquisar();///<menu referente �s op��es de pesquisa
                int menu_filtro();///<menu referente �s op��es de filtro
                int menu_configuracoes();///<menu referente �s op��es de congura��es
			    int menu_sim_nao();///<menu referente � resposta do usu�rio (sim ou n�o)
			    int menu_exibir_voltar();///<menu referente �s op��es exibir ou voltar
			    
		};




#endif

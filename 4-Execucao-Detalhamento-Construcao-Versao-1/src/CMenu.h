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
			     int resposta;///<representa a resposta do usuário
			     string resposta_str;///<representa a resposta do usuário convertida para string
				char ch;///<representa um caracter
			public:
			    int menu_inicio();///<método referente ao menu de início
			    int menu_banco_de_dados();///<método referente ao menu que lista as funções referentes ao banco de dados
                int menu_exportar_dados();///<menu referente à geração de relatórios
                int menu_banco_de_dados_pesquisar();///<menu referente às opções de pesquisa
                int menu_filtro();///<menu referente às opções de filtro
                int menu_configuracoes();///<menu referente às opções de congurações
			    int menu_sim_nao();///<menu referente à resposta do usuário (sim ou não)
			    int menu_exibir_voltar();///<menu referente às opções exibir ou voltar
			    
		};




#endif

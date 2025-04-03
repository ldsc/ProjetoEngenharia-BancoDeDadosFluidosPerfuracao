///verifica sistema operacional
	#ifdef __linux
        ///#include <unistd.h>
        #include <cstdlib>///<para system
	#elif _WIN32

        #include <windows.h>
        #include <stdlib.h>///<para system
        #include <conio.h>

	#else

	#endif
#include <iostream>
#include <string>
#include <sstream>
#include <locale>

#include <vector>
#include "CMenu.h"
#include <stdio.h>



using namespace std;

int CMenu::menu_inicio()
{
  
  #ifdef __linux
  cout<<"(1)Banco de Dados"<<endl;
  cout<<"(2)Configura\u00E7\u00F5es"<<endl;
  cout<<"(3)Abrir Diret\u00F3rio de Trabalho"<<endl;
  cout<<"(4)Abrir Diret\u00F3rio de Dados"<<endl;
  cout<<"(5)SAIR"<<endl;
  cout<<"Informe a Op\u00E7\u00E3o: ";
  #elif _WIN32
  cout<<"(1)Banco de Dados"<<endl;
  cout<<"(2)Configurações"<<endl;
  cout<<"(3)Abrir Diretório de Trabalho"<<endl;
  cout<<"(4)Abrir Diretório de Dados"<<endl;
  cout<<"(5)SAIR"<<endl;
  cout<<"Informe a Opção: ";
  #else
  
  #endif
  
  cin>>resposta_str;
  cin.get();
  ///testa se foi digitado um numero maior ou menor
  if(atoi(resposta_str.c_str()))
  {
    if(atoi(resposta_str.c_str())<1 || atoi(resposta_str.c_str()) >4)
    {
      resposta=5;///<se resposta for fora do intervalo, define 1 como padrao
    }
    else
    {
      resposta=atoi(resposta_str.c_str());
    }
    
  }
  else
  {
    resposta=5;///<Permanece no MENU
  }
  return resposta;
}

		
int CMenu::menu_banco_de_dados()
{
  #ifdef __linux
  
  cout<<"(1)Listar"<<endl;
  cout<<"(2)Pesquisar"<<endl;
  cout<<"(3)Inserir"<<endl;
  cout<<"(4)Excluir"<<endl;
  cout<<"(5)Exportar"<<endl;
  cout<<"(6)VOLTAR"<<endl;
  ///cout<<"(8)SAIR"<<endl;
  cout<<endl;
  cout<<"Infome a Op\u00E7\u00E3o: ";
  
  #elif _WIN32
  
  cout<<"(1)Listar"<<endl;
  cout<<"(2)Pesquisar"<<endl;
  cout<<"(3)Inserir"<<endl;
  cout<<"(4)Excluir"<<endl;
  cout<<"(5)Exportar"<<endl;
  cout<<"(6)VOLTAR"<<endl;
  ///cout<<"(8)SAIR"<<endl;
  cout<<endl;
  cout<<"Infome a Opção: ";
  
  #else
  
  #endif
  
  while(!(cin>>resposta))///<correcao de erro caso entre alguma resposta errada
  {
    cin.clear() ;
    cin >> ch;
    if(ch==120)break;///<se caracter for x termina processo
  }
  cin.get();
  
  if(resposta<1 || resposta >7)
  {
    resposta=7;///<se resposta for fora do intervalo, define 1 como padrao
  }
  
  return resposta;
}	
		 
int CMenu::menu_banco_de_dados_pesquisar()
		 
{
  cout<<"(1)Pesquisa Simples"<<endl;
  cout<<"(2)VOLTAR"<<endl;
  cout<<endl;
  
  
  #ifdef __linux
  cout<<"Infome a Op\u00E7\u00E3o: ";
  #elif _WIN32
  
  cout<<"Infome a Opção: ";
  #else
  
  #endif
  
  while(!(cin>>resposta))///<correcao de erro caso entre alguma resposta errada
  {
    cin.clear() ;
    cin >> ch;
    if(ch==120)break;///<se caracter for x termina processo
  }
  cin.get();
  
  if(resposta<1 || resposta >2)
  {
    resposta=2;///<se resposta for fora do intervalo, define 1 como padrao
  }
  
  return resposta;
}

int CMenu::menu_configuracoes()
{
  #ifdef __linux
  cout<<"(1)Explorador"<<endl;
  cout<<"(2)Editor de Texto"<<endl;
  cout<<"(3)Op\u00E7\u00E3o Abrir Diret\u00F3rio de Trabalho (DT)"<<endl;
  cout<<endl;
  cout<<"(4)Voltar"<<endl;
  cout<<endl;
  cout<<"Infome a Op\u00E7\u00E3o: ";
  #elif _WIN32
  cout<<"(1)Explorador"<<endl;
  cout<<"(2)Editor de Texto"<<endl;
  cout<<"(3)Opção Abrir Diretorio de Trabalho (DT)"<<endl;
  cout<<endl;
  cout<<"(4)Voltar"<<endl;
  cout<<endl;
  cout<<"Infome a Opção: ";
  #else
  
  #endif
  
  while(!(cin>>resposta))///<correcao de erro caso entre alguma resposta errada
  {
    cin.clear() ;
    cin >> ch;
    if(ch==120)break;///<se caracter for x termina processo
  }
  cin.get();
  if(resposta<0 || resposta >4)
  {
    resposta=4;///<se resposta for fora do intervalo, define 1 como padrao
  }
  return resposta;
}

int CMenu::menu_filtro()
{
  #ifdef __linux
  
  cout<<"(-)Chave"<<endl;          
  cout<<"(2)Nome do fluido"<<endl;  
  cout<<"(3)Base"<<endl;            
  cout<<"(4)pH m\u00EDnimo"<<endl;     
  cout<<"(5)pH m\u00C1ximo"<<endl; 
  cout<<"(6)Teor de \u00C1gua"<<endl; 
  cout<<"(7)Peso espec\u00EDfico m\u00EDnimo"<<endl; 
  cout<<"(8)Peso espec\u00EDfico m\u00C1ximo"<<endl; 
  cout<<"(9)Temperatura de envelhecimento"<<endl; 
  cout<<"(10)Salinidade"<<endl;  
  cout<<"(11)Filtrado"<<endl; 
  cout<<"|DATA DE CADASTRO|"<<endl; 
  cout<<"(12)Dia"<<"           (13)M\u00EAs"<<"         (14)Ano"<<endl;
  cout<<"(15)Listar todos"<<endl; 
  cout<<"(16)VOLTAR"<<endl;
  cout<<endl;
  cout<<"Infome a Op\u00E7\u00E3o: ";
  
  
  #elif _WIN32
  
  cout<<"(-)Chave"<<endl;          
  cout<<"(2)Nome do fluido"<<endl;  
  cout<<"(3)Base"<<endl;            
  cout<<"(4)pH m\u00EDnimo"<<endl;     
  cout<<"(5)pH m\u00C1ximo"<<endl; 
  cout<<"(6)Teor de \u00C1gua"<<endl; 
  cout<<"(7)Peso espec\u00EDfico m\u00EDnimo"<<endl; 
  cout<<"(8)Peso espec\u00EDfico m\u00C1ximo"<<endl; 
  cout<<"(9)Temperatura de envelhecimento"<<endl; 
  cout<<"(10)Salinidade"<<endl;  
  cout<<"(11)Filtrado"<<endl; 
  cout<<"|DATA DE CADASTRO|"<<endl; 
  cout<<"(12)Dia"<<"           (13)M\u00EAs"<<"         (14)Ano"<<endl;
  cout<<"(15)Listar todos"<<endl; 
  cout<<"(16)VOLTAR"<<endl;
  cout<<endl;
  cout<<"Infome a Op\u00E7\u00E3o: ";
  
  #else
  
  #endif
  
  while(!(cin>>resposta))///<correcao de erro caso entre alguma resposta errada
  {
    cin.clear() ;
    cin >> ch;
    if(ch==120)break;///<se caracter for x termina processo
  }
  cin.get();
  
  if(resposta<1 || resposta >16)
  {
    resposta=16;
  }
  
  return resposta;
}
		 
		 
int CMenu::menu_sim_nao()
{
	
#ifdef __linux

    cout<<endl;
    
    setlocale(LC_ALL, "Portuguese");
    cout<<"(1)Sim"<<endl;
    cout<<"(0)N\u00E3o"<<endl;
    cout<<endl;
    cout<<"Infome a Op\u00E7\u00E3o: ";
    locale::global(locale(""));
    
#elif _WIN32
    setlocale(LC_ALL, "Portuguese");
    cout<<endl;
    setlocale(LC_ALL, "Portuguese");
    cout<<"(1)Sim"<<endl;
    cout<<"(0)Não"<<endl;
    cout<<endl;
    cout<<"Infome a Opção: ";
    locale::global(locale(""));
    
#else

#endif
    
    while(!(cin>>resposta))///<correcao de erro caso entre alguma resposta errada
    {
      cin.clear() ;
      cin >> ch;
      if(ch==120)break;///<se caracter for x termina processo
    }
    ///<cin.get();
    
    if(resposta<0 || resposta >1)
    {
      resposta=0;///<se resposta for fora do intervalo, define 0 como padrao
    }
    
    return resposta;
}

int CMenu::menu_exibir_voltar()
{
  
  cout<<endl;
  cout<<"(0)Voltar"<<endl;
  cout<<"(1)Exibir"<<endl;
  
  
  cout<<endl;
  
  #ifdef __linux
  setlocale(LC_ALL, "Portuguese");
  cout<<"Infome a Op\u00E7\u00E3o: ";
  locale::global(locale(""));
  #elif _WIN32
  setlocale(LC_ALL, "Portuguese");
  cout<<"Infome a Opção: ";
  locale::global(locale(""));
  #else
  
  #endif
  
  
  while(!(cin>>resposta))///<correcao de erro caso entre alguma resposta errada
  {
    cin.clear() ;
    cin >> ch;
    if(ch==120)break;///<se caracter for x termina processo
  }
  cin.get();
  
  if(resposta<0 || resposta >1)
  {
    resposta=0;///<se resposta for fora do intervalo, define 0 como padrao
  }
  
  return resposta;
}

int CMenu::menu_exportar_dados()
{
	
#ifdef __linux
    setlocale(LC_ALL, "Portuguese");
    cout<<"(1)Completo"<<endl;
    cout<<"(2)VOLTAR"<<endl;
    cout<<endl;
    cout<<"Infome a Op\u00E7\u00E3o: ";

    locale::global(locale(""));
#elif _WIN32
    setlocale(LC_ALL, "Portuguese");
    cout<<"(1)Completo"<<endl;
    cout<<"(2)VOLTAR"<<endl;
    cout<<endl;
    cout<<"Infome a Opção: ";

    locale::global(locale(""));
#else

#endif

    while(!(cin>>resposta))///<correcao de erro caso entre alguma resposta errada
    {
      cin.clear() ;
      cin >> ch;
      if(ch==120)break;///<se caracter for x termina processo
    }
    cin.get();
    if(resposta<1 || resposta >3)
    {
      resposta=3;///<se resposta for fora do intervalo, define 3 como padrao
    }
    return resposta;
}


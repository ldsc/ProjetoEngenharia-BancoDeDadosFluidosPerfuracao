///verifica sistema operacional
#ifdef __linux
#include <cstdlib>
///  #include <unistd.h>
#elif _WIN32

#include <windows.h>
#include <stdlib.h>///<para system
#include <conio.h>
#else
#endif
#include <iostream>
#include <stdio.h>
#include <locale>
#include "CHeader.h"
using namespace std;

void CHeader::header_titulo()///<escreve titulo do programa
{
  
  ///Titulo Programa
  ///verifica sistema operacional
  #ifdef __linux
  ///system("clear");
  
  {
    largura=45;
    cout<<"\u2554";///<canto sup esq
    for(i=0;i<largura;i++)///<barra sup
      cout<<"\u2550";
    cout<<"\u2557"<<endl;///<canto su dir
    cout<<"\u2551"<<"                                             "<<"\u2551"<<endl;;///<Margem vert acim Titulo
    cout<<"\u2551";///<Margem vert Titulo
    cout<<"   Banco de Dados de Fluidos de Perfuracao   ";
    cout<<"\u2551"<<endl;///<Margem vert Titulo
    cout<<"\u255A";///<canto inf dir  
    for(i=0;i<largura;i++)///<barra inf
      cout<<"\u2550";
    cout<<"\u255D"<<endl;///<canto inf esq
  }
  #elif _WIN32
  ///<system("cls");
  
  {
    
    largura=30;
    cout<<(char)201;///<canto sup esq
    for(i=0;i<largura;i++)///<barra sup
      cout<<(char)205;
    cout<<(char)187<<endl;///<canto su dir
    cout<<(char)186<<"                                           "<<(char)186<<endl;;///<Margem vert acim Titulo
    cout<<(char)186;///<Margem vert Titulo
    cout<<"   Banco de Dados de Fluidos de Perfuração   ";
    cout<<endl;
    cout<<(char)186<<endl;///<Margem vert Titulo
    cout<<(char)200;///<canto inf dir
    for(i=0;i<largura;i++)///<barra inf
      cout<<(char)205;
    cout<<(char)188<<endl;///<canto inf esq
  }
  
  
  
  
  
  #else
  
  #endif
  
  
}
    
    

    void CHeader::header_inicio()///<escreve subtitulo do menu inicio
    {
      #ifdef __linux
      {
	
	largura=30;
	cout<<"\u250C";///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<"\u2500";
	cout<<"\u2510"<<endl;///<canto su dir
	cout<<"\u2502";///<Margem vert Titulo
	cout<<"            In\u00EDcio            ";
	cout<<"\u2502"<<endl;///<Margem vert Titulo
	cout<<"\u2514";///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<"\u2500";
	cout<<"\u2518"<<endl;
	cout<<endl;
	
      }
	
	
	
	
      
      #elif _WIN32
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	cout<<"            Início            ";
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
	
	
      }
      #else
      
      #endif
      
    }

    void CHeader::header_banco_de_dados()///<escreve subtitulo para banco de dados
    {
      #ifdef __linux
      {
	largura=30;
	cout<<"\u250C";///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<"\u2500";
	cout<<"\u2510"<<endl;///<canto su dir
	cout<<"\u2502";///<Margem vert Titulo
	cout<<"        Banco de Dados        ";
	cout<<"\u2502"<<endl;///<Margem vert Titulo
	cout<<"\u2514";///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<"\u2500";
	cout<<"\u2518"<<endl;
	cout<<endl;
	
      }
      #elif _WIN32
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<"        Banco de Dados        ";
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      #else
      
      #endif
      
    }
    
    void CHeader::header_banco_de_dados_lista_de_amostras()///<escreve subtitulo para lista de fluidos
    {
      #ifdef __linux
      
      {
	largura=40;
	cout<<"\u250C";///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<"\u2500";
	cout<<"\u2510"<<endl;///<canto su dir
	cout<<"\u2502";///<Margem vert Titulo
	cout<<"      Lista de Fluidos de Perfuracao    ";
	cout<<"\u2502"<<endl;///<Margem vert Titulo
	cout<<"\u2514";///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<"\u2500";
	cout<<"\u2518"<<endl;
	cout<<endl;
      }
      
      #elif _WIN32
      
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	cout<<"      Lista de Fluidos de Perfuração       ";
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
	
      
      #else
      
      #endif
    }
    
    void CHeader::header_banco_de_dados_exibir_amostras()///<escreve subtitulo das amostras listadas
    {
      #ifdef __linux
      
      
      largura=30;
      cout<<"\u250C";///<canto sup esq
      for(i=0;i<largura;i++)///<barra sup
	cout<<"\u2500";
      cout<<"\u2510"<<endl;///<canto su dir
      cout<<"\u2502";///<Margem vert Titulo
      
      
      cout<<"            Exibir            ";
      
      cout<<"\u2502"<<endl;///<Margem vert Titulo
      cout<<"\u2514";///<canto inf dir
      for(i=0;i<largura;i++)///<barra inf
	cout<<"\u2500";
      cout<<"\u2518"<<endl;
      cout<<endl;
      
      
      #elif _WIN32
      
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<"            Exibir            ";
	
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      #else
      
      #endif
      
    }
    
    void CHeader::header_banco_de_dados_pesquisa_de_amostras()///<escreve subtitulo para pesquisa de amostras
    {
      
      #ifdef __linux
      
      {
	largura=40;
	cout<<"\u250C";///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<"\u2500";
	cout<<"\u2510"<<endl;///<canto su dir
	cout<<"\u2502";///<Margem vert Titulo
	
	cout<<"     Pesquisa de Fluidos de Perfuracao  ";
	
	cout<<"\u2502"<<endl;///<Margem vert Titulo
	cout<<"\u2514";///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<"\u2500";
	cout<<"\u2518"<<endl;
	cout<<endl;
      }
      #elif _WIN32
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<"     Pesquisa de Fluidos de Perfuração  ";
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      #else
      
      #endif
      
    }
    void CHeader::header_banco_de_dados_inserir_amostras()///<escreve subtitulo para inserir fluidos
    {
      
      #ifdef __linux
      
      largura=40;
      cout<<"\u250C";///<canto sup esq
      for(i=0;i<largura;i++)///<barra sup
	cout<<"\u2500";
      cout<<"\u2510"<<endl;///<canto su dir
      cout<<"\u2502";///<Margem vert Titulo
      
      cout<<"       Inserir Fluidos de Perfuracao    ";
      
      cout<<"\u2502"<<endl;///<Margem vert Titulo
      cout<<"\u2514";///<canto inf dir
      for(i=0;i<largura;i++)///<barra inf
	cout<<"\u2500";
      cout<<"\u2518"<<endl;
      cout<<endl;
      
      #elif _WIN32
      
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<"       Inserir Fluidos de Perfuracao   ";
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      #else
      
      #endif
    }
    
    void CHeader::header_banco_de_dados_excluir_amostras()///<escreve subtitulo das amostras listadas
    {
      
      #ifdef __linux
      
      largura=30;
      cout<<"\u250C";///<canto sup esq
      for(i=0;i<largura;i++)///<barra sup
	cout<<"\u2500";
      cout<<"\u2510"<<endl;///<canto su dir
      cout<<"\u2502";///<Margem vert Titulo
      
      
      cout<<"       Excluir Amostras       ";
      
      cout<<"\u2502"<<endl;///<Margem vert Titulo
      cout<<"\u2514";///<canto inf dir
      for(i=0;i<largura;i++)///<barra inf
	cout<<"\u2500";
      cout<<"\u2518"<<endl;
      cout<<endl;
      
      #elif _WIN32
      
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	cout<<"       Excluir Amostras       ";
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      #else
      
      #endif
      
      
    }
    
    
    void CHeader::header_banco_de_dados_exportar_amostras()///<escreve subtitulo para exportar
    {
      #ifdef __linux
      {
	
	largura=40;
	cout<<"\u250C";///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<"\u2500";
	cout<<"\u2510"<<endl;///<canto su dir
	cout<<"\u2502";///<Margem vert Titulo
	
	cout<<"       Exportar Fluidos de Perfuracao   ";
	
	cout<<"\u2502"<<endl;///<Margem vert Titulo
	cout<<"\u2514";///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<"\u2500";
	cout<<"\u2518"<<endl;
	cout<<endl;
      }
      #elif _WIN32
      
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<"       Exportar Fluidos de Perfuracao   ";
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      
      #else
      
      #endif
      
    }
    
    
    
    void CHeader::header_configuracoes()///<subtitulo do menu 2
    {
      
      
      #ifdef __linux
      
      largura=30;
      cout<<"\u250C";///<canto sup esq
      for(i=0;i<largura;i++)///<barra sup
	cout<<"\u2500";
      cout<<"\u2510"<<endl;///<canto su dir
      cout<<"\u2502";///<Margem vert Titulo
      cout<<"         Configura\u00E7\u00F5es        ";
      cout<<"\u2502"<<endl;///<Margem vert Titulo
      cout<<"\u2514";///<canto inf dir
      for(i=0;i<largura;i++)///<barra inf
	cout<<"\u2500";
      cout<<"\u2518"<<endl;
      cout<<endl;
      
      #elif _WIN32
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<"         Configurações        ";
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      
      #else
      
      #endif
    }
    
    void CHeader::header_menu_abre_DT()///<subtitulo do menu 3
    {
      #ifdef __linux
      
      largura=30;
      cout<<"\u250C";///<canto sup esq
      for(i=0;i<largura;i++)///<barra sup
	cout<<"\u2500";
      cout<<"\u2510"<<endl;///<canto su dir
      cout<<"\u2502";///<Margem vert Titulo
      
      cout<<" Abrindo Diret\u00F3rio de Trablho ";
      
      cout<<"\u2502"<<endl;///<Margem vert Titulo
      cout<<"\u2514";///<canto inf dir
      for(i=0;i<largura;i++)///<barra inf
	cout<<"\u2500";
      cout<<"\u2518"<<endl;
      cout<<endl;
      
      #elif _WIN32
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<" Abrindo Diretório de Trablho ";
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      
      #else
      
      #endif
    }
    
    void CHeader::header_menu_abre_bd()///<subtitulo do menu 3
    {
      
      #ifdef __linux
      
      largura=30;
      cout<<"\u250C";///<canto sup esq
      for(i=0;i<largura;i++)///<barra sup
	cout<<"\u2500";
      cout<<"\u2510"<<endl;///<canto su dir
      cout<<"\u2502";///<Margem vert Titulo
      
      cout<<"  Abrindo Diret\u00F3rio de Dados  ";
      
      cout<<"\u2502"<<endl;///<Margem vert Titulo
      cout<<"\u2514";///<canto inf dir
      for(i=0;i<largura;i++)///<barra inf
	cout<<"\u2500";
      cout<<"\u2518"<<endl;
      cout<<endl;
      
      #elif _WIN32
      {
	largura=30;
	cout<<(char)218;///<canto sup esq
	for(i=0;i<largura;i++)///<barra sup
	  cout<<(char)196;
	cout<<(char)191<<endl;///<canto su dir
	cout<<(char)179;///<Margem vert Titulo
	
	cout<<"  Abrindo Diretório de Dados  ";
	
	cout<<(char)179<<endl;///<Margem vert Titulo
	cout<<(char)192;///<canto inf dir
	for(i=0;i<largura;i++)///<barra inf
	  cout<<(char)196;
	cout<<(char)217<<endl;
	cout<<endl;
      }
      
      
      
      #else
      
      #endif
    }
      
      

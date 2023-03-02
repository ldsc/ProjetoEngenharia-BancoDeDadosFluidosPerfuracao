#include <iostream>
///verifica sistema operacional
#ifdef __linux
    #include <cstdlib>
    #include <stdio.h>
   /// #include <unistd.h>
#elif _WIN32
	#include <windows.h>///<para configurar a janela
	#include <stdlib.h>///<para system
#else

#endif

#include <sstream>
#include <cstring>///<biblioteca para trab com os comandos
#include <string>
#include "CInterface.h"///<inclui classe
#include "CMenu.h"///<Inclui classes utilizadas
#include "CHeader.h"
#include "CFluidodePerfuracao.h"


using namespace std;

///usuario simples

void CInterface::inicia()///<inicia o menu
{
 
  
  ajusta_janela();
  do{
    
    limpa_janela();
    Head.header_titulo();///<Coloca titulo principal do programa
    Head.header_inicio();///<Coloca subtitulo Inicio
    resposta=Menu.menu_inicio();///<Escreve o menu inicio e obtem a resposta
    
    switch (resposta)///<testa a resposta
    {
      case 1:///<Banco de dados
	do
	{
	  limpa_janela();
	  Head.header_titulo();///<Coloca titulo pricipal do programa
	  Head.header_banco_de_dados();///<Coloca subtitulo editar amostras
	  resposta=Menu.menu_banco_de_dados(); ///<obtem resposta do menu editar amostra
	  
	  switch (resposta)///<faz a funçao respctiva do submenu editar amostra
	  {
	    case 1:///<listar
	      limpa_janela();
	      Head.header_titulo();
	      Head.header_banco_de_dados_lista_de_amostras();
	      amostras=bancodedados.ler_amostra_basico();
	      bancodedados.listar_amostra(amostras);
	      cout<<endl;
	      amostras.clear();
		do
		{   
		cout<<endl;
		resposta=Menu.menu_exibir_voltar();
		if(resposta==0)break;
		    do
		    {
		    limpa_janela();
		    Head.header_titulo();
		    Head.header_banco_de_dados_exibir_amostras();
		    amostras=bancodedados.ler_amostra_basico();
		    bancodedados.listar_amostra(amostras);
		    amostras.clear();
		    cout<<"CHAVE: ";
		    cin>>int_chave;
		    ///<limpa tudo e reescreve
		    limpa_janela();
		    Head.header_titulo();
		    Head.header_banco_de_dados_exibir_amostras();
		    amostras=bancodedados.ler_amostra_basico();
		    bancodedados.listar_amostra(amostras);
		    amostras.clear();
		    bancodedados.exibir_amostra(int_chave);
		    cout<<endl;
		    cout<<"Exibir Outra Amostra?";
		    resposta=Menu.menu_sim_nao();
		    }while(resposta!=0);
		}while(resposta!=0);
	      ///<exibe lista pergunta chave para visualizaca
	      
	      resposta=2;
	      break;
	      
	    case 2:///<pesquisar
	      limpa_janela();
	      Head.header_titulo();
	      Head.header_banco_de_dados_pesquisa_de_amostras();
	      resposta=Menu.menu_banco_de_dados_pesquisar();
	      if(resposta==2)
	      {
		resposta=1;
		break;
	      }
	      
	      switch(resposta)
	      {
		
		case 1:
		  
		  do
		  {
		    limpa_janela();
		    Head.header_banco_de_dados_pesquisa_de_amostras();
		    amostras=bancodedados.ler_amostra_basico();///<lista todas as amostras
		    cout<<"Itens de Pesquisa"<<endl<<endl;
		    resposta=Menu.menu_filtro();///<escreve menu filtro e retorna seu valor
		    if(resposta==16)break;///<volta
		    limpa_janela();
		    Head.header_banco_de_dados_pesquisa_de_amostras();
		    amostras=bancodedados.ler_amostra_basico(resposta);///<vetor de amostra recebe amostra ja filtradas
		    bancodedados.listar_amostra(amostras,resposta);
		    cout<<endl;
		    resposta=Menu.menu_exibir_voltar();
		    if(resposta==0)break;
		    
		    
		    do
		    {
		      ///<limpa tudo e reescreve
		      limpa_janela();
		      Head.header_titulo();
		      Head.header_banco_de_dados_exibir_amostras();
		      ///bancodedados.listar_amostra(amostras,resposta);
		      ///cout<<endl;
		      ///resposta=Menu.menu_exibir_voltar();
		      ///if(resposta==0)break;
		      ///inicia exibicao amostra
		      cout<<"CHAVE: ";
		      cin>>int_chave;
		      limpa_janela();///acha a chave digitada e reescreve tudo novamente
		      Head.header_titulo();
		      Head.header_banco_de_dados_exibir_amostras();
		      bancodedados.listar_amostra(amostras,resposta);
		      bancodedados.exibir_amostra(int_chave);   
		      cout<<"Deseja Pesquisar Novamente?";
		      resposta=Menu.menu_sim_nao();
		      amostras.clear();
		      
		    }
		    while(resposta==1);
		  }
		  while(resposta==1);
		  break;
	      }
	      resposta=2;
	      break;///<break da pesquisa
	      
	      case 3:///<inserir
		limpa_janela();
		Head.header_titulo();
		Head.header_banco_de_dados_inserir_amostras();
		if(configuracao.opcao_abrir_DT()==1)
		{
		  abre_DT();
		}
		
		do
		{
		  bancodedados.inserir_amostra();
		  cout<<endl;
		  cout<<endl;
		  cout<<"Deseja Inserir Novamente?"<<endl;
		  resposta=Menu.menu_sim_nao();
		}
		while(resposta==1);
	    resposta=2;///<retorna ao menu Banco de DADOS
	    
	    break;
	    
	       case 4:///<excluir
		 do
		 {
		   limpa_janela();
		   Head.header_titulo();
		   Head.header_banco_de_dados_excluir_amostras();
		   amostras=bancodedados.ler_amostra_basico();
		   bancodedados.listar_amostra(amostras);
		   cout<<"Deseja realmente Excluir?";
		   resposta=Menu.menu_sim_nao();
		 
		   if(resposta==0)break;
		   cout<<"CHAVE: ";
		   
		   cin>>int_chave;
		   ///<cin.get();
                    
		   ///system("pause");
		   bancodedados.excluir_amostra(int_chave);
		   amostras.clear();
		   cout<<endl;
		   cout<<endl;
		   
		   ///atualiza tela
		   limpa_janela();
		   Head.header_titulo();
		   Head.header_banco_de_dados_excluir_amostras();
		   amostras=bancodedados.ler_amostra_basico();
		   bancodedados.listar_amostra(amostras);
		   amostras.clear();
		   cout<<"Deseja Excluir Outra Amostra?"<<endl;
		   resposta=Menu.menu_sim_nao();
		 }
		 while(resposta==1);
		 resposta=2;///<retorna ao menu Banco de DADOS
		 
		 
		 break;

		
	      case 5:///<Exportar
		limpa_janela();
		Head.header_titulo();
		Head.header_banco_de_dados_exportar_amostras();
		resposta=Menu.menu_exportar_dados();
		if(resposta==2)
		{
		  resposta=2;
		  break;
		}
		switch(resposta)
		{
		  case 1:
		    
		    cout<<"CHAVE: ";
		    cin>>int_chave;
		    cin.get();
		    relatorio.exportar_amostra(int_chave);
		    abre_relatorio(int_chave);
		    break;
		    
		  default:
		    resposta=2;
		    break;
		    ///abre diretorio com relatorio(os)
		}
		resposta=2;
		break;      
		      
		case 6:///<voltar
		  resposta=1;
		  break;      
		      
		   default:
		  {
		    #ifdef __linux
		    setlocale(LC_ALL, "Portuguese");
		    cout<<"Op\u00E7\u00E3o invalida."<<endl;
		    locale::global(locale(""));
		    #elif _WIN32
		    setlocale(LC_ALL, "Portuguese");
		    cout<<"Opcão invalida."<<endl;
		    locale::global(locale(""));
		    #else
		    
		    #endif
		    
		    limpa_janela();
		    
		  }
		  resposta=1;
		  break;
		 }
	  }
	  while(resposta==2);
	  
	  break;///<fechando o caso 1:Banco de dados    
		    
    
        case 2:///<configuracoes
	  limpa_janela();
	  Head.header_titulo();
	  Head.header_configuracoes();
	  resposta=Menu.menu_configuracoes();
	  
	  switch(resposta)
	  {
	    case 1:
	      cout<<endl;
	      cout<<"Explorador Padr\u00E3o: "<<configuracao.opcao_programa("explorador")<<endl;
	      cout<<"Explorador Padr\u00E3o: ";
	      cin>>informacao_str;
	      cin.get();
	      configuracao.opcao_programa("explorador",informacao_str);
	      break;
	      
	    case 2:
	      cout<<endl;
	      cout<<"Editor de Texto Padr\u00E3o: "<<configuracao.opcao_programa("editortexto")<<endl;
	      cout<<"Editor de Texto Padr\uE003o: ";
	      cin>>informacao_str;
	      cin.get();
	      configuracao.opcao_programa("editortexto",informacao_str);
	      break;
	      
	    case 3:
	      cout<<endl;
	      cout<<"Op\u00E7\u00E3o Atual: "<<configuracao.opcao_abrir_DT()<<endl;
	      cout<<endl;
	      cout<<"Deseja sempre abrir o Diret\u00F3rio de Trabalho (DT)?"<<endl;
	      resposta=Menu.menu_sim_nao();
	      configuracao.opcao_abrir_DT(resposta);///<0 para nao abrir e 1 para abrir
	      break;
	      
	    case 4:
	      resposta=1;
	      break;
	      
	      
	    default:
	      resposta=1;
	      break;
	  }
	  
	  break;
	  
	     
	case 3:///<abrir diretorio de trabalho
	  limpa_janela();
	  
	  Head.header_menu_abre_DT();
	  ///verifica sistema operacional
	  #ifdef __linux
	  ///sleep(100);
	  #elif _WIN32
	  Sleep(100);
	  #else
	  
	  #endif
	  
	  abre_DT();
	  resposta=1;
	  
	  break;
	  
	  
	case 4:///abrir diretorio de dados
	  limpa_janela();
	  
	  Head.header_menu_abre_bd();
	  ///verifica sistema operacional
	  #ifdef __linux
	  ///sleep(100);
	  #elif _WIN32
	  Sleep(100);
	  #else
	  
	  #endif
	  
	  abre_bd();
	  resposta=1;
	  
	  
	  break;
	  
	  
	 case 5:///sair
	   limpa_janela();
	   Head.header_titulo();
	   cout<<"Realmente deseja sair?"<<endl;
	   resposta=Menu.menu_sim_nao();
	   if(resposta==1)
	     exit(0);
	   else
	     resposta=1;
	   break;
	   
	   
	 default:    
	   
	   ///verifica sistema operacional
	   #ifdef __linux
	   setlocale(LC_ALL, "Portuguese");
	   cout<<"Op\u00E7\u00E3o inv\u00E1lida."<<endl;
	   locale::global(locale(""));
	   /// sleep(1000);
	   #elif _WIN32
	   setlocale(LC_ALL, "Portuguese");
	   cout<<"Opção inválida."<<endl;
	   locale::global(locale(""));
	   Sleep(1000);
	   #else
	   
	   #endif
	   
	   resposta=1;
	   break;
	   
    }
  }
  while(resposta==1); 
}
		

void CInterface::abre_DT()
{
  ///inicia diretorio de trabalho
  ///comando: "move bd\0.txt bd\lixo" Comando para mover o arquivo da amostra
  ///verifica sistema operacional
  programa=configuracao.opcao_programa("explorador");///<define explorardor
  comando_abrir.str("");
  #ifdef __linux
  comando_abrir<<programa<<" "<<"./DT";
  #elif _WIN32
  comando_abrir<<"start"<<" "<<programa<<" "<<"DT";
  
  #else
  
  #endif
  system(comando_abrir.str().c_str());///<Manda o comando pro prompt para mover o arquivo p lixeira
  comando_abrir.str("");
}

void CInterface::abre_relatorio(int int_chave_)
{
  ///inicia diretorio de trabalho
  ///comando: "move bd\0.txt bd\lixo" Comando para mover o arquivo da amostra
  ///verifica sistema operacional
  programa=configuracao.opcao_programa("explorador");///<define explorador
  int_chave=int_chave_;
  comando_abrir.str("");
  #ifdef __linux
  comando_abrir<<programa<<" "<<"./DT/relatorios/"<<int_chave;
  #elif _WIN32
  comando_abrir<<"start"<<" "<<programa<<" "<<"DT"<<char(92)<<"relatorios"<<char(92)<<int_chave;
  cout<<comando_abrir.str();
  #else
  
  #endif
  if(configuracao.opcao_abrir_DT()==1)
  {
    system(comando_abrir.str().c_str());///<Manda o comando pro prompt para mover o arquivo p lixeira
  }
  
  comando_abrir.str("");
}

void CInterface::abre_bd()
{
  ///inicia diretorio de dados
  ///comando: "move bd\0.txt bd\lixo" Comando para mover o arquivo da amostra
  programa=configuracao.opcao_programa("explorador");//define explorador
  ///verifica sistema operacional
  comando_abrir.str("");
  #ifdef __linux
  comando_abrir<<programa<<" "<<"./bd";
  #elif _WIN32
  comando_abrir<<"start"<<" "<<programa<<" "<<"bd";
  
  #else
  
  #endif
  system(comando_abrir.str().c_str());///<Manda o comando pro prompt para mover o arquivo p lixeira
  comando_abrir.str("");
}

void CInterface::ajusta_janela()
{
  ///verifica sistema operacional
  #ifdef __linux
  ///sleep(100);
  #elif _WIN32
  ///ajusta cor do programa(comando de MS-DOS)
  system("color F0");
  ///Maximiza Programa
  {///Referencia(http://forum.clubedohardware.com.br/full-screen-c/567207 em 15/11/2013)
    keybd_event ( VK_MENU, 0x38, 0, 0 );
    keybd_event ( VK_SPACE, 0x39, 0, 0 );
    keybd_event(0x58,0,0,0);
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_SPACE, 0x39, KEYEVENTF_KEYUP, 0 );
    keybd_event(0x58,0,KEYEVENTF_KEYUP,0);
  }
  CHeader Header;
  ///Escreve Versao do Windows
  cout<<"Versao do sistema: ";
  system("VER");
  Sleep(100);
  #else
  
  #endif
  
}

void CInterface::limpa_janela()
{
  #ifdef __linux
  system("clear");///<limpa tela
  #elif _WIN32
  system("cls");
  #else
  
  #endif
}


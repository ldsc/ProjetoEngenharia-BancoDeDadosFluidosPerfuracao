#ifndef CInterface_h
#define CInterface_h
#include <iostream>

#ifdef __linux

#include <cstdlib>

#elif _WIN32
#include <windows.h>///<para configurar a janela
#include <stdlib.h>///<para system
#else

#endif

#include "CMenu.h"
#include "CHeader.h"
#include "CBancodeDados.h"
#include "CFluidodePerfuracao.h"
#include "CRelatorio.h"
#include "CConfiguracao.h"


#include <string>
#include <sstream>
#include <vector>

class CInterface
{
public:
  int resposta;///<representa a resposta ao usu�rio referente ao menu de op��es
  int int_chave;///<representa a chave das amostras
  int item;///<representa os t�tulos do arquivo
  unsigned int c;///<representa um contador
  
  CHeader Head;
  CMenu Menu;
  CBancodeDados bancodedados;
  CRelatorio relatorio;
  CConfiguracao configuracao;
  
  stringstream comando_abrir;///<para convers�o em string
  stringstream titulo_ss;///<para convers�o em string
  string titulo;///<representa o t�tulo
  string informacao_str;///<representa o novo programa lido
  string programa;///<representa o nome do explorador e do editor de texto
  
  char ch;///<representa um caracter
  
  vector<CFluidodePerfuracao> amostras;///<representa o vetor de amostras do tipo CFluidodePerfuracao
 
public:
  void inicia();///<m�todo para iniciar o programa
  void abre_DT();///<m�todo para abrir diret�rio de trabalho
  void abre_bd();///<m�todo para abrir pasta do banco de dados
  void abre_relatorio(int);///<m�todo para abrir relat�rios
  void ajusta_janela();///<m�todo para ajustar janela
  void limpa_janela();///<m�todo para limpar janela
  
  
};

#endif

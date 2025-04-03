#ifndef CConfiguracao_h
#define CConfiguracao_h
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

class CConfiguracao
{
public:
  
  /// Representa a classe que configura o explorador e o editor de texto
  ifstream fin;
  ofstream fout;
  
  stringstream caminho_ss;///<usado para convers�o em string
  string caminho_str;///<representa o caminho do diret�rio em string
  string nome_programa;///<nome do programa definido pelo usu�rio
  string nome_explorador_linux;///<representa o explorador do linux
  string nome_explorador_windows;///<representa o explorador do windows
  string nome_editor_texto_linux;///<representa o nome do editor texto do linux
  string nome_editor_texto_windows;///<representa o nome do editor texto do windows
  string tipo_programa;///<representa o tipo de programa, se � explorador ou editor de texto
  string str;///<representa uma string
  
  int opcao;///<representa a op��o selecionada pelo usu�rio no menu
  
public:
  
  int opcao_abrir_DT();///<m�todo que retorna a op��o para abrir o diret�rio
  void opcao_abrir_DT(int);///<m�todo que edita a op��o de abrir ou n�o o diret�rio
  void opcao_programa(string, string);///<m�todo para a troca do explorador e do editor de texto
  string opcao_programa(string);///<m�todo para a troca do explorador
  
};

#endif

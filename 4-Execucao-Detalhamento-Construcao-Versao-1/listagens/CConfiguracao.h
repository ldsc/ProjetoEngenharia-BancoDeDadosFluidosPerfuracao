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
  
  stringstream caminho_ss;///<usado para conversão em string
  string caminho_str;///<representa o caminho do diretório em string
  string nome_programa;///<nome do programa definido pelo usuário
  string nome_explorador_linux;///<representa o explorador do linux
  string nome_explorador_windows;///<representa o explorador do windows
  string nome_editor_texto_linux;///<representa o nome do editor texto do linux
  string nome_editor_texto_windows;///<representa o nome do editor texto do windows
  string tipo_programa;///<representa o tipo de programa, se é explorador ou editor de texto
  string str;///<representa uma string
  
  int opcao;///<representa a opção selecionada pelo usuário no menu
  
public:
  
  int opcao_abrir_DT();///<método que retorna a opção para abrir o diretório
  void opcao_abrir_DT(int);///<método que edita a opção de abrir ou não o diretório
  void opcao_programa(string, string);///<método para a troca do explorador e do editor de texto
  string opcao_programa(string);///<método para a troca do explorador
  
};

#endif

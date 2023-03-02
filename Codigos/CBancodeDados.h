#ifndef CBancodeDados_h
#define CBancodeDados_h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>///<para conversao de int para string
#include "CHeader.h"
#include "CConfiguracao.h"
#include "CFluidodePerfuracao.h"

using namespace std;

class CBancodeDados
{
  
public:
  int int_chave;
  int int_chave_aux;
  int item;
  int tipo;
  int resposta;///<respsota
  int int_posicao;
  int filtro;///<filtro da pesquisa
  int dia;
  int mes;
  int ano;
  int num_int;
  
  
  unsigned int i;///< i para contagem do for;
  double num;
  char ch;
  double num_double;
  double const_vazio_num_double;
  
  string caminho_amostra;
  string diretorio_amostra;    	///< string nome_amostra;
  string item_amostra;
  string comando_remover_str;///<comando para remover amostra em string
  string dado_str;
  string nome;
  string caminho;
  string linha_str;
  string vazio_str;
  string const_vazio_str;
  
  ifstream fin;///<variavel de leitura do arquivo
  ofstream fout;
  
  vector<int> chave;///<Vetor de chaves lidas no arquivo
  vector<CFluidodePerfuracao> amostra_fluido; ///<vetor de amostras
  vector<CFluidodePerfuracao> amostra_fluido_vec_aux;
  vector<CFluidodePerfuracao> amostra_fluido_vec_aux_2;
  vector<int> vetor_resposta;
  
  stringstream ss;///<stringstream para conversao de inteiro para string
  stringstream comando_remover;///<cria comando para remover amostra para lixeira
  stringstream comando_caminho_amostra;
  stringstream comando;
  stringstream nome_amostra;
  stringstream caminho_bd;
  stringstream linha_ss;
  stringstream num_double_ss;
  
  CFluidodePerfuracao amostra_aux;
  CFluidodePerfuracao amostra_fluido_aux;///<obj auxiliar
  CConfiguracao configuracao;            


public: 
  void listar_amostra(vector<CFluidodePerfuracao>);///<lista todas as amostras
  void listar_amostra(vector<CFluidodePerfuracao>, int);
  void exibir_amostra(int);
  void inserir_amostra();///<insere amostras
  void excluir_amostra(int);///<exclui amostras
  vector<CFluidodePerfuracao> ler_amostra_basico();
  vector<CFluidodePerfuracao> ler_amostra_basico(int);
  string teste_vazio(double);
  double teste_vazio(string);
  
};

#endif


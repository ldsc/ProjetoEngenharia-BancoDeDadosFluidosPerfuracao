#ifndef CRelatorio_h
#define CRelatorio_h
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "CFluidodePerfuracao.h"
#include "CBancodeDados.h"

using namespace std;
///representa a classe que exporta as amostras em forma de relatório
class CRelatorio
{
  
public:
  
  int chave;///<representa a chave da amostra a ser exportada
  int int_chave;///<representa a chave da amostra a ser exportada
  int resposta;///<representa a resposta do usuário
  unsigned int c;///<contador
  
  vector<CFluidodePerfuracao> v_amostra;///<vetor do tipo vector<CFluidodePerfuracao> de amostra
  
  ofstream fout;
  
  stringstream ss;///<conversão em string
  
  CBancodeDados lerbasico;///< cria um objeto da classe CBancodeDados
  
public:
  void exportar_amostra(int);///<método para exportar as amostras em forma de relatório
};

#endif

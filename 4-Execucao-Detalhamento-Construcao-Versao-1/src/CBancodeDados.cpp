#ifdef __linux
#elif _WIN32
#include <windows.h>
#else
#endif

#include <cstdlib>
#include <stdlib.h>///para system
#include <stdio.h>
#include <string>
#include <sstream>///para conversao de int para string
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include "CBancodeDados.h"
#include "CFluidodePerfuracao.h"

using namespace std;

vector<CFluidodePerfuracao> CBancodeDados::ler_amostra_basico()
{
/////////////////////////////////////////////////////////////////////////////////////////
//Inicio da leitura das chaves (Primeiro le o arquivo de informacao do banco de dados)
////////////////////////////////////////////////////////////////////////////////////////
  vector<int> chave;///<vetor que armazena as chaves
  vector<CFluidodePerfuracao> amostra_fluido;
  ifstream fin;///<objeto de leitura
  int int_chave;///<inteiro que recebe cada linha lida no arquivo
  unsigned int i;///<inteiro para contagem no for
  
  #ifdef __linux
  caminho_bd<<"bd"<<char(47)<<"ini"<<char(47)<<"bdinfo";
  #elif _WIN32
  caminho_bd<<"bd"<<char(92)<<"ini"<<char(92)<<"bdinfo";
  #else
  
  #endif
  
  fin.open(caminho_bd.str().c_str());///<abre o arquivo de informacoes do bd
  caminho_bd.str("");
  while(! fin.eof())	///<carrega o arquivo de informacoes do bd
  {
    fin >> int_chave;
    chave.push_back(int_chave);
  }
  fin.close();
  
////////////////////////////////////////////
//Termino da leitura das chaves
////////////////////////////////////////////

////////////////////////////////////////////
//Inicio da leitura das amostras
////////////////////////////////////////////
	 
  CFluidodePerfuracao amostra_fluido_aux;///<objeto amostra fluido auxiliar
  
  string caminho_amostra;///<caminho da amostra a ser lida incluindo o nome dela
  string item_amostra;///<string para ler os titulos e subtitulos dos respectivos itens das amostras
  stringstream ss;///<stringstream para conversao de inteiro para string
  num_int=0;///<inicia variavel auxiliar
  i=0;
  
  for(i=0;i<chave.size();i++)///<For para leitura de todas as amostras
  {
    
    #ifdef __linux
    ss<<"bd"<<char(47)<<chave[i]<<char(47)<<chave[i];///<"bd/chave/chave" e exatamente assim que o fin le o arquivo(linux)
    #elif _WIN32
    ss<<"bd"<<char(92)<<chave[i]<<char(92)<<chave[i];///<"bd\chave\chave" e exatamente assim que o fin le o arquivo(windows)
    #else
    
    #endif
    caminho_amostra=ss.str();///<converte o caminho da amostra incluindo o nome para string
    ss.str("");///<apaga conteudo de ss
    fin.open(caminho_amostra.c_str());///<abre todas as amostras existentes    
    
    ///////////////////////////////////////////////////////////////////////////////////
    //lÃª o arquivo de texto e atribui os dados do respectivo objeto amostra_fluido[i]////
    ///////////////////////////////////////////////////////////////////////////////////
    //Nesta etapa usa-se o objeto amostra_fluido_aux para depois de setado ser incluido//
    //no vetor de amostras                                                           //
    ///////////////////////////////////////////////////////////////////////////////////
    
    fin>>item_amostra;///<le a string "-chave"
    fin>>amostra_fluido_aux.chave;///<le a chave da amostra i
    fin>>item_amostra;///<le a string data
    fin>>item_amostra;///<le a string  dia:         
    fin>>amostra_fluido_aux.dia;///<le a string       
    fin>>item_amostra;///<le a string  mes:        
    fin>>amostra_fluido_aux.mes;///<le a string       
    fin>>item_amostra;///<le a string  ano:        
    fin>>amostra_fluido_aux.ano;///<le a string           		
    fin>>item_amostra;///<le a string -nome
    fin>>amostra_fluido_aux.nome_do_fluido;///<le o nome do fluido
    fin>>item_amostra;///<le a string -base
    fin>>amostra_fluido_aux.base;///<le o nome da base
    fin>>item_amostra;///<le a string -teorbase
    fin>>amostra_fluido_aux.teorbase;///<le o teor da base        	 
    fin>>item_amostra;///<le a string -teor_de_agua
    fin>>amostra_fluido_aux.teoragua;///<le o teor de agua
    fin>>item_amostra;///<le a string linha
    fin>>item_amostra;///<le a string PROPRIEDADES FÍSICAS E QUÍMICAS
    fin>>item_amostra;///<le a string pH_min
    fin>>amostra_fluido_aux.pH_min;///<le o pH_min
    fin>>item_amostra;///<le a string pH_max
    fin>>amostra_fluido_aux.pH_max;///<le o pH_max
    fin>>item_amostra;///<le a string --pe_min
    fin>>amostra_fluido_aux.pe_min;///<le pe_min
    fin>>item_amostra;///<le a string --pe_max
    fin>>amostra_fluido_aux.pe_max;///<le pe_max
    fin>>item_amostra;///<le a string --temp_e
    fin>>amostra_fluido_aux.temp_e;///<le temp_e
    fin>>item_amostra;///<le a string --gel_i_ae
    fin>>amostra_fluido_aux.gel_i_ae;///<le gel_i_ae
    fin>>item_amostra;///<le a string --gel_f_ae
    fin>>amostra_fluido_aux.gel_f_ae;///<le gel_f_ae
    fin>>item_amostra;///<le a string --gel_i_de
    fin>>amostra_fluido_aux.gel_i_de;///<le gel_i_de
    fin>>item_amostra;///<le a string --gel_f_de
    fin>>amostra_fluido_aux.gel_f_de;///<le gel_f_de
    fin>>item_amostra;///<le a string --est_el_ae
    fin>>amostra_fluido_aux.est_el_ae;///<le est_el_ae
    fin>>item_amostra;///<le a string --est_el_de
    fin>>amostra_fluido_aux.est_el_de;///<le est_el_de
    fin>>item_amostra;///<le a string -c_lubricidade
    fin>>amostra_fluido_aux.c_lubricidade;///<le c_lubricidade	
    fin>>item_amostra;///<le a string -filtrado
    fin>>amostra_fluido_aux.filtrado;///<le filtrado
    fin>>item_amostra;///<le a string -teor_solidos
    fin>>amostra_fluido_aux.teor_solidos;///<le teor_solidos
    fin>>item_amostra;///<le a string -salinidade
    fin>>amostra_fluido_aux.salinidade;///<le salinidade
    fin>>item_amostra;///<le a string linha
    fin>>item_amostra;///<le a string PROPRIEDADES REOLÓGICAS
    fin>>item_amostra;///<le a string VA_ae
    fin>>amostra_fluido_aux.VA_ae;///<le VA_ae
    fin>>item_amostra;///<le a string VA_de
    fin>>amostra_fluido_aux.VA_de;///<le VA_de
    fin>>item_amostra;///<le a string VP_ae
    fin>>amostra_fluido_aux.VP_ae;///<le VP_ae
    fin>>item_amostra;///<le a string VP_de
    fin>>amostra_fluido_aux.VP_de;///<le VP_de
    fin>>item_amostra;///<le a string LE_ae
    fin>>amostra_fluido_aux.LE_ae;///<le LE_ae
    fin>>item_amostra;///<le a string LE_de
    fin>>amostra_fluido_aux.LE_de;///<le LE_de
    fin>>item_amostra;///<le a string linha
    fin>>item_amostra;///<le a string ADITIVOS
    fin>>item_amostra;///<le a string adensante
    fin>>amostra_fluido_aux.adensante;///<le adensante
    fin>>item_amostra;///<le a string conc_adensante
    fin>>amostra_fluido_aux.conc_adensante;///<le conc_adensante
    fin>>item_amostra;///<le a string inibidor_fa
    fin>>amostra_fluido_aux.inibidor_fa;///<le inibidor_fa
    fin>>item_amostra;///<le a string conc_inibidor_fa
    fin>>amostra_fluido_aux.conc_inibidor_fa;///<le conc_inibidor_fa
    fin>>item_amostra;///<le a string redutor_f
    fin>>amostra_fluido_aux.redutor_f;///<le redutor_f
    fin>>item_amostra;///<le a string conc_redutor_f
    fin>>amostra_fluido_aux.conc_redutor_f;///<le conc_redutor_f
    fin>>item_amostra;///<le a string biopolimero
    fin>>amostra_fluido_aux.biopolimero;///<le biopolimero
    fin>>item_amostra;///<le a string conc_biopolimero
    fin>>amostra_fluido_aux.conc_biopolimero;///<le conc_biopolimero 
    fin>>item_amostra;///<le a string viscosificante
    fin>>amostra_fluido_aux.viscosificante;///<le viscosificante
    fin>>item_amostra;///<le a string conc_viscosificante
    fin>>amostra_fluido_aux.conc_viscosificante;///<le conc_viscosificante  
    fin>>item_amostra;///<le a string dispersante
    fin>>amostra_fluido_aux.dispersante;///<le dispersante
    fin>>item_amostra;///<le a string conc_dispersante
    fin>>amostra_fluido_aux.conc_dispersante;///<le conc_dispersante  
    fin>>item_amostra;///<le a string defloculante
    fin>>amostra_fluido_aux.defloculante;///<le defloculante
    fin>>item_amostra;///<le a string conc_defloculante
    fin>>amostra_fluido_aux.conc_defloculante;///<le conc_defloculante  
    fin>>item_amostra;///<le a string emulsificante
    fin>>amostra_fluido_aux.emulsificante;///<le emulsificante
    fin>>item_amostra;///<le a string conc_emulsificante
    fin>>amostra_fluido_aux.conc_emulsificante;///<le conc_emulsificante 
    fin>>item_amostra;///<le a string biocida
    fin>>amostra_fluido_aux.biocida;///<le biocida
    fin>>item_amostra;///<le a string conc_biocida
    fin>>amostra_fluido_aux.conc_biocida;///<le conc_biocida 
    fin>>item_amostra;///<le a string lubrificante
    fin>>amostra_fluido_aux.lubrificante;///<le lubrificante
    fin>>item_amostra;///<le a string conc_lubrificante
    fin>>amostra_fluido_aux.conc_lubrificante;///<le conc_lubrificante
    fin>>item_amostra;///<le a string inibidor_c
    fin>>amostra_fluido_aux.inibidor_c;///<le inibidor_c
    fin>>item_amostra;///<le a string conc_inibidor_c
    fin>>amostra_fluido_aux.conc_inibidor_c;///<le conc_inibidor_c
    fin>>item_amostra;///<le a string controlador_pH
    fin>>amostra_fluido_aux.controlador_pH;///<le controlador_pH
    fin>>item_amostra;///<le a string controlador_pH
    fin>>amostra_fluido_aux.conc_controlador_pH;///<le conc_controlador_pH
    
    amostra_fluido.push_back(amostra_fluido_aux);
    fin.close();
    
  }
  return amostra_fluido;
  
}

vector<CFluidodePerfuracao> CBancodeDados::ler_amostra_basico(int filtro_)///<funcao listar amostras
{
  vector<CFluidodePerfuracao> amostra_fluido_vec_aux;
  amostra_fluido_vec_aux.clear();
  amostra_fluido_vec_aux=ler_amostra_basico();///<le tododas infos basicas
  ///<de todas amostras
  vector<CFluidodePerfuracao> amostra_fluido;
  amostra_fluido.clear();
  int filtro;
  filtro=filtro_;
  int int_chave;
  unsigned int c;
  double dado_double;
  string nome;
  ///<comeca preencher o vetor de amostras amostra_fluifo
  amostra_fluido.push_back(amostra_fluido_vec_aux[0]);///<retorna a amostra zero como base de calculos
  switch (filtro)///<testa a resposta
    
  {
    case 1:
      cout<<"Informe a CHAVE: ";
      cin>>int_chave;
      cin.get();
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].chave==int_chave)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 2:
      cout<<"Informe o nome do Fluido: ";
      cin>>nome;
      cin.get();
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].nome_do_fluido==nome)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 3:
      cout<<"Informe a Base: ";
      cin>>nome;
      cin.get();
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].base==nome)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 4:
      cout<<"Informe o pH minimo: ";
      
      
      
      cin>>nome;
      cin.get();
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      }
      
      
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].pH_min==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 5:
      cout<<"Informe o pH maximo: ";
      cin>>nome;
      cin.get();
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      }
      
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].pH_max==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
      
      
    case 6:
      cout<<"Informe o Teor de agua: ";
      cin>>nome;
      cin.get();
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      };
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].teoragua==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 7:
      cout<<"Informe o peso especifico minimo: ";
       cin>>nome;
      cin.get();
      
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      }
      
      
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].pe_min==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
     
      
      
    case 8:
      cout<<"Informe o peso especifico maximo: ";
      cin>>nome;
      cin.get();
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      }
      
      
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].pe_max==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
      
      
      
    case 9:
      cout<<"Informe a Temperatura de envelhecimento: ";
      cin>>nome;
      cin.get();
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      }
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].temp_e==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 10:
      cout<<"Informe a Salinidade: ";
      cin>>nome;
      cin.get();
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      }
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].salinidade==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 11:
      cout<<"Informe o volume de filtrado: ";
      cin>>nome;
      cin.get();
      
      if(nome=="-")
      {
	dado_double=999999;
      }
      else
      {
	if(atof(nome.c_str()))
	{
	  dado_double=atof(nome.c_str());
	}
	else
	{
	  dado_double=999999;
	}
      }
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].filtrado==dado_double)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 12:
      cout<<"Informe o Dia: ";
      cin>>dia;
      cin.get();
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].dia==dia)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 13:
      cout<<"Informe o Mes: ";
      cin>>mes;
      cin.get();
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].mes==mes)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
      
    case 14:
      cout<<"Informe o ano: ";
      cin>>ano;
      cin.get();
      for(c=0;c<amostra_fluido_vec_aux.size();c++)///<corre amostras
      {
	if(amostra_fluido_vec_aux[c].ano==ano)
	{
	  amostra_fluido.push_back(amostra_fluido_vec_aux[c]);
	}
      }
      
      break;
      
    case 15: ///< listar todos
      amostra_fluido=amostra_fluido_vec_aux;
      break;
      
    default:
      cout<<"Filtro invalido."<<endl;
      ///<verifica sistema operacional
      #ifdef __linux__
      ///<sleep(1000);
      #elif _WIN32
      Sleep(1000);
      #else
      
      #endif
      resposta=1;
      break;
  }
  
  
  return amostra_fluido;
  
}

void CBancodeDados::exibir_amostra(int chave_)
{
  
  int_chave=chave_;
  CFluidodePerfuracao amostra_aux;
  vector<CFluidodePerfuracao> v_amostra;
  unsigned int c;
  ///lendo todas as amostras basico
  v_amostra=ler_amostra_basico();
  ///procurando amostra correspontende a chave informada
  for(c=0;c<v_amostra.size();c++)
  {
    if (int_chave==v_amostra[c].chave)
    {string teste_vazio(double);
      double teste_vazio(string);
      amostra_aux=v_amostra[c];
      break;
    }
  }
  ///inicia das exibicoes basica das amostras
  cout<<"________________________________________________"<<endl;
  cout<<"                                                "<<endl;
  cout<<"      Exibindo Amostra de Chave "<<int_chave<<"     "<<endl;
  cout<<"________________________________________________"<<endl;
  cout<<endl<<endl;
  cout<<"Data de Cadastro ---- : "<<amostra_aux.dia<<"/"<<amostra_aux.mes<<"/"<<amostra_aux.ano<<endl;
  cout<<"Nome do Fluido -------: "<<amostra_aux.nome_do_fluido<<endl;
  cout<<"Base ---------------- : "<<amostra_aux.base<<endl;
  cout<<"Teor de Base -------- : "<<teste_vazio(amostra_aux.teorbase)<<endl;
  cout<<"Teor de Agua -------- : "<<teste_vazio(amostra_aux.teoragua)<<endl<<endl;
  cout<<"    -----Propriedades Fisicas e Quimicas-----      "<<endl<<endl;
  cout<<"pH Minimo ----------- : "<<teste_vazio(amostra_aux.pH_min)<<endl;
  cout<<"pH Maximo ----------- : "<<teste_vazio(amostra_aux.pH_max)<<endl;
  cout<<"Peso Especifico Minimo: "<<teste_vazio(amostra_aux.pe_min)<<endl;
  cout<<"Peso Especifico Maximo: "<<teste_vazio(amostra_aux.pe_max)<<endl;
  cout<<"Temperatura de envelhecimento: "<<teste_vazio(amostra_aux.temp_e)<<endl;
  cout<<"Forca gel inicial antes do envelhecimento: "<<teste_vazio(amostra_aux.gel_i_ae)<<endl;
  cout<<"Forca gel final antes do envelhecimento: "<<teste_vazio(amostra_aux.gel_f_ae)<<endl;
  cout<<"Forca gel inicial depois do envelhecimento: "<<teste_vazio(amostra_aux.gel_i_de)<<endl;
  cout<<"Forca gel final depois do envelhecimento: "<<teste_vazio(amostra_aux.gel_f_de)<<endl;
  cout<<"Estabilidade eletrica antes do envelhecimento: "<<teste_vazio(amostra_aux.est_el_ae)<<endl;
  cout<<"Estabilidade eletrica depois do envelhecimento: "<<teste_vazio(amostra_aux.est_el_de)<<endl;
  cout<<"Coeficiente de lubricidade: "<<teste_vazio(amostra_aux.c_lubricidade)<<endl;
  cout<<"Volume de filtrado: "<<teste_vazio(amostra_aux.filtrado)<<endl;
  cout<<"Teor de solidos ---------- : "<<teste_vazio(amostra_aux.teor_solidos)<<endl;
  cout<<"Salinidade ---------- : "<<teste_vazio(amostra_aux.salinidade)<<endl<<endl;
  cout<<"    ----Propriedades Reologicas----      "<<endl<<endl;
  cout<<"Viscosidade Aparente antes do envelhecimento: "<<teste_vazio(amostra_aux.VA_ae)<<endl;
  cout<<"Viscosidade Aparente depois do envelhecimento: "<<teste_vazio(amostra_aux.VA_de)<<endl;
  cout<<"Viscosidade Plastica antes do envelhecimento: "<<teste_vazio(amostra_aux.VP_ae)<<endl;
  cout<<"Viscosidade Plastica depois do envelhecimento: "<<teste_vazio(amostra_aux.VP_de)<<endl<<endl;
  cout<<"Limite de escoamento antes do envelhecimento: "<<teste_vazio(amostra_aux.LE_ae)<<endl<<endl;
  cout<<"Limite de escoamento depois do envelhecimento: "<<teste_vazio(amostra_aux.LE_de)<<endl<<endl;
  cout<<"    ----Aditivos----      "<<endl<<endl;
  cout<<"Adensante ----------- : "<<amostra_aux.adensante<<endl;
  cout<<"Concentracao de Adensante ---------- : "<<teste_vazio(amostra_aux.conc_adensante)<<endl;
  cout<<"Inibidor de Formacoes Ativas ------- : "<<amostra_aux.inibidor_fa<<endl;
  cout<<"Concentracao do Inibidor de Formacoes Ativas ---------- : "<<teste_vazio(amostra_aux.conc_inibidor_fa)<<endl;
  cout<<"Redutor de Filtrado  : "<<amostra_aux.redutor_f<<endl;
  cout<<"Concentracao do Redutor de Filtrado ---------- : "<<teste_vazio(amostra_aux.conc_redutor_f)<<endl;
  cout<<"Biopolimero  : "<<amostra_aux.biopolimero<<endl;
  cout<<"Concentracao do Biopolimero ---------- : "<<teste_vazio(amostra_aux.conc_biopolimero)<<endl;
  cout<<"Viscosificante  : "<<amostra_aux.viscosificante<<endl;
  cout<<"Concentracao do Viscosificante---------- : "<<teste_vazio(amostra_aux.conc_viscosificante)<<endl;
  cout<<"Dispersante  : "<<amostra_aux.dispersante<<endl;
  cout<<"Concentracao do Dispersante---------- : "<<teste_vazio(amostra_aux.conc_dispersante)<<endl;
  cout<<"Defloculante  : "<<amostra_aux.defloculante<<endl;
  cout<<"Concentracao do Defloculante---------- : "<<teste_vazio(amostra_aux.conc_defloculante)<<endl;
  cout<<"Emulsificante  : "<<amostra_aux.emulsificante<<endl;
  cout<<"Concentracao do Emulsificante---------- : "<<teste_vazio(amostra_aux.conc_emulsificante)<<endl;
  cout<<"Biocida  : "<<amostra_aux.biocida<<endl;
  cout<<"Concentracao do Biocida---------- : "<<teste_vazio(amostra_aux.conc_biocida)<<endl;
  cout<<"Lubrificante  : "<<amostra_aux.lubrificante<<endl;
  cout<<"Concentracao do Lubrificante---------- : "<<teste_vazio(amostra_aux.conc_lubrificante)<<endl;
  cout<<"Inibidor de corrosao  : "<<amostra_aux.inibidor_c<<endl;
  cout<<"Concentracao do Inibidor de Corrosao---------- : "<<teste_vazio(amostra_aux.conc_inibidor_c)<<endl;
  cout<<"Controlador de pH  : "<<amostra_aux.controlador_pH<<endl;
  cout<<"Concentracao do Controlador de pH---------- : "<<teste_vazio(amostra_aux.conc_controlador_pH)<<endl;
  cout<<endl<<endl;
}

void CBancodeDados::listar_amostra(vector<CFluidodePerfuracao> amostra_fluido_)///<funcao listar amostras
{
  
  i=0;///<inteiro para contagem no for
  
  amostra_fluido=amostra_fluido_;
  ////////////////////////////////////////////
  //Inicia a listagem das amostras lidas no disco
  ////////////////////////////////////////////
  //escreve linha superior ao titulo dos atributos das amostras
  for(i=0;i<90;i++)
  {
    
    #ifdef __linux
    cout<<"\u2500";
    #elif _WIN32
    cout<<(char)196;
    #else
    
    #endif
    
  }
  cout<<endl;//finaliza linha
  ///<escreve titulo dos atributos das amostras
  cout.setf(ios::left);
  cout.width(7);
  cout<<"CHAVE";
  
  cout.setf(ios::left);
  cout.width(20);
  cout<<"NOME DO FLUIDO";
  
  cout.setf(ios::left);
  cout.width(10);
  cout<<"BASE";
  
  cout.setf(ios::left);
  cout.width(20);
  cout<<"TEOR DE BASE";
  
  cout.setf(ios::left);
  cout.width(20);
  cout<<"TEOR DE AGUA";
  
  cout.setf(ios::left);
  cout.width(20);
  cout<<"DATA";
  
  cout<<endl;///finaliza titulo dos itens
  
  ///escreve a linha abaixo do titulo das tabelas
  for(i=0;i<90;i++)
  {
    #ifdef __linux
    cout<<"\u2500";
    #elif _WIN32
    cout<<(char)196;
    #else
    
    #endif
  }
  
  ///escreve os atributos das amostras na tela
  
  cout<<endl;///<pula linha para primeira listagem
  for(i=0;i<amostra_fluido.size();i++)///</<comeca listar da 1, amostra zero é a base
  {
    
    if(amostra_fluido[i].chave!=0)
    {
      
      cout.setf(ios::left);
      cout.width(7);
      cout<<amostra_fluido[i].chave;///<escreve as chaves
      
      cout.setf(ios::left);
      cout.width(20);
      cout<<amostra_fluido[i].nome_do_fluido;///<escreve o nome do fluido
      
      cout.setf(ios::left);
      cout.width(10);
      cout<<amostra_fluido[i].base;///<escreve a base
      
      cout.setf(ios::left);
      cout.width(20);
      cout<<teste_vazio(amostra_fluido[i].teorbase);///<escreve o teor de base
      
      cout.setf(ios::left);
      cout.width(20);
      cout<<teste_vazio(amostra_fluido[i].teoragua);///<escreve o teor de agua
      
      cout.setf(ios::left);
      cout.width(20);
      if(amostra_fluido[i].dia<10)ss<<0;
			ss<<amostra_fluido[i].dia<<"/";
      if(amostra_fluido[i].mes<10)ss<<0;
			ss<<amostra_fluido[i].mes<<"/";
      if(amostra_fluido[i].ano<10)ss<<0;
			ss<<amostra_fluido[i].ano;///<constroi data
			cout<<ss.str();
      ss.str("");
      
      cout<<endl;///<pula linha antes das pausas
      
    }
  }
  
  i=0;
  cout<<endl;
  
  ///escreve linha inferior
  for(i=0;i<90;i++)
  {
    #ifdef __linux
    cout<<"\u2500";
    #elif _WIN32
    cout<<(char)196;
    #else
    
    #endif
  }
  cout<<endl;
  chave.clear();
}

void CBancodeDados::listar_amostra(vector<CFluidodePerfuracao> amostra_fluido_, int filtro_)//funcao listar amostras
{
  
  i=0;
  filtro=filtro_;
  amostra_fluido=amostra_fluido_;
  ////////////////////////////////////////////
  //Inicia a listagem das amostras lidas no disco
  ////////////////////////////////////////////
  //escreve linha superior ao titulo dos atributos das amostras
  for(i=0;i<80;i++)
  {
    
    #ifdef __linux
    cout<<"\u2500";
    #elif _WIN32
    cout<<(char)196;
    #else
    
    #endif
    
  }
  cout<<endl;//finaliza linha
  ///<escreve titulo dos atributos das amostras
  cout.setf(ios::left);
  cout.width(10);
  cout<<"CHAVE";
  
  cout.setf(ios::left);
  cout.width(20);
  cout<<"NOME DO FLUIDO";
  
  cout.setf(ios::left);
  cout.width(20);
  cout<<"TEOR DE BASE";
  
  switch(filtro)
  {
    
    case 3:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"Base";
      break;
      
    case 4:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"pH minimo";
      break;
      
    case 5:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"pH maximo";
      break;
      
    case 6:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"Teor de agua";
      break;
      
    case 7:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"Peso especifico minimo";
      break;
      
    case 8:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"Peso especifico maximo";
      break;
      
    case 9:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"Temperatura de envelhecimento";
      break;
      
    case 10:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"Salinidade";
      break;
      
    case 11:
      cout.setf(ios::left);
      cout.width(20);
      cout<<"Filtrado";
      break;
      
    case 12:
      cout.setf(ios::left);
      cout.width(10);
      cout<<"Dia";
      break;
      
     case 13:
      cout.setf(ios::left);
      cout.width(10);
      cout<<"Mes";
      break;
      
    case 14:
      cout.setf(ios::left);
      cout.width(10);
      cout<<"Ano";
      break;
      
  }
  cout<<endl;//finaliza titulo dos itens
  
  ///escreve a linha abaixo do titulo das tabelas
  for(i=0;i<80;i++)
  {
    #ifdef __linux
    cout<<"\u2500";
    #elif _WIN32
    cout<<(char)196;
    #else
    
    #endif
  }
  
  ///<escreve os atributos das amostras na tela
  for(i=0;i<amostra_fluido.size();i++)
  {
    if(amostra_fluido[i].chave!=0) ///<nao lista amostra de chave zero
    {
      
      
      cout<<endl;
      
      cout.setf(ios::left);
      cout.width(10);
      cout<<amostra_fluido[i].chave;///<escreve as chaves
      
      cout.setf(ios::left);
      cout.width(20);
      cout<<amostra_fluido[i].nome_do_fluido;///<escreve o nome do fluido
      
      cout.setf(ios::left);
      cout.width(20);
      cout<<teste_vazio(amostra_fluido[i].teorbase);///<escreve o teor de base
      
      
      switch(filtro)
      {
	
	case 3:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].base);
	  break;
	  
	case 4:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].pH_min);
	  break;
	  
	case 5:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].pH_max);
	  break;
	  
	case 6:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].teoragua);
	  break;
	  
	case 7:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].pe_min);
	  break;
	  
	case 8:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].pe_max);
	  break;
	  
	case 9:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].temp_e);
	  break;
	  
	case 10:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].salinidade);
	  break;
	  
	case 11:
	  cout.setf(ios::left);
	  cout.width(20);
	  cout<<teste_vazio(amostra_fluido[i].filtrado);
	  break;
	  
	case 12:
	  cout.setf(ios::left);
	  cout.width(20);
	  if(amostra_fluido[i].dia<10)ss<<0;
			ss<<amostra_fluido[i].dia;
	  cout<<ss.str();
	  ss.str("");
	  break;
	  
	case 13:
	  cout.setf(ios::left);
	  cout.width(20);
	  if(amostra_fluido[i].mes<10)ss<<0;
			ss<<amostra_fluido[i].mes;
	  cout<<ss.str();
	  ss.str("");
	  break;
	  
	case 14:
	  cout.setf(ios::left);
	  cout.width(20);
	  if(amostra_fluido[i].ano<10)ss<<0;
			ss<<amostra_fluido[i].ano;
	  cout<<ss.str();
	  ss.str("");
	  break;  
      }
      
    }
    
    
    }
    i=0;
    cout<<endl;
    
    ///escreve linha inferior
    for(i=0;i<80;i++)
    {
      #ifdef __linux
      cout<<"\u2500";
      #elif _WIN32
      cout<<(char)196;
      #else
      
      #endif
    }
    cout<<endl;
    chave.clear();
  }

  void CBancodeDados::excluir_amostra(int int_chave_)
  {
    /////////////////////////////////////
    //Inicio da exclusao chave
    ////////////////////////////////////
    vector<int> chave;///<vetor que armazena as chaves
    
    int_chave=int_chave_;///<inteiro que recebe chave informada
    
    //abre o arquivo de informacoes do bd
    #ifdef __linux
    caminho_bd<<"bd"<<char(47)<<"ini"<<char(47)<<"bdinfo";
    #elif _WIN32
    caminho_bd<<"bd"<<char(92)<<"ini"<<char(92)<<"bdinfo";
    #else
    
    #endif
    fin.open(caminho_bd.str().c_str());
    caminho_bd.str("");
    ///<carrega o arquivo de informacoes do bd
    while(! fin.eof())
    {
      fin >> int_chave_aux;
      chave.push_back(int_chave_aux);
    }
    fin.close();
    ///<inicia pesquisa da chave a ser deletada
    for(i=0;i<=chave.size();i++)
    {
      if (chave[i]==int_chave)
      {
	chave.erase(chave.begin() + i);///<deleta a chave encontrada
      }
    }
    
    ///reescreve vetor no arquivo bdinfo
    ofstream fout;
    #ifdef __linux
    caminho_bd<<"bd"<<char(47)<<"ini"<<char(47)<<"bdinfo";
    #elif _WIN32
    caminho_bd<<"bd"<<char(92)<<"ini"<<char(92)<<"bdinfo";
    #else
    
    #endif
    fout.open(caminho_bd.str().c_str());///<abre bdinfo para escrever informacoes atualizadas
    caminho_bd.str("");
    ///testa se nao abriu o arquivo
    if(fout.fail())
    {
      cout<<"Nao foi possivel reescrever a chave."<<endl;
    }
    for(i=0;i<(chave.size()-1);i++)///<escreve ate o punultimo item do vetor chave pulando linha
    {
      fout<<chave[i]<<endl;
    }
    ///<para nÃ£o pular linha ao fim do arquivo, escreve o ultimo item do vetor chave
    fout<<chave[i];
    fout.close();///<fecha o arquivo de informaÃ§Ãµes do banco de dados
    i=0;
    ////////////////////////////////////
    //Fim da exclusao chave
    ////////////////////////////////////
    ////////////////////////////////////
    //Inicio da remocao da amostra para \lixo
    ////////////////////////////////////
    stringstream comando_remover;///<DeclaraÃ§ao das variaveis do comando de remover para lixeira
    ///criar o comando a ser executado
    ///comando: "move bd\0.txt bd\lixo" Comando para mover o arquivo da amostra
    comando_remover.str("");///<apagand stringstream
    ///verifica sistema operacional
    #ifdef __linux
    ///mv ./bd/0.txt ./bd/lixo
    comando_remover<<"mv"<<" "<<"./bd/"<<int_chave<<" "<<"./bd/lixo";
    #elif _WIN32
    comando_remover<<"move"<<" "<<"bd"<<char(92)<<int_chave<<" "<<"bd"<<char(92)<<"lixo";
    
    #else
    
    #endif
    system(comando_remover.str().c_str());///<Manda o comando pro prompt para mover o arquivo p lixeira
    comando_remover.str("");///<apagand stringstream
    
    }
  
  string CBancodeDados::teste_vazio(double num_double_)
  {
    num_double_ss.str("");
    num_double=num_double_;
    const_vazio_num_double=999999;
    if(num_double==const_vazio_num_double)
    {
      return("-");
    }
    else
    {
      num_double_ss<<num_double;///<converte o double para string
      return(num_double_ss.str());
    }
  }

  double CBancodeDados::teste_vazio(string vazio_str_)
  {
    double dado_double;
    vazio_str=vazio_str_;
    const_vazio_str="-";
    if(vazio_str==const_vazio_str)
    {
      return 999999;
    }
    else
    {
      return dado_double=atof(vazio_str.c_str());///<converte a string que entrou para double
    }
  }
  
  void CBancodeDados::inserir_amostra()
  {
    ///Inclusao de chave no arquivo bdinfo
    
    vector<int> chave;///<vetor que armazena as chaves
    ifstream fin;///<objeto de leitura
    int int_chave;///<inteiro que recebe cada linha lida no arquivo
    
    #ifdef __linux
    caminho_bd<<"bd"<<char(47)<<"ini"<<char(47)<<"bdinfo";
    #elif _WIN32
    caminho_bd<<"bd"<<char(92)<<"ini"<<char(92)<<"bdinfo";
    #else
    
    #endif
    
    fin.open(caminho_bd.str().c_str());///<abre o arquivo de informacoes do bd usando metodos que retorna uma string de um numero e converte a string C++ para para padrao C
    caminho_bd.str("");
    while(! fin.eof())///<carrega o arquivo de informacoes do bd(chaves) e realiza leitura até o final do arquivo
    {
      fin >> int_chave;
      chave.push_back(int_chave);
    }
    fin.close();
    
    ///Escrita da nova chave
    #ifdef __linux
    caminho_bd<<"bd"<<char(47)<<"ini"<<char(47)<<"bdinfo";
    #elif _WIN32
    caminho_bd<<"bd"<<char(92)<<"ini"<<char(92)<<"bdinfo";
    #else
    
    #endif
    
    ofstream fout;
    fout.open(caminho_bd.str().c_str(),ios::app);///<abre bdinfo e vai para o final do arquivo
    caminho_bd.str("");
    ///testa se nao abriu o arquivo
    if(fout.fail())
    {
      cout<<"Nao foi possivel inserir amostra."<<endl;
    }
    
    int_chave++;///<soma ultima chave mais um
    fout<<endl;///<pula uma linha para inserir a chave
    fout<<int_chave;///<escreve a chave posterior no fim do arquivo
    
    fout.close();
    
    ///Fim da inclusao da chave
    
    ///Inclusao do novo arquivo para novo fluido
    
    ///cria diretorio
    #ifdef __linux
    comando_caminho_amostra<<"mkdir "<<"bd"<<char(47)<<int_chave;///< comando mkdir cria diretorio
    #elif _WIN32
    comando_caminho_amostra<<"mkdir "<<"bd"<<char(92)<<int_chave;
    #else
    
    #endif
    
    system(comando_caminho_amostra.str().c_str());///<cria o diretorio a ser gravado os arquivos
    comando_caminho_amostra.str("");///<apaga stringstream
    
    ///<Formar nome do arquivo
    
    #ifdef __linux
    nome_amostra<<"bd"<<char(47)<<int_chave<<char(47)<<int_chave;
    #elif _WIN32
    nome_amostra<<"bd"<<char(92)<<int_chave<<char(92)<<int_chave;
    #else
    
    #endif
    
    ///Escrita no arquivo do novo fluido
    
    fout.open(nome_amostra.str().c_str());///<abre o arquivo
    nome_amostra.str("");
    
    string nome;
    float num;
   
    cout<<"---------------------------------"<<endl;
    cout<<"Preencha com os dados da amostra: "<<endl;
    cout<<"Para dado numerico nulo, informe "<<endl;
    cout<<"apenas um -        .              "<<endl;
    cout<<"---------------------------------"<<endl;
    fout<<"-chave:"<<endl;///<escreve o titulo chave
    fout<<int_chave<<endl;///<escreve a chave
    
    fout<<"-data: "<<endl;///<escreve a string -data:
    fout<<"--dia: "<<endl;///<escreve a string --dia:
    cout<<"Data de Cadastro da Amostra: "<<endl;;
    repetedia:
    
    cout<<"Dia: ";
    while(!(cin>>num_int))///<correcao de erro caso entre alguma resposta errada
    {
      cin.clear();
      cin>>ch;
      cout<<endl<<"Resposta Incorreta!"<<endl;
      cin.get();
      goto repetedia;///<nao aceita dia maior que 31
    }
    
    if (num_int>31)
    {
      cout<<endl<<"Resposta Incorreta!"<<endl;
      cout<<"Dia maior que 31!"<<endl;
      goto repetedia;///<nao aceita dia maior que 31
    }
    fout<<num_int<<endl;
    
    fout<<"--mes: "<<endl;///<escreve a string --dia:
    repetemes:
    cout<<"Mes: ";
    while(!(cin>>num_int))///<correcao de erro caso entre alguma resposta errada
    {
      cin.clear();
      cin>>ch;
      cin.get();
      cout<<endl<<"Resposta Incorreta!"<<endl;
      goto repetemes;///<nao aceita dia maior que 31
    }
    
    if (num_int>12)
    {
      cout<<endl<<"Resposta Incorreta!"<<endl;
      cout<<"Mes maior que 12!"<<endl;
      goto repetemes;///<nao aceita dia maior que 31
    }
    fout<<num_int<<endl;
    
    fout<<"--ano: "<<endl;///<escreve a string --dia:
    cout<<"Ano: ";
    while(!(cin>>num_int))///<correcao de erro caso entre alguma resposta errada
    {
      cin.clear();
      cin>>ch;
      cout<<endl<<"Resposta Incorreta!"<<endl;
    }
    cin.get();
    fout<<num_int<<endl;
    
    fout<<"-Nome_do_Fluido_de_Perfuracao: "<<endl;///<escreve o titulo bacia
    cout<<"Nome do Fluido de Perfuracao (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Base: "<<endl;///<escreve o titulo bacia
    cout<<"Base : ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Teor_da_base: "<<endl;
    
    cout<<"Teor da base: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    
    fout<<"-teor_de_agua: "<<endl;
    cout<<"Teor de Agua: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"_____________________________________________________________________"<<endl;
    fout<<"PROPRIEDADES_FISICAS_E_QUIMICAS"<<endl;
    fout<<"-pH_min: "<<endl;
    cout<<"pH minimo:  ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-pH_max: "<<endl;
    cout<<"pH maximo: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    
    fout<<"-Peso_especifico_min: "<<endl;
    cout<<"Peso especifico minimo: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Peso_especifico_max: "<<endl;
    
    cout<<"Peso especifico maximo: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Temperatura_envelhecimento: "<<endl;
    
    cout<<"Temperatura do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Forca_gel_inicial_antes_do_envelhecimento: "<<endl;
    
    cout<<"Forca gel inicial antes do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Forca_gel_final_antes_do_envelhecimento: "<<endl;
    
    cout<<"Forca gel final antes do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Forca_gel_inicial_depois_do_envelhecimento: "<<endl;
    
    cout<<"Forca gel inicial depois do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Forca_gel_final_depois_do_envelhecimento: "<<endl;
    
    cout<<"Forca gel final depois do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    
    fout<<"-Estabilidade_eletrica_antes_do_envelhecimento: "<<endl;
    
    cout<<"Estabilidade eletrica antes do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Estabilidade_eletrica_depois_do_envelhecimento: "<<endl;
    
    cout<<"Estabilidade eletrica depois do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Coeficiente_de_lubricidade: "<<endl;
    
    cout<<"Coeficiente de Lubricidade: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Volume_de_Filtrado: "<<endl;
    
    cout<<"Volume de Filtrado: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Teor_de_solidos: "<<endl;
    
    cout<<"Teor de solidos: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Salinidade: "<<endl;
    
    cout<<"Salinidade: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"_____________________________________________________________"<<endl;
    fout<<"PROPRIEDADES_REOLOGICAS"<<endl;
    fout<<"-Viscosidade_aparente_antes_do_envelhecimento: "<<endl;
    
    cout<<"Viscosidade aparente antes do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Viscosidade_aparente_depois_do_envelhecimento: "<<endl;
    
    cout<<"Viscosidade aparente depois do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl; 
    
    fout<<"-Viscosidade_plastica_antes_do_envelhecimento: "<<endl;
    
    cout<<"Viscosidade plastica antes do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Viscosidade_plastica_depois_do_envelhecimento: "<<endl;
    
    cout<<"Viscosidade plastica depois do envelhecimento: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Limite_de_escoamento_antes_do_envelhecimento: "<<endl;
    
    cout<<"Limite de Escoamento antes do envelheciemnto:  ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"-Limite_de_escoamento_depois_do_envelhecimento: "<<endl;
    
    cout<<"Limite de Escoamento depois do envelheciemnto:  ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    fout<<num<<endl;
    
    fout<<"_____________________________________________________________"<<endl;
    fout<<"ADITIVOS"<<endl;
    fout<<"-Adensante: "<<endl;
    cout<<"Adensante utilizado (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_adensante: "<<endl;
    
    cout<<" Concentracao do adensante: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Inibidor_de_formacoes_ativas: "<<endl;
    cout<<"Inibidor de formacoes ativas (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentração_do_inibidor_de_formacoes_ativas: "<<endl;
    
    cout<<"Concentração do Inibidor de formacoes ativas: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Redutor_de_filtrado: "<<endl;
    cout<<"Redutor de filtrado (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_redutor_de_filtrado: "<<endl;
    
    cout<<"Concentracao do redutor de filtrado: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Biopolimero: "<<endl;
    cout<<"Biopolimero (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_biopolimero: "<<endl;
    
    cout<<"Concentracao do biopolimero  :";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Viscosificante: "<<endl;
    cout<<"Viscosificante (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_viscosificante: "<<endl;
    
    cout<<"Concentracao do viscosificante: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Dispersante: "<<endl;
    cout<<"Dispersante (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_dispersante: "<<endl;
    
    cout<<"Concentracao do dispersante: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Defloculante: "<<endl;
    cout<<"Defloculante (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_defloculante: "<<endl;
    
    cout<<"Concentracao do defloculante: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Emulsificante: "<<endl;
    cout<<"Emulsificante (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_emulsificante: "<<endl;
    
    cout<<"Concentracao do emulsificante: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Biocida: "<<endl;
    cout<<"Biocida (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_biocida: "<<endl;
    
    cout<<"Concentracao do biocida: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Lubrificante: "<<endl;
    cout<<"Lubrificante (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_lubrificante: "<<endl;
    
    cout<<"Concentracao do lubrificante: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Inibidor_de_corrosao: "<<endl;
    cout<<"Inibidor de corrosao (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_inibidor_de_corrosao: "<<endl;
    
    cout<<"Concentracao do inibidor de corrosao: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout<<"-Controlador_de_pH: "<<endl;
    cout<<"Controlador de pH (9 caracteres): ";
    cin>>nome;
    cin.get();
    fout<<nome<<endl;
    
    fout<<"-Concentracao_do_controlador_de_pH: "<<endl;
    cout<<"Concentracao do controlador de pH: ";
    cin>>nome;
    cin.get();
    
    if(nome=="-")
    {
      num=999999;
    }
    else
    {
      if(atof(nome.c_str()))
      {
	num=atof(nome.c_str());
      }
      else
      {
	num=999999;
      }
    }
    
    fout<<num<<endl;
    
    fout.close();
    
    
    ////////////////////////////////////
    //fim da inclusao do arquivo basico
    ///////////////////////////////////
  }
  

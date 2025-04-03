#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

///verifica sistema operacional
#ifdef __linux

    #include <cstdlib>

#elif _WIN32

    #include <windows.h>
    #include <stdlib.h>///<para system
    #include <conio.h>

#else

#endif


#include "CRelatorio.h"
#include "CFluidodePerfuracao.h"
#include "CBancodeDados.h"

void CRelatorio::exportar_amostra(int chave_)
{
  chave=chave_;
  
  ///criando o diretorio para salvar o relatorio de chave n
  #ifdef __linux
  ss<<"mkdir "<<"DT"<<char(47)<<"relatorios"<<char(47)<<chave;///<DT/relatorios/1
  #elif _WIN32
  ss<<"mkdir "<<"DT"<<char(92)<<"relatorios"<<char(92)<<chave;///<DT\relatorios\1
  #else
  
  #endif
  
  system(ss.str().c_str());///<cria o diretorio a ser gravado os arquivos
  ss.str("");///<apaga stringstream
  
  ///////////////////////////////////////
  /////inicia leitura basica das amostras
  ///////////////////////////////////////
  
  ///pesquisa amostra de chave n
  int_chave=chave_;
  CFluidodePerfuracao amostra_aux;
  vector<CFluidodePerfuracao> v_amostra;
  unsigned int c;
  ///lendo todas as amostras basico
  v_amostra=lerbasico.ler_amostra_basico();
  ///procurando amostra correspontende a chave informada
  for(c=0;c<v_amostra.size();c++)
  {
    if (int_chave==v_amostra[c].chave)
    {
      amostra_aux=v_amostra[c];
      break;
    }
  }
  ///////////////////////////////////////
  /////Termina leitura Basica das amostras
  ///////////////////////////////////////
  ss.str("");///<apaga stringstream
  
  #ifdef __linux
  ss<<"DT"<<char(47)<<"relatorios"<<char(47)<<chave<<char(47)<<"Amostra-"<<chave<<"-completa.txt";///<
  #elif _WIN32
  ss<<"DT"<<char(92)<<"relatorios"<<char(92)<<chave<<char(92)<<"Amostra-"<<chave<<"-completa.txt";
  #else
  
  #endif
  
  fout.open(ss.str().c_str());///<abre arquivo para escrita
  ss.str("");
  /////////////////////////////////////////////////////////////////////////
  ////////////INICIO DA ESCRITA DO CODIGO
  /////////////////////////////////////////////////////////////////////////
  
  ///inicia das exibicoes basica das amostras
  fout<<"________________________________________________"<<endl;
  fout<<"                                                "<<endl;
  fout<<"      Relatório da Amostra de Chave "<<int_chave<<"     "<<endl;
  fout<<"________________________________________________"<<endl;
  fout<<endl<<endl;
  fout<<"Data de Cadastro ---- : "<<amostra_aux.dia<<"/"<<amostra_aux.mes<<"/"<<amostra_aux.ano<<endl;
  fout<<"Nome do Fluido -------: "<<amostra_aux.nome_do_fluido<<endl;
  fout<<"Base ---------------- : "<<amostra_aux.base<<endl;
  fout<<"Teor de Base -------- : "<<lerbasico.teste_vazio(amostra_aux.teorbase)<<endl;
  fout<<"Teor de Agua -------- : "<<lerbasico.teste_vazio(amostra_aux.teoragua)<<endl;
  fout<<"    -----Propriedades Físicas e químicas-----      "<<endl;
  fout<<"pH Mínimo ----------- : "<<lerbasico.teste_vazio(amostra_aux.pH_min)<<endl;
  fout<<"pH Máximo ----------- : "<<lerbasico.teste_vazio(amostra_aux.pH_max)<<endl;
  fout<<"Peso Específico Mínimo: "<<lerbasico.teste_vazio(amostra_aux.pe_min)<<endl;
  fout<<"Peso Específico Máximo: "<<lerbasico.teste_vazio(amostra_aux.pe_max)<<endl;
  fout<<"Temperatura de envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.temp_e)<<endl;
  fout<<"Força gel inicial antes do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.gel_i_ae)<<endl;
  fout<<"Força gel inicial depois do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.gel_i_de)<<endl;
  fout<<"Força gel final antes do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.gel_f_ae)<<endl;
  fout<<"Força gel final depois do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.gel_f_de)<<endl;
  fout<<"Estabilidade elétrica antes do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.est_el_ae)<<endl;
  fout<<"Estabilidade elétrica depois do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.est_el_de)<<endl;
  fout<<"Coeficiente de lubricidade: "<<lerbasico.teste_vazio(amostra_aux.c_lubricidade)<<endl;
  fout<<"Volume de filtrado: "<<lerbasico.teste_vazio(amostra_aux.filtrado)<<endl;
  fout<<"Teor de sólidos ----- : "<<lerbasico.teste_vazio(amostra_aux.teor_solidos)<<endl;
  fout<<"Salinidade ---------- : "<<lerbasico.teste_vazio(amostra_aux.temp_e)<<endl;
  fout<<"    ----Propriedades Reológicas----      "<<endl;
  fout<<"Viscosidade Aparente antes do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.VA_ae)<<endl;
  fout<<"Viscosidade Aparente depois do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.VA_de)<<endl;
  fout<<"Viscosidade Plástica antes do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.VP_ae)<<endl;
  fout<<"Viscosidade Plástica depois do envelhecimento: "<<lerbasico.teste_vazio(amostra_aux.VP_de)<<endl;
  fout<<"    ----Aditivos----      "<<endl;
  fout<<"Adensante ----------- : "<<amostra_aux.adensante<<endl;
  fout<<"Concentração de Adensante ---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_adensante)<<endl;
  fout<<"Inibidor de Formações Ativas ------- : "<<amostra_aux.inibidor_fa<<endl;
  fout<<"Concentração do Inibidor de Formações Ativas ---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_inibidor_fa)<<endl;
  fout<<"Redutor de Filtrado - : "<<amostra_aux.redutor_f<<endl;
  fout<<"Concentração do Redutor de Filtrado ---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_redutor_f)<<endl;
  fout<<"Biopolimero - : "<<amostra_aux.biopolimero<<endl;
  fout<<"Concentração do Biopolimero ---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_biopolimero)<<endl;
  fout<<"Viscosificante - : "<<amostra_aux.viscosificante<<endl;
  fout<<"Concentração do Viscosificante---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_viscosificante)<<endl;
  fout<<"Dispersante - : "<<amostra_aux.dispersante<<endl;
  fout<<"Concentração do Dispersante---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_dispersante)<<endl;
  fout<<"Defloculante - : "<<amostra_aux.defloculante<<endl;
  fout<<"Concentração do Defloculante---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_defloculante)<<endl;
  fout<<"Emulsificante - : "<<amostra_aux.emulsificante<<endl;
  fout<<"Concentração do Emulsificante---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_emulsificante)<<endl;
  fout<<"Biocida - : "<<amostra_aux.biocida<<endl;
  fout<<"Concentração do Biocida---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_biocida)<<endl;
  fout<<"Lubrificante - : "<<amostra_aux.lubrificante<<endl;
  fout<<"Concentração do Lubrificante---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_lubrificante)<<endl;
  fout<<"Inibidor de corrosão - : "<<amostra_aux.inibidor_c<<endl;
  fout<<"Concentração do Inibidor de Corrosão---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_inibidor_c)<<endl;
  fout<<"Controlador de pH - : "<<amostra_aux.controlador_pH<<endl;
  fout<<"Concentração do Controlador de pH---------- : "<<lerbasico.teste_vazio(amostra_aux.conc_controlador_pH)<<endl;
  fout<<endl<<endl;
  
  
  ///////////////////////////////////////////////////////////
  ////////FIM DA ESCRITA DO CODIGO
  //////////////////////////////////////////////////////////
  
  fout.close();
}



       

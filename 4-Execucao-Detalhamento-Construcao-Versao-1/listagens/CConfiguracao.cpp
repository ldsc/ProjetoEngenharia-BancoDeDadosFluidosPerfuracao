#include <iostream>
#include <stdio.h>
///verifica sistema operacional
#ifdef __linux

#include <cstdlib>

#elif _WIN32

#include <windows.h>
#include <stdlib.h>///<para system
#include <conio.h>

#else

#endif

#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>

#include "CConfiguracao.h"

using namespace std;

int CConfiguracao::opcao_abrir_DT()
{
  caminho_ss.str("");
  #ifdef __linux
  caminho_ss<<"config"<<char(47)<<"DT.ini";
  #elif _WIN32
  caminho_ss<<"config"<<char(92)<<"DT.ini";
  #else
  
  #endif
  fin.open(caminho_ss.str().c_str());
  if(fin.fail())
  {
    cout<<"Não foi possivel ler."<<endl;
  }
  caminho_ss.str("");
  fin>>opcao;
  fin.close();
  return opcao;
}


void CConfiguracao::opcao_abrir_DT(int opcao_)
{
  opcao=opcao_;
  caminho_ss.str("");
  #ifdef __linux
  caminho_ss<<"config"<<char(47)<<"DT.ini";
  #elif _WIN32
  caminho_ss<<"config"<<char(92)<<"DT.ini";
  #else
  
  #endif
  fout.open(caminho_ss.str().c_str());
  if(fout.fail())
  {
    cout<<"Não foi possivel editar."<<endl;
  }
  caminho_ss.str("");
  fout<<opcao;
  fout.close();
}

void CConfiguracao::opcao_programa(string tipo_programa_, string nome_programa_)
{
  tipo_programa=tipo_programa_;
  nome_programa=nome_programa_;
  caminho_ss.str("");
  #ifdef __linux
  caminho_ss<<"config"<<char(47)<<"programas.ini";
  #elif _WIN32
  caminho_ss<<"config"<<char(92)<<"programas.ini";
  #else
  
  #endif
  ///le o arquivo todo
  fin.open(caminho_ss.str().c_str());
  if(fin.fail())
  {
    cout<<"Não foi possivel ler."<<endl;
  }
  caminho_ss.str("");
  fin>>str;
  fin>>str;
  fin>>str;
  fin>>str;
  
  fin>>nome_explorador_windows;
  fin>>nome_explorador_linux;
  fin>>str;
  
  fin>>nome_editor_texto_windows;
  fin>>nome_editor_texto_linux;
  
  fin.close();
  
  caminho_ss.str("");
  #ifdef __linux
  caminho_ss<<"config"<<char(47)<<"programas.ini";
  #elif _WIN32
  caminho_ss<<"config"<<char(92)<<"programas.ini";
  #else
  
  #endif
  
  ///escreve o arquivo
  fout.open(caminho_ss.str().c_str());
  if(fout.fail())
  {
    cout<<"Não foi possivel editar."<<endl;
  }
  caminho_ss.str("");
  fout<<"Tipo-do-Programa:"<<endl;
  fout<<"nome-windows"<<endl;
  fout<<"nome-linux"<<endl;
  fout<<"explorador:"<<endl;
  if(tipo_programa=="explorador")
  {
    #ifdef __linux
    fout<<nome_explorador_windows<<endl;
    fout<<nome_programa<<endl;
    #elif _WIN32
    fout<<nome_programa<<endl;
    fout<<nome_explorador_linux<<endl;
    #else
    
    #endif
  }
  else
  {
    fout<<nome_explorador_windows<<endl;
    fout<<nome_explorador_linux<<endl;
  }
  
  
  
  fout<<"editor-texto:"<<endl;
  if(tipo_programa=="editortexto")
  {
    #ifdef __linux
    fout<<nome_editor_texto_windows<<endl;
    fout<<nome_programa<<endl;
    #elif _WIN32
    fout<<nome_programa<<endl;
    fout<<nome_editor_texto_linux<<endl;
    #else
    
    #endif
  }
  else
  {
    fout<<nome_editor_texto_windows<<endl;
    fout<<nome_editor_texto_linux<<endl;
  }
  
  
  fout<<endl;
  fout<<"#OBS: O nome do programa é o mesmo que você digita no cmd do windows"<<endl;
  fout<<"#ou no terminal do linux."<<endl;
  fout.close();
  
}

string CConfiguracao::opcao_programa(string tipo_programa_)
{
  tipo_programa=tipo_programa_;
  caminho_ss.str("");
  #ifdef __linux
  caminho_ss<<"config"<<char(47)<<"programas.ini";
  #elif _WIN32
  caminho_ss<<"config"<<char(92)<<"programas.ini";
  #else
  
  #endif
  ///le o arquivo todo
  fin.open(caminho_ss.str().c_str());
  if(fin.fail())
  {
    cout<<"Não foi possivel ler."<<endl;
  }
  caminho_ss.str("");
  fin>>str;
  fin>>str;
  fin>>str;
  fin>>str;
  
  fin>>nome_explorador_windows;
  fin>>nome_explorador_linux;
  
  fin>>str;
  
  fin>>nome_editor_texto_windows;
  fin>>nome_editor_texto_linux;
  
  fin.close();
  
  
  if(tipo_programa=="explorador")
  {
    #ifdef __linux
    nome_programa = nome_explorador_linux;
    #elif _WIN32
    nome_programa = nome_explorador_windows;
    #else
    
    #endif
  }
  
  if(tipo_programa=="editortexto")
  {
    #ifdef __linux
    nome_programa = nome_editor_texto_linux;
    #elif _WIN32
    nome_programa = nome_editor_texto_windows;
    #else
    
    #endif
  }
  return nome_programa;
  
}

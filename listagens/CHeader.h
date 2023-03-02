#ifndef CHeader_h
#define CHeader_h
#include <iostream>

/// Classe que representa os cabe√ßalhos a serem exibidos na tela.
/// coment·rios 
/// coment·rios
class CHeader
{
public:
  
  int i;///<vetor i contagem de for
  int largura;///<vetor de largura do retangulo do titulo
public:
  void header_carregando();                         ///< Animacao de carregamento
  void header_titulo();                             ///< Escreve titulo do programa
  void header_inicio();                             ///< Escreve subtitulo do programa
  void header_banco_de_dados();///<escreve subtitulo de listar amostras
  void header_banco_de_dados_lista_de_amostras();///<escreve subtitulo de amostras listadas
  void header_banco_de_dados_exibir_amostras();///<escreve subtitulo de exibir amostras
  void header_banco_de_dados_pesquisa_de_amostras();///<escreve subtitulo de amostras listadas
  void header_banco_de_dados_inserir_amostras();///<escreve subtitulo de inserir amostras
  void header_banco_de_dados_excluir_amostras();///<escreve subtitulo de excluir amostras
  void header_banco_de_dados_exportar_amostras();///<escreve subtitulo de excluir amostras
  void header_configuracoes();///<escreve subtitulo do menu 2
  void header_menu_abre_DT();///<escreve subtitulo do menu 
  void header_menu_abre_bd();///<escreve subtitulo do menu 
  
  
  
};


#endif

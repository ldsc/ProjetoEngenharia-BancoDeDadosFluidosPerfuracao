#ifndef CFluidodePerfuracao_h
#define CFluidodePerfuracao_h
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CFluidodePerfuracao
{
public:
  //Atributos

  //Componentes
  int chave; ///< representa a chave de identifica��o do fluido.
  string nome_do_fluido;
  int dia;
  int mes;
  int ano;
  /// representa o tipo de base que comp�e o fluido, �gua,�leo ou g�s.
  string base;
  /// representa o teor(%) de base no fluido.
  double teorbase;
  /// representa o teor(%) de �gua no fluido.
  double teoragua;

  /// Propriedades fisicas e quimicas
  /// Representa o valor inferior da faixa de pH para o fluido desenvolvido.
  double pH_min;
  /// representa o valor superior da faixa de pH para o fluido desenvolvido.
  double pH_max;
  double pe_min; ///<representa o valor inferior da faixa de peso espec�fico para o fluido desenvolvido.
  double pe_max; ///<representa o valor superior da faixa de peso espec�fico para o fluido desenvolvido.
  double gel_i_ae; ///<representa a for�a gel, for�as atrativas el�tricas dentro de um fluido de perfura��o, quando submetido �s condi��es est�ticas ap�s 10 segundos e antes do envelhecimento;
  double temp_e; ///<representa a temperatura de envelhecimento, temperatura da estufa aquecedora na qual o fluido foi inserido numa c�lula de a�o;
  double gel_i_de; ///<representa a for�a gel, for�as atrativas el�tricas dentro de um fluido de perfura��o, quando submetido �s condi��es est�ticas ap�s 10 segundos e depois do envelhecimento;
  double gel_f_ae; ///<representa a for�a gel, for�as atrativas el�tricas dentro de um fluido de perfura��o, quando submetido �s condi��es est�ticas ap�s 10 minutos e antes do envelhecimento;
  double gel_f_de; ///<representa a for�a gel, for�as atrativas el�tricas dentro de um fluido de perfura��o, quando submetido �s condi��es est�ticas ap�s 10 minutos e depois do envelhecimento;
  double est_el_ae; ///<representa a estabilidade el�trica medida pela voltagem requerida para iniciar um fluxo de corrente no fluido antes do envelhecimento.
  double est_el_de; ///<representa a estabilidade el�trica medida pela voltagem requerida para iniciar um fluxo de corrente no fluido depois do envelhecimento.
  double c_lubricidade; ///<representa o coeficiente de lubricidade do fluido de perfura��o;
  double filtrado; ///<representa o volume de filtrado obtido em an�lise laboratorial.
  double VA_ae; ///<representa a viscosidade aparente do fluido antes do envelhecimento.
  double VA_de; ///<representa a viscosidade aparente do fluido depois do envelhecimento.
  double VP_ae; ///<representa a viscosidade pl�stica do fluido antes do envelhecimento.
  double VP_de; ///<representa a viscosidade pl�stica do fluido depois do envelhecimento.
  double LE_ae; ///<representa o limite de escoamento do fluido antes do envelhecimento.
  double LE_de; ///<representa o limite de escoamento do fluido depois do envelhecimento.
  double teor_solidos; ///<representa o teor(%) de s�lidos presentes no fluido.
  double salinidade; ///<representa a salinidade do fluido.

  //ADiTIVOS
  string adensante; ///<representa o adensante usado podendo ser dolomita, por exemplo.
  double conc_adensante; ///<representa a concentra��o de adensante no fluido de perfura��o.
  string inibidor_fa; ///<representa o inibidor de forma��es ativas (sal) usado podendo ser cloreto de s�dio, por exemplo.
  double conc_inibidor_fa; ///<representa a concentra��o do sal no fluido de perfura��o.
  string redutor_f; ///<representa o redutor de filtrado usado podendo ser amido, por exemplo.
  double conc_redutor_f; ///<representa a concentra��o do redutor de filtrado no fluido de perfura��o.
  string biopolimero; ///<representa o biopol�mero usado podendo ser carboximetilcelulose, por exemplo.
  double conc_biopolimero; ///<representa a concentra��o do biopol�mero no fluido de perfura��o.
  string viscosificante; ///<representa o controlador de viscosidade usado podendo ser bentonita, por exemplo.
  double conc_viscosificante; ///<representa a concentra��o do sal no fluido de perfura��o.
  string dispersante; ///<representa o dispersante usado podendo ser lignosulfonatos, por exemplo.
  double conc_dispersante; ///<representa a concentra��o do dispersante no fluido de perfura��o.
  string defloculante; ///<representa o defloculante usado podendo ser poliacrilato de c�lcio, por exemplo.
  double conc_defloculante; ///<representa a concentra��o do defloculante no fluido de perfura��o.
  string emulsificante; ///<representa o emulsificante usado podendo ser �cido graxo, por exemplo.
  double conc_emulsificante; ///<representa a concentra��o do emulsificante no fluido de perfura��o.
  string biocida; ///<representa o biocida usado podendo ser glutaralde�do, por exemplo.
  double conc_biocida; ///<representa a concentra��o do biocida no fluido de perfura��o.
  string lubrificante; ///<representa o lubrificante usado podendo ser �cido graxo, por exemplo.
  double conc_lubrificante; ///<representa a concentra��o do lubrificante no fluido de perfura��o.
  string inibidor_c; ///<representa o inibidor de corros�o usado podendo ser �cidos de cadeia longa, por exemplo.
  double conc_inibidor_c; ///<representa a concentra��o do inibidor de corros�o no fluido de perfura��o.
  string controlador_pH; ///<representa o controlador de pH usado podendo ser hidr�xido de s�dio, por exemplo.
  double conc_controlador_pH; ///<representa a concentra��o do controlador de pH no fluido de perfura��o.

};

#endif

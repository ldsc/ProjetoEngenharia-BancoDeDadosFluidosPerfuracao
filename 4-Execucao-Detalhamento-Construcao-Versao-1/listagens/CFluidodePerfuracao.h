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
  int chave; ///< representa a chave de identificação do fluido.
  string nome_do_fluido;
  int dia;
  int mes;
  int ano;
  /// representa o tipo de base que compõe o fluido, água,óleo ou gás.
  string base;
  /// representa o teor(%) de base no fluido.
  double teorbase;
  /// representa o teor(%) de água no fluido.
  double teoragua;

  /// Propriedades fisicas e quimicas
  /// Representa o valor inferior da faixa de pH para o fluido desenvolvido.
  double pH_min;
  /// representa o valor superior da faixa de pH para o fluido desenvolvido.
  double pH_max;
  double pe_min; ///<representa o valor inferior da faixa de peso específico para o fluido desenvolvido.
  double pe_max; ///<representa o valor superior da faixa de peso específico para o fluido desenvolvido.
  double gel_i_ae; ///<representa a força gel, forças atrativas elétricas dentro de um fluido de perfuração, quando submetido às condições estáticas após 10 segundos e antes do envelhecimento;
  double temp_e; ///<representa a temperatura de envelhecimento, temperatura da estufa aquecedora na qual o fluido foi inserido numa célula de aço;
  double gel_i_de; ///<representa a força gel, forças atrativas elétricas dentro de um fluido de perfuração, quando submetido às condições estáticas após 10 segundos e depois do envelhecimento;
  double gel_f_ae; ///<representa a força gel, forças atrativas elétricas dentro de um fluido de perfuração, quando submetido às condições estáticas após 10 minutos e antes do envelhecimento;
  double gel_f_de; ///<representa a força gel, forças atrativas elétricas dentro de um fluido de perfuração, quando submetido às condições estáticas após 10 minutos e depois do envelhecimento;
  double est_el_ae; ///<representa a estabilidade elétrica medida pela voltagem requerida para iniciar um fluxo de corrente no fluido antes do envelhecimento.
  double est_el_de; ///<representa a estabilidade elétrica medida pela voltagem requerida para iniciar um fluxo de corrente no fluido depois do envelhecimento.
  double c_lubricidade; ///<representa o coeficiente de lubricidade do fluido de perfuração;
  double filtrado; ///<representa o volume de filtrado obtido em análise laboratorial.
  double VA_ae; ///<representa a viscosidade aparente do fluido antes do envelhecimento.
  double VA_de; ///<representa a viscosidade aparente do fluido depois do envelhecimento.
  double VP_ae; ///<representa a viscosidade plástica do fluido antes do envelhecimento.
  double VP_de; ///<representa a viscosidade plástica do fluido depois do envelhecimento.
  double LE_ae; ///<representa o limite de escoamento do fluido antes do envelhecimento.
  double LE_de; ///<representa o limite de escoamento do fluido depois do envelhecimento.
  double teor_solidos; ///<representa o teor(%) de sólidos presentes no fluido.
  double salinidade; ///<representa a salinidade do fluido.

  //ADiTIVOS
  string adensante; ///<representa o adensante usado podendo ser dolomita, por exemplo.
  double conc_adensante; ///<representa a concentração de adensante no fluido de perfuração.
  string inibidor_fa; ///<representa o inibidor de formações ativas (sal) usado podendo ser cloreto de sódio, por exemplo.
  double conc_inibidor_fa; ///<representa a concentração do sal no fluido de perfuração.
  string redutor_f; ///<representa o redutor de filtrado usado podendo ser amido, por exemplo.
  double conc_redutor_f; ///<representa a concentração do redutor de filtrado no fluido de perfuração.
  string biopolimero; ///<representa o biopolímero usado podendo ser carboximetilcelulose, por exemplo.
  double conc_biopolimero; ///<representa a concentração do biopolímero no fluido de perfuração.
  string viscosificante; ///<representa o controlador de viscosidade usado podendo ser bentonita, por exemplo.
  double conc_viscosificante; ///<representa a concentração do sal no fluido de perfuração.
  string dispersante; ///<representa o dispersante usado podendo ser lignosulfonatos, por exemplo.
  double conc_dispersante; ///<representa a concentração do dispersante no fluido de perfuração.
  string defloculante; ///<representa o defloculante usado podendo ser poliacrilato de cálcio, por exemplo.
  double conc_defloculante; ///<representa a concentração do defloculante no fluido de perfuração.
  string emulsificante; ///<representa o emulsificante usado podendo ser ácido graxo, por exemplo.
  double conc_emulsificante; ///<representa a concentração do emulsificante no fluido de perfuração.
  string biocida; ///<representa o biocida usado podendo ser glutaraldeído, por exemplo.
  double conc_biocida; ///<representa a concentração do biocida no fluido de perfuração.
  string lubrificante; ///<representa o lubrificante usado podendo ser ácido graxo, por exemplo.
  double conc_lubrificante; ///<representa a concentração do lubrificante no fluido de perfuração.
  string inibidor_c; ///<representa o inibidor de corrosão usado podendo ser ácidos de cadeia longa, por exemplo.
  double conc_inibidor_c; ///<representa a concentração do inibidor de corrosão no fluido de perfuração.
  string controlador_pH; ///<representa o controlador de pH usado podendo ser hidróxido de sódio, por exemplo.
  double conc_controlador_pH; ///<representa a concentração do controlador de pH no fluido de perfuração.

};

#endif

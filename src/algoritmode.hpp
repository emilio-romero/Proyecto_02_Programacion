#ifndef ALGORITMODE_HPP 
#define ALGORITMODE_HPP
#include "capa.hpp"

class EvolucionDif{
private:
  int individuos;
  int generaciones;
  std::vector<std::vector<double> > poblacion;
  std::vector<std::vector<double> > pmutada;
  std::vector<std::vector<double> > pcruzada;
  std::vector<double> mejor_individuo;
  std::vector<double> dentrada; 
  std::vector<double> dground;
  std::vector<int> arqred; 
  int inred; 
  int outred;
public:
  EvolucionDif(int ts, int tt);
  ~EvolucionDif();

  void set_datos(std::vector<double>, std::vector<double>);
  void set_red(std::vector<int>, int, int); 
  void IniciaPoblacion(std::vector<double> bL, std::vector<double> bU);
  void Mutacion(double F,std::vector<double> bL, std::vector<double> bU);
  void Cruza(double Cr);
  void Seleccion();
  void Elmejor();
  double fob(std::vector<double>);
  std::vector<double> Algoritmo(std::vector<double>,std::vector<double>,double,double);
  std::vector<int> randperm();
};


#endif 

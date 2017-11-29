#ifndef ALGORITMODE_HPP 
#define ALGORITMODE_HPP
#include "capa.hpp"

class EvolucionDif{
private:
  int individuos;
  int generaciones;
public:
  EvolucionDif(int ts, int tt);
  ~EvolucionDif();
  
  void IniciaPoblacion();
  void Mutacion();
  void Cruza();
  void Seleccion();
  void Elmejor();

};

#endif 

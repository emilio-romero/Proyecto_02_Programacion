#ifndef CAPA_HPP
#define CAPA_HPP
/*Recuerda hacer todo en espaniol*/
/*Para que pueda ser usado como*/
/*recurso didactico*/
/*=======================
Fernando Emilio Romero de los Santos 
MSc ciencias de la computacion y matematicas industriales
CIMAT, Guanajuato, Mexico
26 de noviembre de 2017
========================*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<cstdlib>

class Capa{
private:
  int Neuronas;
  int Entradas_capa; 
  std::vector<double> valores_salida;
  std::vector<std::vector<double> > pesos;
  int tipo;
public:
  Capa(int nneur,int nin, int tipoactivacion);
  Capa();
  ~Capa();
  
  void funcion_activacion(std::vector<double>);
  void calcula_salidas(std::vector<double> );

  void set_neuronas(int);
  void set_entradas(int);
  void set_pesos();

  void cambiar_pesos(std::vector<double>);

  int get_neuronas();
  int get_entradas();
  std::vector<double> get_salidas();
  std::vector<std::vector<double> > get_pesos();
  std::vector<double> get_pesosinvec();
};

class Rna{
private: 
  std::vector<Capa> Lared;
  std::vector<double> Salida;
public: 
  Rna(std::vector<int> arquitectura,int entradas, int salidas);
  Rna();
  ~Rna();
  void Prealimentacion(std::vector<double> Entrada);
  
  std::vector<double> get_salida();
  std::vector<double> get_parametros();

  void cambiar_parametros(std::vector<double>);
  std::vector<double> segmentar(std::vector<double>);
};



double randx();
#endif 

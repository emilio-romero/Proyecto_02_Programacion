#include "capa.hpp"

/*Clase capa*/
/*Constructores de capa*/
Capa::Capa(int nneur, int nin){
  Neuronas=nneur;
  Entradas_capa=nin+1; 
  //Conexiones hacia atras? 
  for(int i=0;i<nneur;i++){
    std::vector<double> mvec;
    for(int j=0;j<nin+1;j++){
      mvec.push_back(randx());
    }
    pesos.push_back(mvec);
  }
}

Capa::Capa(){

}

Capa::~Capa(){

}
/*Operaciones de las neuronas*/
void Capa::funcion_activacion(std::vector<double> valores_medios){
  int n=valores_medios.size();
  if(n==valores_salida.size()) valores_salida.clear();
  for(int i=0;i<n;i++){
    valores_salida.push_back(valores_medios[i]);
  }
}
void Capa::calcula_salidas(std::vector<double> valores_entrada){
  double suma;

  std::vector<double> medios; 
  std::vector<double> primeros=valores_entrada;
  primeros.push_back(1.0);
  for(int i=0;i<Neuronas;i++){
    suma=0;
    for(int j=0;j<Entradas_capa;j++){
      suma+=pesos[i][j]*primeros[j];
    }
    medios.push_back(suma);
  }
  funcion_activacion(medios);
}
/*Setters o "Establecedores"*/

void Capa::set_neuronas(int nneur){
  Neuronas=nneur;
}
void Capa::set_entradas(int nin){
  Entradas_capa=nin+1;
}

void Capa::set_pesos(){
for(int i=0;i<Neuronas;i++){
    std::vector<double> mvec;
    for(int j=0;j<Entradas_capa;j++){
      mvec.push_back(randx());
    }
    pesos.push_back(mvec);
  }
}
/*Modificadores*/
void Capa::cambiar_pesos(std::vector<double> nuevos_pesos){
  for(int j=0;j<Entradas_capa;j++){
    for(int i=0;i<Neuronas;i++){
      //std::cout<<Neuronas*j+i<<std::endl;
      pesos[i][j]=nuevos_pesos[Neuronas*j+i];
   }
  }
}
/*Getters u "Obtenedores"*/

int Capa::get_neuronas(){
  return(Neuronas);
}

int Capa::get_entradas(){
  return(Entradas_capa);
}

std::vector<double> Capa::get_salidas(){
  return(valores_salida);
}
std::vector<std::vector<double> > Capa::get_pesos(){
  return(pesos);
}
std::vector<double> Capa::get_pesosinvec(){
  std::vector<double> aux; 

  for(int j=0;j<Entradas_capa;j++){
    for(int i=0;i<Neuronas;i++){
      aux.push_back(pesos[i][j]);
    }
  }
  
  return(aux);
}


/*Clase Red neuronal artificial (Rna)*/
/*Constructores*/
Rna::Rna(std::vector<int> arquitectura,int entradas, int salidas){
  int n=arquitectura.size();
  if(n>1){
    Lared.push_back(Capa(arquitectura[0],entradas));
    for(int i=1;i<n;i++){
      Lared.push_back(Capa(arquitectura[i],arquitectura[i-1]));
    }
    Lared.push_back(Capa(salidas,arquitectura[n-1]));
  }
  else if(n==1){
    Lared.push_back(Capa(arquitectura[0],entradas));
    Lared.push_back(Capa(salidas,arquitectura[0]));
  }
  else{
    std::cout<<"Introduzca un numero de capas valido"<<std::endl;
  }
}
Rna::Rna(){

}

Rna::~Rna(){

}

void Rna::Prealimentacion(std::vector<double> Entrada){
  std::vector<double> auxiliar; 
  int n=Lared.size();
  Lared[0].calcula_salidas(Entrada);
  auxiliar=Lared[0].get_salidas();
  for(int i=1;i<n;i++){
    Lared[i].calcula_salidas(auxiliar);
    auxiliar.clear();
    auxiliar=Lared[i].get_salidas();
  }
  Salida=auxiliar;
}

std::vector<double> Rna::get_salida(){
  return(Salida);
}

std::vector<double> Rna::get_parametros(){
  std::vector<double> auxiliar;
  std::vector<double> toma;
  int n=Lared.size();
  auxiliar=Lared[0].get_pesosinvec();
  for(int i=1;i<n;i++){
    toma=Lared[i].get_pesosinvec();
    auxiliar.reserve(auxiliar.size()+toma.size());
    auxiliar.insert(auxiliar.end(),toma.begin(),toma.end());
    toma.clear();
  }
return(auxiliar);
}

void Rna::cambiar_parametros(std::vector<double> nuevos_parametros){
  int n=Lared.size();
  //std::cout<<"Cuantas matrices: "<<n<<"\n";
  int neu,ent,ni=0;
  std::vector<double> auxiliar;
  for(int i=0;i<n;i++){
    neu=Lared[i].get_neuronas();
    ent=Lared[i].get_entradas();
    std::cout<<"Elementos "<<neu*ent<<std::endl;
    for(int j=ni;j<ni+neu*ent;j++){
     // std::cout<<j<<std::endl;
      auxiliar.push_back(nuevos_parametros[j]);
    }
    //std::cout<<std::endl;
    Lared[i].cambiar_pesos(auxiliar);
    auxiliar.clear();
    ni=ni+neu*ent;
  }
}

/*Funciones Auxiliares*/
double randx(){
return(std::rand()/(double)RAND_MAX);
}

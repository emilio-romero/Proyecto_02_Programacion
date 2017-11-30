#ifndef LECTURA_HPP 
#define LECTURA_HPP
#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <fstream>
#include <cstdio>
std::vector<double> readPgm(std::string pfile);
std::vector<double> readPgmgt(std::string pfile);
int writePgm(std::vector<std::vector<double> > laimagen,std::string nombre);

std::vector<std::vector<double> > cambia_tamanio(std::vector<double> actual);
#endif 

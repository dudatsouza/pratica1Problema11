#ifndef PROBLEMA11_HPP
#define PROBLEMA11_HPP

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <vector>
#include <chrono>
#include <algorithm> 
#include <cmath>
#include <map>
#include <random>
#include <cstdlib>
#include <filesystem>

void gerarProcessosEArquivos(int& qntProcesso, int& qntArquivos);
void gerarArquivos(std::string nomeArquivo);
void gerarProcessos(std::string nomeProcesso, int qntDeArquivos, int qntLinhas, int qntDeArquivosPorLinha);

void proposta1(int qntConjuntosProcessos);
void proposta2(int qntConjuntosProcessos);
void proposta3(int qntConjuntosProcessos);
void proposta4(int qntConjuntosProcessos);
void proposta5(int qntConjuntosProcessos, int qntArquivos);
void proposta6(int qntConjuntosProcessos, int qntArquivos);

void extrairArquivosPorLinha(std::string linha, std::vector<int>& arquivosPorLinha);
void medindoTempoDeExecucaoDeCadaProposta(int qntConjuntosProcessos, int qntArquivos, std::ofstream& csvFile);
void limparArquivo(std::string nomeArquivo);
double calculandoASomaDasRaizQuadradaDeUmArquivo(std::string nomeArquivo);
void escreverResultadoNoArquivoDeSaida(std::string nomeArquivo, double resultado);

void trocar(std::vector<std::vector<int>>& matriz, int i, int j);
int particao(std::vector<std::vector<int>>& matriz, int low, int high);
void quickSort(std::vector<std::vector<int>>& matriz, int low, int high);

double buscarNoCache(int idArquivo, std::vector<std::vector<double>>& cacheArquivos);
void colocarCacheOrdenado(std::vector<std::vector<double>>& cacheArquivos, int idArquivo, double valor);

void limparPastas();

void limparconsole();
void apresentacao();
std::vector<int> preparandoConjuntos(int qntProcesso);
void gerenciandoMedicao(std::vector<int> qntConjuntosProcessos, int qntArquivos);
void gerandoGrafico();
void analiseDeResultados();
void finalizando();
#endif 
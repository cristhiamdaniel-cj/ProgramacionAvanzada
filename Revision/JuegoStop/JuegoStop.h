// JuegoStop.h
#ifndef JUEGOSTOP_H
#define JUEGOSTOP_H

#include <vector>
#include <set>
#include <string>

struct ResultadoRonda {
    char letra;
    double tiempo;
    int puntos;
};

char generarLetraAleatoria(std::set<char>& letrasUsadas);
bool iniciaConLetra(const std::string& palabra, char letra);
int calcularPuntos(const std::vector<std::string>& respuestas, char letra);
std::vector<ResultadoRonda> jugarRonda(const std::string& nombreJugador, std::set<char>& letrasUsadas);
void imprimirResultados(const std::vector<ResultadoRonda>& resultados, const std::string& nombreJugador);
void decidirGanador(const std::string& nombreJugador1, const std::vector<ResultadoRonda>& resultadosJugador1,
                    const std::string& nombreJugador2, const std::vector<ResultadoRonda>& resultadosJugador2);
bool deseaContinuar(const std::string& nombreJugador);

#endif // JUEGOSTOP_H

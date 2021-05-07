#ifndef _SIMULADOR_HPP_
#define _SIMULADOR_HPP_

#include <thread>

#include "semaforo.hpp"
#include "sincronizador.hpp"
#include "desenhador.hpp"

class Simulador
{
public:
  Simulador(unsigned int tV, unsigned int tA, unsigned int tT);
  void comecar(unsigned int ciclos);

private:
  Semaforo s1, s2;
  Sincronizador sinc;
  Desenhador des;
};

#endif
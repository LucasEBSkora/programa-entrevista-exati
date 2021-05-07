#ifndef _SINCRONIZADOR_HPP_
#define _SINCRONIZADOR_HPP_

#include "semaforo.hpp"

class Sincronizador
{
public:
  Sincronizador(Semaforo *s1, Semaforo *s2, unsigned int tV, unsigned int tA, unsigned int tT);
  void executar(unsigned int ciclos);
  unsigned int periodo();

private:
  Semaforo *s1;
  Semaforo *s2;
  const unsigned int tVerde;
  const unsigned int tAmarelo;
  const unsigned int tVermelhoPreTransicao;
};

#endif
#ifndef _DESENHADOR_HPP_
#define _DESENHADOR_HPP_

#include "semaforo.hpp"

#include <chrono>

class Desenhador
{
public:
  Desenhador(const Semaforo &s1, const Semaforo &s2);
  void desenhar(unsigned int tempo);

private:
  const Semaforo &semaforoHorizontal;
  const Semaforo &semaforoVertical;
  //retorna o número de segundos que passaram desde o time_point t0
  unsigned int getIntervalo(std::chrono::steady_clock::time_point t0) const;
};

#endif
#ifndef _DESENHADOR_HPP_
#define _DESENHADOR_HPP_

#include "semaforo.hpp"

class Desenhador
{
public:
  Desenhador(const Semaforo &s1, const Semaforo &s2);
  void desenhar(unsigned int tempo);

private:
  const Semaforo &semaforoHorizontal;
  const Semaforo &semaforoVertical;
};

#endif
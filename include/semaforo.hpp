#ifndef _SEMAFORO_HPP_
#define _SEMAFORO_HPP_

#include <ostream>
#include <string>

class Semaforo
{
public:
  enum Estado
  {
    verde,
    amarelo,
    vermelho
  };

  Semaforo(Estado estadoInicial);
  const char *imprimir() const;
  void setEstado(Estado novoEstado);

private:
  Estado estadoAtual;
};

std::ostream &operator<<(std::ostream &out, const Semaforo &semaforo);

#endif
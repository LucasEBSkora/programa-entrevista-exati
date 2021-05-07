#include "semaforo.hpp"

#include "stdlib.h"

Semaforo::Semaforo(Estado estadoInicial) : estadoAtual{estadoInicial} {}

const char *Semaforo::imprimir() const
{
  switch (estadoAtual)
  {
  case verde:
    return "verde   ";
  case amarelo:
    return "amarelo ";
  case vermelho:
    return "vermelho";
  default:
    exit(-1);
    break;
  }
}

void Semaforo::setEstado(Estado novoEstado)
{
  estadoAtual = novoEstado;
}

std::ostream &operator<<(std::ostream &out, const Semaforo &semaforo)
{
  out << semaforo.imprimir();
  return out;
}
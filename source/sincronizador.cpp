#include "sincronizador.hpp"

#include <thread>
#include <chrono>

Sincronizador::Sincronizador(Semaforo *s1, Semaforo *s2, unsigned int tV, unsigned int tA, unsigned int tT) : s1{s1},
                                                                                                              s2{s2},
                                                                                                              tVerde{tV},
                                                                                                              tAmarelo{tA},
                                                                                                              tVermelhoPreTransicao{tT} {}
void Sincronizador::executar(unsigned int ciclos)
{
  for (int i = 0; i < 2 * ciclos; ++i)
  {
    s1->setEstado(Semaforo::verde);
    s2->setEstado(Semaforo::vermelho);
    std::this_thread::sleep_for(std::chrono::seconds(tVerde));

    s1->setEstado(Semaforo::amarelo);
    std::this_thread::sleep_for(std::chrono::seconds(tAmarelo));

    s1->setEstado(Semaforo::vermelho);
    std::this_thread::sleep_for(std::chrono::seconds(tVermelhoPreTransicao));

    Semaforo *aux = s1;
    s1 = s2;
    s2 = aux;
  }
}

unsigned int Sincronizador::periodo()
{
  return tVerde + tAmarelo + tVermelhoPreTransicao;
}
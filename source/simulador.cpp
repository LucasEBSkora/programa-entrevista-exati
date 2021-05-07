#include "simulador.hpp"

#include <thread>
#include <chrono>

Simulador::Simulador(unsigned int tV, unsigned int tA, unsigned int tT) : s1{Semaforo::verde}, s2{Semaforo::vermelho},
                                                                          sinc{&s1, &s2, tV, tA, tT}, des{s1, s2} {}

void Simulador::comecar(unsigned int ciclos)
{
  std::thread threadSinc{[this, ciclos] { sinc.executar(ciclos); }};
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  const unsigned int segundos = 2 * ciclos * sinc.periodo();
  std::thread threadDes{[this, segundos] { des.desenhar(segundos); }};

  threadSinc.join();
  threadDes.join();
}
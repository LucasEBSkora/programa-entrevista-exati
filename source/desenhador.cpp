#include "desenhador.hpp"

#include <iostream>
#include <iomanip>
#include <thread>
#include <math.h>

Desenhador::Desenhador(const Semaforo &s1, const Semaforo &s2) : semaforoHorizontal{s1}, semaforoVertical{s2}
{
}

void Desenhador::desenhar(unsigned int tempo)
{
  auto t0 = std::chrono::steady_clock::now();
  do
  {
    int dt = getIntervalo(t0);

    std::cout << "t: " << std::setw(ceil(log10(tempo))) << dt << std::setw(0) << " segundos | "
              << "semaforo horizontal: " << semaforoHorizontal
              << " | semaforo vertical: " << semaforoVertical << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
  } while (getIntervalo(t0) <= tempo);
}

unsigned int Desenhador::getIntervalo(std::chrono::steady_clock::time_point t0) const
{
  return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - t0).count();
}

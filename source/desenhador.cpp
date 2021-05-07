#include "desenhador.hpp"

#include <chrono>
#include <iostream>
#include <thread>

Desenhador::Desenhador(const Semaforo &s1, const Semaforo &s2) : semaforoHorizontal{s1}, semaforoVertical{s2}
{
}

void Desenhador::desenhar(unsigned int tempo)
{
  auto t0 = std::chrono::steady_clock::now();
  do
  {
    int dt = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - t0).count();
    std::cout << "t: " << dt + 1 << " segundos | "
              << "semaforo horizontal: " << semaforoHorizontal
              << " | semaforo vertical: " << semaforoVertical << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  } while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - t0).count() < tempo);
}
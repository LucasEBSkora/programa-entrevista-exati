#include <iostream>

#include "simulador.hpp"

int main(int argc, char *argv[])
{
  if (argc != 5)
  {
    std::cout << "uso: simsem.exe N tV tA tT\n"
                 "onde:\n\tN é o numero (inteiro) de ciclos completos que a simulação rodara\n"
                 "\ttV e o tempo (em segundos) que cada semaforo ficara verde\n"
                 "\ttA e o tempo (em segundos) que cada semaforo ficara amarelo\n"
                 "\ttT e o tempo (em segundos) que um semaforo demorara para ficar verde após o outro ficar vermelho\n"
              << std::endl;
    return -1;
  }

  const int N = atoi(argv[1]);
  const int tV = atoi(argv[2]);
  const int tA = atoi(argv[3]);
  const int tT = atoi(argv[4]);

  if (N <= 0 || tV <= 0 || tA <= 0 || tT <= 0)
  {
    std::cout << "Erro! Todos os valores precisam ser estritamente positivos." << std::endl;
    return -1;
  }
  else
  {
    Simulador s(tV, tA, tT);
    s.comecar(N);
    return 0;
  }
}
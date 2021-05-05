#include <iostream>

#include "desenhador.hpp"
#include "semaforo.hpp"
#include "sincronizador.hpp"



int main (int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "uso: simsem N\n"
                "onde N é o numero (inteiro) de segundos que a simulação rodará" << std::endl;
    return -1;
  }

  const int N = atoi(argv[1]);
  Semaforo sHorizontal = Semaforo();
  Semaforo sVertical = Semaforo(); 

  Sincronizador sinc = Sincronizador(sHorizontal, sVertical);

  Desenhador desenhador = Desenhador(sHorizontal, sVertical);

  sinc.comecar();
  desenhador.comecar();

  return 0;
}
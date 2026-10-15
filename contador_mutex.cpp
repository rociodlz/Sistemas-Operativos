#include <iostream>
#include <thread>
#include <mutex>

int contador = 0;
std::mutex mutexContador;

void procesoA()
{
    for (int i = 0; i < 100000; i++)
    {
        mutexContador.lock();      
        contador++;                
        mutexContador.unlock();    
    }
}

void procesoB()
{
    for (int i = 0; i < 100000; i++)
    {
        mutexContador.lock();
        contador++;
        mutexContador.unlock();
    }
}

int main()
{
    std::thread p1(procesoA);
    std::thread p2(procesoB);

    p1.join();
    p2.join();

    std::cout << "Contador final: " << contador << std::endl;

    return 0;
}
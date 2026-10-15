#include <iostream>
#include <thread>

int contador = 0;

void procesoA()
{
    for (int i = 0; i < 100000; i++)
    {
        contador++;
    }
}

void procesoB()
{
    for (int i = 0; i < 100000; i++)
    {
        contador++;
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
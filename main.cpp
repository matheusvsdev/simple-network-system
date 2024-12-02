//
// Created by Matheus Valdevino on 02/12/24.
//

#include <iostream>

int main() {
    std::cout << "Iniciando servidor e cliente..." << std::endl;
    system("./server &");
    system("./client");
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

void send_response(const std::string &command) {
    FILE *pipe = popen(command.c_str(), "w");
    if (!pipe) {
        std::cerr << "Error al abrir el pipe.\n";
        return;
    }

    // Envía la respuesta 'y' automáticamente
    fputs("y\n", pipe);
    pclose(pipe);
}

int main() {
    // Simula un comando de tu terminal que hace una pregunta
    std::string comando = "Do you want automatically install prerequisite JDK? [y/N]";
    send_response(comando);

    std::cout << "Respuesta enviada automáticamente.\n";
    return 0;
}

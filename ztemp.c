#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <stdbool.h>

// Configurações do terminal
void configurar_terminal() {
    struct termios config;
    tcgetattr(STDIN_FILENO, &config);
    config.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &config);
}

void restaurar_terminal(struct termios *original) {
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

// Limpa a tela de forma eficiente
void limpar_tela() {
    printf("\033[2J\033[H");
}

// Obtém temperatura com tratamento de erro
float ler_temperatura() {
    FILE *arquivo = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (!arquivo) {
        perror("Erro ao ler temperatura");
        return -1.0;
    }

    int miligraus;
    if (fscanf(arquivo, "%d", &miligraus) != 1) {
        fclose(arquivo);
        return -1.0;
    }
    fclose(arquivo);

    return miligraus / 1000.0;
}

// Exibe a interface com bordas estilizadas
void mostrar_interface(float temp) {
    limpar_tela();
    printf("================================\n");
    printf("║   MONITOR DE TEMPERATURA     ║\n");
    printf("================================\n");
    
    if (temp < 0) {
        printf("║  Erro ao ler temperatura!   =\n");
    } else if (temp < 50.0) {
        printf("║  Temperatura: \033[32m%.1f°C\033[0m         ║\n", temp);
    } else if (temp < 70.0) {
        printf("║  Temperatura: \033[33m%.1f°C\033[0m         ║\n", temp);
    } else {
        printf("║  Temperatura: \033[31m%.1f°C\033[0m         ║\n", temp);
    }
    
    printf("================================\n");
    printf("║  Pressione Q para sair       ║\n");
    printf("================================\n");
    fflush(stdout);
}

int main() {
    struct termios config_original;
    tcgetattr(STDIN_FILENO, &config_original);
    configurar_terminal();

    bool executando = true;
    while (executando) {
        float temperatura = ler_temperatura();
        mostrar_interface(temperatura);

        // Verificação não-bloqueante de input
        struct timeval timeout = {0, 100000}; // 100ms
        fd_set conj_leitura;
        FD_ZERO(&conj_leitura);
        FD_SET(STDIN_FILENO, &conj_leitura);

        if (select(1, &conj_leitura, NULL, NULL, &timeout) > 0) {
            char tecla;
            read(STDIN_FILENO, &tecla, 1);
            if (tecla == 'q' || tecla == 'Q') executando = false;
        }

        usleep(400000); // Totalizando ~500ms por ciclo
    }

    restaurar_terminal(&config_original);
    limpar_tela();
    printf("Monitor encerrado com sucesso.\n");

    return 0;
}

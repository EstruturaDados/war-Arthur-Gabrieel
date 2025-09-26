#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
    char *missao;
} Territorio;

// Exibir mapa do jogo
void exibirTabela(Territorio* territorios) {
    printf("===============================\n");
    printf("America do Norte: Cor: %s Tropas: %d\n", territorios[0].cor, territorios[0].tropas);
    printf("America do Sul:   Cor: %s Tropas: %d\n", territorios[1].cor, territorios[1].tropas);
    printf("Europa:           Cor: %s Tropas: %d\n", territorios[2].cor, territorios[2].tropas);
    printf("Africa:           Cor: %s Tropas: %d\n", territorios[3].cor, territorios[3].tropas);
    printf("Ásia:             Cor: %s Tropas: %d\n", territorios[4].cor, territorios[4].tropas);
    printf("Oceania:          Cor: %s Tropas: %d\n", territorios[5].cor, territorios[5].tropas);
    printf("===============================\n");
}

// Atribuir missão aleatória
void atribuirMissao(char** destino, char* missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    *destino = malloc(strlen(missoes[indice]) + 1);
    strcpy(*destino, missoes[indice]);
}

// Exibir missão
void exibirMissao(char* missao) {
    printf("Sua missão: %s\n", missao);
}

// Verificar missão (exemplo simples)
int verificarMissao(char* missao, Territorio* territorios, int tamanho) {
    if (strcmp(missao, "Eliminar todas as tropas da cor vermelha") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(territorios[i].cor, "vermelho") == 0 && territorios[i].tropas > 0)
                return 0; // não cumprida
        }
        return 1; // cumprida
    }
    // Você pode adicionar mais regras aqui
    return 0;
}

// Ataque entre territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    if (atacante->tropas < 2) {
        printf("O território %s não tem tropas suficientes para atacar.\n", atacante->nome);
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("Dado atacante (%s): %d\n", atacante->nome, dadoAtacante);
    printf("Dado defensor (%s): %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Atacante vence!\n");
        defensor->tropas = atacante->tropas / 2;
        strcpy(defensor->cor, atacante->cor);
        atacante->tropas -= defensor->tropas;
    } else {
        printf("Defensor vence!\n");
        atacante->tropas -= 1;
    }
}

// Liberar memória
void liberarMemoria(Territorio* territorios, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(territorios[i].missao);
    }
}

// Menu principal
void menu(Territorio* territorios, int total) {
    int opcao;
    do {
        printf("========= Menu do War =========\n");
        printf("1. Iniciar guerra\n");
        printf("2. Exibir mapa\n");
        printf("3. Sair do jogo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                int a, d;
                exibirTabela(territorios);
                printf("Escolha território atacante (0-5): ");
                scanf("%d", &a);
                printf("Escolha território defensor (0-5): ");
                scanf("%d", &d);

                if (a == d) {
                    printf("Atacante e defensor não podem ser o mesmo território!\n");
                } else {
                    atacar(&territorios[a], &territorios[d]);

                    // Verificar missão
                    for (int i = 0; i < total; i++) {
                        if (verificarMissao(territorios[i].missao, territorios, total)) {
                            printf("Missão de %s cumprida! Você venceu o jogo!\n", territorios[i].nome);
                            liberarMemoria(territorios, total);
                            exit(0);
                        }
                    }
                }
                break;
            }
            case 2:
                exibirTabela(territorios);
                break;
            case 3:
                printf("Saindo do jogo...\nObrigado por jogar!\nCriado por Arthur Gabriel\n");
                liberarMemoria(territorios, total);
                exit(0);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 3);
}

int main() {
    srand(time(NULL));

    char* missoes[5] = {
        "Conquistar 3 territorios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Conquistar a America do Sul",
        "Conquistar Europa e Asia",
        "Ter mais de 10 tropas no total"
    };

    Territorio territory[6] = {
        {"America do Norte", "vermelho", 5, NULL},
        {"America do Sul", "azul", 5, NULL},
        {"Europa", "verde", 5, NULL},
        {"Africa", "amarelo", 5, NULL},
        {"Asia", "preto", 5, NULL},
        {"Oceania", "branco", 5, NULL}
    };

    // Atribuir missões aleatórias a cada território/jogador
    for (int i = 0; i < 6; i++) {
        atribuirMissao(&territory[i].missao, missoes, 5);
        exibirMissao(territory[i].missao); // exibe missão apenas uma vez
    }

    menu(territory, 6);

    liberarMemoria(territory, 6);
    return 0;
}

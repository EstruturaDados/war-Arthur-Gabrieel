// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

#include <stdio.h>
#include <string.h>

 struct  Territory {
       char name[30]; 
       char color[30];
       int troops;
    };

int main () {

    const char* colorOptions[5] = {
        "Green or Blue",
        "Yellow or Purple",
        "white or Red",
        "Black or Pink",
        "Brown or Gray",

    };
   
struct Territory territories[5];

        printf("========================= \n");
        printf("Welcome to War!\n");
        printf("========================= \n");

    for (int i = 0; i < 5; i++) {
       
        printf("Territory %d \n", i + 1);
        
        printf("Enter the territory: \n");
        scanf(" %[^\n]", territories[i].name);

        printf("Enter your color: (%s)\n", colorOptions[i]);
        scanf(" %[^\n]", territories[i].color);

        printf("Enter your troops: \n");
        scanf(" %d", &territories[i].troops);
    }

    for(int i = 0; i < 5; i++) {
        printf("Territory %d:\n", i + 1);
        printf("Name: %s\n", territories[i].name);
        printf("Color: %s\n", territories[i].color);
        printf("Troops: %d\n", territories[i].troops);
        printf("-----------------\n");
    }


    return 0;
}


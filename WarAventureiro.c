#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

 struct  Territory {
       char name[30]; 
       char color[30];
       int troops;
    };
    int attack(struct Territory* attacker, struct Territory* defender) {
    int diceAttacker = (rand() % 6) + 1;
    int diceDefender = (rand() % 6) + 1;

    if (diceAttacker > diceDefender) {
        defender->troops -= 1;

        if (defender->troops <= 0) {
            strcpy(defender->color, attacker->color);
            defender->troops = attacker->troops / 2;
            attacker->troops -= defender->troops;
            return 1; // atacante venceu e conquistou o território
        }

        return 1; // atacante venceu o turno
    } else if (diceDefender > diceAttacker) {
        attacker->troops -= 1;

        if (attacker->troops <= 0) {
            return 4; // atacante perdeu todas as tropas
        }
        if (defender->troops <= 0) {
            return 5;
        }

        return 2; // defensor venceu o turno
    }

    return 3; // empate
}

int main () {
      const char* colorOptions[5] = {
        "Verde ou Azul",
        "Amarelo ou Roxo",
        "Branco ou Vermelho",
        "Preto ou Rosa",
        "Marrom ou Cinza",

    };
    //inicializa o ponteiro ataque e defesa como nulo
    struct Territory* attacker = NULL;
    struct Territory* defender = NULL;
   
   //número de cadastros
    int t;

    int resultado;
    
    

    //inicializa o gerador aleatório
     srand(time(NULL));
    
 
        //Bem-vindo
        printf("========================= \n");
        printf("Bem-Vindo ao War!\n");
        printf("========================= \n");


        printf("quantos territorios vai adicionar? (MAX: 5) ");
        scanf("%d", &t);

        //solicitar um espaço de 5 inteiros na memória
    struct Territory* territory = (struct Territory*) malloc (t * sizeof(struct Territory));

   //repita o registro 5 vezes
    for (int i = 0; i < t; i++) {
       
        printf("Territorio %d \n", i + 1);
        
        printf("digite o nome territorio: \n");
        scanf(" %[^\n]", territory[i].name);

        printf("digite a cor: (%s)\n", colorOptions[i]);
        scanf(" %[^\n]", territory[i].color);

        printf("digite a quantidade de tropas: \n");
        scanf(" %d", &territory[i].troops);
    }

    char nameAttacker[30];
    char nameDefender[30];
while(1) {
   

    printf("Quem vai atacar?\n");
    scanf(" %s", nameAttacker);

    printf("Quem vai defender?\n");
    scanf(" %s", nameDefender);

    for(int i = 0; i < t; i++) {
        if(strcmp(territory[i].name, nameAttacker) == 0) {
            attacker = &territory[i];
            break;
        }
    }

    for(int i = 0; i < t; i++) {
        if(strcmp(territory[i].name, nameDefender) == 0) {
            defender = &territory[i];
            break;
        }
    }

   if (attacker != NULL && defender != NULL) {
    if (strcmp(attacker->name, defender->name) == 0) {
        printf("Não pode escolher o mesmo território duas vezes..\n");
    } else {
       resultado = attack(attacker, defender);
    }
} else {
    printf("Atacante ou defensor não encontrado!\n");
}



     //mapa do jogo
        printf("====================\n");
        printf("Mapa do War\n");
        printf("====================\n");

    //exibir na tela todos os registros
     for(int i = 0; i < t; i++) {
       
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territory[i].name);
        printf("Cor: %s\n", territory[i].color);
        printf("Tropas: %d\n", territory[i].troops);
        printf("-----------------\n");

        // exibir resultado do ataque depois do mapa

    }
    if (resultado == 1) {
    printf("Resultado da batalha: O atacante %s venceu!\n", attacker->name);
} else if (resultado == 2) {
    printf("Resultado da batalha: O defensor %s resistiu!\n", defender->name);
} else if (resultado == 3) {
    printf("Resultado da batalha: Empate! Ninguém perdeu tropas.\n");
} else if (resultado == 4) {
    printf("Resultado da batalha: O atacante %s (%s) perdeu todas as tropas para %s (%s)!\n", attacker->name, attacker->color, defender->name, defender->color);
} else if (resultado == 5) {
    printf("Resultado da batalha: O defensor %s (%s) perdeu todas as tropas para %s (%s)!\n", defender->name, defender->color, attacker->name, attacker->color);
}
        

    char keepPlaying[3];
    printf("Quer Continuar Jogando? (sim ou não)\n");
    scanf("%3s", &keepPlaying);

    if (strcmp(keepPlaying, "nao") == 0 || strcmp(keepPlaying, "NAO") == 0) {
        printf("Saindo do jogo... Obrigado por ter jogado.\n");
        printf("Criado por Arthur Gabriel");
        break; //sair do jogo
    }

}
    free(territory);
    return 0;
    
}
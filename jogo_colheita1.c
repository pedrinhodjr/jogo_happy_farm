// Aluno: José Pedro

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define X 10
#define Y 10

char mundo[X][Y];
int dinheiro = 2, energia = 10, sementes = 0;

//int menu();
//void inicializa();
//void mostrar();
//void comprar();
//void arar(int px, int py);
//void plantar(int px, int py);
//void colher(int px, int py);
//void dormir();

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int op, px = 0, py = 0;
    inicializa();
    mundo[px][py] = '@';

    system("cls || clear");
    do {
        mostrar();

        if (energia <= 0) {
            printf("\nVocê ficou sem energia e desmaiou... Fim de jogo!\n");
            break;
        }

        op = menu();
        switch (op) {
            case 1:
                comprar();
                break;
            case 2:
                arar(px, py);
                break;
            case 3:
                plantar(px, py);
                break;
            case 4:
                colher(px, py);
                break;
            case 5:
                dormir();
                break;
            case 6:
                printf("\n| Saldo em dinheiro: %d | Energia: %d | Sementes: %d\n", dinheiro, energia, sementes);
                system("pause");
                system("cls || clear");
                break;
            case 7:
                printf("\n\nObrigado por jogar!\n\n");
                break;
            default:
                printf("\nOpção inexistente...\n");
        }

    } while (op != 7);

    system("pause");
    return 0;
}

// --------------------- FUNÇÕES -----------------------

int menu() {
    int op;
    printf("\n\nEscolha uma opção:\n");
    printf("+-------------------------------+\n");
    printf("| 1. Comprar sementes           |\n");
    printf("| 2. Arar terreno               |\n");
    printf("| 3. Plantar sementes           |\n");
    printf("| 4. Colher plantação           |\n");
    printf("| 5. Dormir (recuperar energia) |\n");
    printf("| 6. Mostrar status             |\n");
    printf("| 7. Sair                       |\n");
    printf("+-------------------------------+\n");
    printf("\nOpção: ");
    scanf("%d", &op);
    return op;
}

void inicializa() {
    int i, j;
    for (i = 0; i < X; i++) {
        for (j = 0; j < Y; j++) {
            mundo[i][j] = '='; 
        }
    }
}

void mostrar() {
    int i, j;
    system("cls || clear");
    printf("\nEnergia: %d | Dinheiro: %d | Sementes: %d\n", energia, dinheiro, sementes);
    printf("+---------------------------+\n");
    for (i = 0; i < X; i++) {
        for (j = 0; j < Y; j++) {
            printf("%c ", mundo[i][j]);
        }
        printf("\n");
    }
    printf("+---------------------------+\n");
}

void comprar() {
    int qtde;
    printf("\nBem-vindo à loja de sementes!\n");
    printf("Seu dinheiro: %d | Energia: %d | Sementes: %d\n\n", dinheiro, energia, sementes);
    printf("Quantas sementes deseja comprar? ");
    scanf("%d", &qtde);

    if (energia <= 0) {
        printf("Você está muito cansado para comprar.\n");
        system("pause");
        return;
    }
    if (qtde > dinheiro) {
        printf("Dinheiro insuficiente!\n");
        system("pause");
        return;
    }

    sementes += qtde;
    dinheiro -= qtde;
    energia -= 1;

    printf("\nCompra realizada!\n");
    printf("Agora você tem %d sementes.\n", sementes);
    system("pause");
}

void arar(int px, int py) {
    int x, y;
    printf("\nDigite a posição (linha e coluna) para arar (0 a 9): ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= X || y < 0 || y >= Y) {
        printf("Posição inválida!\n");
        return;
    }
    if (energia < 2) {
        printf("Você está muito cansado para arar.\n");
        return;
    }

    if (mundo[x][y] == '=') {
        mundo[x][y] = '~';
        energia -= 2;
        printf("Terreno arado com sucesso!\n");
    } else {
        printf("Este terreno já foi arado ou está ocupado.\n");
    }
    system("pause");
}


void plantar(int px, int py) {
    int x, y;
    printf("\nDigite a posição (linha e coluna) para plantar: ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= X || y < 0 || y >= Y) {
        printf("Posição inválida!\n");
        return;
    }
    if (sementes <= 0) {
        printf("Você não tem sementes para plantar.\n");
        return;
    }
    if (mundo[x][y] != '~') {
        printf("Você só pode plantar em terreno arado ('~').\n");
        return;
    }

    mundo[x][y] = '*';
    sementes -= 1;
    energia -= 2;

    printf("Semente plantada com sucesso!\n");
    system("pause");
}


void colher(int px, int py) {
    int x, y;
    printf("\nDigite a posição (linha e coluna) para colher: ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= X || y < 0 || y >= Y) {
        printf("Posição inválida!\n");
        return;
    }
    if (mundo[x][y] == '*') {
        mundo[x][y] = '=';
        dinheiro += 3;
        energia -= 1;
        printf("Colheita feita com sucesso! +3 de dinheiro!\n");
    } else {
        printf("Aqui não há nada para colher.\n");
    }
    system("pause");
}


void dormir() {
    printf("\nVocê dormiu e recuperou suas forças.\n");
    energia += 10;
    if (energia > 10) energia = 10;
    system("pause");
}


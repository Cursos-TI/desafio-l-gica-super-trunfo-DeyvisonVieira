#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* --- Modelo de dados --- */
typedef struct {
    char  pais[50];
    int   populacao;
    float area;
    float pib;
    int   pontos_turisticos;
    float densidade_demografica; /* derivado */
} Carta;

/* --- Utilidades de I/O --- */
static void limpar_tela(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void aguarda_enter_se_necessario(int escolha) {
    if (escolha != 0) {
        printf("\nPressione Enter para continuar...");
        while (getchar() != '\n') { /* limpa buffer */ }
        getchar(); /* aguarda Enter */
    }
}

/* --- Setup das cartas --- */
static void inicializa_carta(Carta *c, const char *pais, int pop, float area, float pib, int pts) {
    strcpy(c->pais, pais);
    c->populacao = pop;
    c->area = area;
    c->pib = pib;
    c->pontos_turisticos = pts;
    c->densidade_demografica = c->populacao / c->area; /* derivado */
}

/* --- UI --- */
static void mostra_menu(const Carta *c1, const Carta *c2) {
    limpar_tela();
    printf("=============================================\n");
    printf("    SUPER TRUNFO - HORA DO DUELO!    \n");
    printf("=============================================\n\n");
    printf("Carta 1: %s\n", c1->pais);
    printf("Carta 2: %s\n\n", c2->pais);
    printf("Escolha o atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (Menor vence!)\n");
    printf("---------------------------------------------\n");
    printf("0. Sair do Jogo\n\n");
    printf("Digite sua opcao: ");
}

int main(void) {
    /* Cartas pré-definidas (mesmos valores do original) */
    Carta carta1, carta2;
    inicializa_carta(&carta1, "Brasil", 215300000, 8516000.0f, 1609.0f, 25);   /* PIB em bilhões USD */
    inicializa_carta(&carta2, "Japao",  125700000, 377975.0f,  4937.0f, 30);

    int escolha;
    do {
        mostra_menu(&carta1, &carta2);
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: /* População */
                printf("\n--- Comparando: Populacao ---\n");
                printf("%s: %d habitantes\n", carta1.pais, carta1.populacao);
                printf("%s: %d habitantes\n", carta2.pais, carta2.populacao);
                if (carta1.populacao > carta2.populacao) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.pais);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.pais);
                } else {
                    printf("\nResultado: Empate!\n");
                }
                break;

            case 2: /* Área */
                printf("\n--- Comparando: Area ---\n");
                printf("%s: %.2f km^2\n", carta1.pais, carta1.area);
                printf("%s: %.2f km^2\n", carta2.pais, carta2.area);
                if (carta1.area > carta2.area) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.pais);
                } else if (carta2.area > carta1.area) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.pais);
                } else {
                    printf("\nResultado: Empate!\n");
                }
                break;

            case 3: /* PIB */
                printf("\n--- Comparando: PIB ---\n");
                printf("%s: %.2f bilhoes USD\n", carta1.pais, carta1.pib);
                printf("%s: %.2f bilhoes USD\n", carta2.pais, carta2.pib);
                if (carta1.pib > carta2.pib) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.pais);
                } else if (carta2.pib > carta1.pib) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.pais);
                } else {
                    printf("\nResultado: Empate!\n");
                }
                break;

            case 4: /* Pontos Turísticos */
                printf("\n--- Comparando: Pontos Turisticos ---\n");
                printf("%s: %d pontos\n", carta1.pais, carta1.pontos_turisticos);
                printf("%s: %d pontos\n", carta2.pais, carta2.pontos_turisticos);
                if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.pais);
                } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.pais);
                } else {
                    printf("\nResultado: Empate!\n");
                }
                break;

            case 5: /* Densidade Demográfica (menor vence) */
                printf("\n--- Comparando: Densidade Demografica ---\n");
                printf("Regra Especial: O MENOR valor vence!\n");
                printf("%s: %.2f hab/km^2\n", carta1.pais, carta1.densidade_demografica);
                printf("%s: %.2f hab/km^2\n", carta2.pais, carta2.densidade_demografica);
                if (carta1.densidade_demografica < carta2.densidade_demografica) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.pais);
                } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.pais);
                } else {
                    printf("\nResultado: Empate!\n");
                }
                break;

            case 0: /* Sair */
                printf("\nObrigado por jogar! Saindo...\n");
                break;

            default: /* Inválida */
                printf("\nOpcao invalida! Por favor, escolha um numero do menu.\n");
                break;
        }

        aguarda_enter_se_necessario(escolha);
    } while (escolha != 0);

    return 0;
}

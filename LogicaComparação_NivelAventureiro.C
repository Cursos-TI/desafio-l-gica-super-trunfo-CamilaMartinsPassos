#include <stdio.h>

int main() {
    printf("Desafio Super Trunfo - Países\n");
    printf("Tema 2 - Comparação das Cartas\n");

    // Variáveis comuns
    char estado1[3], estado2[3];
    char codigo1[10], codigo2[10];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    // Variáveis adicionais
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // Cadastro da Carta 1
    printf("\n=== Cadastro da Carta 1 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado1);

    printf("Codigo da carta: ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade1); // permite espaços

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cadastro da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado2);

    printf("Codigo da carta: ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo dos atributos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0 / densidade1);
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0 / densidade2);

    // Menu interativo
    int opcao;

    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("6 - Mostrar nomes dos países\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");

    switch (opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %lu\n", cidade1, populacao1);
            printf("%s: %lu\n", cidade2, populacao2);
            if (populacao1 > populacao2)
                printf("Carta 1 venceu!\n");
            else if (populacao2 > populacao1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Área:\n");
            printf("%s: %.2f km²\n", cidade1, area1);
            printf("%s: %.2f km²\n", cidade2, area2);
            if (area1 > area2)
                printf("Carta 1 venceu!\n");
            else if (area2 > area1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("PIB:\n");
            printf("%s: %.2f\n", cidade1, pib1);
            printf("%s: %.2f\n", cidade2, pib2);
            if (pib1 > pib2)
                printf("Carta 1 venceu!\n");
            else if (pib2 > pib1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Pontos Turísticos:\n");
            printf("%s: %d\n", cidade1, pontosTuristicos1);
            printf("%s: %d\n", cidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Carta 1 venceu!\n");
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Densidade Demográfica (menor vence):\n");
            printf("%s: %.2f hab/km²\n", cidade1, densidade1);
            printf("%s: %.2f hab/km²\n", cidade2, densidade2);
            if (densidade1 < densidade2)
                printf("Carta 1 venceu!\n");
            else if (densidade2 < densidade1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 6:
            printf("Nome dos países:\n");
            printf("Carta 1: %s (%s)\n", cidade1, estado1);
            printf("Carta 2: %s (%s)\n", cidade2, estado2);
            break;

        default:
            printf("Opção inválida. Por favor, escolha um número entre 1 e 6.\n");
    }

    return 0;
}
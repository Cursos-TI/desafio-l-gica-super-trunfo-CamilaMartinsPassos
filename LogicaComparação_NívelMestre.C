#include <stdio.h>

// Função para extrair valores dos atributos
float getValor(int atributo, int carta,
               unsigned long int populacao1, unsigned long int populacao2,
               float area1, float area2,
               float pib1, float pib2,
               int pontosTuristicos1, int pontosTuristicos2,
               float densidade1, float densidade2) {
    switch (atributo) {
        case 1: return carta == 1 ? populacao1 : populacao2;
        case 2: return carta == 1 ? area1 : area2;
        case 3: return carta == 1 ? pib1 : pib2;
        case 4: return carta == 1 ? pontosTuristicos1 : pontosTuristicos2;
        case 5: return carta == 1 ? densidade1 : densidade2;
        default: return 0;
    }
}

int main() {
    // Dados das cartas
    char estado1[3], estado2[3];
    char codigo1[10], codigo2[10];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    // Atributos derivados
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // Cadastro das cartas
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado1);
    printf("Código da carta: ");
    scanf("%s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado2);
    printf("Código da carta: ");
    scanf("%s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo dos atributos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    // Escolha dos atributos
    int atributo1 = -1, atributo2 = -1;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma1 = 0, soma2 = 0;

    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo1);

    // Menu dinâmico para segundo atributo
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica (menor vence)\n"); break;
            }
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &atributo2);

    // Obter valores dos atributos
    valor1_carta1 = getValor(atributo1, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2);
    valor1_carta2 = getValor(atributo1, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2);
    valor2_carta1 = getValor(atributo2, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2);
    valor2_carta2 = getValor(atributo2, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontosTuristicos1, pontosTuristicos2, densidade1, densidade2);

    // Exibir nomes
    printf("\n=== COMPARAÇÃO DAS CARTAS ===\n");
    printf("Carta 1: %s (%s)\n", cidade1, estado1);
    printf("Carta 2: %s (%s)\n\n", cidade2, estado2);

    // Comparação do primeiro atributo
    printf("Atributo 1: %s\n", 
        atributo1 == 1 ? "População" :
        atributo1 == 2 ? "Área" :
        atributo1 == 3 ? "PIB" :
        atributo1 == 4 ? "Pontos Turísticos" :
        "Densidade Demográfica");

    printf("Carta 1: %.2f\n", valor1_carta1);
    printf("Carta 2: %.2f\n", valor1_carta2);
    printf("Resultado: %s\n",
        atributo1 == 5 ?
            (valor1_carta1 < valor1_carta2 ? "Carta 1 venceu!" :
             valor1_carta2 < valor1_carta1 ? "Carta 2 venceu!" : "Empate!") :
            (valor1_carta1 > valor1_carta2 ? "Carta 1 venceu!" :
             valor1_carta2 > valor1_carta1 ? "Carta 2 venceu!" : "Empate!")
    );

    // Comparação do segundo atributo
    printf("\nAtributo 2: %s\n", 
        atributo2 == 1 ? "População" :
        atributo2 == 2 ? "Área" :
        atributo2 == 3 ? "PIB" :
        atributo2 == 4 ? "Pontos Turísticos" :
        "Densidade Demográfica");

    printf("Carta 1: %.2f\n", valor2_carta1);
    printf("Carta 2: %.2f\n", valor2_carta2);
    printf("Resultado: %s\n",
        atributo2 == 5 ?
            (valor2_carta1 < valor2_carta2 ? "Carta 1 venceu!" :
             valor2_carta2 < valor2_carta1 ? "Carta 2 venceu!" : "Empate!") :
            (valor2_carta1 > valor2_carta2 ? "Carta 1 venceu!" :
             valor2_carta2 > valor2_carta1 ? "Carta 2 venceu!" : "Empate!")
    );

    // Soma dos atributos
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\n=== RESULTADO FINAL ===\n");
    printf("Soma dos atributos:\n");
    printf("Carta 1: %.2f\n", soma1);
    printf("Carta 2: %.2f\n", soma2);
    printf("%s\n", 
        soma1 > soma2 ? "🏆 Carta 1 venceu a rodada!" :
        soma2 > soma1 ? "🏆 Carta 2 venceu a rodada!" :
        "⚖️ Empate!"
    );

    return 0;
}
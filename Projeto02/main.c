/* 
GABRIEL ALVES POSSATO - RA: 10769692 
HENRIQUE SILVA PEREIRA - RA: ?
FELIPE VENÂNCIO BARROS - RA: ?
*/

#include <stdio.h>

#define MAX 1000

int carregarLeituras(const char nomeArquivo[], 
                    int ids[],
                    int unidadeIds[],
                    int meses[],
                    int anos[],
                    float consumos[],
                    int max) {
    // Abre e lê o arquivo
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo leituras.txt.\nEncerrando o programa.");
        return -1;
    }

    int n = 0;
    // Usando esse "fscanf" no while porque ele faz duas coisas ao mesmo tempo: lê os dados e retorna quantos dados foram lidos (motivo pelo qual tem um "== 5" no final)
    while (n < max && fscanf(arquivo, "%d %d %d %d %f", &ids[n], &unidadeIds[n], &meses[n], &anos[n], &consumos[n]) == 5) {
        n++;
    }
    fclose(arquivo);

    return n;
}

int carregarUnidades(const char nomeArquivo[], 
                    int unidadeIds[],
                    char descricoes[][50], 
                    int max) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo unidades.csv.\nEncerrando o programa.");
        return -1;
    }

    char linha[100];
    int n = 0;
    // Usando agora o "fgets" porque ele pega a linha inteira como texto, com todos espaços (o "fscanf" só leria, por exemplo, "Laboratório" de "Laboratório de Informática")
    while (n < max && fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Esse "sscanf" têm a mesma funcionalidade do "fscanf", mas ele lê uma string ao invés de um arquivo
        if (sscanf(linha, "%d;%49[^\r\n]", &unidadeIds[n], descricoes[n]) == 2) {
            n++;
        }
    }
    fclose(arquivo);

    return n;
}

// Essa função auxiliar aqui só procura no array das "unidades" a descrição exata que queremos (exibimos elas várias vezes) 
int indiceUnidade(int unidadeIdsCatalogo[], int nUnidades, int id) {
    for (int j = 0; j < nUnidades; j++) {
        if (unidadeIdsCatalogo[j] == id) return j;
    }
    return -1;
}

int buscaLinear(int ids[], int n, int idProcurado) {
    int i;
    for (i = 0; i < n; i++) {
        if (ids[i] == idProcurado) {
            return i;
        } 
    } return -1;
}

int buscaBinaria(int ids[], int n, int idProcurado) {
    int inicio = 0;
    int fim = n - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (ids[meio] == idProcurado) {
            return meio;
        } else if (ids[meio] > idProcurado) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    } return -1;
}

int main() {
    /* DECLARAÇÕES INICIAIS */
    int ids[MAX];
    int unidadeIds[MAX];
    int meses[MAX];
    int anos[MAX];
    float consumos[MAX];
    int nLeituras;

    int unidadeIdsCatalogo[MAX];
    char descricoes[MAX][50];
    int nUnidades;

    int opcao = 0;

    int ordenado = 0;
    int opcaoOrd;
    int i; 

    int idLeitura, opcaoBusca;
    int j;

    int idUnidade;
    float consumoTotal;

    int mesInicial, anoInicial, mesFinal, anoFinal;

    int idMaior;
    /* -------------------- */

    /* CARREGAMENTO DOS ARQUIVOS */
    nLeituras = carregarLeituras("leituras.txt", ids, unidadeIds, meses, anos, consumos, MAX);
    nUnidades = carregarUnidades("unidades.csv", unidadeIdsCatalogo, descricoes, MAX);

    if (nLeituras == -1 || nUnidades == -1) {
        return 1;
    }
    /* ------------------------- */

    /* MENU PRINCIPAL */
    while (opcao != 6) {
        printf(
            "\n===== SISTEMA DE ANALISE DE CONSUMO DE ENERGIA =====\n"
            "\n1. Mostrar leituras ordenadas por ID\n"
            "2. Buscar leitura por ID\n"
            "3. Calcular consumo de uma unidade\n"
            "4. Calcular consumo em um periodo\n"
            "5. Identificar unidade com maior consumo\n"
            "6. Sair da aplicacao\n"
            "\nEscolha uma opcao: "
        );
        scanf("%d", &opcao);

        switch (opcao) {
            /* OPÇÃO 1 (ordenação dos arrays) */
            case 1:
                if (!ordenado) {
                    printf(
                    "\nEscolha o algoritmo de ordenacao:\n"
                    "\n1. Bubble Sort\n"
                    "2. Insertion Sort\n"
                    "3. Selection Sort\n"
                    "4. Quick Sort\n"
                    "5. Merge Sort\n"
                    "\nEscolha uma opcao: "
                    );
                    scanf("%d", &opcaoOrd);

                    switch (opcaoOrd) {
                        case 1:
                            bubbleSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, nLeituras);
                            ordenado = 1;
                            break;
                        case 2:
                            insertionSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, nLeituras);
                            ordenado = 1;
                            break;
                        case 3:
                            selectionSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, nLeituras);
                            ordenado = 1;
                            break;
                        case 4:
                            quickSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, nLeituras - 1);
                            ordenado = 1;
                            break;
                        case 5:
                            mergeSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, nLeituras - 1);
                            ordenado = 1;
                            break;
                        default: 
                            printf("Opcao invalida. Tente novamente.\n");
                            break;
                    } 
                } if (ordenado) {
                    printf(
                        "\nLeituras ordenadas por ID:\n\n"
                        "ID | Unidade | Descricao                  | Mes | Ano  | Consumo (kWh)\n"
                        "----------------------------------------------------------------------\n"
                    );
                    for (i = 0; i < nLeituras; i++) {
                        int j = indiceUnidade(unidadeIdsCatalogo, nUnidades, unidadeIds[i]);
                        printf("%d | %d | %-26s | %d | %d | %.2f\n",
                            ids[i], unidadeIds[i], descricoes[j], meses[i], anos[i], consumos[i]);
                    }
                }
                break;
            /* ------------------------------ */

            /* OPÇÃO 2 (tipos de busca) */
            case 2: 
                printf("\nDigite o ID da leitura: ");
                scanf("%d", &idLeitura);

                printf(
                    "\nEscolha o algoritmo de busca: \n"
                    "\n1. Busca linear\n"
                    "2. Busca binaria\n"
                    "\nEscolha uma opcao: "
                );
                scanf("%d", &opcaoBusca);

                i = -1;

                switch (opcaoBusca) {
                    case 1: 
                        i = buscaLinear(ids, nLeituras, idLeitura);
                        break;
                    case 2:
                        if (!ordenado) {
                            mergeSortLeituraPorId(ids, unidadeIds, meses, anos, consumos, 0, nLeituras - 1);
                            ordenado = 1;
                        }
                        i = buscaBinaria(ids, nLeituras, idLeitura);
                        break;
                    default: 
                        printf("Opcao invalida. Tente novamente.\n");
                        break;
                }
                if (opcaoBusca == 1 || opcaoBusca == 2) {
                    if (i == -1) {
                        printf("\nLeitura nao encontrada.\n");
                    } else {
                        j = indiceUnidade(unidadeIdsCatalogo, nUnidades, unidadeIds[i]);
                        printf(
                            "\nLeitura encontrada:\n\n"
                            "ID Leitura: %d\n"
                            "Unidade: %d\n"
                            "Descricao: %s\n"
                            "Mes: %d\n"
                            "Ano: %d\n"
                            "Consumo: %.2f kWh\n", 
                            ids[i], unidadeIds[i], descricoes[j], meses[i], anos[i], consumos[i]
                        );
                    }
                }
                break;
            /* ------------------------ */
            
            /* OPÇÃO 3 (calcular consumo de unidade) */
            case 3: 
                printf("\nDigite o ID da unidade: ");
                scanf("%d", &idUnidade);

                j = indiceUnidade(unidadeIdsCatalogo, nUnidades, idUnidade);

                if (j == -1) {
                    printf("\nUnidade nao encontrada.\n");
                } else {
                    consumoTotal = calcularConsumoUnidade(unidadeIds, consumos, nLeituras, idUnidade);
                    printf(
                        "\nConsumo da unidade:\n\n"
                        "Unidade: %d\n"
                        "Descricao: %s\n"
                        "Consumo total: %.2f kWh\n",
                        idUnidade, descricoes[j], consumoTotal
                    );
                }
                break;
            /* ------------------------------------- */
            
            /* OPÇÃO 4 (calcular consumo em um período) */
            case 4: 
                printf("\nDigite o mes inicial: ");
                scanf("%d", &mesInicial);
                printf("Digite o ano inicial: ");
                scanf("%d", &anoInicial);
                printf("Digite o mes final: ");
                scanf("%d", &mesFinal);
                printf("Digite o ano final: ");
                scanf("%d", &anoFinal);

                if (mesInicial < 1 || mesInicial > 12 ||
                    mesFinal < 1 || mesFinal > 12 ||
                    anoInicial > anoFinal ||
                    (anoInicial == anoFinal && mesInicial > mesFinal)) {
                    printf("\nPeriodo invalido.\n");
                } else {
                    consumoTotal = calcularConsumoPeriodo(meses, anos, consumos, nLeituras,
                                                        mesInicial, anoInicial, mesFinal, anoFinal);
                    printf(
                        "\nConsumo no periodo:\n\n"
                        "Periodo: %02d/%d ate %02d/%d\n"
                        "Consumo total: %.2f kWh\n",
                        mesInicial, anoInicial, mesFinal, anoFinal, consumoTotal
                    );
                }
                break;
            /* ---------------------------------------- */
            
            /* OPÇÃO 5 (unidade com maior consumo) */
            case 5: 
                idMaior = encontrarUnidadeMaiorConsumo(unidadeIds, consumos, nLeituras);

                j = indiceUnidade(unidadeIdsCatalogo, nUnidades, idMaior);
                consumoTotal = calcularConsumoUnidade(unidadeIds, consumos, nLeituras, idMaior);

                printf(
                    "\nUnidade com maior consumo:\n\n"
                    "Unidade: %d\n"
                    "Descricao: %s\n"
                    "Consumo total: %.2f kWh\n",
                    idMaior, descricoes[j], consumoTotal
                );
                break;
            /* ----------------------------------- */
            
            case 6:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
    /* -------------- */
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Item, que armazena informações essenciais de cada objeto coletado.
// Campos: nome (até 29 caracteres + \0), tipo (até 19 caracteres + \0) e quantidade (inteiro).
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor global para armazenar até 10 itens, simulando a mochila.
Item mochila[10];

// Variável global para controlar o número de itens cadastrados na mochila.
int numItens = 0;

// Função para inserir um novo item na mochila.
// Verifica se há espaço (máximo 10 itens), solicita nome, tipo e quantidade, e adiciona ao vetor.
void inserirItem() {
    if (numItens >= 10) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }
    
    Item novoItem;
    
    // Limpa o buffer de entrada para evitar problemas com leituras anteriores.
    getchar();
    
    // Solicita o nome do item. Usa fgets para permitir espaços no nome.
    printf("Digite o nome do item: ");
    fgets(novoItem.nome, sizeof(novoItem.nome), stdin);
    // Remove o '\n' do final da string lida por fgets.
    novoItem.nome[strcspn(novoItem.nome, "\n")] = '\0';
    
    // Solicita o tipo do item (ex: arma, municao, cura). Usa scanf para simplicidade, assumindo sem espaços.
    printf("Digite o tipo do item (ex: arma, municao, cura): ");
    scanf("%s", novoItem.tipo);
    
    // Solicita a quantidade do item.
    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);
    
    // Adiciona o item ao vetor e incrementa o contador.
    mochila[numItens] = novoItem;
    numItens++;
    
    printf("Item cadastrado com sucesso!\n");
}

// Função para remover um item da mochila pelo nome.
// Busca sequencialmente pelo nome, remove se encontrado (deslocando os itens subsequentes) e decrementa o contador.
void removerItem() {
    if (numItens == 0) {
        printf("Mochila vazia! Não há itens para remover.\n");
        return;
    }
    
    char nomeRemover[30];
    
    // Limpa o buffer de entrada.
    getchar();
    
    // Solicita o nome do item a remover.
    printf("Digite o nome do item a remover: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';
    
    // Busca sequencial pelo item.
    int i;
    for (i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            // Item encontrado: desloca os itens subsequentes para a esquerda.
            int j;
            for (j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            numItens--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }
    
    printf("Item não encontrado na mochila.\n");
}

// Função para listar todos os itens cadastrados na mochila.
// Percorre o vetor e imprime os dados de cada item.
void listarItens() {
    if (numItens == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    
    printf("\nItens na mochila:\n");
    int i;
    for (i = 0; i < numItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("\n");
}

// Função para buscar um item na mochila pelo nome.
// Realiza busca sequencial e exibe os dados se encontrado.
void buscarItem() {
    if (numItens == 0) {
        printf("Mochila vazia! Não há itens para buscar.\n");
        return;
    }
    
    char nomeBuscar[30];
    
    // Limpa o buffer de entrada.
    getchar();
    
    // Solicita o nome do item a buscar.
    printf("Digite o nome do item a buscar: ");
    fgets(nomeBuscar, sizeof(nomeBuscar), stdin);
    nomeBuscar[strcspn(nomeBuscar, "\n")] = '\0';
    
    // Busca sequencial pelo item.
    int i;
    for (i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBuscar) == 0) {
            printf("Item encontrado:\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }
    
    printf("Item não encontrado na mochila.\n");
}

// Função principal: controla o fluxo do programa com um menu interativo.
// Permite ao jogador escolher operações e chama as funções correspondentes.
// Após cada operação (exceto sair), lista os itens para feedback.
int main() {
    int opcao;
    
    printf("Bem-vindo ao sistema de inventário da mochila de loot!\n");
    printf("Você pode cadastrar até 10 itens.\n\n");
    
    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    
    return 0;
}

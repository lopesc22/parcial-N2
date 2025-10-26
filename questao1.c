#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
} Data;

typedef struct {
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    Data aniv;
} Contato;

typedef struct elemento {
    Contato info;
    struct elemento *prox;
} Elemento;

Elemento* cria_agenda() {
    return NULL;
}

Elemento* insere_contato(Elemento* lista) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro de memoria\n");
        return lista;
    }

    getchar();
    printf("Nome: ");
    fgets(novo->info.nome, 41, stdin);
    novo->info.nome[strcspn(novo->info.nome, "\n")] = '\0';

    printf("Telefone: ");
    fgets(novo->info.telefone, 16, stdin);
    novo->info.telefone[strcspn(novo->info.telefone, "\n")] = '\0';

    printf("Celular: ");
    fgets(novo->info.celular, 16, stdin);
    novo->info.celular[strcspn(novo->info.celular, "\n")] = '\0';

    printf("Email: ");
    fgets(novo->info.email, 41, stdin);
    novo->info.email[strcspn(novo->info.email, "\n")] = '\0';

    printf("Dia do aniversario: ");
    scanf("%d", &novo->info.aniv.dia);

    printf("Mes do aniversario: ");
    scanf("%d", &novo->info.aniv.mes);

    novo->prox = NULL;

    if (lista == NULL) {
        lista = novo;
    } else {
        Elemento* aux = lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    printf("Contato inserido com sucesso.\n");
    return lista;
}

void lista_contatos(Elemento* lista) {
    if (lista == NULL) {
        printf("Agenda vazia.\n");
        return;
    }

    Elemento* aux = lista;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->info.nome);
        printf("Telefone: %s\n", aux->info.telefone);
        printf("Celular: %s\n", aux->info.celular);
        printf("Email: %s\n", aux->info.email);
        printf("Aniversario: %02d/%02d\n", aux->info.aniv.dia, aux->info.aniv.mes);
        aux = aux->prox;
    }
}

Elemento* busca_contato(Elemento* lista, char nome[]) {
    Elemento* aux = lista;
    while (aux != NULL) {
        if (strcmp(aux->info.nome, nome) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

Elemento* remove_contato(Elemento* lista, char nome[]) {
    Elemento *anterior = NULL, *atual = lista;

    while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato nao encontrado.\n");
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Contato removido.\n");
    return lista;
}

void atualiza_contato(Elemento* lista, char nome[]) {
    Elemento* contato = busca_contato(lista, nome);

    if (contato == NULL) {
        printf("Contato nao encontrado.\n");
        return;
    }

    getchar(); 
    printf("Novo telefone: ");
    fgets(contato->info.telefone, 16, stdin);
    contato->info.telefone[strcspn(contato->info.telefone, "\n")] = '\0';

    printf("Novo celular: ");
    fgets(contato->info.celular, 16, stdin);
    contato->info.celular[strcspn(contato->info.celular, "\n")] = '\0';

    printf("Novo email: ");
    fgets(contato->info.email, 41, stdin);
    contato->info.email[strcspn(contato->info.email, "\n")] = '\0';

    printf("Novo dia do aniversario: ");
    scanf("%d", &contato->info.aniv.dia);

    printf("Novo mes do aniversario: ");
    scanf("%d", &contato->info.aniv.mes);

    printf("Contato atualizado.\n");
}

int main() {
    Elemento* agenda = cria_agenda();
    int op;
    char nome[41];

    do {
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao do menu: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                agenda = insere_contato(agenda);
                break;

            case 2:
                lista_contatos(agenda);
                break;

            case 3:
                getchar();
                printf("Informe o contato para buscar: ");
                fgets(nome, 41, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                if (busca_contato(agenda, nome))
                    printf("Contato encontrado\n");
                else
                    printf("Contato nao encontrado\n");
                break;

            case 4:
                getchar();
                printf("Informa o contato para editar: ");
                fgets(nome, 41, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                atualiza_contato(agenda, nome);
                break;

            case 5:
                getchar();
                printf("Informe o contato para remover: ");
                fgets(nome, 41, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                agenda = remove_contato(agenda, nome);
                break;

            case 6:
                printf("Saindo do programa\n");
                break;
        }

    } while (op != 6);

    return 0;
}
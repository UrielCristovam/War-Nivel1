// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO - NÍVEL NOVATO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// Criar uma struct chamada Territorio.
// Usar um vetor estático de 5 elementos para armazenar os territórios.
// Cadastrar os dados de cada território: Nome, Cor do Exército, e Número de Tropas.
// Exibir o estado atual do mapa.
//
// ============================================================================
// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 




// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

#define MAX_TERRITORIOS 5



// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

struct Territorio{
    
    //as variaveis são estrutudadas com: tipo nomeDaVariavel[tamanho];
     char NomeTerritorio[50];    
     char CorDoTerritorio[50];
     int numeroDeTropas; 
 
};


// Funções
// Leitura de dados pelo terminal (fgets e scanf)
void limparBufferEntrada(){
    
    int c; 

    //o laço funciona da seguinte forma: função (while, que significa "enquanto") (variável c recebe o valor da função getchar() que lê um caractere do stdin) (enquanto c for diferente de '\n' (nova linha) e diferente de EOF (fim do arquivo))
    //em seu parametro, atribui a variavel c o valor retornado pela função getchar(), que lê um caractere do stdin (entrada padrão, geralmente o teclado).
    //a condição envolve testar se getchar() retornou um caractere que não seja uma nova linha ('\n') ou o fim do arquivo (EOF), isso porque "\n" indica o final de uma linha de entrada, e EOF indica que não há mais dados para ler. 
    while((c = getchar()) != '\n' && c != EOF); 
    
};


// uma função void, com parametro struct Territorio com ponteiro, e um indice do tipo int 
void entradaDoUsuario(struct Territorio *t, int indice){

    char buffer[10];

    printf("\n--TERRITÓRIO #%d --- \n", indice);

    printf("Digite o numero de tropas que deseja alocar:\n");

    if(fgets(buffer, sizeof(buffer), stdin) != NULL){

        t->numeroDeTropas = atoi(buffer);
    }else{
        t -> numeroDeTropas = 0;
        printf("erro na leitura. Definindo tropas para 0.\n");
    }

    if(t -> numeroDeTropas == 0 && (buffer)[0] != '0'){
        limparBufferEntrada();
    }

    printf("Qual é o nome do seu território?\n");
    scanf("%49s", t->NomeTerritorio);
    limparBufferEntrada();

    printf("Qual é a cor do seu exército?\n");
    scanf("%49s", t->CorDoTerritorio);
    limparBufferEntrada();
}

int main(){
    struct Territorio territ[MAX_TERRITORIOS];
    
    for(int i = 0; i < MAX_TERRITORIOS; ++i){
        entradaDoUsuario(&territ[i], i + 1);
    }; 
    
    
    return 0;
}

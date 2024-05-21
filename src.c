#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <new> //Substitui o malloc
#include <string>

using namespace std;

struct pessoa{
    string nome;
    int rg;
};

void limpaTela(){
    system("CLS");
}
//(Essa funcao imprime uma lista sequencial)  Assim eu sei qual eh a primneira posição na memoria que contem meu vetor, se eu sei tamanho da lista sei quanto eu posso navegar nessa lista
void imprimeSequencial(pessoa *ponteiroSequencial, int tamanhoDaLista){
    int cont;
    for(cont = 0; cont < tamanhoDaLista; cont++){
        cout << cont << "-"<< ponteiroSequencial[cont].nome << "," << ponteiroSequencial[cont].rg << "\n"; //Como eu to usando um ponteiro que esta sendo enviardo para uma funcao nao vou suar a setinha(->), vou usar ponto(.)
    }
}   
//Adicionar no inicio da nosssa sequencial(*& -> usado para fazer com que a variavel de escopo local tenha escopo global)
void adcComecoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista,string nome, int rg){
    //Se a lista estiver vazia, cria um lista nova
    if(tamanhoDaLista ==0){
        pessoa *novaListaSequencial = new pessoa [1];
        //Insere o primeiro novo elemento
        novaListaSequencial[0].nome = nome;
        novaListaSequencial[0].rg = rg;
        //Atualiza o ponteiro para a lista nova
        ponteiroSequencial = novaListaSequencial;
    }else{
        //Caso a lista ja tenha membros(criamos um vetor com um tamanho a mais)
        pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];
        //Insere o primeiro novo elemento
        novaListaSequencial[0].nome = nome;
        novaListaSequencial[0].rg = rg;

        //Passa os elementos do vetor anmtigo para o novo uma casa a frente
        for(int i = 0;i < *tamanhoDaLista; i++){
            novaListaSequencial[i + 1].nome = ponteiroSequencial[i].nome;
            novaListaSequencial[i + 1].rg = ponteiroSequencial[i].rg;
        }

        //Atualiza o ponteiro para a lista nova
        ponteiroSequencial = novaListaSequencial;    
    }

    //Aumenta o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void adcFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista,string nome, int rg){
    //Cria uma lista com tamanho maior(1 espaço a mais)
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

    //Passa os elementos do vetor anmtigo para o novo uma casa a frente
    for(int i = 0; i < *tamanhoDaLista; i++){
        novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
        novaListaSequencial[i].rg = ponteiroSequencial[i].rg;
    }
    //Posiciona o ultimo elemento
    //O ultimo elemento da lista nova, vai ser o tamasnho da lista velha
    novaListaSequencial[*tamanhoDaLista].nome = nome;
    novaListaSequencial[*tamanhoDaLista].rg = rg;

    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Atualiza o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void adcPosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista,string nome, int rg, int posicao){//Criar um vetor maior, iniciar colocando os antugois, quando numa posição especifica coloca o novo valor e depois retoma a colocação dos antigos
    //Cria uma lista com tamanho maior(1 espaço a mais)
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];
    int i;
    //Passa os elementos do vetor anmtigo para o novo uma casa a frente, indo ate a posicao que eu quero inserir
    for(i = 0; i < posicao; i++){
        novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
        novaListaSequencial[i].rg = ponteiroSequencial[i].rg;
    } 
    //Adiciona o novo registro na posição correta
    novaListaSequencial[i].nome = nome;
    novaListaSequencial[i].rg = rg;

    //Adiciona o resto dos valores antigos
    for(i = posicao + 1; i < *tamanhoDaLista + 1; i++){
        novaListaSequencial[i].nome = ponteiroSequencial[i - 1].nome;
        novaListaSequencial[i].rg = ponteiroSequencial[i - 1].rg;
    }

    //Atualiza o ponteiro para a lista nova(lista seguinte)
    ponteiroSequencial = novaListaSequencial;

    //Atualiza o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}


void removeInicioSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista){
    //Cria um vetor com uma posição a menos
    pessoa *novaListaSquencial = new pessoa[*tamanhoDaLista - 1];
    //Passar elementos da lista antiga
    for(int i = 1 ; i < *tamanhoDaLista; i++){ //O indice 0 da nova lista recebe o indice 1 da lista antiga
        novaListaSquencial[i].nome = ponteiroSequencial[i].nome;
        novaListaSquencial[i].rg = ponteiroSequencial[i].rg;
    }

    //Atualiza o ponteiro para a lista nova(lista seguinte)
    ponteiroSequencial = novaListaSquencial;

    //Atualiza o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

void removeFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista){
    //Cria um vetor menor
    pessoa *novaListaSquencial = new pessoa[*tamanhoDaLista - 1];

    //Passar elementos da lista antiga(menos o último valor)
    for(int i = 0 ; i < *tamanhoDaLista - 1; i++){ //O indice 0 da nova lista recebe o indice 1 da lista antiga
        novaListaSquencial[i - 1].nome = ponteiroSequencial[i].nome;
        novaListaSquencial[i - 1].rg = ponteiroSequencial[i].rg;
    }

    //Atualiza o ponteiro para a lista nova(lista seguinte)
    ponteiroSequencial = novaListaSquencial;

    //Atualiza o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

void removePosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista,int posicao){
    //Cria um vetor menor
    pessoa *novaListaSquencial = new pessoa[*tamanhoDaLista - 1];

    //Passar elementos da lista antiga(menos o último valor)
    for(int i = 0 ; i < posicao; i++){ //O indice 0 da nova lista recebe o indice 1 da lista antiga
        //Se estiver antes da posicao, passa normalmente
        if(i < posicao){
            novaListaSquencial[i].nome = ponteiroSequencial[i].nome;
            novaListaSquencial[i].rg = ponteiroSequencial[i].rg;
        }else{ //Assim que eu chego no valor que eu desejo remover, eu ignoro ele e vou pro proximo e continua dicionando na nova lista
            novaListaSquencial[i + 1].nome = ponteiroSequencial[i].nome;
            novaListaSquencial[i + 1].rg = ponteiroSequencial[i].rg;
        }
    }

    //Atualiza o ponteiro para a lista nova(lista seguinte)
    ponteiroSequencial = novaListaSquencial;

    //Atualiza o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

string retornaNomeSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int rg){
    string nome = "Nao encontrado";
    //Busca o nome pelo RG digitado
    for(int i = 0; i < *tamanhoDaLista; i++){
        if(ponteiroSequencial[i].rg == rg){
            nome = ponteiroSequencial[i].nome; 
        }
    }
    return nome;
}

int main(){

    int funcaoDesejada = 1;
    //Ponteiro para a lista sequencial(ponteiro principal)
    pessoa *ponteiroSequencial;

    //Tamanho da lista
    int tamanhoDaLista = 0;

    /*Exemplo
    pessoa *exemploListaSequencial = new pessoa[1]; //Mesma cosa que fazer malloc 
    
    exemploListaSequencial[0].nome = "Jhon";
    exemploListaSequencial[0].rg = 123;
    exemploListaSequencial[0].nome = "Maicon";
    exemploListaSequencial[0].rg = 321;

    //Faz o ponteiro principal apontar para o novo vetor
    ponteiroSequencial = exemploListaSequencial;
    */

    //Mostrando o menu
    while (funcaoDesejada < 9 && funcaoDesejada > 0){
        //Imprime a lista completa
        imprimeSequencial(ponteiroSequencial, tamanhoDaLista);

        printf("Operacoes \n");
        printf("1 - Insercao de um node no inicio da lista \n");
        printf("2 - Insercao de um node no fim da lista \n");
        printf("3 - Insercao de um node na posicao N \n");
        printf("4 - Retirar um node do inicio da lista \n");
        printf("5 - Retirar um node no fim da lista \n");
        printf("6 - Retirar um node na posicao N \n");
        printf("7 - Procurar um node com o campo RG \n");
        printf("8 - Imprimir a lista \n");
        printf("9 - Sair do sistema \n");
        printf("\nEscolha um numero e pressione ENTER: \n");
        //Lendo opcao do usuario
        scanf("%d", &funcaoDesejada);

        limpaTela();
        //Variáveis usadas nas operações
        string nome;
        int rg, posicao;

        //Chama a funcao desejada
        switch(funcaoDesejada)
        {
        case 1:
            printf("Funcao escolhida: 1 - Insercao de um node no inicio da lista \n");
            cout << "Digite um nome:\n";
            cin  >> nome;
            cout << "Digite um rg:";
            cin  >> rg;

            adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
            break;
        case 2:
            printf("Funcao escolhida: 2 - Insercao de um node no fim da lista \n");
            //Como eu ja tenho na funcao adcComecoSequencial a verificacao se minha lista esta vazia pra que eu vou criar tudo isso denovo numa nova funcao
            cout << "Digite um nome:\n";
            cin  >> nome;
            cout << "Digite um rg:";
            cin  >> rg;
            //Se a lista for vazia usamos a funcao de criar no inicio, se nao fazemos a operacao de criar um novo vetor com um tamanho a mais e passar todo mundo do antigo pro novo
            if(tamanhoDaLista == 0){
                adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);

            }else{ //Vou preicsar passar o ponteiro sequencial ja que vou ter que enviar ponteiro principal pra apontar pra minha lista nova, enviar tbm meu tamanho da lista nova
                adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
            }
            break;
        case 3:
            printf("Funcao escolhida: 3 - Insercao de um node na posicao N \n");

            cout << "Digite um nome:\n";

            cout << "Digite uma posicao:\n";
            cin  >> posicao;
            cin  >> nome;
            cout << "Digite um rg:";
            cin  >> rg;
            //Se estiver adicionando no comeco
            if(posicao == 0){
                adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);

            }else if(posicao == tamanhoDaLista){ //Quando quer adicionar ao fim
                adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
            }else{ //Adiciona na posição N
                adcPosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg, posicao);
            }
            break;
        case 4:
            printf("Funcao escolhida: 4 - Retirar um node do inicio da lista \n");
            //Se a lista for vazia
            if(tamanhoDaLista == 0){
                cout << "\n Lista vazia!\n";
                removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
            }else{

            }
            break;
        case 5:
            printf("Funcao escolhida: 5 - Retirar um node no fim da lista \n");

            //Se a lista for vazia
            if(tamanhoDaLista == 0){
                cout << "\nLista Vazia!\n";
            }else{
                removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
            }
            break;
        case 6:
            printf("Funcao escolhida: 6 - Retirar um node na posicao N \n");

            //Se a lista for vazia
            if(tamanhoDaLista == 0){
                cout << "\n Lista vazia!\n";
            }else{
                cout << "Digite a posicao: ";
                cin >> posicao;

                if(posicao == 0){
                    removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
                }else if(posicao == tamanhoDaLista - 1){
                    removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
                }else{
                    removePosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, posicao);
                }
            }
            break;
        case 7:
            printf("Funcao escolhida: 7 - Procurar um node com o campo RG \n");

            //Se a lista for vazia
            if(tamanhoDaLista == 0){
                cout << "\n Lista vazia!\n";
            }else{
                cout << "Digite o RG: ";
                cin >> rg;

                cout << "Nome correspondente ao RG -> " << rg << ": " << retornaNomeSequencial(ponteiroSequencial, &tamanhoDaLista, rg);
            }
            break;
        case 8:
            printf("Funcao escolhida: 8 - Imprimir a lista \n");
            //Imprime a lista completa
            imprimeSequencial(ponteiroSequencial, tamanhoDaLista);
            break;
        
        default:
            break;
        }

    }

    return 0;
}

//Johan Santos-Lp1
//declarando constantes
//declaração  de biblioteca
#include <stdio.h>
//contantes para cores
#define BG_AZUL "\x01b[44;1m"
#define BG_VERMELHO "\x01b[41;1m"
#define BG_VERDE "\x001b[42m"
#define BG_MAGENTA "\x001b[45m"
#define VERMELHO "\x01b[31;1m"
#define AZUL "\x01b[34;1m"
#define AMARELO "\x01b[33;1m"
#define VERDE "\x01b[32;1m"
#define ROXO "\x01b[35;1m"
//constante para resetar a cor do texto ao normal
#define RESET "\x1b[0m"
//contante do tamanho da matriz
#define TAM 26 
//constantes para os danos dos obstaculos
#define DANO_4 25
#define DANO_5 20
#define DANO_6 35
#define DANO_7 25
#define DANO_8 30
#define DANO_9 25
#define DANO_10 20
#define DANO_11 35
#define DANO_12 25
#define DANO_13 20
#define DANO_14 30
#define DANO_15 100
//valor muito alto utilizado nos laços de for para criação de mensagens temporárias
#define DELAY 999999999
//criando função para limpar teclado
void LimpaBuffer(){
      scanf("%*[^\n]");
      scanf("%*c");
};
//criando função para limpar tela
void LimpaTela(){
    system("clear||cls");
};
//delcaração da matriz do labirinto
int main(void){
    int labirinto[TAM][TAM]={
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,3,1,
    1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,
    1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,
    1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,0,1,0,0,7,1,1,0,0,0,1,
    1,0,0,0,1,1,1,0,0,1,6,1,0,0,1,1,1,1,0,1,0,1,0,0,0,1,
    1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,14,0,1,0,1,0,0,0,1,
    1,0,1,0,0,0,1,5,1,0,1,1,1,1,1,0,0,1,1,1,0,1,11,0,0,1,
    1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,
    1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,13,1,0,0,0,0,1,0,0,1,
    1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,0,0,1,0,0,0,0,1,0,0,1,
    1,0,1,1,1,0,1,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,
    1,0,0,0,0,0,0,0,1,0,0,0,0,12,0,0,0,1,0,1,0,0,0,0,0,1,
    1,0,0,0,1,1,1,4,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,0,0,1,
    1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,
    1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,10,0,0,1,0,0,1,
    1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,0,1,0,0,1,
    1,0,0,1,0,1,1,1,0,1,8,1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,
    1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,
    1,0,0,1,1,1,0,1,0,1,1,0,0,1,0,0,1,9,1,1,1,1,1,0,0,1,
    1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
    1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,
    1,2,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    };
    //declaração de variáveis
    int lin, col, posx, posy, hp=100, dano, cont, fim=0;
    char nome[50], tec;
    //perguntando ao usuario seu nick
    printf("\n\n\n\t\t\t------------------------------------------------------Labirinto----------------------------------------------------\n");
    printf      ("\t\t\t                              Antes de comecarmos, Insira seu nome de usuario abaixo:                        \n\n\t\t");
    scanf("%[^\n]s", &nome);
    LimpaBuffer();
    LimpaTela();
    //tela introdutoria
    printf("\n\n\t\t"VERMELHO"Essa tela inicial desaparecera automaticamente em alguns segundos"RESET);
    printf("\n\n\t\t--------------------------------------------------------------------------------------");
    printf  ("\n\t\t|                                                                                    |");
    printf  ("\n\t\t| - Se achava que teria uma mensagem de boas vindas, achou certo, seja bem vindo(a)  |");
    printf  ("\n\t\t| - As instrucoes de movimentacao aparecerao na tela assim q iniciar                 |");
    printf  ("\n\t\t| - Seu nome e a quantidade de vida que voce tem aparecera o tempo todo              |");
    printf  ("\n\t\t| - Se o HP zerar, e game over, tome cuidado, existem armadilhas pelo mapa           |");
    printf  ("\n\t\t| - Esse labirinto pode parecer simples mas ha um segredo escondido, descubra        |");
    printf  ("\n\t\t| - Pressione 'f' para encerrar o jogo a qualquer momento                            |");
    printf  ("\n\t\t|                                                                                    |");
    printf  ("\n\t\t--------------------------------------------------------------------------------------");
    //delay pra tela inicial sumir
    for(cont=0; cont<DELAY; cont++){}
    for(cont=0; cont<DELAY; cont++){}
    for(cont=0; cont<DELAY; cont++){}
    for(cont=0; cont<DELAY; cont++){}
    for(cont=0; cont<DELAY; cont++){}
    for(cont=0; cont<DELAY; cont++){}
    for(cont=0; cont<DELAY; cont++){}
    LimpaTela();
    //laço para printar o labirinto de acordo com as instruções do usuario
    do {
        printf("\n\t\tPlayer: " AZUL"%s"RESET, nome);//nome do jogador
        printf("\t\t\t\t\tHP: " VERDE"%d"RESET, hp);//vida do jogador
        printf("\n\n\n\t\t");
        for (lin=0; lin<TAM;lin++){//laço para printar o labirinto
            for (col=0;col<TAM;col++){
                if (labirinto[lin][col]==2) {//printando o usuario
                    printf(BG_VERDE" "RESET);
                    posx=lin;
                    posy=col;
                }
                else if(labirinto[lin][col]==0){//printando paredes
                       printf(BG_MAGENTA" "RESET);
                    }
                    else //if(labirinto[lin][col]==1){
                         printf(" ");//printando caminhos
                        //}
                        /*else if(labirinto[lin][col]==3){
                               printf(BG_AZUL" "RESET);
                            }
                            else printf(BG_VERMELHO" "RESET);*/
            }
            printf("\n\t\t\t\t");
        }    
        printf("\n\n\t\tINSTRUCOES:");//printando as instruções para o usuario
        printf("\n\n\t\tDigite 'w' para subir, 'a' para ir para a esquerda, 's' para descer e 'd' para ir para a direita:\n\n\t\t");
        scanf("%c", &tec);//lendo as instruções do usuario
        LimpaBuffer();
        //testando se a tecla é válida
        if(tec=='d' || tec=='s' || tec=='w' || tec=='a' || tec=='f' || tec=='D' || tec=='S' || tec=='W' || tec=='A' || tec=='F'){
            if(tec=='d' || tec=='D'){//testando caso o usuario queira ir para a direita
                switch(labirinto[posx][posy+1]){
                    case 0://caso encontre parede
                        printf("\n\t\tOlhe por onde anda! Ate o Zoro se localiza melhor\n");
                        for(cont=0; cont<DELAY; cont++){}
                        break;                     
                    case 4://caso encontre o obstáculo 4
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição 
                        dano=DANO_4;//atribuindo valor do dano
                        hp-=dano;//calculo do hp do jogador
                        printf("\n\t\tVoce encontrou Scar e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'As vezes, coisas ruins acontecem e nao se pode fazer nada'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para mensagem de dano desaparecer 
                        break;
                    case 5://caso encontre o obstáculo 5
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição 
                        dano=DANO_5;//atribuindo dano
                        hp-=dano;//calculando hp do jogador
                        printf("\n\t\tVoce encontrou Agente Smith e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'Os seres humanos sao uma doenca. Um cancer neste planeta. Voces sao uma praga. E nos somos a cura'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para a mensagem de dano desaparecer
                        break;
                    case 6://caso encontre o obstáculo 6
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição 
                        dano=DANO_6;//atribuindo valor do dano
                        hp-=dano;//calculando hp do jogador
                        printf("\n\t\tVoce encontrou Hades e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'Tenho vinte e quatro horas para me livrar desse idiota, antes que todo o esquema que montei por dezoito anos vire fumaca…'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para a mensagem de dano desaparecer 
                        break;
                    case 7://caso encontre o obstáculo 7 
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atuaizando posição
                        dano=DANO_7;//atribuindo valor do dano
                        hp-=dano;//fazendo calculo do hp do jogador
                        printf("\n\t\tVoce encontrou Scorpion e foi recebido com um abraco caloroso. Acabou se queimando e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'GET OVER HERE");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para a mensagem desaparecer 
                        break;
                    case 8://caso encontre o obstáculo 8
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição
                        dano=DANO_8;//atribuindo valor do dano
                        hp-=dano;//calculando hp do jogador
                        printf("\n\t\tVoce encontrou Freeza e, por ser calvo, foi confundido com o Kuririn e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'Uau, uau, o que temos aqui? Um principe caído.'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;
                    case 9://caso encontre o obstáculo 9 
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario
                        dano=DANO_9;//atribuindo o valor do dano
                        hp-=dano;//calculando o hp do jogador
                        printf("\n\t\tVoce encontrou Kratos e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'As maos da morte não podem me derrotar, as irmas do destino nao podem me segurar, e voce nao vai ver o final deste dia! Eu terei minha vingança!'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;
                    case 10://caso encontre o obstáculo 10
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario 
                        dano=DANO_10;//atribuindo valor do dano
                        hp-=dano;//calculando o hp do jogador
                        printf("\n\t\tVoce encontrou Goku, pena que foi o Black. Recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'Eu sou a justica!'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;
                    case 11://caso encontre o obstáculo 11 
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario
                        dano=DANO_11;//atribuindo valor do dano
                        hp-=dano;//calculando o hp do jogador
                        printf("\n\t\tVoce encontrou o Exterminador e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'Hasta la vista, baby'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;
                    case 12://caso encontre o obstáculo 12
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario 
                        dano=DANO_12;//atribuindo valor do dano
                        hp-=dano;//calculando o hp do jogador
                        printf("\n\t\tVoce olhou Akashi de cima e foi derrubado. Na queda tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'Eu sou absoluto. Abaixe sua cabeca'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;
                    case 13://caso encontre o obstáculo 13
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario
                        dano=DANO_13;//atribuindo valor do dano
                        hp-=dano;//calculando o hp do jogador
                        printf("\n\t\tVoce encontrou Darth Vader e duvidou da Forca. Pela insolencia, recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\t'Sua falta de fe e perturbadora!'");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;
                    case 14://caso encontre o obstáculo 14 
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario
                        dano=DANO_14;//atribuindo valor do dano
                        hp-=dano;//calculando o hp do jogador
                        printf("\n\t\tVoce foi enganado por Loki e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\tEu sou um deus, criatura ridicula!");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;
                    case 15://caso encontre o obstáculo 15
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario 
                        dano=DANO_15;//atribuindo valor do dano
                        hp-=dano;//calculando o hp do jogador
                        printf("\n\t\tVoce encontrou Thanos e tomou " VERMELHO"%d"RESET " de dano e evaporou. Agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                        printf("\n\t\tEu sou inevitavel");
                        for(cont=0; cont<DELAY; cont++){}
                        for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                        break;                    
                    default://caso seja um caminho livre
                        labirinto[posx][posy]=1;
                        labirinto[posx][++posy]=2;//atualizando posição do usuario
                        break;      
                }                
            }
            else if(tec=='a' || tec=='A'){//tetando caso o usuario queira ir para a esquerda
                    switch(labirinto[posx][posy-1]){
                        case 0://caso encontre uma parede
                            printf("\n\t\tAcho que vc anda assistindo muita ficcao. Voce nao consegue atravessar paredes irma(o), acorda\n");
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 3://caso chegue na saida
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario
                            LimpaTela();
                            printf("\n\n\n\t\t\t\tPARABENS," AZUL"%s"RESET ", VOCE PENSOU FORA DA CAIXA E CHEGOU NA SAIDA, SE BEM QUE VOCE JA TINHA SAIDO PRA CHEGAR ATE AQUI NE? BOM, VOCE ENTENDEU.", nome);
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            printf("\n\n\n\t\t\t\t                                     ATE BREVE, VALEU, FALOU, TAMO JUNTO, BYE, ADEUS, NOS VEMOS NUMA PROXIMA");
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano                            
                            fim=1;//quando o usuario chegar no final, a varivael recebe valor 1 para a condição de saída der verdadeira
                            break;     
                        case 4://caso encontre o obstáculo 4
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_4;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Scar e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'As vezes, coisas ruins acontecem e não se pode fazer nada'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 5://caso encontre o obstáculo 5
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_5;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Agente Smith e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'Os seres humanos são uma doença. Um câncer neste planeta. Vocês sao uma praga. E nos somos a cura'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 6://caso encontre o obstáculo 6
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_6;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Hades e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'Tenho vinte e quatro horas para me livrar desse idiota, antes que todo o esquema que montei por dezoito anos vire fumaca…'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 7://caso encontre o obstáculo 7
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_7;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Scorpion e foi recebido com um abraxo caloroso. Acabou se queimando e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'GET OVER HERE");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 8://caso encontre o obstáculo 8
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_8;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Freeza e, por ser calvo, foi confundido com o Kuririn e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'Uau, uau, o que temos aqui? Um principe caido.'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 9://caso encontre o obstáculo 9
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_9;//atribuindo valor do dano
                            hp-=dano;
                            printf("\n\t\tVoce encontrou Kratos e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'As maos da morte nao podem me derrotar, as irmas do destino nao podem me segurar, e voce não vai ver o final deste dia! Eu terei minha vinganca!'");
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 10://caso encontre o obstáculo 10
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_10;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Goku, pena que foi o Black. Recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'Eu sou a justica!'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 11://caso encontre o obstáculo 11
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_11;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou o Exterminador e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'Hasta la vista, baby'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 12://caso encontre o obstáculo 12
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_12;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce olhou Akashi de cima e foi derrubado. Na queda tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'Eu sou absoluto. Abaixe sua cabeca'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 13://caso encontre o obstáculo 13
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_13;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Darth Vader e duvidou da Forca. Pela insolencia, recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\t'Sua falta de fe e perturbadora!'");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 14://caso encontre o obstáculo 14
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_14;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce foi enganado por Loki e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\tEu sou um deus, criatura ridicula!");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        case 15://caso encontre o obstáculo 15
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario 
                            dano=DANO_15;//atribuindo valor do dano
                            hp-=dano;//calculando o hp do jogador
                            printf("\n\t\tVoce encontrou Thanos e tomou " VERMELHO"%d"RESET " de dano e evaporou. Agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                            printf("\n\t\tEu sou inevitavel");
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}
                            for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                            break;
                        default://caso seja um caminho livre
                            labirinto[posx][posy]=1;
                            labirinto[posx][--posy]=2;//atualizando posição do usuario
                            break;      
                    }
                }
                else if(tec=='s' || tec=='S'){//testando caso o usuario queira ir para baixo
                        switch(labirinto[posx+1][posy]){
                            case 0://caso encontre uma parede
                                printf("\n\t\tTa ficando doido? Se persistirem os sintomas o medico devera ser consultado\n");
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;                                 
                            case 4://caso encontre o obstáculo 4
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_4;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Scar e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'As vezes, coisas ruins acontecem e nao se pode fazer nada'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 5://caso encontre o obstáculo 5
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_5;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Agente Smith e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'Os seres humanos sao uma doença. Um cancer neste planeta. Vocês sao uma praga. E nas somos a cura'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 6://caso encontre o obstáculo 6
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_6;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Hades e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'Tenho vinte e quatro horas para me livrar desse idiota, antes que todo o esquema que montei por dezoito anos vire fumaca…'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 7://caso encontre o obstáculo 7
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_7;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Scorpion e foi recebido com um abraco caloroso. Acabou se queimando e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'GET OVER HERE");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 8://caso encontre o obstáculo 8
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_8;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Freeza e, por ser calvo, foi confundido com o Kuririn e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'Uau, uau, o que temos aqui? Um príncipe caido.'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 9://caso encontre o obstáculo 9
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_9;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Kratos e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'As maos da morte nao podem me derrotar, as irmas do destino nao podem me segurar, e voce não vai ver o final deste dia! Eu terei minha vinganaa!'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 10://caso encontre o obstáculo 10
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_10;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Goku, pena que foi o Black. Recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'Eu sou a justica!'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 11://caso encontre o obstáculo 11
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_11;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou o Exterminador e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'Hasta la vista, baby'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 12://caso encontre o obstáculo 12
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_12;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce olhou Akashi de cima e foi derrubado. Na queda tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'Eu sou absoluto. Abaixe sua cabeca'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 13://caso encontre o obstáculo 13
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_13;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Darth Vader e duvidou da Forca. Pela insolencia, recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\t'Sua falta de fe e perturbadora!'");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 14://caso encontre o obstáculo 14
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_14;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce foi enganado por Loki e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\tEu sou um deus, criatura ridicula!");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            case 15://caso encontre o obstáculo 15
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario 
                                dano=DANO_15;//atribuindo valor do dano
                                hp-=dano;//calculando o hp do jogador
                                printf("\n\t\tVoce encontrou Thanos e tomou " VERMELHO"%d"RESET " de dano e evaporou. Agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                printf("\n\t\tEu sou inevitavel");
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}
                                for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                break;
                            default://caso encontre um caminho livre
                                labirinto[posx][posy]=1;
                                labirinto[++posx][posy]=2;//atualizando posição do usuario
                                break;      
                        }
                    }
                    else if(tec=='w' || tec=='W'){//testando caso o usario queira ir pra cima
                            switch(labirinto[posx-1][posy]){
                                case 0://caso encontre uma parede
                                    printf("\n\t\tBate mais forte que uma hora quebra.......................................................sua cabeca\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;                                     
                                case 4://caso encontre o obstáculo 4
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_4;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Scar e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'As vezes, coisas ruins acontecem e não se pode fazer nada'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 5://caso encontre o obstáculo 5
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_5;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Agente Smith e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'Os seres humanos sao uma doença. Um câncer neste planeta. Voces sao uma praga. E nos somos a cura'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 6://caso encontre o obstáculo 6
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_6;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Hades e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'Tenho vinte e quatro horas para me livrar desse idiota, antes que todo o esquema que montei por dezoito anos vire fumaça…'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 7://caso encontre o obstáculo 7
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_7;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Scorpion e foi recebido com um abraco caloroso. Acabou se queimando e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'GET OVER HERE");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 8://caso encontre o obstáculo 8
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_8;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Freeza e, por ser calvo, foi confundido com o Kuririn e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'Uau, uau, o que temos aqui? Um príncipe caído.'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 9://caso encontre o obstáculo 9
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_9;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador 
                                    printf("\n\t\tVoce encontrou Kratos e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'As maos da morte nao podem me derrotar, as irmas do destino nao podem me segurar, e voce não vai ver o final deste dia! Eu terei minha vingança!'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 10://caso encontre o obstáculo 10
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_10;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Goku, pena que foi o Black. Recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'Eu sou a justica!'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 11://caso encontre o obstáculo 11
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_11;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou o Exterminador e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'Hasta la vista, baby'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 12://caso encontre o obstáculo 12
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_12;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce olhou Akashi de cima e foi derrubado. Na queda tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'Eu sou absoluto. Abaixe sua cabeca'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 13://caso encontre o obstáculo 13
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_13;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Darth Vader e duvidou da Força. Pela insolencia, recebeu " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\t'Sua falta de fe e perturbadora!'");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 14://caso encontre o obstáculo 14
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_14;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador 
                                    printf("\n\t\tVoce foi enganado por Loki e tomou " VERMELHO"%d"RESET " de dano e agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\tEu sou um deus, criatura ridicula!");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 15://caso encontre o obstáculo 15
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario 
                                    dano=DANO_15;//atribuindo valor do dano
                                    hp-=dano;//calculando o hp do jogador
                                    printf("\n\t\tVoce encontrou Thanos e tomou " VERMELHO"%d"RESET " de dano e evaporou. Agora sua quantidade de vida e: " VERDE"%d"RESET, dano, hp);
                                    printf("\n\t\tEu sou inevitavel");
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                case 16://caso encontre o obstaculo 16
                                    labirinto[posx][posy]=1;
                                    labirinto[posx][++posy]=2;//atualizando posição do usuario
                                    hp=0;//calculando o hp do jogador
                                    printf("\n\n\t\tVoce tomou um dano misterioso, calculando a quantidade de vida restante...\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tAguarde mais um pouco...\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tMais um pouco...\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tTa acabando...\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tTa irritado por que? Paciencia...\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tTo tao cansado de calcular quanto voce ta cansado de esperar...\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tEnquanto espera, vou te contar um enigma, pense fora da caixa...\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tAinda to calculando (alguem me tira daqui), continue pensando sobre o enigma\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tEu comecei a gritar: AAAAAAAAA\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tNinguem mandou ter uma maquina com um processador tao ruim, ve se compra outro por favor!\n\n");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    printf("\t\tAh! acho que agora termina...");
                                    for(cont=0; cont<DELAY; cont++){}//delay para desaparecer a mensagem de dano
                                    break;
                                default://caso seja um caminho livre 
                                    labirinto[posx][posy]=1;
                                    labirinto[--posx][posy]=2;//atualizando posição do usuario
                                    break;      
                            }
                    }
            if(hp<=0){//caso o usuario zere o hp
                LimpaTela();
                printf("\n\n\n\n\n\n\t\t\t" AMARELO"G4M3 0V3R"RESET "\n\n\n");
                break;
            }            
        }
        else{//caso o usuario digite uma tecla invalida
            printf("\n\tEu disse 'w','s','a' e 'd'(ou 'f' se quiser desistir). Pare de bancar o espertinho, " AZUL"%s"RESET ", e insira um caractere valido na proxima!");
            for(cont=0; cont<DELAY; cont++){};
        }
        LimpaTela();//limpando tela para printar o labirinto novamente
    }
    while (tec!='f' && tec!='F' && fim!=1);//caso o usuario digite f ou chegue na saida, o programa encerra
    return 0;
}
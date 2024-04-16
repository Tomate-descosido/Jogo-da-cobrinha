//Trabalho de laborat�rio de programa��o - Jogo da cobrinha - Eduardo Oliveira Dobbins

#include <stdio.h>
#include <stdlib.h>     //fun��o system() e srand()
#include <locale.h>     //fun��o setlocale()
#include <windows.h>    //fun��o SetConsoleCursorPosition
#include <conio.h>      //fun��o gatch() e kbhit()
#include <time.h>       //fun��o rand()


int cobra[300][2],pontos=1,cobraX=2,cobraY=2,comida[2],velocidade=150;

void controle(int,int);           //controle principal do sistema
void corpo();                    //desenha o corpo da cobra
void posicao();                 //atualiza a posi��o da cobra
void fim(int *);               //verifica se a cobra bateu
void gerador_de_comida();     //gera a comida
void limpar_tela();          //limpa a tela
void tela_de_carregamento();//mosta uma anima��o de carragamento meramente visual e sem fun��o real
void delay_pequeno();      //cria um pequeno delay 0,05 segundos
void delay_grande();      //cria um grande delay de 1,5 segundos

void controle(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void corpo(){
    int i;
    for(i=0;i<pontos;i++){
        controle(cobra[i][0],cobra[i][1]);
        printf("%c",79);
    } //faz o calculo de quantas unidades do corpo ser�o sesenhadas com base em quantos pontos o jogador tem, 0 pontos significa que n�o ter� unidades do corpo a mais que a pr�pria "cabe�a"
}

void posicao(){
    int i;
    controle(cobra[pontos][0],cobra[pontos][1]);
    printf(" ");
    for(i=pontos;i>=0;i--){
        cobra[i+1][0]=cobra[i][0];
        cobra[i+1][1]=cobra[i][1];
    }} //define uma "ponta da cauda" para a cobra apagando qualquer unidade do corpo q seria deixado para tr�s, utiliza o n�mero de pontos do jogador como meio de calcular o comprimento da cobra e assim substituir o excesso por um car�cter vazio

void fim(int *x){
    int i;
    for(i=1;i<pontos;i++){
        if(cobraX==cobra[i][0] && cobraY==cobra[i][1])
            *x=1;
    } //na teoria, utiliza da mesma id�ia de calcular o complimento do corpo atr�v�s da pontua��o para ent�o identificar a colis�o da cabe�a com o corpo
    *x=0; //na pr�tica n�o est� funcionando por algum motivo, mas a n�o funcionalidade evita um problema em que n�o tem uma forma de impedir do jogador subtamente come�ar a andar da dire��o oposta a que estava andando, o que faria ele inevitavelmente colidir com o corpo mesmo tendo apenas uma unidade do corpo
}

void gerador_de_comida(){
    controle(comida[0],comida[1]); //coloca o controle na posi��o da ultima comida gerada
    printf(" "); //substitui a ultima comida gerada por um espa�o vazio
    srand(time(NULL)); //utiliza da fun��o srand para gerar uma unidade de comida em uma posi��o aleat�ria
    comida[0]=(rand()%48)+1; //delimita uma �rea no eixo x para a gera��o
    comida[1]=(rand()%23)+1; //delimita uma �rea no eixo y para a gera��o
    controle(comida[0],comida[1]); //coloca o controle na posi��o da nova comida gerada
    printf("%c",4); //desenha a comida no mapa
}

void limpar_tela(){
    system("cls"); //utiliza da fun��o system para limpar a tela
}

void tela_de_carregamento(){
    int i;
    limpar_tela();
    for(i=0;i<3;i++){ //uma simples anima��o visual gerada por uma repeti��o para simular uma tela de carregamento
        controle(10,10);
        printf("0----------");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("-0---------");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("--0--------");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("---0-------");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("----0------");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("-----0-----");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("------0----");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("-------0---");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("--------0--");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("---------0-");
        delay_pequeno();
        limpar_tela();
        controle(10,10);
        printf("----------0");
        delay_pequeno();
        limpar_tela();
    }
}

void delay_pequeno(){
    Sleep(25); //utiliza da fun��o sleep para criar um delay em milisegundos, nesse caso s�o 0,025 segundos
}

void delay_grande(){
    Sleep(1500); //utiliza da fun��o sleep para criar um delay em milisegundos, nesse caso s�o 1,5 segundos
}

int main(){
    setlocale(LC_ALL,"");
    int i,fim_de_jogo=0;
    char tecla,nome[256];

    printf("informe o nome do jogador: ");
    scanf(" %256[^\n]",nome); //forma que encontrei de guardar uma linha de at� 256 caracteres (inclui a tecla espa�o), permitindo nomes compostos
    tela_de_carregamento(); //chamada da tela de carregamento
    controle(10,10); //posiciona o controle para executar uma comando num local espec�fico
    printf("usu�rio registrado com sucesso :D");
    delay_grande(); //chama um delay de 1,5 segundos

    limpar_tela();
    for(i=0;i<50;i++){ //desenha o limite superior do mapa com um delay m�nimo apenas para criar a id�ia de uma anima��o
        controle(i,0);
        printf("%c",178);
        Sleep(5);
    }
    for(i=0;i<25;i++){ //desenha o limite direito do mapa com um delay m�nimo apenas para criar a id�ia de uma anima��o
        controle(50,i);
        printf("%c",178);
        Sleep(5);
    }
    for(i=50;i>0;i--){ //desenha o limite inferior do mapa com um delay m�nimo apenas para criar a id�ia de uma anima��o
        controle(i,25);
        printf("%c",178);
        Sleep(5);
    }
    for(i=25;i>0;i--){ //desenha o limite esquerdo do mapa com um delay m�nimo apenas para criar a id�ia de uma anima��o
        controle(0,i);
        printf("%c",178);
        Sleep(5);
    }

    gerador_de_comida(); //chama a gera��o de comida
    corpo(); //chama o desenho do corpo para colocar a cobra na posi��o inicial do mapa
    tecla='d'; //define uma dira��o inicial para o come�o do movimento da cobra

    controle(52,4);
    printf("jogador: %s",nome);

    while(fim_de_jogo==0){ //looping que faz o jogo andar
        controle(52,2);
        printf("pontos: %d",pontos);
        cobra[0][0]=cobraX; //define a posi��o da cabe�a da cobra no eixo x
        cobra[0][1]=cobraY; //define a posi��o da cabe�a da cobra no eixo y
        if(kbhit()) //identifica quando uma tecla � precionada
            tecla=getch(); //a fun��o getch identifica a tecla pressionada e atribui essa tecla ao char 'tecla'
        if(tecla=='w'||tecla=='W'||tecla==72){
            cobraY--; //se 'tecla' for um w, W ou seta para cima o programa faz com que a cobra suba ao repetir esse comando sucessivamente
            if(cobraY==0)
                break; //identifica quando a cobra atinge uma parede e encerra o looping
        }
        if(tecla=='a'||tecla=='A'||tecla==75){
            cobraX--; //se 'tecla' for um a, A ou seta para esquerda o programa faz com que a cobra v� para a esquerda ao repetir esse comando sucessivamente
            if(cobraX==0)
                break; //identifica quando a cobra atinge uma parede e encerra o looping
        }
        if(tecla=='s'||tecla=='S'||tecla==80){
            cobraY++; //se 'tecla' for um s, S ou seta para baixo o programa faz com que a cobra des�a ao repetir esse comando sucessivamente
            if(cobraY==25)
                break; //identifica quando a cobra atinge uma parede e encerra o looping
        }
        if(tecla=='d'||tecla=='D'||tecla==77){
            cobraX++; //se 'tecla' for um d, D ou seta para direita o programa faz com que a cobra v� para a direita ao repetir esse comando sucessivamente
            if(cobraX==50)
                break; //identifica quando a cobra atinge uma parede e encerra o looping
        }
        if(cobraX==comida[0]&&cobraY==comida[1]){
            pontos++; //identifica quando a cabe�a da cobra sobrep�e uma comida e soma um ponto ao total
            if(velocidade>50)
                velocidade=velocidade-10; //caso uma comida seja sobreposta e a velocidade m�xima n�o tenha sido alcan�ada, o sistema diminui o delay do looping para acelerar a cobra
            gerador_de_comida(); //gera uma nova comida em uma posi��o aleat�ria do mapa sempre que a ultima for coletada
        }
        fim(&fim_de_jogo); //verifica a condi��o de fim de jogo para caso o jogador toque a pr�pria calda (n�o est� funcionando por algum motivo)
        posicao(); //atualiza a posi��o atual da cobra
        corpo(); //redesenha o corpo da cobra na nova posi��o
        controle(50,25); //coloca o controle no canto do mapa para n�o atrapalhar na visualiza��o do jogo
        Sleep(velocidade); //aplica um delay para que o jogo n�o rode r�pido de mais
    }
    delay_grande(); //delay aplicado ao perder o jogo (meramente ilustrativo)
    tela_de_carregamento(); //chamada da tela de carregamento
    printf("Fim de jogo.\n\nVoc� fez %d pontos.\n\n\n",pontos);
    system("pause"); //fim do jogo
}
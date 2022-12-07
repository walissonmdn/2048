/*
Author: Walisson Marcelo Dias Nogueira
Graduation: Engenharia de Controle e Automação
Discipline: Métodos e Técnicas de Programação
2nd Semester - 2019
*/

#include "conio2.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27

void matriz();
void menu(int mat[][4]);
void tutorial();
int execucao(int mat[][4], unsigned int first, int *score, unsigned int *times);
void random(int mat[][4], int first);
void numeros(int mat[][4], int i, int j);
int rightarrow(int mat[][4]);
int leftarrow(int mat[][4]);
int uparrow(int mat[][4]);
int downarrow(int mat[][4]);

int main()
{
    int mat[4][4];
    srand(time(NULL));
    textbackground(DARKGRAY);
    textcolor(BLACK);
    system("cls");
    menu(mat);
    return 0;
}

void matriz()
{
    int i;
    gotoxy(1,10);
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xBA         \xBA         \xBA         \xBA         \xBA");
    printf("\n\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
    textcolor(BLUE);
    printf("\nPressione ESC para retornar ao menu");
    textcolor(BLACK);
    gotoxy(5,1);
    textcolor(RED);
    printf("SCORE");
    textcolor(BLUE);
    gotoxy(1,2);
    printf("\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC");
    for(i=3; i<8; i++)
    {
        gotoxy(1,i);
        printf("\xDD");
        gotoxy(13,i);
        printf("\xDE");
    }

    gotoxy(1,8);
    printf("\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF");
    gotoxy(8,5);


    gotoxy(20,5);

    textcolor(RED);
    printf("2048");
    textcolor(RED);
    gotoxy(34,1);
    printf("BEST");
    textcolor(BLUE);
    gotoxy(29,2);
    printf("\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC");
    for(i=3; i<8; i++)
    {
        gotoxy(29,i);
        printf("\xDD");
        gotoxy(41,i);
        printf("\xDE");
    }

    gotoxy(29,8);
    printf("\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF");
}

void menu(int mat[][4])
{
    unsigned int i=1, j, k, start=0, tec, fim=0, first, end, score=0, best=0;

    do
    {
        gotoxy(1,1);
        printf("Novo Jogo");
        printf("\nContinuar");
        printf("\nTutorial");
        printf("\nSair");
        if(i==1)
        {
            gotoxy(1,1);
            textcolor(WHITE);
            printf("Novo Jogo");
            textcolor(BLACK);
        }

        else if(i==2)
        {
            gotoxy(1,2);
            textcolor(WHITE);
            printf("Continuar");
            textcolor(BLACK);
        }
        else if(i==3)
        {
            gotoxy(1,3);
            textcolor(WHITE);
            printf("Tutorial");
            textcolor(BLACK);
        }
        else if(i==4)
        {
            gotoxy(1,4);
            textcolor(WHITE);
            printf("Sair");
            textcolor(BLACK);
        }
        tec=getch();
        system("cls");


        if(tec==DOWN)
        {
            i++;
            if(i>4)
                i=1;

        }
        else if(tec==UP)
        {
            i--;
            if(i<1)
                i=4;
        }

        else if(i==1 && tec==ENTER)
        {
            score=0;
            for(j=0; j<4; j++)
                for(k=0; k<4; k++)
                {
                    mat[j][k]=0;
                }
            start=1;
            first=1;
            end=execucao(mat, first, &score, &best);
            if(end==1)
            {
                start=0;
            }
            system("cls");
        }

        else if(i==2 && tec==ENTER)
        {
            if(start==1)
            {
                first=0;
                end=execucao(mat, first, &score, &best);
                if(end==1)
                    start=0;

            }
            else
            {
                textcolor(RED);
                printf("Opcao invalida, voce nao iniciou o jogo");
                textcolor(BLACK);
                getch();
            }
            system("cls");
        }

        else if(i==3 && tec==ENTER)
        {
            tutorial();
            system("cls");
        }
        else if(i==4 && tec==ENTER)
            fim=1;

    }
    while(fim==0);
}

void tutorial()
{
    system("cls");
    textcolor(LIGHTGREEN);
    printf("1 - Utilize as setas para movimentar os numeros\n2 - O jogo comeca com dois numeros em posicoes aleatorias\n3 - So e permitido que os numeros sejam potencias de 2\n4 - Caso dois blocos de mesmo numero se choquem, eles sao somados\n5 - O objetivo e conseguir um bloco com o numero 2048");
    textcolor(BLACK);
    getch();
}

int execucao(int mat[][4], unsigned int first, int *score, unsigned int *best)
{
    int matcompare[4][4], cont=0, contgetch=1, end=0, win=0, key;
    unsigned int tecla, i, j;
    matriz();

    textcolor(WHITE);
    if(*score>=0 && *score<100)
        gotoxy(7,5);
    else if(*score>=100 && *score<10000)
        gotoxy(6,5);
    else if(*score>=10000 && *score<1000000)
        gotoxy(5,5);
    else if(*score>=1000000 && *score<100000000)
        gotoxy(4,5);

    printf("%i", *score);

    if(*best>=0 && *best<100)
        gotoxy(35,5);
    else if(*best>=100 && *best<10000)
        gotoxy(34,5);
    else if(*best>=10000 && *best<1000000)
        gotoxy(33,5);
    else if(*best>=1000000 && *best<100000000)
        gotoxy(32,5);

    printf("%i", *best);
    if(first==1)
    {
        random(mat, first);
        first=0;
    }

    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            if(mat[i][j]!=0)
                numeros(mat, i, j);
        }

    do
    {
        cont=0;
        fflush(stdin);
        tecla=getch();
        if(tecla!=224 && tecla!=ESC && tecla!=RIGHT && tecla!=LEFT && tecla!=UP && tecla!=DOWN)
        {
            gotoxy(16,21);
            textcolor(RED);
            printf("Tecla invalida");
            textcolor(BLACK);
            getch();
        }

        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
            {
                matcompare[i][j]=mat[i][j];
            }

        if(tecla==RIGHT)
            *score=*score+rightarrow(mat);
        else if(tecla==LEFT)
            *score=*score+leftarrow(mat);

        else if(tecla==UP)
            *score=*score+uparrow(mat);

        else if(tecla==DOWN)
            *score=*score+downarrow(mat);

        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
            {
                if(matcompare[i][j]!=mat[i][j])
                    cont=1;
            }

        if(cont==1)
            random(mat, first);

        if(tecla!=224)
        {
            matriz();
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    if(mat[i][j]!=0)
                    {
                        numeros(mat, i, j);
                    }
                }
        }

        textcolor(WHITE);

        if(*best<*score)
            *best=*score;
        if(*score>=0 && *score<100)
            gotoxy(7,5);
        else if(*score>=100 && *score<10000)
            gotoxy(6,5);
        else if(*score>=10000 && *score<1000000)
            gotoxy(5,5);
        else if(*score>=1000000 && *score<100000000)
            gotoxy(4,5);

        printf("%i", *score);

        if(*best>=0 && *best<100)
            gotoxy(35,5);
        else if(*best>=100 && *best<10000)
            gotoxy(34,5);
        else if(*best>=10000 && *best<1000000)
            gotoxy(33,5);
        else if(*best>=1000000 && *best<100000000)
            gotoxy(32,5);

        printf("%i", *best);
        textcolor(BLACK);

        cont=0;
        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
            {
                if(mat[i][j]==0)
                    cont=1;
            }

        if(cont==0)
        {
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    matcompare[i][j]=mat[i][j];
                }
            leftarrow(matcompare);
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    if(matcompare[i][j]!=mat[i][j])
                        cont=2;
                    break;
                }

            rightarrow(matcompare);
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    if(matcompare[i][j]!=mat[i][j])
                        cont=2;
                    break;
                }

            uparrow(matcompare);
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    if(matcompare[i][j]!=mat[i][j])
                        cont=2;
                    break;
                }

            downarrow(matcompare);

            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    if(matcompare[i][j]!=mat[i][j])
                    {
                        cont=2;
                        break;
                    }
                }
        }

        if(win==0)
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    if(mat[i][j]==2048)
                    {
                        cont=2048;
                        win=1;
                    }

                }

        if(cont==2048)
            do
            {
                i=0;
                textcolor(LIGHTGREEN);
                gotoxy(1,20);
                printf("Parabens, voce conseguiu obter um bloco igual a 2048\nPressione ENTER para continuar jogando ou ESC para sair");
                key=getch();
                textcolor(BLACK);
                if(key==ESC)
                    cont=0;
                if(key==ENTER)
                {
                    system("cls");
                    textcolor(WHITE);

                    if(*score>=0 && *score<100)
                        gotoxy(7,5);
                    else if(*score>=100 && *score<10000)
                        gotoxy(6,5);
                    else if(*score>=10000 && *score<1000000)
                        gotoxy(5,5);
                    else if(*score>=1000000 && *score<100000000)
                        gotoxy(4,5);

                    printf("%i", *score);

                    if(*best>=0 && *best<100)
                        gotoxy(35,5);
                    else if(*best>=100 && *best<10000)
                        gotoxy(34,5);
                    else if(*best>=10000 && *best<1000000)
                        gotoxy(33,5);
                    else if(*best>=1000000 && *best<100000000)
                        gotoxy(32,5);

                    printf("%i", *best);
                    textcolor(BLACK);
                    matriz();
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                        {
                            if(mat[i][j]!=0)
                            {
                                if(mat[i][j]>0 && mat[i][j]<100)
                                    gotoxy(6+(10*j), 13+(6*i));

                                else if(mat[i][j]>100 && mat[i][j]<10000)
                                    gotoxy(5+(10*j), 13+(6*i));

                                else if(mat[i][j]>10000 && mat[i][j]<100000)
                                    gotoxy(4+(10*j), 13+(6*i));

                                numeros(mat, i, j);
                            }
                        }
                }
                else
                {
                    textcolor(RED);
                    gotoxy(17,22);
                    printf("Tecla Invalida");
                    textcolor(BLACK);
                }

            }
            while(key!=ESC && key!=ENTER);

        if(cont==0)
        {
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    mat[i][j]=0;
                }
            end=1;
            gotoxy(16,20);
            if(win==0 || win==2)
            {
                win=2;
                textcolor(RED);
                printf("Voce perdeu");
                printf("\nPressione qualquer tecla para continuar");
                textcolor(BLACK);
                getch();
            }
            return end;
        }

        if(tecla==ESC)
            system("cls");
        contgetch++;
    }
    while(tecla!=ESC);
    return end;
}

void numeros(int mat[][4], int i, int j)
{
    int colors[]= {10, 14, 7, 1, 4, 5, 15, 11, 12, 9, 13};
    unsigned int k=0;
    textcolor(LIGHTGRAY);

    do
    {
        k++;
        if(mat[i][j]==pow(2,k))
        {
            if(k>11)
                textcolor(colors[k%12]);
            else
                textcolor(colors[k-1]);
            for(int a=0; a<9; a++)
                for(int b=0; b<5; b++)
                {
                    gotoxy(6+(10*j)-4+a, 13+(6*i)-2+b);
                    printf("\xDB");
                }


            if(mat[i][j]>0 && mat[i][j]<100)
                gotoxy(6+(10*j),13+(6*i));

            else if(mat[i][j]>100 && mat[i][j]<10000)
                gotoxy(5+(10*j),13+(6*i));

            else if(mat[i][j]>10000 && mat[i][j]<100000)
                gotoxy(4+(10*j),13+(6*i));

            if(k>11)
            {
                textcolor(BLACK);
                textbackground(colors[k%12]);
            }
            else
            {
                textcolor(BLACK);
                textbackground(colors[k-1]);
            }

            if(mat[i][j]>0 && mat[i][j]<100)
                gotoxy(6+(10*j),13+(6*i));
            else if(mat[i][j]>100 && mat[i][j]<10000)
                gotoxy(5+(10*j),13+(6*i));
            else if(mat[i][j]>10000 && mat[i][j]<100000)
                gotoxy(4+(10*j),13+(6*i));

            printf("%i", mat[i][j]);
            textbackground(DARKGRAY);
        }
    }
    while(mat[i][j]!=pow(2,k));

    textcolor(BLACK);
}

void random(int mat[][4], int first)
{
    int i, j,  prob;
    do
    {
        i=rand()%4;
        j=rand()%4;
    }
    while(mat[i][j]!=0);
    prob=rand()%10;
    if(prob==9)
        mat[i][j]=4;
    else
        mat[i][j]=2;
    if(first==1 && mat[i][j]==4)
    {
        do
        {
            i=rand()%4;
            j=rand()%4;
        }
        while(mat[i][j]!=0);
        mat[i][j]=2;
    }
    else if(first==1 && mat[i][j]==2)
    {
        do
        {
            i=rand()%4;
            j=rand()%4;
        }
        while(mat[i][j]!=0);
        prob=rand()%10;
        if(prob==9)
            mat[i][j]=4;
        else
            mat[i][j]=2;
    }

}

int rightarrow(int mat[][4])
{
    unsigned int i, j, k, cont, score=0;
    for(i=0; i<4; i++)
    {
        cont=0;
        for(j=0; j<4; j++)
        {
            if(mat[i][j]!=0)
                cont++;
        }
        if(cont!=0)
            do
            {
                for(j=3; j>0; j--)
                {
                    if(mat[i][j]==0)
                    {
                        mat[i][j]=mat[i][j-1];
                        mat[i][j-1]=0;
                    }
                }
            }
            while(mat[i][3]==0);
        if(cont==2)
        {
            if(mat[i][2]==0)
                do
                {
                    for(j=2; j>0; j--)
                    {
                        mat[i][j]=mat[i][j-1];
                        mat[i][j-1]=0;
                    }
                }
                while(mat[i][2]==0);
        }
        else if(cont==3)
        {
            if(mat[i][2]==0)
                do
                {
                    for(j=2; j>0; j--)
                    {
                        mat[i][j]=mat[i][j-1];
                        mat[i][j-1]=0;
                    }
                }
                while(mat[i][2]==0);
            if(mat[i][1]==0)
            {
                mat[i][1]=mat[i][0];
                mat[i][0]=0;
            }

        }

        for(j=3; j>0; j--)
        {
            if(mat[i][j]==mat[i][j-1])
            {
                mat[i][j]=2*mat[i][j];
                score=score+mat[i][j];
                mat[i][j-1]=0;
                if(j!=1)
                {
                    k=j-1;
                    while(k>0)
                    {
                        mat[i][k]=mat[i][k-1];
                        mat[i][k-1]=0;
                        k--;
                    }
                }
            }
        }

    }
    return score;
}

int leftarrow(int mat[][4])
{

    unsigned int i, j, k, cont, score=0;
    for(i=0; i<4; i++)
    {
        cont=0;
        for(j=0; j<4; j++)
        {
            if(mat[i][j]!=0)
                cont++;
        }
        if(cont!=0)
            do
            {
                for(j=0; j<3; j++)
                {
                    if(mat[i][j]==0)
                    {
                        mat[i][j]=mat[i][j+1];
                        mat[i][j+1]=0;
                    }
                }
            }
            while(mat[i][0]==0);
        if(cont==2)
        {
            if(mat[i][1]==0)
                do
                {
                    for(j=1; j<3; j++)
                    {
                        mat[i][j]=mat[i][j+1];
                        mat[i][j+1]=0;
                    }
                }
                while(mat[i][1]==0);
        }
        else if(cont==3)
        {
            if(mat[i][1]==0)
                do
                {
                    for(j=1; j<3; j++)
                    {
                        mat[i][j]=mat[i][j+1];
                        mat[i][j+1]=0;
                    }
                }
                while(mat[i][1]==0);
            if(mat[i][2]==0)
            {
                mat[i][2]=mat[i][3];
            }

        }

        for(j=0; j<3; j++)
        {
            if(mat[i][j]==mat[i][j+1])
            {
                mat[i][j]=2*mat[i][j];
                score=score+mat[i][j];
                mat[i][j+1]=0;
                if(j!=2)
                {
                    k=j+1;
                    while(k<3)
                    {
                        mat[i][k]=mat[i][k+1];
                        mat[i][k+1]=0;
                        k++;
                    }
                }
            }
        }

    }
    return score;
}

int uparrow(int mat[][4])
{

    unsigned int i, j, k, cont, score=0;
    for(j=0; j<4; j++)
    {
        cont=0;
        for(i=0; i<4; i++)
        {
            if(mat[i][j]!=0)
                cont++;
        }
        if(cont!=0)
            do
            {
                for(i=0; i<3; i++)
                {
                    if(mat[i][j]==0)
                    {
                        mat[i][j]=mat[i+1][j];
                        mat[i+1][j]=0;
                    }
                }
            }
            while(mat[0][j]==0);
        if(cont==2)
        {
            if(mat[1][j]==0)
                do
                {
                    for(i=1; i<3; i++)
                    {
                        mat[i][j]=mat[i+1][j];
                        mat[i+1][j]=0;
                    }
                }
                while(mat[1][j]==0);
        }
        else if(cont==3)
        {
            if(mat[1][j]==0)
                do
                {
                    for(i=1; i<3; i++)
                    {
                        mat[i][j]=mat[i+1][j];
                        mat[i+1][j]=0;
                    }
                }
                while(mat[1][j]==0);
            if(mat[2][j]==0)
            {
                mat[2][j]=mat[3][j];
            }

        }

        for(i=0; i<3; i++)
        {
            if(mat[i][j]==mat[i+1][j])
            {
                mat[i][j]=2*mat[i][j];
                score=score+mat[i][j];
                mat[i+1][j]=0;
                if(i!=2)
                {
                    k=i+1;
                    while(k<3)
                    {
                        mat[k][j]=mat[k+1][j];
                        mat[k+1][j]=0;
                        k++;
                    }
                }
            }
        }

    }
    return score;
}

int downarrow(int mat[][4])
{

    unsigned int i, j, k, cont, score=0;
    for(j=0; j<4; j++)
    {
        cont=0;
        for(i=0; i<4; i++)
        {
            if(mat[i][j]!=0)
                cont++;
        }
        if(cont!=0)
            do
            {
                for(i=3; i>0; i--)
                {
                    if(mat[i][j]==0)
                    {
                        mat[i][j]=mat[i-1][j];
                        mat[i-1][j]=0;
                    }
                }
            }
            while(mat[3][j]==0);
        if(cont==2)
        {
            if(mat[2][j]==0)
                do
                {
                    for(i=2; i>0; i--)
                    {
                        mat[i][j]=mat[i-1][j];
                        mat[i-1][j]=0;
                    }
                }
                while(mat[2][j]==0);
        }
        else if(cont==3)
        {
            if(mat[2][j]==0)
                do
                {
                    for(i=2; i>0; i--)
                    {
                        mat[i][j]=mat[i-1][j];
                        mat[i-1][j]=0;
                    }
                }
                while(mat[2][j]==0);
            if(mat[1][j]==0)
            {
                mat[1][j]=mat[0][j];
                mat[1][j]=mat[0][j];
            }
        }

        for(i=3; i>0; i--)
        {
            if(mat[i][j]==mat[i-1][j])
            {
                mat[i][j]=2*mat[i][j];
                score=score+mat[i][j];
                mat[i-1][j]=0;
                if(i!=1)
                {
                    k=i-1;
                    while(k>0)
                    {
                        mat[k][j]=mat[k-1][j];
                        mat[k-1][j]=0;
                        k--;
                    }
                }
            }
        }
    }
    return score;
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "util.h"


/***********************************
WARNING WARNING WARNING WARNING
ESTE ES UN PROTOTIPO SUCIO, AUN NO ES DINAMICO
************************************/
void Abrir(void)
{

    char fila[300];
    int x,c=1,y=3;
    char *token;

	FILE *f;
	f= fopen("datos.txt", "rt");
    if(f==NULL)
    {
        perror("EL error es: ");
        exit(1);
    }
    clrscr();
	do
    {
        fgets(fila,300, f);
        token = strtok(fila, "|");
        do
        {
            switch(c)
            {
            case 1:
                {
                    c=2;
                    x=3;
                    break;
                }
            case 2:
                {
                    c=3;
                    x=9;
                    break;
                }
            case 3:
                {
                    c=4;
                    x=29;
                    break;
                }
            case 4:
                {
                    c=5;
                    x=49;
                    break;
                }
            case 5:
                {
                    c=1;
                    x=69;
                    break;
                }

            }
            gotoxy(x,y);
            printf( "%s", token );

            token = strtok(NULL, "|");
        }while( token != NULL );
    y++;
	}while(!feof(f));



	fclose(f);
    gotoxy(1,2);
    textcolor(WHITE);
    printf("--ID----CLIENTE-------------APELLIDOS-----------MASCOTA-------------VISITAS\n\r");
    getch();
    clrscr();
    return;
}

void Registrar(void)
{
    char line[200]="";
    char id[5]="";
    char cliente[20]="";
    char apellidos[20]="";
    char pet[25]="";
    char visitas[4]="1";
    char espacio[5]="|";
    char next[]="\n";
    int *token;
    int i=1;

    FILE *f;
    f= fopen("datos.txt", "a+");
    if(f==NULL)
    {
        perror("EL error es: ");
        exit(1);
    }
    clrscr();
    printf("Ingrese el ID\n\r");
    gets(&id);
    printf("Ingrese el nombre del cliente(Maximo 20 caracteres)\n\r");
    gets(&cliente);
    printf("Ingrese los apellidos del cliente(Maximo 20 caracteres)\n\r");
    gets(&apellidos);
    printf("Ingrese el nombre de la mascota(Maximo 25 caracteres)\n\r");
    gets(&pet);
    puts(&visitas);

    strcat(line, id);
    strcat(line, espacio);
    strcat(line, cliente);
    strcat(line, espacio);
    strcat(line, apellidos);
    strcat(line, espacio);
    strcat(line, pet);
    strcat(line, espacio);
    strcat(line, visitas);

    fputs(next, f);
    fputs(line, f);


fclose(f);
clrscr();
return;
}
/*****************************************
SE LLAMA Creditos AL CERRAR EL PROGRAMA
USANDO LA OPCIÓN DE SALIDA DEL MENÚ
******************************************/
void creditos(void)
 {

	int y=25, x=30;
	char c;
	clrscr();
    do
    {
        if(y>=20)
        {
            c=WHITE;
        }
        else if(y<20 && y>=14)
        {
            c=LIGHTGRAY;
        }
        else if(y<14 && y>=6)
        {
            c=DARKGRAY;
        }
        else if(y<6 && y>=0)
        {
            c=BLACK;
        }
        textcolor(c);
        gotoxy(x+20,y-2);
        cprintf("REALIZADO POR:\n\r");
        gotoxy(x,y-1);
        cprintf("CARLOS KASSAB ANDRE -----------LUIS DANIEL CUEVAS GARCIA\n\r");
        gotoxy(x+10,y);
        cprintf("UNIVERSIDAD AUTONOMA DE GUADALAJARA");
        Sleep(200);
        textcolor(BLACK);
        gotoxy(x+20,y-2);
        cprintf("REALIZADO POR:\n\r");
        gotoxy(x,y-1);
        cprintf("CARLOS KASSAB ANDRE -----------LUIS DANIEL CUEVAS GARCIA\n\r");
        gotoxy(x+10,y);
        cprintf("UNIVERSIDAD AUTONOMA DE GUADALAJARA");

    }while(--y>1);
    return;
}

/*************************************
tiempoActual OBTIENE LA FECHA Y HORA
EN LA QUE SE CREA O MODIFICA UN REGISTRO
**************************************/
void tiempoActual(void)
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "\n\rDia y fecha: %s", asctime (timeinfo) );

    return;
}
/************************
EL LOOP PRINCIPAL DEL PROGRAMA
SE ENCUENTRA EN LA SELECCION
DE OPCIONES DE MENU
*************************/
void menuSelect(void)
{
    int choice = 1;
    int loop = 0;
    int tecla;
    gotoxy(1,50);
    textcolor(RED);
    cprintf("\n\rHASTA AHORA SOLO TENEMOS PROTOTIPOS DE REGISTRAR Y ABRIR, NO MUY BUENOS");
    textcolor(WHITE);
    do
    {
        tecla = getch();
        //CUANDO TECLA SEA ENTER, SE LLAMA SU RESPECTIVA FUCNCION
        if (tecla==13)
        {
            switch(choice)
            {
                case 1: //CREAR UN REGISTRO PARA NUEVO CLIENTE
                {
                    Sleep(50);
                    /*printf("se agrega una linea del input del usuario");
                    Sleep(150);
                    */
                    Registrar();
                    menuCuerpoRegistro();
                   break;
                }
                case 2: //ABRIR UN REGISTRO
                {
                    Sleep(50);
                    Abrir();
                    menuCuerpoAbrir();
                    break;
                }
                case 3: //MODIFICACION DE LOS REGISTROS
                {

                    break;
                }
                case 4: //SE LLAMA CREDITOS Y CIERRA EL PROGRAMA
                {
					Sleep(50);
					creditos();
					return;
                }
                default: //EN CASO DE QUE EXISTA UN ERROR
                {
                    printf("HUBO UN ERROR");
                    break;
                }
            }
        }
        //CUANDO LA TECLA SEA CUALQUIER OTRA, VERIFICA SI FUE FLECHA ARRIBA
        //O SI FUE FLECHA ABAJO, ENTONCES LLAMARÁ A LA RESPECTIVA FUNCIÓN
        switch(choice)
        {
            case 1:
            {

                if(tecla==80)
                {
                    clrscr();
                    menuCuerpoAbrir();
                    choice++;
                    break;
                }
                break;
            }
            case 2:
            {
                //printf("Opcion %d", choice);

                if(tecla==80)
                {
                    clrscr();
                    menuCuerpoModificar();
                    choice++;
                    break;
                }
                if(tecla==72)
                {
                    clrscr();
                    menuCuerpoRegistro();
                    choice--;
                    break;
                }
                break;
            }
            case 3:
            {
                //printf("Opcion %d", choice);
                if(tecla==80)
                {
                    clrscr();
                    menuCuerpoCerrar();
                    choice++;
                    break;
                }
                if(tecla==72)
                {
                    clrscr();
                    menuCuerpoAbrir();
                    choice--;
                    break;
                }
                break;
            }
            case 4:
            {
                //printf("Opcion %d", choice);
                if(tecla==72)
                {
                    clrscr();
                    menuCuerpoModificar();
                    choice--;
                }
                break;
            }
            default:
            {
                printf("error en algo");
                break;
            }
        }

    }while(loop==0);

    return;
}


/*****************************
menuTitulo DESTELLA TRES VECES
EL NOMBRE DE LA EMPRESA
******************************/

void menuTitulo(void)
{
    int count=0;
    int x=20, y=10;
    do
    {
		textcolor(RED);
		gotoxy(x,y);
		cprintf("  _      _____ _______ _______ _      ______   _____  ______ _______ _____ ");
		gotoxy(x,y+1);
		cprintf(" | |    |_   _|__   __|__   __| |    |  ____| |  __ \|  ____|__   __/ ____|");
		gotoxy(x,y+2);
		cprintf(" | |      | |    | |     | |  | |    | |__    | |__) | |__     | | | (___  ");
		gotoxy(x,y+3);
		cprintf(" | |      | |    | |     | |  | |    |  __|   |  ___/|  __|    | |  \___ \ ");
		gotoxy(x,y+4);
		cprintf(" | |____ _| |_   | |     | |  | |____| |____  | |    | |____   | |  ____) |");
		gotoxy(x,y+5);
		cprintf(" |______|_____|  |_|     |_|  |______|______| |_|    |______|  |_| |_____/ ");

		Sleep(200);
		textcolor(WHITE);
		clrscr();
		gotoxy(x,y);
		cprintf("  _      _____ _______ _______ _      ______   _____  ______ _______ _____ ");
		gotoxy(x,y+1);
		cprintf(" | |    |_   _|__   __|__   __| |    |  ____| |  __ \|  ____|__   __/ ____|");
		gotoxy(x,y+2);
		cprintf(" | |      | |    | |     | |  | |    | |__    | |__) | |__     | | | (___  ");
		gotoxy(x,y+3);
		cprintf(" | |      | |    | |     | |  | |    |  __|   |  ___/|  __|    | |  \___ \ ");
		gotoxy(x,y+4);
		cprintf(" | |____ _| |_   | |     | |  | |____| |____  | |    | |____   | |  ____) |");
		gotoxy(x,y+5);
		cprintf(" |______|_____|  |_|     |_|  |______|______| |_|    |______|  |_| |_____/ ");
		Sleep(200);
		count++;
    }while(count<3);
    return;
}

/*************************
INICIAN LAS FUNCIONES PARA
PODER MOSTRAR HIGHLIGHT EN
EL MENU DE SELECCIÓN
***************************/
void menuCuerpoRegistro(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    textbackground(WHITE);
	textcolor(BLACK);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(BLACK);
	textcolor(WHITE);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");


    return;
}

void menuCuerpoAbrir(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(WHITE);
	textcolor(BLACK);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    textbackground(BLACK);
	textcolor(WHITE);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");


    return;
}

void menuCuerpoModificar(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    textbackground(WHITE);
	textcolor(BLACK);
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(BLACK);
	textcolor(WHITE);
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");


    return;
}

void menuCuerpoCerrar(void)
{
    int x=11, y=1;

    gotoxy(x,y++);
    cprintf(" _ ____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______ _ ");
    gotoxy(x,y++);
    cprintf("| |                        ____            _     _                                                | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ \\ ___  __ _(_)___| |_ _ __ __ _ _ __                               | |");
    gotoxy(x,y++);
    cprintf("| |                       | |_) / _ \\/ _` | / __| __| '__/ _` | '__|                              | |");
    gotoxy(x,y++);
    cprintf("| |                       |  _ |  __| (_| | \\__ | |_| | | (_| | |                                 | |");
    gotoxy(x,y++);
    cprintf("| |                       |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|_|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                                  |___/                                                        | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|______|_____|___| |____|_____|_____|_____|_____|_____|_____|______|_|");
    gotoxy(x,y++);
    cprintf("| |                                    _    _          _                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                   / \\  | |__  _ __(_)_ __                                     | |");
    gotoxy(x,y++);
    cprintf("| |                                  / _ \\ | '_ \\| '__| | '__|                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                 / ___ \\| |_) | |  | | |                                       | |");
    gotoxy(x,y++);
    cprintf("| |                                /_/   \\_|_.__/|_|  |_|_|                                       | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ _____ _____ ___       __ _____ _____ _____ _____ _____ _____ _____|_|");
    gotoxy(x,y++);
    cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
    gotoxy(x,y++);
    cprintf("| |                          __  __           _ _  __ _                                           | |");
    gotoxy(x,y++);
    cprintf("| |                         |  \\/  | ___   __| (_)/ _(_)__ __ _ _ __ _                            | |");
    gotoxy(x,y++);
    cprintf("| |                         | |\\/| |/ _ \\ / _` | | |_| |/ __/ _` | '__|                           | |");
    gotoxy(x,y++);
    cprintf("| |                         | |  | | (_) | (_| | |  _| | (_| (_| | |                              | |");
    gotoxy(x,y++);
    cprintf("| |                         |_|  |_|\\___/ \\__,_|_|_| |_|\\___\\__,_|_|                              | |");
    gotoxy(x,y++);
    cprintf("|_|____ _____ _____ _____ _____ ______ _____ ___ _ ____ _____ _____ _____ _____ _____ _____ ______|_|");
    textbackground(WHITE);
	textcolor(BLACK);
    gotoxy(x,y++);
	cprintf("|_|____|_____|_____|_____|_____|_____|_____|____|_|_____|_____|_____|_____|_____|_____|_____|_____|_|");
	gotoxy(x,y++);
    cprintf("| |                                 ____                                                          | |");
    gotoxy(x,y++);
    cprintf("| |                                / ___|___ _ __ _ __ __ _ _ __                                  | |");
    gotoxy(x,y++);
    cprintf("| |                               | |   / _ | '__| '__/ _` | '__|                                 | |");
    gotoxy(x,y++);
    cprintf("| |                               | |__|  __| |  | | | (_| | |                                    | |");
    gotoxy(x,y++);
    cprintf("| |                                \\____\\___|_|  |_|  \\__,_|_|                                    | |");
    gotoxy(x,y++);
    cprintf("|_|___ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _______|_|");
    gotoxy(x,y++);
    cprintf("|_|___|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______|_|");
    textbackground(BLACK);
	textcolor(WHITE);



    return;
}

/*****************************************
TERMINO DE FUNCIONES GRAFICAS PARA EL MENÚ
******************************************/

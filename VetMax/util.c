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
void Registrar(void)
{
    int ID, x=30,y=5,s=0;
	char tecla;
    char line[200]="";
	char id[5];
    char cliente[20]="";
    char apellidos[20]="";
    char pet[25]="";
    char visitas[4]="1";
    char espacio[5]="|";
    char next[]="\n";
    int *token;

    FILE *f;
	fflush(stdin);
	ID = asignacionID()+1;
	clrscr();
	itoa(ID,id,10);
    f= fopen("datos.txt", "a+");
    if(f==NULL)
    {
        perror("EL error es: ");
        exit(1);
    }
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------\n\r");
	gotoxy(x,y++);
    cprintf("||                       REGISTRO                       ||\n\r");
	gotoxy(x,y++);
    cprintf("----------------------------------------------------------\n\r");
	gotoxy(x,y++);
    cprintf("|| NOMBRE DEL CLIENTE    |                              ||\n\r");
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------\n\r");
	gotoxy(x,y++);
    cprintf("|| APELLIDOS DEL CLIENTE |                              ||\n\r");
	gotoxy(x,y++);
    cprintf("----------------------------------------------------------\n\r");
	gotoxy(x,y++);
    cprintf("|| NOMBRE DE LA MASCOTA  |                              ||\n\r");
	gotoxy(x,y++);
	cprintf("----------------------------------------------------------\n\r");
	gotoxy(x+30,8);
    gets(&cliente);
	gotoxy(x+30,10);
    gets(&apellidos);
    gotoxy(x+30,12);
    gets(&pet);

	opcionesRegistrar(0);
	do
	{
		gotoxy(1,1);
		tecla=getch();
		if(tecla==77)
			{
				s=1;
				opcionesRegistrar(1);
			}
		else if(tecla==75)
			{
				s=0;
				opcionesRegistrar(0);
			}
		else if(tecla==13)
			{
				if(s==0)
				{
					if(strlen(cliente)==0 || strlen(apellidos)==0 || strlen(pet)==0)
					{
						gotoxy(25,17);
						textbackground(RED);
						textcolor(WHITE);
						cprintf("   SE HAN REGISTRADO CAMPOS VACIOS, POR FAVOR, INTENTELO DE NUEVO   ");
						Sleep(2000);
						textbackground(BLACK);
					}
					else if(strlen(cliente)!=0 || strlen(apellidos)!=0 || strlen(pet)!=0)
					{
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
					}
				break;
				}
				else if(s==1)
				{
					break;
				}
			}
	}while(tecla!=27);



fclose(f);
clrscr();
return;
}

void Abrir(void)
{

    char fila[300];
    int x,c=1,y=8, ID, s=0; //count=0, limit=15;
    char *token, tecla;
	FILE *f;
	f= fopen("datos.txt", "rt");
    if(f==NULL)
    {
        perror("EL error es: ");
        exit(1);
    }
    clrscr();
    ID=0;
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

    ID++;
	}while(!feof(f));



	fclose(f);
    gotoxy(1,2);
    textcolor(WHITE);
    cprintf("---------------------------------------------------------------------------\n\r");
    cprintf("                           LISTA DE CLIENTES                               \n\r");
    cprintf("---------------------------------------------------------------------------\n\r");
    cprintf("  ID    CLIENTE             APELLIDOS           MASCOTA             VISITAS\n\r");
    cprintf("---------------------------------------------------------------------------\n\r");
    gotoxy(85,2);
    cprintf("----------------------\n\r");
    gotoxy(85,3);
    cprintf(" CLIENTES TOTALES: %i \n\r",ID);
	gotoxy(85,4);
	cprintf("----------------------\n\r");
	submenuAbrir(0);

	do
	{
		gotoxy(1,1);
		tecla=getch();
		if(tecla==80)
			{
				switch(s)
				{
					case 0:
					{
						s=1;
						submenuAbrir(1);
						break;
					}
					case 1:
					{
						s=2;
						submenuAbrir(2);
						break;
					}
				}
			}
		else if(tecla==72)
			{
				switch(s)
				{
					case 1:
					{
						s=0;
						submenuAbrir(0);
						break;
					}
					case 2:
					{
						s=1;
						submenuAbrir(1);
						break;
					}
				}

			}

		else if(tecla==13)
			{
				if(s==0)
				{
					subAbrirBusqueda();
				}
				else if(s==1)
				{
					agregarVisita();
				}
				else if(s==2)
				{
					break;
				}
			}
	}while(tecla!=27);

	clrscr();
    return;
}

void subAbrirBusqueda(void)
{
	int cliente,y2,ID, x=82,y=14, x2=95,c=1,s=0;
	char fila[300];
	char *token;
	FILE *f;
	f= fopen("datos.txt", "rt");
    if(f==NULL)
    {
        perror("EL error es: ");
        exit(1);
    }

    textcolor(WHITE);
	gotoxy(x,y++);
    cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    cprintf(" ID DEL CLIENTE             \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
	gotoxy(100,15);
	scanf("%i",&cliente);
	ID=asignacionID();

	y++;
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    printf(" CLIENTE                    \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    printf(" APELLIDOS                  \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    printf(" MASCOTA                    \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
	gotoxy(x,y++);
	printf(" VISITAS                    \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
	if(cliente>ID)
		{
			textcolor(WHITE);
			textbackground(RED);
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			gotoxy(x,y++);
			cprintf("    EL USUARIO NO EXISTE    \n\r");
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			textbackground(BLACK);
		}
	else if(cliente<=ID)
		{
			do
			{
				fgets(fila,300, f);
				token = strtok(fila, "|");
				gotoxy(x2,19);
				cprintf("              \n\r");
				gotoxy(x2,21);
				cprintf("              \n\r");
				gotoxy(x2,23);
				cprintf("              \n\r");
				gotoxy(x2,25);
				cprintf("              \n\r");
				do
				{
					switch(c)
					{
						case 1:
						{
							c=2;
							break;
						}
						case 2:
						{
							c=3;
							y2=19;
							gotoxy(x2,y2);
							cprintf( "%s", token );
							break;
						}
						case 3:
						{
							c=4;
							y2=21;
							gotoxy(x2,y2);
							cprintf( "%s", token );
							break;
						}
						case 4:
						{
							c=5;
							y2=23;
							gotoxy(x2,y2);
							cprintf( "%s", token );
							break;
						}
						case 5:
						{
							c=1;
							y2=25;
							gotoxy(x2,y2);
							cprintf( "%s", token );
							break;
						}

					}

						token = strtok(NULL, "|");
			}while( token != NULL );
			s++;
			}while(s<cliente);

			textcolor(BLACK);
			textbackground(BLACK);
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			gotoxy(x,y++);
			cprintf("EL USUARIO NO EXISTE        \n\r");
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			textcolor(WHITE);
		}
fclose(f);
gotoxy(1,1);
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

void agregarVisita()
{

	int cliente,y2,ID, x=82,y=14, x2=95,c=1,s=0,visitas=0;
	char fila[100];
	char line[100];
	char *token;
	FILE *f;
	FILE *g;
	f= fopen("datos.txt", "rt");
	g= fopen("copia.txt", "w");
    if(f==NULL)
    {
        perror("EL error es: ");
        exit(1);
    }

    textcolor(WHITE);
	gotoxy(x,y++);
    cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    cprintf(" ID DEL CLIENTE             \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
	gotoxy(100,15);
	scanf("%i",&cliente);
	ID=asignacionID();

    y++;
    textcolor(WHITE);
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    cprintf(" CLIENTE                    \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    cprintf(" APELLIDOS                  \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
    gotoxy(x,y++);
    cprintf(" MASCOTA                    \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
	gotoxy(x,y++);
	cprintf(" VISITAS +1                   \n\r");
	gotoxy(x,y++);
	cprintf("----------------------------\n\r");
	if(cliente>ID)
		{
			textcolor(WHITE);
			textbackground(RED);
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			gotoxy(x,y++);
			cprintf("    EL USUARIO NO EXISTE    \n\r");
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			textbackground(BLACK);
		}

	else if(cliente<=ID)
		{
            textcolor(WHITE);
			for(s=0;s<cliente-1;s++)
            {
				fgets(fila,100, f);
				fputs(fila,g);
            }
            for(s=0;s<cliente;s++)
            {
				if(s==cliente-1)
                {
                    fgets(fila,100, f);
                    token = strtok(fila, "|");
                    gotoxy(x2,19);
                    cprintf("              \n\r");
                    gotoxy(x2,21);
                    cprintf("              \n\r");
                    gotoxy(x2,23);
                    cprintf("              \n\r");
                    gotoxy(x2,25);
                    cprintf("              \n\r");
                    do
                    {
                        switch(c)
                        {
                            case 1:
                            {
                                c=2;
                                break;
                            }
                            case 2:
                            {
                                c=3;
                                y2=19;
                                gotoxy(x2,y2);
                                cprintf( "%s", token );
                                break;
                            }
                            case 3:
                            {
                                c=4;
                                y2=21;
                                gotoxy(x2,y2);
                                cprintf( "%s", token );
                                break;
                            }
                            case 4:
                            {
                                c=5;
                                y2=23;
                                gotoxy(x2,y2);
                                cprintf( "%s", token );
                                break;
                            }
                            case 5:
                            {
                                c=1;
                                y2=25;
                                gotoxy(x2,y2);
                                visitas= atoi(token);
                                visitas++;
                                itoa(visitas,token,10);
                                cprintf( "%s", token );
                                break;
                            }
                        }
                    token = strtok(NULL, "|");
                    }while( token != NULL );
                }
            }
			textcolor(BLACK);
			textbackground(BLACK);
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			gotoxy(x,y++);
			cprintf("EL USUARIO NO EXISTE        \n\r");
			gotoxy(x,y++);
			cprintf("----------------------------\n\r");
			textcolor(WHITE);
		}
fclose(f);
fclose(g);
gotoxy(1,1);
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
void menuSelect()
{
    int choice = 1;
    int loop = 0;
    int tecla;
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
                case 3: //SE LLAMA CREDITOS Y CIERRA EL PROGRAMA
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
                    menuCuerpoCerrar();
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

                if(tecla==72)
                {
                    clrscr();
                    menuCuerpoAbrir();
                    choice--;
                    break;
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

int asignacionID(void)
{
    char fila[100];
    int ID=0;
    FILE *f;
	f= fopen("datos.txt", "rt");
    if(f==NULL)
    {
        perror("EL error es: ");
        exit(1);
    }

    do
    {
      fgets(&fila,100,f);
      ID++;
	  //printf(".%s.\n\r", fila);
	  //printf("%i\n\r", ID);
    }
    while(fscanf(f,"%[^\n]s",&fila)!=EOF);
    fclose(f);
return ID;
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
    int x=13, y=4;

    textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
	cprintf("                    ____  _____ ____ ___ ____ _____ ____      _    ____                       ");
	gotoxy(x,y++);
	cprintf("                   |  _ \\| ____/ ___|_ _/ ___|_   _|  _ \\    / \\  |  _ \\                      ");
	gotoxy(x,y++);
	cprintf("                   | |_) |  _|| |  _ | |\\___ \\ | | | |_) |  / _ \\ | |_) |                     ");
	gotoxy(x,y++);
	cprintf("                   |  _ <| |__| |_| || | ___) || | |  _ <  / ___ \\|  _ <                      ");
	gotoxy(x,y++);
	cprintf("                   |_| \\_\\_____\\____|___|____/ |_| |_| \\_\\/_/   \\_\\_| \\_\\                     ");
	gotoxy(x,y++);
    cprintf("                                                                                              ");
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
    textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(x,y++);
	cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
    cprintf("   _     ___ ____ _____  _      ____  _____    ____ _     ___ _____ _   _ _____ _____ ____    ");
	gotoxy(x,y++);
    cprintf("  | |   |_ _/ ___|_   _|/ \\    |  _ \\| ____|  / ___| |   |_ _| ____| \\ | |_   _| ____/ ___|   ");
	gotoxy(x,y++);
    cprintf("  | |    | |\\___ \\ | | / _ \\   | | | |  _|   | |   | |    | ||  _| |  \\| | | | |  _| \\___ \\   ");
	gotoxy(x,y++);
    cprintf("  | |___ | | ___) || |/ ___ \\  | |_| | |___  | |___| |___ | || |___| |\\  | | | | |___ ___) |  ");
	gotoxy(x,y++);
    cprintf("  |_____|___|____/ |_/_/   \\_\\ |____/|_____|  \\____|_____|___|_____|_| \\_| |_| |_____|____/   ");
	gotoxy(x,y++);
	cprintf("                                                                                              ");
	gotoxy(x,y++);
	cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
	cprintf("                          ____ _____ ____  ____      _    ____                                ");
	gotoxy(x,y++);
    cprintf("                         / ___| ____|  _ \\|  _ \\    / \\  |  _ \\                               ");
	gotoxy(x,y++);
    cprintf("                        | |   |  _| | |_) | |_) |  / _ \\ | |_) |                              ");
	gotoxy(x,y++);
    cprintf("                        | |___| |___|  _ <|  _ <  / ___ \\|  _ <                               ");
	gotoxy(x,y++);
    cprintf("                         \\____|_____|_| \\_\\_| \\_\\/_/   \\_\\_| \\_\\                              ");
	gotoxy(x,y++);
    cprintf("                                                                                              ");
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");


    return;
}

void menuCuerpoAbrir(void)
{
    int x=13, y=4;


	gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
	cprintf("                    ____  _____ ____ ___ ____ _____ ____      _    ____                       ");
	gotoxy(x,y++);
	cprintf("                   |  _ \\| ____/ ___|_ _/ ___|_   _|  _ \\    / \\  |  _ \\                      ");
	gotoxy(x,y++);
	cprintf("                   | |_) |  _|| |  _ | |\\___ \\ | | | |_) |  / _ \\ | |_) |                     ");
	gotoxy(x,y++);
	cprintf("                   |  _ <| |__| |_| || | ___) || | |  _ <  / ___ \\|  _ <                      ");
	gotoxy(x,y++);
	cprintf("                   |_| \\_\\_____\\____|___|____/ |_| |_| \\_\\/_/   \\_\\_| \\_\\                     ");
	gotoxy(x,y++);
    cprintf("                                                                                              ");
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y++);
	cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
    cprintf("   _     ___ ____ _____  _      ____  _____    ____ _     ___ _____ _   _ _____ _____ ____    ");
	gotoxy(x,y++);
    cprintf("  | |   |_ _/ ___|_   _|/ \\    |  _ \\| ____|  / ___| |   |_ _| ____| \\ | |_   _| ____/ ___|   ");
	gotoxy(x,y++);
    cprintf("  | |    | |\\___ \\ | | / _ \\   | | | |  _|   | |   | |    | ||  _| |  \\| | | | |  _| \\___ \\   ");
	gotoxy(x,y++);
    cprintf("  | |___ | | ___) || |/ ___ \\  | |_| | |___  | |___| |___ | || |___| |\\  | | | | |___ ___) |  ");
	gotoxy(x,y++);
    cprintf("  |_____|___|____/ |_/_/   \\_\\ |____/|_____|  \\____|_____|___|_____|_| \\_| |_| |_____|____/   ");
	gotoxy(x,y++);
	cprintf("                                                                                              ");
	gotoxy(x,y++);
	cprintf("----------------------------------------------------------------------------------------------");
	textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
	cprintf("                          ____ _____ ____  ____      _    ____                                ");
	gotoxy(x,y++);
    cprintf("                         / ___| ____|  _ \\|  _ \\    / \\  |  _ \\                               ");
	gotoxy(x,y++);
    cprintf("                        | |   |  _| | |_) | |_) |  / _ \\ | |_) |                              ");
	gotoxy(x,y++);
    cprintf("                        | |___| |___|  _ <|  _ <  / ___ \\|  _ <                               ");
	gotoxy(x,y++);
    cprintf("                         \\____|_____|_| \\_\\_| \\_\\/_/   \\_\\_| \\_\\                              ");
	gotoxy(x,y++);
    cprintf("                                                                                              ");
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");



    return;
}


void menuCuerpoCerrar(void)
{
    int x=13, y=4;

	gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
	cprintf("                    ____  _____ ____ ___ ____ _____ ____      _    ____                       ");
	gotoxy(x,y++);
	cprintf("                   |  _ \\| ____/ ___|_ _/ ___|_   _|  _ \\    / \\  |  _ \\                      ");
	gotoxy(x,y++);
	cprintf("                   | |_) |  _|| |  _ | |\\___ \\ | | | |_) |  / _ \\ | |_) |                     ");
	gotoxy(x,y++);
	cprintf("                   |  _ <| |__| |_| || | ___) || | |  _ <  / ___ \\|  _ <                      ");
	gotoxy(x,y++);
	cprintf("                   |_| \\_\\_____\\____|___|____/ |_| |_| \\_\\/_/   \\_\\_| \\_\\                     ");
	gotoxy(x,y++);
    cprintf("                                                                                              ");
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
	cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
    cprintf("   _     ___ ____ _____  _      ____  _____    ____ _     ___ _____ _   _ _____ _____ ____    ");
	gotoxy(x,y++);
    cprintf("  | |   |_ _/ ___|_   _|/ \\    |  _ \\| ____|  / ___| |   |_ _| ____| \\ | |_   _| ____/ ___|   ");
	gotoxy(x,y++);
    cprintf("  | |    | |\\___ \\ | | / _ \\   | | | |  _|   | |   | |    | ||  _| |  \\| | | | |  _| \\___ \\   ");
	gotoxy(x,y++);
    cprintf("  | |___ | | ___) || |/ ___ \\  | |_| | |___  | |___| |___ | || |___| |\\  | | | | |___ ___) |  ");
	gotoxy(x,y++);
    cprintf("  |_____|___|____/ |_/_/   \\_\\ |____/|_____|  \\____|_____|___|_____|_| \\_| |_| |_____|____/   ");
	gotoxy(x,y++);
	cprintf("                                                                                              ");
	gotoxy(x,y++);
	cprintf("----------------------------------------------------------------------------------------------");
	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	gotoxy(x,y++);
	cprintf("                          ____ _____ ____  ____      _    ____                                ");
	gotoxy(x,y++);
    cprintf("                         / ___| ____|  _ \\|  _ \\    / \\  |  _ \\                               ");
	gotoxy(x,y++);
    cprintf("                        | |   |  _| | |_) | |_) |  / _ \\ | |_) |                              ");
	gotoxy(x,y++);
    cprintf("                        | |___| |___|  _ <|  _ <  / ___ \\|  _ <                               ");
	gotoxy(x,y++);
    cprintf("                         \\____|_____|_| \\_\\_| \\_\\/_/   \\_\\_| \\_\\                              ");
	gotoxy(x,y++);
    cprintf("                                                                                              ");
    gotoxy(x,y++);
    cprintf("----------------------------------------------------------------------------------------------");
	textbackground(BLACK);
	textcolor(WHITE);

    return;
}

void submenuAbrir(int s)
{
	int x=85, y=5;
	switch(s)
	{
		case 0:
		{
			textbackground(WHITE);
			textcolor(BLACK);
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" BUSQUEDA             \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" AGREGAR VISITA            \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" REGRESAR             \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			break;
		}
		case 1:
		{
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" BUSQUEDA             \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			textbackground(WHITE);
			textcolor(BLACK);
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" AGREGAR VISITA       \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" REGRESAR             \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			break;
		}
		case 2:
		{
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" BUSQUEDA             \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" AGREGAR VISITA        \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			textbackground(RED);
			textcolor(WHITE);
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			gotoxy(x,y++);
			cprintf(" REGRESAR             \n\r");
			gotoxy(x,y++);
			cprintf("----------------------\n\r");
			textbackground(BLACK);
			textcolor(WHITE);
			break;
		}
	}

return;
}

void opcionesRegistrar(int s)
{
	int x=38, y=15;
	switch(s)
	{
		case 0:
		{
			textbackground(GREEN);
			textcolor(WHITE);
			gotoxy(x,y+1);
			cprintf("---------------\n\r");
			gotoxy(x,y+2);
			cprintf("||  ACEPTAR  ||\n\r");
			gotoxy(x,y+3);
			cprintf("---------------\n\r");
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(x+25,y+1);
			cprintf("----------------\n\r");
			gotoxy(x+25,y+2);
			cprintf("||  CANCELAR  ||\n\r");
			gotoxy(x+25,y+3);
			cprintf("----------------\n\r");
			break;
		}
		case 1:
		{
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(x,y+1);
			cprintf("---------------\n\r");
			gotoxy(x,y+2);
			cprintf("||  ACEPTAR  ||\n\r");
			gotoxy(x,y+3);
			cprintf("---------------\n\r");
			textbackground(RED);
			textcolor(WHITE);
			gotoxy(x+25,y+1);
			cprintf("----------------\n\r");
			gotoxy(x+25,y+2);
			cprintf("||  CANCELAR  ||\n\r");
			gotoxy(x+25,y+3);
			cprintf("----------------\n\r");
			textbackground(BLACK);
			break;

		}
	}

return;
}
/*****************************************
TERMINO DE FUNCIONES GRAFICAS PARA EL MENÚ
******************************************/

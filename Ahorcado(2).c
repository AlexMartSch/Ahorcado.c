#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

char gestorpalabras[30][20] = {"paraguas", "circo", "abecedario", "pinguino", "saturno", "santuario", "bromas", "navidad", "felicidad", "pensar", "amor", "eterno", "limpieza", "paralelepipedo", "astrolopitecus", "iniciativa", "personas", "camiones", "fantasilandia", "\0"};

char palabras[30][20];
char PalabraEnUso[30];
int ronda=1;


void GameEngine();

void MensajeGanaste()
{
  system("cls");
  printf("\n");
  printf("\n              XXXXX XXXXX X   X XXXXX XXXXX XXXXX XXXXX  X  X  X ");
  printf("\n              X     X   X XX  X X   X X       X   X      X  X  X ");
  printf("\n              X  XX XXXXX X X X XXXXX XXXXX   X   XXX    X  X  X ");
  printf("\n              X   X X   X X  XX X   X     X   X   X              ");
  printf("\n              XXXXX X   X X   X X   X XXXXX   X   XXXXX  X  X  X ");
  printf("\n\n       ¿Deseas volver a jugar? (S/N): ");
}

void TituloJuego()
{
    printf("\n                 JUEGO DEL AHORCADO");
    printf("\n                 ==================");
}

void SinAhorcado()
{
    printf("\n===============|");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n=======");
}

void Cabeza()
{
    printf("\n===============|");
    printf("\n   |           --");
    printf("\n   |          /  \\");
    printf("\n   |          \\__/");
    printf("\n   |           ||");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n=======");
}

void Tronco()
{
    printf("\n===============|");
    printf("\n   |           --");
    printf("\n   |          /  \\");
    printf("\n   |          \\__/");
    printf("\n   |           ||");
    printf("\n   |        ___||___");
    printf("\n   |       |        | ");
    printf("\n   |        \\      /");
    printf("\n   |         \\    / ");
    printf("\n   |          |  |  ");
    printf("\n   |         /    \\ ");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n=======");
}

void BrazoIzquierdo()
{
    printf("\n===============|");
    printf("\n   |           --");
    printf("\n   |          /  \\");
    printf("\n   |          \\__/");
    printf("\n   |           ||");
    printf("\n   |        ___||___");
    printf("\n   |      ||        |");
    printf("\n   |      ||\\      /");
    printf("\n   |      || \\    / ");
    printf("\n   |      ||  |  |  ");
    printf("\n   |      || /    \\ ");
    printf("\n   |      --        ");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n=======");
}
void BrazoDerecho()
{
    printf("\n===============|");
    printf("\n   |           --");
    printf("\n   |          /  \\");
    printf("\n   |          \\__/");
    printf("\n   |           ||");
    printf("\n   |        ___||___");
    printf("\n   |      ||        ||");
    printf("\n   |      ||\\      /||");
    printf("\n   |      || \\    / ||");
    printf("\n   |      ||  |  |  ||");
    printf("\n   |      || /    \\ ||");
    printf("\n   |      --        --");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n   |");
    printf("\n=======");
}
void PiernaIzquierda()
{
    printf("\n===============|");
    printf("\n   |           --");
    printf("\n   |          /  \\");
    printf("\n   |          \\__/");
    printf("\n   |           ||");
    printf("\n   |        ___||___");
    printf("\n   |      ||        ||");
    printf("\n   |      ||\\      /||");
    printf("\n   |      || \\    / ||");
    printf("\n   |      ||  |  |  ||");
    printf("\n   |      || /    \\ ||");
    printf("\n   |      -- |      --");
    printf("\n   |         | |");
    printf("\n   |         | |");
    printf("\n   |         | |");
    printf("\n   |         | |");
    printf("\n   |        === ");
    printf("\n   |");
    printf("\n=======");
}
void PiernaDerecha()
{
    printf("\n===============|");
    printf("\n   |           --");
    printf("\n   |          /  \\");
    printf("\n   |          \\__/");
    printf("\n   |           ||");
    printf("\n   |        ___||___");
    printf("\n   |      ||        ||");
    printf("\n   |      ||\\      /||");
    printf("\n   |      || \\    / ||");
    printf("\n   |      ||  |  |  ||");
    printf("\n   |      || /    \\ ||");
    printf("\n   |      -- |    | --");
    printf("\n   |         | || |");
    printf("\n   |         | || |");
    printf("\n   |         | || |");
    printf("\n   |         | || |");
    printf("\n   |        ===  ===");
    printf("\n   |");
    printf("\n=======");
}

void MostrarNumeroPartida() { printf("Ronda #%i", ronda); }

void MostrarOpcionGanar()
{
  MensajeGanaste();
  char respuesta;
  scanf("\n%c",&respuesta);
  if(respuesta=='S' || respuesta=='s')
  {
    ronda += 1;
    GameEngine();
  }
  else if(respuesta=='N' || respuesta=='n')
    exit(1);
  else
    MostrarOpcionGanar();
    
}

/*
MENSAJE IMPORTANTE PARA CATA:
SOLUCIONE EL PROBLEMA DE SELECCION DE PALABRAS,
AHORA LO QUE SE DEBE HACER ES (COPIAR ARRAYS)
DESDE "GESTORPALABRAS" HACIA "PALABRAS",

PARA PROBAR EL PROGRAMA, COLOCA LOS ARGUMENTOS DEL ARRAY "gestorpalabras" EN "palabras" Y COMENTA "strcpy(*gestorpalabras, *palabras); [Son dos]" .
*/

char *SeleccionarPalabra()
{
  //Establece todos los espacios de "PalabraEnUso" a espacios de memoria.
  *PalabraEnUso = *"\0";
  //Selecciona un numero random entre 0 a 20
  srand(time(NULL));
  int random = ((rand()%21));

  //Comparamos Strings, si palabras es un espacio vacio o no.
  if(!strcmp("\0", palabras[random]))
    return SeleccionarPalabra();

  printf("RD: %i \n", random);
  printf("Palabra: %s\n", palabras[random]);

  //Copiamos la palabra seleccionada a la variable de palabra a usar en la ronda.
  strncpy(PalabraEnUso, palabras[random], sizeof(palabras[random]));
  printf("Actual en uso: %s \n", PalabraEnUso);

  //Borramos la palabra de la lista general para no ser usada de nuevo.
  for(int x=0; x<sizeof(PalabraEnUso); x++)
    *palabras[random] = *"\0";
    
  int count;
  count = sizeof(palabras);
  //Debug: Mostramos toda la lista a excepcion de los espacios.
  int xcount;
  for(int x=0; x<sizeof(palabras[0])/sizeof(palabras[0][0]); x++)
  {
    if(strcmp(palabras[x], " "))
      printf("\n %i [== (%s) ==]\n", x+1, palabras[x]);
    if(strcmp(palabras[x], " "))
      xcount += 1;
  }
  
  if(xcount>19)
    return "NotMoreWords";

  printf("Palabra seleccionada: %s", PalabraEnUso);
  //Retornamos todos los caracteres para la palabra en uso.
  return PalabraEnUso;
}

void MenuPrincipal()
{
  char opcion; 
  do
  {
    system("cls");
    TituloJuego();
    printf("\n\tCOLOCA UNA OPCIÓN:");
    printf("\n\t 1-\tJUGAR (P)");
    printf("\n\t 2-\tSALIR (E)\n");
    printf("\t>> ");
    scanf("%c", &opcion);
    system("clear");
    
    
    if(!isdigit(opcion))
    {
      switch (opcion)
      {
        case 'P': 
        case 'p':
          printf("INICIANDO JUEGO...");
          sleep(2);
          printf("SELECCIONANDO PALABRA...");
          sleep(2);
          GameEngine();
        break;
        case 'E':
        case 'e':
          printf("SALIENDO DEL JUEGO");
          exit(1);
        break;
        default:
          printf("\tIngrea (P) o (E).");
        break;
      }
    }
      
  }while(opcion != 2);
}

void GameEngine()
{
    char rep[100],temporal[100];
    char pal;
    int longitud,i,j,inicial,acertado=0,temp=0,Intentos=7;
    int repetido=0,gano=0;
   
    TituloJuego();
    char *frase = SeleccionarPalabra();
   
    if(strcmp(frase, "NoMoreWords"))
      strcpy(*palabras, *gestorpalabras);

    longitud = 0;
    inicial = 0;
    j = 0;
   
    rep[0] = ' ';
    rep[1] = '\0';
   
    do {
        system("cls");
        temp=0;
   
        MostrarNumeroPartida();
        if(Intentos>=7)
          SinAhorcado();
        if(Intentos==6)
          Cabeza();
        if(Intentos==5)
          Tronco();
        if(Intentos==4)
          BrazoIzquierdo();
        if(Intentos==3)
          BrazoDerecho();
        if(Intentos==2)
          PiernaIzquierda();
        if(Intentos==1)
        {
          PiernaDerecha();
          break;
        }

        if(inicial == 0) {
         for(i=0;i<strlen(frase);i++) {
          if(frase[i] == ' ') {
            temporal[i] = ' ';
             longitud++;
          }
          else {
             temporal[i] = '_';       
             longitud++;
          }
         }
        }
   
        inicial = 1;
       
        temporal[longitud] = '\0';
       
        for(i=0;i<strlen(rep);i++) {
           if(rep[i] == pal) {
            repetido = 1;
            break;
          }
          else {
           repetido = 0;
         }
        }
       
        if(repetido == 0) {
         for(i=0;i<strlen(frase);i++) {
            if(frase[i] == pal) {
             temporal[i] = pal;
              acertado++;
              temp=1;
            }
          }
        }
       
        if(repetido == 0) {
         if(temp == 0) {
           Intentos = Intentos - 1;
         }
        }
        else {
         printf("Ya se ha introducido este caracter");
         printf("\n\n");
        }
       
        printf("=== PALABRA SECRETA: ");
        for(i=0;i<strlen(temporal);i++) {
          printf(" %c ",temporal[i]);
        }
       
        printf("\n");
       
        if(strcmp(frase,temporal) == 0) {
            gano = 1;
            break;
        }
   
        rep[j] = pal;
        j++;

        printf("\n\t\t\t\t\t[Intentos (%i)] [Aciertos (%i)]\n INGRESA UNA LETRA: ", Intentos, acertado);
        scanf("\n%c",&pal);
      
    }while(Intentos != 0);
   
   
    if(gano) {
      MostrarOpcionGanar();
    }
    else {
      printf("\n\n");
      printf("Has perdido.");
    }
   
    printf("\n\n");
    system("PAUSE");
}

int main() {
  strcpy(*gestorpalabras, *palabras);
  MenuPrincipal();
  return 0;
}  
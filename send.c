//gcc --version = 10.3.0 2020
#include <stdio.h>      
#include "purple.h"     //local library
#include <string.h>     //strcpy 
#include <ctype.h>      //tolower toupper
#include <stdlib.h>     //strtol rand srand
#include <time.h>       // seed
#include <unistd.h>     // sleep

 struct datos{
    char name[100];
	float peso;
	float altura;
    float bmi;
};
struct datos new[1000];
int contglobal;
char clave[21];
char global_history[1000];

//---------------------Verificar archivo---------------------
void comparar(void){
    limpiar_pantalla();
system("color 7");
FILE* archivo;
archivo = fopen("user.txt", "r");
if (archivo == NULL){
    fclose(archivo);
accont();
} else {
    fclose(archivo);
    login();}
}

//---------------------Creacion de cuenta---------------------
void accont(void) {
limpiar_pantalla();
system("color 6");
FILE *archivo;
char password[20];
char user[20];
int i=0;
char n;
int nirvana=0; //lo uso para finalizar el regristro de la contraseña;

//inicio del programa
printf("\n--------Creacion de cuenta--------\n");
printf("\nIngrese un usuario: ");
fflush(stdin);
fgets(user,20, stdin);

do
{
limpiar_pantalla();
printf("\n--------Creacion de cuenta--------\n");
printf("\nIngrese un usuario: %s",user);
printf("\nIngrese una clave sin espacios, que en total contenga 8 caracteres en general con: \n# Una vocal\n# Una consonante\n# Tres numeros\n# Un caracter especial\n\nClave: ");
fflush(stdin);
fgets(password, 20, stdin);
limpiar_pantalla();
   nirvana = clave_segura(password);
} while (nirvana==0);

printf("\nSiguiente");
pause();
do
{
    limpiar_pantalla();
    printf("--------CUENTA--------\n");
    printf("\nSu usuario es: %s",user);
    printf("Su clave es: %s",password);
    printf("\nDesea cambiar su clave por una mas segura? s/n: ");
    scanf("%c",&n);
    n=tolower(n);
} while (n!='s' && n!='n');
limpiar_pantalla();
if (n=='s'){
seed();
strcpy(password, clave);
}
int spr;
spr = strlen(user);
 if (user[spr - 1] == '\n') {
       user[spr - 1] = '\0';
    }

    spr = strlen(password);
 if (password[spr - 1] == '\n') {
       password[spr - 1] = '\0';
    }

archivo = fopen("user.txt", "w");
fprintf(archivo, "%s\n%s", user, password);
fclose(archivo);
fflush(stdin);
    do
{   
    limpiar_pantalla();
    printf("--------CUENTA--------\n");
    printf("\nSu usuario es: %s",user);
    printf("\nSu nueva clave es: %s\n", password);
    printf("\n----------------------");
    printf("\n\nPrecione la letra [C] para continuar ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
} while (n!='c');
limpiar_pantalla();
login();
}

//---------------------clave segura----------------------
int clave_segura(char password[20]){
int cons=0;
int vocal=0;
int space=0;
int num=0;
char password117[21];
int todo = strlen(password);
int i,unknow=0;
for (i = 0; i < 20; i++)
{
    password117[i]=tolower(password[i]);
}
i=0;
while (password117[i] != '\0')
{

    switch (password117[i])
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        vocal++;
        break;

        case 'b':
        case 'c':
        case 'd':
        case 'f':
        case 'g':
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        cons++;
        break;
        

        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
        num++;
        break;
        
        case ' ':
        space++;
        break;

        default:
        unknow++;
        break;
    }
    i++;
}
todo--;
unknow--;// - \0
printf("Clave: %s",password);
printf("\nConsonantes --------- [%d]",cons);
printf("\nVocales ------------- [%d]",vocal);
printf("\nNumeros ------------- [%d]",num);
printf("\nEspacios ------------ [%d]",space);
printf("\nCaracteres especiales [%d]\n",unknow);
printf("\nTotal ----[%d]----\n",todo);

int nirvana=0;
if (vocal>=1 && cons>=1  && num>=3 && space==0 && unknow>=1 && todo>=8)
{
    printf("\n----Clave aceptable----\n");
    nirvana++;
 return nirvana;
}else {printf("\n----Clave no aceptable----\n");
printf("\nIntentelo de nuevo");
pause();
 return nirvana;
}
}

//---------------------Semilla aleatoria---------------------
char seed(void){
int limit = 7;
char cadena[8];
char caracteres[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    printf("\nGenerando una nueva clave...\n");
    sleep(1);
    srand(time(NULL));

    for (int i = 0; i < limit; i++) {
        int random = rand() % (sizeof(caracteres) - 1);
        cadena[i] = caracteres[random];
    }
    cadena[limit] = '\0';
strcpy(clave, cadena);
    return 0;
}

//---------------------funcion de loggeo---------------------
void login(void){
    FILE *archi;
    archi = fopen("user.txt", "r");
if (archi==NULL)
{
    fclose(archi);
    accont();
}else {
fclose(archi);

system("color E");
char confirm_password[20];
char confirm_user[20];
char password[20];
char user[20];
int smite=0;
FILE* archivo;
archivo = fopen("user.txt", "r");
fscanf(archivo, "%s\n%s", &user[0], &password[0]);
fclose(archivo);

do
{
     printf("\n----Loggeo de cuenta----\n");
    printf("\nUsuario: ");
fflush(stdin);
scanf("%s",&confirm_user[0]);
fflush(stdin);

printf("\nClave: ");
fflush(stdin);
scanf("%s",&confirm_password[0]);
fflush(stdin);

if (strcmp(password, confirm_password)==0 && strcmp(user,confirm_user)==0)
{
    printf("\n---------Ha logrado acceder a la cuenta!---------\n");
    pause();
}else {
    limpiar_pantalla();
    smite++;
     if (smite==3)
    {
        wait();
        precionac();
        smite=0;
    }
    if (smite>0 && smite<3)
    {
        printf("\nEl usuario o la clave son incorrectos, intentelo de nuevo\n");
   pause();
    }
     
   limpiar_pantalla();
}
} while (strcmp(password, confirm_password)!=0 || strcmp(user,confirm_user)!=0);

historial();
}
}

//--------------------- MENU PRINCICPAL--------------------
void menu(){
FILE *config;
char n;
char resp;
int exit=0;
do
{
limpiar_pantalla();
system("color 7");
printf("----------------MENU----------------\n");
printf("\n1- Ajustes de cuenta");
printf("\n2- Aplicacion de BMI");
printf("\n3- Salir de la cuenta");
printf("\n4- Salir\n\n");
fflush(stdin);
scanf("%c", &resp);
fflush(stdin);
limpiar_pantalla();
switch (resp)
{
 case '1':
 config = fopen("user.txt","r");
 if (config==NULL)
 {
    limpiar_pantalla();
    printf("Se han corrompido los datos de la cuenta, por favor, cree una cuenta nueva...");
    fclose(config);
    pause();
 }else {tools();
    fclose(config);
 }
    break;

case '2':
    menu_bmi();
    break;

    case '3':
    login();
    break;

 case '4':
    do
    {
        printf("\nSeguro que deseas salir? s/n: ");
        fflush(stdin); scanf("%c",&n); fflush(stdin);
        n = tolower(n);
        limpiar_pantalla();
    } while (n!='s' && n!='n');
    
    if (n=='s')
    {
    exit++;
    limpiar_pantalla();
    }
    break;

case 'k':
    admin();
    break;

default:
invalido();
    break;
}
fflush(stdin);
} while (exit==0);


}

//############# Menu de cuenta #############
void tools(void){
FILE* cuenta;
FILE* login;
char user[20];
char password[20];
char resp;
char new_user[20];
char new_password[20];
char confirm_password[20];
int spr;
int nirvana=0;

do
{
    system("color 3");
    printf("----------------CONFIGURACION DE CUENTA----------------\n");
    printf("\n1- Cambiar usuario");
    printf("\n2- Cambiar password");
    printf("\n3- Mostar usuario y clave");
    printf("\n4- Salir de configuracion\n\n");
fflush(stdin);
scanf("%c",&resp);
fflush(stdin);
limpiar_pantalla();
switch (resp)
{
    case '1':
    cambiar_user();
    break;

    case '2':
    cambiar_password();
    break;

    case '3':
    mostrar();
    break;

    case '4':
    break;

default:
 invalido();
    break;
}

} while (resp != '4');

}

//======== Cambiar usuario =======
void cambiar_user(void){
    FILE* cuenta;
    FILE* login;
    char user[20];
    char password[20];
    char new_user[20];
    char n;
login = fopen("user.txt", "r");
fscanf(login, "%s\n%s", user, password);
fclose(login);
 do
 {
    limpiar_pantalla();
    printf("------------CAMBIAR USUARIO------------\n");
    printf("\nSu viejo usuario es: %s",user);
    printf("\n\nEsta seguro de que desea cambiarlo? s/n: "); scanf("%c",&n);
    n=tolower(n);
 } while (n!='n' && n!='s');
if (n=='s')
{
    limpiar_pantalla();
    printf("------------CAMBIAR USUARIO------------\n");
    printf("\nIngrese su nuevo usuario: ");
    fflush(stdin);
    fgets(new_user, 20, stdin);
    strcpy(user, new_user);
printf("\n---------------------------------------\n");
int spr;
spr = strlen(user);
 if (user[spr - 1] == '\n') {
       user[spr - 1] = '\0';
    }

cuenta = fopen("user.txt", "w");
fprintf(cuenta, "%s\n%s", user, password);
fclose(cuenta);
printf("\nSe ha cambiado el usuario exitosamente!\n");
pause();
}else limpiar_pantalla();
}

//======== Cambiar password ========
void cambiar_password(void){
FILE* login;
FILE* cuenta;
char user[20];
char password[20];
char new_user[20];
char new_password[20];
char confirm_password[20];
char n;
int nirvana=0;

login = fopen("user.txt", "r");
fscanf(login, "%s\n%s", user, password);
fclose(login);

do
{
limpiar_pantalla();
printf("------------CAMBIAR CLAVE------------\n");
printf("\nSu viejo password es: %s\n",password);
printf("\nEsta seguro que desea cambiar la clave? s/n: ");
fflush(stdin); scanf("%c",&n); fflush(stdin); 
} while (n!='s' && n!='n');

if (n=='s')
{
do
{
    limpiar_pantalla();
printf("\nIngrese una clave sin espacios, que en total contenga 8 caracteres en general con: \n# Una vocal\n# Una consonante\n# Tres numeros\n# Un caracter especial\n\nClave: ");
fflush(stdin);
fgets(new_password, 20, stdin);
limpiar_pantalla();
   nirvana = clave_segura(new_password);
} while (nirvana==0);

    printf("\nIngrese nuevamente la Clave: ");
    fflush(stdin);
    fgets(confirm_password, 20, stdin);

    while (strcmp(new_password, confirm_password)!=0)
    {
    printf("\nLas claves no son iguales, intentelo de nuevo\n");
    pause();
    do
{
limpiar_pantalla();
printf("\nIngrese una clave sin espacios, que en total contenga 8 caracteres en general con: \n# Una vocal\n# Una consonante\n# Tres numeros\n# Un caracter especial\n\nClave: ");
fflush(stdin);
fgets(new_password, 20, stdin);
limpiar_pantalla();
   nirvana = clave_segura(new_password);
} while (nirvana==0);

    printf("\nIngrese nuevamente la clave: ");
    fgets(confirm_password, 20, stdin);

    /*if (strcmp(new_password, confirm_password)!=0)
    {
        printf("\nLas claves no son iguales, intentelo de nuevo\n");
          fflush(stdin);
        pause();
    }*/
    
}

strcpy(password,new_password);
do
{
    limpiar_pantalla();
    printf("--------CUENTA--------\n");
    printf("\nSu usuario es: %s",user);
    printf("\nSu clave es: %s",password);
    printf("\nDesea cambiar su clave por una mas segura? s/n: ");
    scanf("%c",&n);
    n=tolower(n);
} while (n!='s' && n!='n');
limpiar_pantalla();
if (n=='s'){
seed();
strcpy(password, clave);
}
int rps;
    rps = strlen(password);
 if (password[rps - 1] == '\n') {
       password[rps - 1] = '\0';
    }

do
{   
    limpiar_pantalla();
    printf("--------CUENTA--------\n");
    printf("\nSu usuario es: %s",user);
    printf("\nSu nueva clave es: %s\n", password);
    printf("\n----------------------");
    printf("\n\nPrecione la letra [C] para continuar ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
} while (n!='c');

cuenta = fopen("user.txt", "w");
fprintf(cuenta, "%s\n%s", user, password);
fclose(cuenta);
limpiar_pantalla();
printf("\nSe ha cambiado la clave exitosamente!\n");
pause();
}else limpiar_pantalla();
}

//---------------------mostar password---------------------
void mostrar(void){
limpiar_pantalla();
FILE* archivo;
char password[20];
char user[20];
archivo = fopen("user.txt", "r");
fscanf(archivo, "%s\n%s",user, password);
fclose(archivo);
printf("--------CUENTA--------\n");
printf("\nUsuario:  %s",user);
printf("\nPassword: %s",password);
printf("\n\n----------------------");
printf("\n\nPrecione cualquier tecla...");
pause();
limpiar_pantalla();
}

//++++++++cow funtion++++++++
void cow(void){
    limpiar_pantalla();
    system("color 5");
    printf("\n");
    printf("  ^__^\n");
    printf("  (oo)\\_______\n");
    printf("  (__)\\       )\\/\\\n");
    printf("      ||----w |\n");
    printf("      ||     ||\n");
pause();
}

//---------------------BMI menu---------------------
void  menu_bmi(void) {
char opcion;
do
{
system("color 2");
printf("----------------BMI MENU----------------\n");
printf("\n1- Calcular BMI's");
printf("\n2- Agregar BMI");
printf("\n3- Editar BMI");
printf("\n4- Mostrar BMI");
printf("\n5- Buscar");
printf("\n6- Eliminar BMI");
printf("\n7- Salir\n\n");
fflush(stdin);
scanf("%c",&opcion);
fflush(stdin);
limpiar_pantalla();
switch (opcion)
{
    case '1':
    comparar_bmi();
    break;

    case '2':
    agregar_bmi();
    break;

    case '3':
    edit_bmi();
    break;

    case '4':
    mostar_bmi();
    break;

    case '5':
    buscar_bmi();
    break;

    case '6':
    eliminar_bmi();
    break;

    case '7':
    break;

default:
 invalido();
    break;
}

} while (opcion != '7');


}

//---------------------Comparar BMI---------------------
void comparar_bmi(void){
    limpiar_pantalla();
FILE *comp;
FILE *ncomp;
comp = fopen("bmi.txt", "r");
if (comp == NULL)
{
    fclose(comp);
bmi();
}else {
    fclose(comp);
    ncomp = fopen("n.txt", "r");
    if (ncomp==NULL)
    {
    fclose(ncomp);
    limpiar_pantalla();
    printf("Se ha encontrado registros de un BMI pero esta corrupta, elimine el BMI y vuelva a intentarlo");
    pause();
    }else {
    fclose(ncomp);
    char n;
    do {
    limpiar_pantalla();
    printf("Ya existe un BMI, desea reemplazarlo? si dice que si, se eliminara el registro anterior s/n :");
     fflush(stdin); scanf("%c",&n); fflush(stdin);
    n=tolower(n);
    } while (n!='s' && n!='n');
    if (n=='s')
    {
        bmi();
    }else limpiar_pantalla();
    }
}
}

//---------------------BMI---------------------
void bmi(void){
FILE* archivo;
int i=0,spr;
char name[100];
float peso,altura,bmi;
do
{
    limpiar_pantalla();
    printf("Cuantas  personas desea ingresar?: ");
fflush(stdin); scanf("%d",&contglobal); fflush(stdin);
} while (contglobal <= 0 || contglobal > 1000); //

archivo = fopen("bmi.txt", "w");                    //
limpiar_pantalla();
for ( i = 0; i < contglobal; i++)
{
    peso=0; altura=0;
    do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",i+1);
    printf("\nNombre: "); fgets(name, sizeof(name), stdin);
} while (name[0]=='\n');

do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",i+1);
    printf("\nNombre: %s",name);
    printf("Peso: "); fflush(stdin); scanf(" %f", &peso); fflush(stdin);
} while (peso <= 0 || peso > 1000);
    
do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",i+1);
    printf("\nNombre: %s",name);
    printf("Peso: %.2f\n",peso);
    printf("Altura: "); fflush(stdin); scanf(" %f", &altura); fflush(stdin);
} while (altura <= 0 || altura > 1000);

    bmi = calcular_bmi(peso,altura);
    limpiar_pantalla();

    spr = strlen(name);
    if (name[spr - 1] == '\n') {
    name[spr - 1] = '\0';
    }

    strcpy(new[i].name, name);
    new[i].peso = peso;
    new[i].altura = altura;
    new[i].bmi = bmi;

    limpiar_pantalla();
}

for ( i = 0; i < contglobal; i++)
{
    fseek(stdin, 0, SEEK_END);
    fprintf(archivo, "%s\n%f\n%f\n%f\n\n", new[i].name, new[i].peso, new[i].altura, new[i].bmi);
}
fclose(archivo);

FILE* contador;
contador = fopen("n.txt", "wb");     
fprintf(contador, "%d", contglobal);           //
fclose(contador);

printf("\nPrecione cualquier tecla...");
pause();

}

//---------------------Calcular bmi---------------------
float calcular_bmi(float peso, float altura){
float bmi;
bmi= peso/(altura*altura);
return bmi;
}

//---------------------Estadisticas BMI---------------------
void stats_bmi(float bmi){
if (bmi<18.5)
{
    printf("\nEstado: Estas en bajo peso!");
}
if (bmi>=18.5 && bmi<=24.9)
{
    printf("\nEstado: Peso saludable");
}
if (bmi >= 25 && bmi <= 29.9)
{
   printf("\nEstado: Sobre peso!");
}
if (bmi>=30)
{
    printf("\nEstado: Obesidad");
}
}

//---------------------AGREGAR BMI---------------------
void agregar_bmi(void){
FILE *archivo;
FILE *ncomp;
char name[100];
float peso, altura,bmi;
int j;
archivo = fopen("bmi.txt", "r");
limpiar_pantalla();
if (archivo == NULL)
{
    printf("No se ha ingresado ningun BMI");
    fclose(archivo);
    pause();
}else {
    fclose(archivo);
    ncomp = fopen("n.txt", "r");
    if (ncomp == NULL)
    {
    fclose(ncomp);
    limpiar_pantalla();
    printf("Se ha encontrado registros de un BMI pero esta corrupta, elimine el BMI y vuelva a intentarlo");
    pause();
    }else {
    fclose(ncomp);
    FILE *contador;
    char n;
 do{
    limpiar_pantalla();
    printf("Quieres agregar otro BMI? s/n: ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
} while (n!='s' && n!='n');

    do{
if (n == 's')
{
   limpiar_pantalla();
        contador = fopen("n.txt", "rb");
        fscanf(contador, "%d", &contglobal);
        fclose(contador);

peso=0; altura=0;
do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",contglobal+1);
    printf("\nNombre: "); fgets(name, sizeof(name), stdin);
} while (name[0]=='\n');
   do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",contglobal+1);
    printf("\nNombre: %s",name);
    printf("Peso: "); fflush(stdin); scanf(" %f", &peso); fflush(stdin);
} while (peso <= 0 || peso > 1000);
    
do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",contglobal+1);
    printf("\nNombre: %s",name);
    printf("Peso: %.2f\n",peso);
    printf("Altura: "); fflush(stdin); scanf(" %f", &altura); fflush(stdin);
} while (altura <= 0 || altura > 1000);
        
    bmi = calcular_bmi(peso,altura);
    limpiar_pantalla();

contglobal++;
contador = fopen("n.txt", "wb");     
fprintf(contador, "%d", contglobal);           //
fclose(contador);

archivo =fopen("bmi.txt", "a");
fprintf(archivo, "%s%f\n%f\n%f\n\n", name, peso, altura, bmi);
fclose(archivo);
do{
    limpiar_pantalla();
    printf("Quieres agregar otro BMI? s/n: ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
    limpiar_pantalla();
} while (n!='s' && n!='n');
}// if

    }while (n!='n');
    limpiar_pantalla();
    }
}
}

//---------------------Editar BMI---------------------
void edit_bmi(void){
FILE *archivo;
FILE *ncomp;
archivo = fopen("bmi.txt", "r");
limpiar_pantalla();
if (archivo == NULL)
{
    printf("No se ha ingresado ningun BMI");
    fclose(archivo);
    pause();
}else {
    fclose(archivo);
    ncomp = fopen("n.txt", "r");
    if (ncomp==NULL)
    {
    fclose(ncomp);
    limpiar_pantalla();
    printf("Se ha encontrado registros de un BMI pero esta corrupta, elimine el BMI y vuelva a intentarlo");
    pause();
    }else {
    fclose(ncomp);
    FILE *contador;
    archivo = fopen("bmi.txt", "r");
    char buscar[100];
    int spr,cont=0,i=0;
    char n;
        contador = fopen("n.txt", "rb");
        fscanf(contador, "%d", &contglobal);
        fclose(contador);

        fseek(archivo, 0, SEEK_SET);
for (int j = 0; j < contglobal; j++)
{
    
    fscanf(archivo, "%s %f %f %f\n\n", new[j].name, &new[j].peso, &new[j].altura, &new[j].bmi);
}
fclose(archivo);

 printf("Ingrese el nombre a buscar: ");
 fgets(buscar, sizeof(buscar), stdin);
 spr = strlen(buscar);
 if (buscar[spr - 1] == '\n') {
       buscar[spr - 1] = '\0';
    }
 
for ( i = 0; i < contglobal; i++)
{
        if(strcmp(new[i].name, buscar) == 0){
    
    do
    {
        limpiar_pantalla();
        printf("----------------EDITAR BMI----------------\n\n");
     printf("---Persona [%d]---\n",i+1);
     printf("Nombre: %s",  new[i].name);
     printf("\nPeso: %.2f Kg",  new[i].peso);
     printf("\nAltura: %.2f M",  new[i].altura);
     printf("\nBMI: %.2f",  new[i].bmi);
     stats_bmi(new[i].bmi);
     printf("\n-----------------");
     cont++;
        printf("\n\nEstas seguro que deseas editar la informacion en la posicion [%d]? s/n: ",i+1);
        fflush(stdin); scanf("%c",&n); fflush(stdin);
        n=tolower(n);
    } while (n!='s' && n!='n');

    if (n=='s')
    {
    char name[100];
    float peso=0, altura=0,bmi=0;
    do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",i+1);
    printf("\nNombre: "); fgets(name, sizeof(name), stdin);
} while (name[0]=='\n');
   do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",i+1);
    printf("\nNombre: %s",name);
    printf("Peso: "); fflush(stdin); scanf(" %f", &peso); fflush(stdin);
} while (peso <= 0 || peso > 1000);
    
do
{
    limpiar_pantalla();
    printf("----Persona numero [%d]----",i+1);
    printf("\nNombre: %s",name);
    printf("Peso: %.2f\n",peso);
    printf("Altura: "); fflush(stdin); scanf(" %f", &altura); fflush(stdin);
} while (altura <= 0 || altura > 1000);
    bmi = calcular_bmi(peso,altura);
    limpiar_pantalla();

    spr = strlen(name);
    if (name[spr - 1] == '\n') {
    name[spr - 1] = '\0';
    }

    strcpy(new[i].name, name);
    new[i].peso = peso;
    new[i].altura = altura;
    new[i].bmi = bmi;

    archivo = fopen("bmi.txt", "w");
    for ( int k = 0; k < contglobal; k++)
    {
    fseek(archivo, 0, SEEK_END);
    fprintf(archivo, "%s\n%f\n%f\n%f\n\n", new[k].name, new[k].peso, new[k].altura, new[k].bmi);
    }
    fclose(archivo);
    

    printf("\nSiguiente");
    pause();
    }
    limpiar_pantalla();

    }

}
if (cont==0)
 {
    limpiar_pantalla();
    printf("No se encontro la persona a buscar\n");
    pause();
 }
 }
}//else
}

//---------------------Mostar bmi---------------------
void mostar_bmi(void){
    limpiar_pantalla();
    FILE*archivo;
    FILE *ncomp;
    int j=0;
    int i=0;
    archivo= fopen("bmi.txt","r");
    if (archivo == NULL)
    {
        fclose(archivo);
        printf("No se ha ingresado ningun BMI");
        pause();
        limpiar_pantalla();
    }else { 
        fclose(archivo);
        ncomp = fopen("n.txt", "r");
        if (ncomp==NULL)
        {
        fclose(ncomp);
        limpiar_pantalla();
        printf("Se ha encontrado registros de un BMI pero esta corrupta, elimine el BMI y vuelva a intentarlo");
        pause();
        }else {
        fclose(ncomp);
        FILE*contador;
        contador = fopen("n.txt", "rb");
        fscanf(contador, "%d", &contglobal);
        fclose(contador);

archivo= fopen("bmi.txt","r");
fseek(archivo, 0, SEEK_SET);
for ( j = 0; j < contglobal; j++)
{
    fscanf(archivo, "%s %f %f %f\n", new[j].name, &new[j].peso, &new[j].altura, &new[j].bmi);
}
fclose(archivo);

    for ( i = 0; i < contglobal; i++)
    {
        printf("---Persona [%d]---\n",i+1);
        printf("Nombre: %s",  new[i].name);
        printf("\nPeso: %.2f Kg",  new[i].peso);
        printf("\nAltura: %.2f M",  new[i].altura);
        printf("\nBMI: %.2f",  new[i].bmi);
        stats_bmi(new[i].bmi);
        printf("\n-----------------\n");
        printf("\nSiguiente");
pause();
limpiar_pantalla();
    }
    }
    }
}

//---------------------Buscar BMI---------------------
void buscar_bmi(void){
limpiar_pantalla();
    FILE*archivo;
    FILE*ncomp;
    int j=0;
    int i=0;
    archivo= fopen("bmi.txt","r");
    if (archivo == NULL)
    {
        fclose(archivo);
        printf("No se ha ingresado ningun BMI");
        pause();
        limpiar_pantalla();
    }else { 
        fclose(archivo);
        ncomp=fopen("n.txt", "r");
        if (ncomp==NULL)
        {
        fclose(ncomp);
        limpiar_pantalla();
        printf("Se ha encontrado registros de un BMI pero esta corrupta, elimine el BMI y vuelva a intentarlo");
        pause();
        }else {
        fclose(ncomp);
        FILE*contador;
        contador = fopen("n.txt", "rb");
        fscanf(contador, "%d", &contglobal);
        fclose(contador);

archivo= fopen("bmi.txt","r");
fseek(archivo, 0, SEEK_SET);
for ( j = 0; j < contglobal; j++)
{
    fscanf(archivo, "%s %f %f %f\n", new[j].name, &new[j].peso, &new[j].altura, &new[j].bmi);
}
fclose(archivo);

char buscar[30];
int i=0;
int spr;
limpiar_pantalla();
 printf("------BUSCAR BMI------\n\n");
 printf("Ingrese el nombre a buscar: ");
 fgets(buscar, sizeof(buscar), stdin);
 i=0;
  int cont=0;
 spr = strlen(buscar);
 if (buscar[spr - 1] == '\n') {
       buscar[spr - 1] = '\0';
    }
    limpiar_pantalla();

    for ( i = 0; i < contglobal; i++)
    {
        if(strcmp(new[i].name, buscar) == 0){
     printf("---Persona [%d]---\n",i+1);
     printf("Nombre: %s",  new[i].name);
     printf("\nPeso: %.2f Kg",  new[i].peso);
     printf("\nAltura: %.2f M",  new[i].altura);
     printf("\nBMI: %.2f",  new[i].bmi);
     stats_bmi(new[i].bmi);
     printf("\n-----------------\n\n");
    cont++;
    }
}
if (cont==0)
 {
    printf("No se encontro la persona a buscar\n");
 }
 pause();
 limpiar_pantalla();
 fclose(archivo);
}
}
}

//---------------------Eliminar BMI---------------------
void eliminar_bmi(){
    FILE *archivo;
    archivo = fopen("bmi.txt","r");
    if (archivo == NULL)
    {
        printf("No se ha ingresado ningun BMI");
        pause();
        fclose(archivo);
    }else {
        fclose(archivo);
        char n;
 do
{
    limpiar_pantalla();
    
    printf("Esta seguro de que desea elimanar el BMI? s/n: ");
    fflush(stdin); scanf("%c",&n); fflush(stdin);
    n=tolower(n);
} while (n!='s' && n!='n');
limpiar_pantalla();
   
    switch (n)
    {
    case 's':
remove("bmi.txt");
remove("n.txt");

    printf("Los datos se han eliminado correctamente");
    pause();
    limpiar_pantalla();
        break;
    
    case 'n':
        break;
    }
}
}

//========limpiar pantalla========
void limpiar_pantalla(void)
{
    #ifdef _WIN32
    system("cls");
    #elif __unix__
    system("clear");
    #endif
}

//========pausar pantalla========
void pause(void){
    char sad[100];
fgets(sad, sizeof(sad), stdin);
limpiar_pantalla();
}

//========mensaje de invalido========
void invalido(void){
    limpiar_pantalla();
printf("Invalido, intentelo de nuevo");
pause();
limpiar_pantalla();
}

//========tiempo de castigo========
void wait(void){
for (int i = 0; i < 30; i++)
{
    limpiar_pantalla();
   printf("Muchos intentos, espere %d segundos",30-(i));
   sleep(1);
   limpiar_pantalla();
   fflush(stdin);
}

}

//========Precione c==========
void precionac(void) {
    char n;
    do
{   

    printf("Precione la letra [C] para continuar ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
    limpiar_pantalla();
} while (n!='c');
limpiar_pantalla();
}

//========Historial========
void historial(void){
time_t date = time(NULL);
FILE *historial;
historial = fopen("history.txt", "a");
if (historial == NULL)
{
    fprintf(historial, "%s", ctime(&date));
    fclose(historial);
}else {
    fclose(historial);
    FILE *history;
    fseek(stdin, 0, SEEK_END);
    history = fopen("history.txt", "a");
    fprintf(history, "%s", ctime(&date));
    fclose(history);
}
}

//========COW MENU========
void cow_menu(void){
limpiar_pantalla();
system("color D");
char n;
do
{
    printf("----------------COW MENU----------------\n");
    printf("\n1- ELIMINAR CUENTA");
    printf("\n2- ELIMINAR HISTORIAL");
    printf("\n3- KAMIKAZE");
    printf("\n4- Salir\n\n");
fflush(stdin);
scanf("%c",&n);
fflush(stdin);
    limpiar_pantalla();

switch (n)
{
case '1':
do
{
    limpiar_pantalla();
    printf("Esta seguro de que desea eliminar la cuenta? s/n: ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
} while (n!='s' && n!='n');
limpiar_pantalla();
   
   if (n=='s')
   {
    remove("user.txt");
    printf("Se eliminaron correctamente los registros del la cuenta");
    pause();
    limpiar_pantalla();
   }
   break;

case '2':
do
{
    limpiar_pantalla();
    printf("Esta seguro de que desea eliminar el historial? s/n: ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
} while (n!='s' && n!='n');
limpiar_pantalla();
   
   if (n=='s')
   {
    remove("history.txt");
    printf("Se eliminaron correctamente los registros del historial");
    pause();
    limpiar_pantalla();
   }
    break;

case '3':
do
{
limpiar_pantalla();
    printf("Esta seguro de que desea eliminar toda la informacion? s/n: ");
    fflush(stdin);
    scanf("%c",&n);
    fflush(stdin);
    n=tolower(n);
} while (n!='s' && n!='n');
limpiar_pantalla();
   
   if (n=='s')
   {
    remove("history.txt");
    remove("bmi.txt");
    remove("n.txt");
    remove("user.txt");
    
    cow();
    limpiar_pantalla();
   }
    break;

case '4':
    break;

default:
invalido();
    break;
}

} while (n!='4');

}

//========ADMIN MODE========
void admin(void){
char god_mode[]= "For The Covenant";
char confirm_clave[100];
int spr;
limpiar_pantalla();
system("color 4");
fgets(confirm_clave, sizeof(confirm_clave), stdin);

spr = strlen(confirm_clave);
 if (confirm_clave[spr - 1] == '\n') {
       confirm_clave[spr - 1] = '\0';
    }
    if (strcmp(god_mode, confirm_clave) == 0) {
cow_menu();
}
}

//hash
//att arbiter_289

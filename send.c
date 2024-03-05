#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void comparar();
void accont();
int clave_segura(char password[20]);
void login();
void menu();
void tools();
void mostrar();
void cow();
void bmi();
void mostar_bmi();
float calcular_bmi(float peso, float altura);
char texto_bmi(float bmi);

int main (){
    comparar();   
    menu();
return 0;
}

//Verificar archivo
void comparar(){
FILE* archivo;
archivo = fopen("user.txt", "r");
if (archivo == NULL){
accont();
} else login();
}

//---------------------Creacion de cuenta---------------------
void accont(void) {
    
    FILE *archivo;
char password[20];
char password117[21];
char user[20];
int vocal=0,cons=0,todo,num=0,space=0;
int i=0;
int unknow=0;
char n;
int nirvana=0; //lo uso para finalizar el regristro de la contraseña;

//variables de la contraseña aleatoria;

int limit = 7;
char cadena[8];
char caracteres[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";  //Queria hacer que existieran 3 semillas aleatorias y asi la probabilidad de numeros seria igual de probable que la de las letras mayusculas y minusculas pero no se como usar bien el strcat con vevtores , o sea si se sumar los vectores con palabras desperdigadas pero no con vectores :(;

//------inicio del programa -------
printf("\n--------Creacion de cuenta--------\n");
printf("\nIngrese un usuario: ");
fflush(stdin);
fgets(user,20, stdin);

do
{
printf("\nIngrese una contraseña con minimo 1 vocal, 1 consonante ,3 numeros , 1 caracter especial , sin espacios y que en total contenga 8 caracteres en general: ");
fflush(stdin);
fgets(password, 20, stdin);
   nirvana = clave_segura(password);
} while (nirvana==0);

printf("\n\nSu usuario es: %s",user);
printf("Su contraseña es: %s",password);

do
{
    printf("\n\nDesea cambiar su contraseña por una mas segura? s/n: ");
    scanf("%c",&n);
    n=tolower(n);
} while (n!='s' && n!='n');
switch (n)
{
case 's':
    printf("\nGenerando una nueva contraeña...\n");
    srand(time(NULL));

    for (int i = 0; i < limit; i++) {
        int random = rand() % (sizeof(caracteres) - 1);
        cadena[i] = caracteres[random];
    }
    cadena[8] = '\0';
    strcpy(password,cadena);

    printf("Su usuario es: %s",user);
    printf("\nSu nueva contraseña es: %s", password);
    break;

default:
    break;
}
archivo = fopen("user.txt", "w");
fprintf(archivo, "%s\n%s\n", user, password);
fclose(archivo);

login();

}

//---------------------clave segura----------------------
int clave_segura(char password[20]){
//
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
printf("\n%s",password);
printf("Consonantes: %d",cons);
printf("\nVocales: %d",vocal);
printf("\nNumeros: %d",num);
printf("\nEspacios: %d",space);
printf("\nCaracteres especiales: %d\n",unknow);
printf("\nTotal: %d\n",todo);

int nirvana=0;
if (vocal>=1 && cons>=1  && num>=3 && space==0 && unknow>=1 && todo>=8)
{
    printf("\n----Contraseña aceptable----\n");
    nirvana++;
 return nirvana;
}else {printf("\n----Contraeña no aceptable----\n");
 return nirvana;
}
}

//---------------------funcion de loggeo---------------------
void login(void){
char confirm_password[20];
char confirm_user[20];
char password[20];
char password117[21];
char user[20];
FILE* archivo;
archivo = fopen("user.txt", "r");
fscanf(archivo, "%s\n%s", &user[0], &password[0]);
fclose(archivo);

  printf("\n----Loggeo de cuenta----\n");

do
{
    printf("\nUsuario: ");
fflush(stdin);
scanf("%s",&confirm_user[0]);
fflush(stdin);

printf("\nContraseña: ");
fflush(stdin);
scanf("%s",&confirm_password[0]);
fflush(stdin);

if (strcmp(password, confirm_password)==0 && strcmp(user,confirm_user)==0)
{
    printf("\n---------Ha logrado acceder a la cuenta!---------\n");
}else printf("\nEl usuario o la contraseña son incorrectos, intentelo de nuevo\n");

} while (strcmp(password, confirm_password)!=0 || strcmp(user,confirm_user)!=0);
}

//---------------------Menu de cuenta---------------------
void tools(void){
FILE* login;
FILE* cuenta;
char user[20];
char password[20];
char new_user[20];
char new_password[20];
char confirm_password[20];
char entrada[2];
char resp;
int nirvana=0;

login = fopen("user.txt", "r");
 fscanf(login, "%s\n%s", user, password);
fclose(login);

do
{
    printf("\n----CONFIGURACION DE CUENTA----");
    printf("\n1- Cambiar usuario");
    printf("\n2- Cambiar password");
    printf("\n3- Mostar usuario y clave");
    printf("\n4- Salir de configuracion\n");
fflush(stdin);
//scanf("%c",&resp);
fgets(entrada, sizeof(entrada), stdin);
resp=strtol(entrada, NULL, 10);
fflush(stdin);
switch (resp)
{
case 1:
printf("\n\nSu viejo usuario es: %s",user);
    printf("\nIngrese su nuevo usuario: ");
    fflush(stdin);
    fgets(new_user, 20, stdin);
    strcpy(user, new_user);

cuenta = fopen("user.txt", "w");
fprintf(cuenta, "%s\n%s\n", user, password);
fclose(cuenta);
printf("\nSe ha cambiado el usuario exitosamente!\n\n");
    break;

case 2:
printf("\n\nSu viejo password es: %s\n",password);

do
{
printf("\nIngrese una contraseña con minimo 1 vocal, 1 consonante ,3 numeros , 1 caracter especial , sin espacios y que en total contenga 8 caracteres en general: ");
fflush(stdin);
fgets(new_password, 20, stdin);
   nirvana = clave_segura(new_password);
} while (nirvana==0);

    printf("\nIngrese nuevamente la contraseña:");
    fflush(stdin);
    fgets(confirm_password, 20, stdin);

    while (strcmp(new_password, confirm_password)!=0) 
    {
    printf("\nLas contraseñas no son iguales, intentelo de nuevo\n");
    
    do
{
printf("\nIngrese una contraseña con minimo 1 vocal, 1 consonante ,3 numeros , 1 caracter especial , sin espacios y que en total contenga 8 caracteres en general: ");
fflush(stdin);
fgets(new_password, 20, stdin);
   nirvana = clave_segura(new_password);
} while (nirvana==0);

    printf("Ingrese nuevamente el password:");
    fgets(confirm_password, 20, stdin);
}
strcpy(password,new_password);
cuenta = fopen("user.txt", "w");
fprintf(cuenta, "%s\n%s\n", user, password);
fclose(cuenta);
printf("\nSe ha cambiado la clave exitosamente!\n\n");
    break;

    case 3:
    mostrar();
    break;

    case 4:
    break;

default:
 printf("\nOpcion invalida, intentelo de nuevo\n");
    break;
}

} while (resp != 4);

}

//---------------------mostar password---------------------
void mostrar(void){
FILE* archivo;
char password[20];
char user[20];
archivo = fopen("user.txt", "r");
fscanf(archivo, "%s\n%s",user, password);
fclose(archivo);
printf("\nusuario:  %s",user);
printf("\npassword: %s\n",password);
}

//++++++++cow funtion++++++++
void cow(void){
    printf("\n");
    printf("  ^__^\n");
    printf("  (oo)\\_______\n");
    printf("  (__)\\       )\\/\\\n");
    printf("      ||----w |\n");
    printf("      ||     ||\n");
}

//---------------------funcion de menu---------------------
void menu(){
char entrada[2];
int resp;
do
{
fflush(stdin);
printf("\n\n--------MENU--------\n");
printf("1- Ajustes de cuenta");
printf("\n2- Calcular BMI");
printf("\n3- Mostrar bmi");
printf("\n4- Salir de la cuenta");
printf("\n5- Salir\n\n");
fgets(entrada, sizeof(entrada), stdin);
resp= strtol(entrada, NULL,10);
fflush(stdin);
switch (resp)
{
 case 1:
    tools();
    break;

case 2:
    bmi();
    break;

    case 3:
    mostar_bmi();
    break;

case 4:
login();
break;

 case 5:
    printf("\nExit\n");
    break;

case 7:
    cow();
    break;

default:
printf("\n----Invalido----\n");
    break;
}
fflush(stdin);
} while (resp !=5);


}

//---------------------BMI---------------------
void bmi(void){
float peso,altura,bmi;
char stats;
FILE* file_bmi;
   printf("\n----BMI----\n");
printf("\nIngrese su peso: ");
scanf("%f",&peso);

printf("\nIngrese su altura: ");
scanf("%f",&altura);

//bmi=peso/(altura*altura);
bmi=calcular_bmi(peso,altura);

printf("\nPeso: %.2fKg\nAltura : %.2fm",peso,altura);
printf("\nTu BMI es de: %.2f",bmi);

file_bmi = fopen("bmi.txt", "w");
fprintf(file_bmi, "%f\n%f\n%f", peso, altura, bmi);
fclose(file_bmi);

if (bmi<18.5)
{
    printf("\nEstas en bajo peso!\n");
}
if (bmi>=18.5 && bmi<=24.9)
{
    printf("\nPeso saludable\n");
}
if (bmi >= 25 && bmi <= 29.9)
{
   printf("\nSobre peso!\n");
}
if (bmi>=30)
{
    printf("\nObesidad\n");
}

}

//---------------------Calcular bmi---------------------
float calcular_bmi(float peso, float altura){
float bmi;
bmi= peso/(altura*altura);
return bmi;
}

//---------------------Mostar bmi---------------------
void mostar_bmi(){
float peso=0,altura=0,bmi=0;
char stats[50];
FILE* archivo;
fflush(stdin);
archivo = fopen("bmi.txt","r");
if (archivo==NULL){
printf("\nNo se ha ingresado aun el bmi, precione 2 para ingresar el BMI");
}else if(archivo!=NULL){
    fscanf(archivo, "%f\n", &peso);
    fscanf(archivo, "%f\n", &altura);
    fscanf(archivo, "%f", &bmi);
    printf("\n------BMI------\n");
printf("%.2fKg\n",peso);
printf("%.2fM\n",altura);
printf("%.2f\n",bmi);
if (bmi<18.5)
{
    printf("Estas en bajo peso!\n");
}
if (bmi>=18.5 && bmi<=24.9)
{
    printf("Peso saludable\n");
}
if (bmi >= 25 && bmi <= 29.9)
{
   printf("Sobre peso!\n");
}
if (bmi>=30)
{
    printf("Obesidad\n");
}
fclose(archivo);
}
}

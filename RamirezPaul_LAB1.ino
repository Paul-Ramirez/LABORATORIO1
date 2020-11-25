/*
 * LABORATORIO I
 * CAPITULO II: PUERTOS DIGITALES Y COMUNICACION SERIAL
 * AUTOR: Ramirez Paul
 * FECHA: 25/11/2020
 */
#include <Keypad.h>
#include <LiquidCrystal.h>

//Pines para la pantalla lcd
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

//Configuracion para keypad
const byte filas = 4; //numero de filas del teclado
const byte cols= 4;   //Numero de columnas del teclado
char keys[filas][cols] = {
  {'7','8','9','a'},
  {'4','5','6','c'},
  {'1','2','3','j'},
  {'*','0','r','p'}
};
//pines de arduino utilizados para keypad
byte pinFilas[filas]={13,12,11,10};
byte pincols[cols]={9,8,7,6};

//Creación del objeto de tipo keypad
Keypad teclado = Keypad(makeKeymap(keys),pinFilas,pincols,filas,cols);

//Declaración de variables
char tecla;
char pass[9];
char pass1[9]="ca900813";
String emp1 = "BIENVENIDO - CARLOS ARIAS";
char pass2[9]="aj881112";
String emp2 = "BIENVENIDO - ANDRES JUAREZ";
char pass3[9]="ja890109";
String emp3 = "BIENVENIDO - JAVIER ANDRADA";
char pass4[9]="pr980301";
String emp4 = "BIENVENIDO - PAUL RAMIREZ";
byte m=0;
int i=0;
int j=0;
const int btn =5;


void setup() {
  pinMode(btn,INPUT);
  //iniciliza comunicacion serial
  Serial.begin(9600);
  Serial.println("---------Sistema de Seguridad----------");
  Serial.println(" ");
  Serial.println("Ingrese Contraseña:");
  //inicializa lcd
  lcd.begin(16,2);
}

void loop() {
  
  tecla = teclado.getKey();
  //Presionar la tecla del keypad y obtener el caracter
  if(tecla){
    pass[m]=tecla;
    m++;
    Serial.print(tecla);
  }
  mostrar();
  //comparacion del tamaño de la contraseña 
  if(m==8){
    //Comparacion de contraseñas de acceso
    if(!strcmp(pass1,pass) || !strcmp(pass2,pass) || !strcmp(pass3,pass) || !strcmp(pass4,pass)){
      Serial.println(" Contraseña Correcta!");
      
    //Impresion usuario ingresado numero 1
      if(!strcmp(pass,pass1)){
        lcd.setCursor(5,0);
        lcd.print(emp1);
        for(i=0;i<30;i++){//Ciclo for para recorrer el texto
          lcd.scrollDisplayLeft();
          delay(200);
          
        }
        
        lcd.clear();
        
      }
    //Impresion usuario ingresado numero 2
      if(!strcmp(pass,pass2)){
        lcd.setCursor(5,0);
        lcd.print(emp2);
        for(i=0;i<30;i++){//Ciclo for para recorrer el texto
          lcd.scrollDisplayLeft();
          delay(200);
        }
        lcd.clear();
        
      }
    //Impresion usuario ingresado numero 3
      if(!strcmp(pass,pass3)){
        lcd.setCursor(5,0);
        lcd.print(emp3);
        for(i=0;i<30;i++){//Ciclo for para recorrer el texto
          lcd.scrollDisplayLeft();
          delay(200);
       }
       lcd.clear();
       
      }
    //Impresion usuario ingresado numero 4
      if(!strcmp(pass,pass4)){
        lcd.setCursor(5,0);
        lcd.print(emp4);
        for(i=0;i<30;i++){//Ciclo for para recorrer el texto
          lcd.scrollDisplayLeft();
          delay(200);
        }
        lcd.clear();
        
      }
      Serial.println(" ");
      Serial.println("Ingrese contraseña:");
      m=0;

    }else{
     
      Serial.println(" Contraseña Incorrecta!");
      
      Serial.println(" ");
      m=0;
      Serial.println("Vuelva a ingresar contraseña:");
      
    }
    
  }
  
  
}


void mostrar(){
  if(!strcmp(pass,pass1) && digitalRead(btn)==LOW ){
      delay(300);
      Serial.println(" ");
      Serial.println("---Usuario Ingresado--");
      Serial.println("Carlos Arias - Ingresado");
      Serial.println("Ramirez Paul - No ingresado");
      Serial.println("Andres Juarez - No ingresado");
      Serial.println("Javier Andrade - No ingresado");
      Serial.println(" ");
      Serial.println("Ingrese contraseña:");
    
  }
    
  if(!strcmp(pass,pass4) && digitalRead(btn)==LOW ){
      delay(300);
      Serial.println(" ");
      Serial.println("---Usuario Ingresado--");
      Serial.println("Carlos Arias - No Ingresado");
      Serial.println("Ramirez Paul - Ingresado");
      Serial.println("Andres Juarez - No ingresado");
      Serial.println("Javier Andrade - No ingresado");
      Serial.println(" ");
      Serial.println("Ingrese contraseña:");
    }
    if(!strcmp(pass,pass3) && digitalRead(btn)==LOW ){
      delay(300);
      Serial.println(" ");
      Serial.println("---Usuario Ingresado--");
      Serial.println("Carlos Arias - No Ingresado");
      Serial.println("Ramirez Paul - No ingresado");
      Serial.println("Andres Juarez - Ingresado");
      Serial.println("Javier Andrade - No ingresado");
      Serial.println(" ");
      Serial.println("Ingrese contraseña:");
    }
    if(!strcmp(pass,pass2) && digitalRead(btn)==LOW ){
      delay(300);
      Serial.println(" ");
      Serial.println("---Usuario Ingresado--");
      Serial.println("Carlos Arias - No ingresado");
      Serial.println("Ramirez Paul - No ingresado");
      Serial.println("Andres Juarez - No ingresado");
      Serial.println("Javier Andrade - Ingresado");
      Serial.println(" ");
      Serial.println("Ingrese contraseña:");
    }
  }    
  

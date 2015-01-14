#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
void pintar(int x, int y, int color);
void pintarmenu(int x,int y);
float indice (int x,int y,float p, float e);
char namr (int x, int y);
int genr (int x, int y);
int edd (int x, int y);
float estr (int x,int y);
float pso (int x, int y);
void indicel (int x,int y, float i);
int nact (int x,int y);
void gasto (int x, int y, int n, float p, int g, int e);
void dieta (int x, int y, float m);
void fin (int x, int y);
void creditos(int x, int y);
void psmenu(int x,int y);
void bien(int x, int y,int color);
int alea(void);
void con(int x, int y, int a);
void main() 
{
	char nombre[30];
	char sonido [100]={" "};
	float est, peso, masac, gas;
	int opcion, edad, gener, niv, opd, alo;
	textbackground(BLUE);
	clrscr();
	bien(14,7,WHITE);
	strcpy(sonido,"soundtrackmenu.wav"); 
	if(strcmp(sonido," ")!=0)
	{          
		PlaySound(sonido, NULL, SND_FILENAME);;           
	}
	do
	{		
	    clrscr();	    
		pintar(25,2,WHITE);
		pintarmenu(25,10);
		scanf("%i",&opcion);
		switch (opcion)
		{
		case 1: clrscr();
				//nombre=namr(25,10);
				gener=genr(25,10);
				edad=edd(25,10);
				est=estr(25,10);
				peso=pso(25,10);
				masac=indice(25,10,peso,est);
				indicel(25,10,masac);
				niv=nact(25,10);
				gasto(25,10,niv,peso,gener,edad);	
				dieta(17,10,masac);
				fin(25,20);
          break;
  		case 2: clrscr();
  				psmenu(25,10);
  				scanf("%i",&opd);
  				switch (opd)
  				{
  				case 1: clrscr();
  						est=estr(25,10);
						peso=pso(25,10);
						masac=indice(25,10,peso,est);
						indicel(25,10,masac);
						while( !kbhit() );
   						cprintf("");
   						getch();
				break;
  				case 2:	clrscr();
  						gener=genr(25,10);
  						edad=edd(25,10);
  						peso=pso(25,8);
  						niv=nact(25,13);
  						gasto(25,15,niv,peso,gener,edad);
  						while( !kbhit() );
   						cprintf("");
   						getch();
  				break;
  				case 3: clrscr();
  						alo=alea();
  						con(17,10,alo);
  				break;
  				default:cprintf("salir");
  				break;	
  				}	
          break;
        case 3: clrscr();
        		creditos(25,10);
        		
          break;
  		default:cprintf("salir");
          break; 
		}
		
	}while(opcion<4);

}

void pintar(int x, int y,int color)
{
	textcolor(color);
	gotoxy(x,y);  cprintf("  -----------------------  ");
	gotoxy(x,y+1);cprintf(" | ___      ____________| ");
	gotoxy(x,y+2);cprintf(" |    \\    /            | ");
	gotoxy(x,y+3);cprintf(" |     \\  /  CALORIE    | ");
	gotoxy(x,y+4);cprintf(" |      \\/              | ");
	gotoxy(x,y+5);cprintf("  -----------------------\n");
}
void pintarmenu (int x,int y)
{
	gotoxy(x,y);cprintf("MENU");
	gotoxy(x,y+1);cprintf("1-INICIAR UCALORIES");
	gotoxy(x,y+2);cprintf("2-OPCIONES");
	gotoxy(x,y+3);cprintf("3-CREDITOS");
	gotoxy(x,y+4);cprintf("4-SALIR");
	gotoxy(x,y+5);cprintf("SELECCIONE UNA OPCION(1,2,3,4)\n");
}
char namr (int x, int y)
{
	char nom[30];
	gotoxy(x,y);cprintf("Dame tu nombre");
  	gotoxy(x,y+2);gets(nom);
  	return(nom[30]);
}
int genr (int x, int y)
{
	int gen;
	gotoxy(x,y+3);cprintf("Indique su genero 1.-Hombre 2.- Mujer");
  	gotoxy(x,y+4);scanf("%i",&gen);	
  	return(gen);
}
int edd (int x, int y)
{
	int edad;
	gotoxy(x,y+5);cprintf("Dame tu edad");
	gotoxy(x,y+6);scanf("%i",&edad);
	return(edad);
}
float estr (int x,int y)
{
	float e;
	gotoxy(x,y+7);cprintf("Dame tu estatura en metros");
	gotoxy(x,y+8);scanf("%f",&e);
	return(e);
}
float pso (int x, int y)
{
	float w;
	gotoxy(x,y+9);cprintf("Dame tu peso en kilogramos");
	gotoxy(x,y+10);scanf("%f",&w);
	return(w);
}
float indice (int x,int y,float p, float e)
{
 	float masac;
 	clrscr();
 	masac=p/(e*e);
 	gotoxy(x,y+1);cprintf("Su indice de masa corporal es %f",masac);
 	return(masac);	
}
void indicel (int x,int y, float i)
{
	float masac;
	int opcion;
	masac=i;
	if (masac<18.50)
	{
	gotoxy(x,y+2);cprintf("Su indice de masa corporal indica Bajo Peso");
	}
	else
	if ((masac>18.51)&&(masac<24.99))
	{
	gotoxy(x,y+3);cprintf("Su indice de masa corporal es Normal");
	}
	else
	if ((masac>25)&&(masac<29.99))
	{
	gotoxy(x,y+4);cprintf("Su indice de masa corporal indica Sobrepeso");
	}
	else
	if (masac>30)
	{
	gotoxy(x,y+5);cprintf("Su indice de masa corporal indica Obesidad");
	}
}
int nact (int x,int y)
{
	int nivel;
 	gotoxy(x,y+6);cprintf("Como definir�a su nivel de actividad fisica");
 	gotoxy(x,y+7);cprintf("1.- Inexistente, 2.-Ligera, 3.-Moderada, 4.-Intensa");
 	scanf("%i",&nivel);
 	return(nivel);
}
void gasto (int x, int y, int n, float p, int g, int e)
{
	int lvl, peso, genr, edad;
	float calc;
	lvl=n;
	peso=p;
	genr=g;
	edad=e;
	if (lvl==1)
	{
		if(genr==1)
		{
			if((edad>17)&&(edad<28))
			{
				calc=(694+((peso)*15));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(785+((peso)*14));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(876+((peso)*12));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(733+((peso)*12));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>60)
			{
				calc=(590+((peso)*11));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			
		}
		else
		if(genr==2)
		{
			if((edad>18)&&(edad<28))
			{
				calc=(488+((peso)*15));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(668+((peso)*12));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(849+((peso)*8));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(755+((peso)*8));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>61)
			{
				calc=(661+((peso)*9));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
		}
	}
	else
	if (lvl==2)
	{
		if(genr==1)
		{
			if((edad>18)&&(edad<28))
			{
				calc=(993+((peso)*22));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(1123+((peso)*19));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(1253+((peso)*17));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(733+((peso)*17));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>61)
			{
				calc=(590+((peso)*17));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}		
		}
		else
		if(genr==2)
		{
			if((edad>18)&&(edad<28))
			{
				calc=(698+((peso)*21));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(956+((peso)*16));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(1214+((peso)*11));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(1079+((peso)*13));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>61)
			{
				calc=(945+((peso)*13));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
		}
	}
	else
	if (lvl==3)
	{
		if(genr==1)
		{
			if((edad>18)&&(edad<28))
			{
				calc=(1047+((peso)*23));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(1184+((peso)*20));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(1321+((peso)*17));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(1105+((peso)*17));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>61)
			{
				calc=(889+((peso)*18));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}		
		}
		else
		if(genr==2)
		{
			if((edad>18)&&(edad<28))
			{
				calc=(736+((peso)*22));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(1007+((peso)*18));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(1279+((peso)*12));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(1137+((peso)*13));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>61)
			{
				calc=(996+((peso)*13));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
		}
	}
	else
	if (lvl==4)
		{
		if(genr==1)
		{
			if((edad>18)&&(edad<28))
			{
				calc=(1215+((peso)*26));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(1374+((peso)*23));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(1533+((peso)*20));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(1282+((peso)*21));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>61)
			{
				calc=(1032+((peso)*20));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}		
		}
		else
		if(genr==2)
		{
			if((edad>18)&&(edad<28))
			{
				calc=(854+((peso)*26));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>28)&&(edad<40))
			{
				calc=(1169+((peso)*20));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);
			}
			else
			if((edad>40)&&(edad<50))
			{
				calc=(1484+((peso)*15));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);	
			}
			else
			if((edad>50)&&(edad<60))
			{
				calc=(1320+((peso)*15));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);			
			}
			else
			if(edad>61)
			{
				calc=(1156+((peso)*16));
				gotoxy(x,y+8);cprintf("Hoy a gastado %f calorias",calc);		
			}
		}
	}	
}
void dieta (int x, int y, float m)
{
	float masac;
	masac=m;
	if (masac<18.49)
	{
		gotoxy(x,y+9);cprintf("Usted tiene problemas con bajo peso.");	
		gotoxy(x,y+10);cprintf("Las calor�as deben aumentarse a expensas de: la cantidad y calidad de alimentos ingeridos, el aumento de los hidratos de carbono y en menor medida de las grasas.");
		gotoxy(x,y+11);cprintf("No deben saltarse ni olvidarse las comidas principales: desayuno, almuerzo (comida) y cena. Agregar una o dos meriendas entre comidas.");
		gotoxy(x,y+12);cprintf("Las prote�nas deben ser suficientes, entre 1 y 1,5 gramos por kilo de peso. De esta manera quedan cubiertas necesidades proteicas previas, en  caso de haberse producido.");
		gotoxy(x,y+13);cprintf("Dado el alto valor de saciedad que otorgan los alimentos ricos en fibra, los mismos deben consumirse de manera moderada. Preferir los alimentos que aportan muchas calor�as con poco volumen, como por ejemplo, frutos secos, aceites, az�cares, miel y mantequilla.");
		gotoxy(x,y+14);cprintf("No es conveniente ingerir al inicio de las comidas ensaladas y sopas, ya que disminuyen el apetito hacia los platos principales o posteriores.");
		gotoxy(x,y+15);cprintf("Los alimentos deben ser de f�cil digesti�n. Esta es una de las causas de porque se recurren a los hidratos de carbono. Las grasas y las prote�nas retardan el vaciamiento g�strico, es decir,  tardan m�s en digerirse.");
		gotoxy(x,y+16);cprintf("Las grasas crudas se digieren mejor que si las sometemos a alg�n tipo de cocci�n. Por eso, el aceite como ali�o es beneficioso por muchos motivos y adem�s porque se digiere f�cilmente. En cambio una fritura, genera m�s saciedad  junto con todos los inconvenientes para la salud");
		gotoxy(x,y+17);cprintf("");
		gotoxy(x,y+18);cprintf("");
		gotoxy(x,y+19);cprintf("");
		gotoxy(x,y+20);cprintf("");
		gotoxy(x,y+21);cprintf("");
		gotoxy(x,y+22);cprintf("");
	}
	else
	if ((masac>18.5)&&(masac<24.99))
	{
		gotoxy(x,y+9);cprintf("Usted tiene un peso normal. ");	
		gotoxy(x,y+10);cprintf("Desayuno:");
		gotoxy(x,y+11);cprintf("Cereal, Fruta, Leche.");
		gotoxy(x,y+12);cprintf("Colacion:");
		gotoxy(x,y+13);cprintf("Manzana");
		gotoxy(x,y+14);cprintf("Comida");
		gotoxy(x,y+15);cprintf("Arroz o Pasta, Carne asada, Ensalada de verdeuras, Fruta, Tortilla");
		gotoxy(x,y+16);cprintf("Colacion:");
		gotoxy(x,y+17);cprintf("Ensalada de chayote");
		gotoxy(x,y+18);cprintf("Cena:");
		gotoxy(x,y+19);cprintf("Huevo a la mexicana, Frijoles de la olla, Fruta, Cafe con Leche, Pan o Tortilla");
		gotoxy(x,y+20);cprintf("*Dieta basada en el plato del buen comer*");
		gotoxy(x,y+21);cprintf("");
		gotoxy(x,y+22);cprintf("");
	}
	else
	if ((masac>25)&&(masac<30))
	{
		gotoxy(x,y+9);cprintf("Usted tiene problemas con Sobrepeso");	
		gotoxy(x,y+10);cprintf("Para rebajar el sobrepeso seguiremos una alimentaci�n equilibrada y un plan regular de ejercicio f�sico. ");
		gotoxy(x,y+11);cprintf("L�cteos. La leche y los yogures ser�n desnatados; los quesos, magros. Se aconsejan 2-3 raciones al d�a para asegurar un aporte adecuado de calcio.");
		gotoxy(x,y+12);cprintf("Carnes y pescados. Se seleccionar�n cortes magros y se retirar� la grasa visible antes de la cocci�n. En el caso de las aves, quitar toda la piel. Evitaremos alimentos ricos en grasa saturada, como los embutidos y el tocino. Se recomienda consumir pescado al menos tres veces a la semana.");
		gotoxy(x,y+13);cprintf("Huevos. Es un alimento muy completo que presenta una prote�na de alto valor biol�gico. Se incluir� preferentemente cocido o pasados por agua y se evitar� la fritura.");
		gotoxy(x,y+14);cprintf("Cereales, legumbres y tub�rculos. Aportan principalmente hidratos de carbono complejos, muy �tiles en el control del apetito porque aumentan la sensaci�n de saciedad. De este grupo, se restringir� la boller�a (croissants, ensaimadas, magdalenas, donuts, etc�tera).");
		gotoxy(x,y+15);cprintf("Frutas y verduras. Elige frutas crudas de consistencia firme, evitando las piezas cocidas o los batidos que aportan menor saciedad. Se recomienda un alto consumo de verduras y hortalizas. Lo ideal es consumir al menos cinco raciones diarias entre frutas y verduras.");
		gotoxy(x,y+16);cprintf("Grasa y aceites. Utiliza m�todos de cocci�n que precisen poca grasa (plancha, horno, papillote), reduciendo el uso de frituras, salsas grasas y rebozados. Se recomienda el uso del aceite de oliva virgen extra.");
		gotoxy(x,y+17);cprintf("Az�car y derivados. Restringir los alimentos con alta concentraci�n de az�cares: az�car, mermelada y refrescos. En su lugar, utiliza edulcorantes y refrescos diet�ticos que no aporten calor�as.");
		gotoxy(x,y+18);cprintf("");
		gotoxy(x,y+19);cprintf("");
		gotoxy(x,y+20);cprintf("");
		gotoxy(x,y+21);cprintf("");
		gotoxy(x,y+22);cprintf("");
	}
	else
	if (masac>30.01)
	{
		gotoxy(x,y+9);cprintf("Usted tiene problemas con Obesidad");	
		gotoxy(x,y+10);cprintf("Consejos");
		gotoxy(x,y+11);cprintf("Elija alimentos con poca grasa.");
		gotoxy(x,y+12);cprintf("Reduzca en consumo de az�car.");
		gotoxy(x,y+13);cprintf("Reparta su alimentaci�n en 5 comidas al d�a: desayuno, media ma�ana, comida, merienda y cena.");
		gotoxy(x,y+14);cprintf("No alterne per�odos de ayuno con comidas abundantes.");
		gotoxy(x,y+15);cprintf("No coma entre comidas.");
		gotoxy(x,y+16);cprintf("Coma sentado, despacio y mastique muy bien los alimentos. D� bocados peque�os, con peque�as cantidades.");
		gotoxy(x,y+17);cprintf("Beba abundante agua, entre 1.5 y 2 litros al d�a.");
		gotoxy(x,y+18);cprintf("Desayuno: 200 ml. de leche desnatada. 30 gr. de pan blanco o integral.");
		gotoxy(x,y+19);cprintf("Media ma�ana: 50 gr. de pan blanco o integral. 20 gr. del grupo PROTE�NAS: at�n sin aceite o queso");
		gotoxy(x,y+20);cprintf("Comida: Un alimento a escoger del grupo VERDURAS. Un alimento a escoger del grupo FARIN�CEOS. Un alimento a escoger del grupo PROTE�NAS. Un alimento a escoger del grupo FRUTAS. 20 gr. de pan blanco o integral.");
		gotoxy(x,y+21);cprintf("Merienda: 200 ml. de leche desnatada. Un alimento a escoger del grupo FRUTAS.");
		gotoxy(x,y+22);cprintf("Cena: Un alimento a escoger del grupo VERDURAS. Un alimento a escoger del grupo FARIN�CEOS. Un alimento a escoger del grupo PROTE�NAS. Un alimento a escoger del grupo FRUTAS. 20 gr. de pan blanco o integral.");
		gotoxy(x,y+23);cprintf("Antes de acostarse: 200 ml. de leche desnatada o 2 yogures naturales desnatados.");
	}
}
void fin (int x, int y)
{
   
   gotoxy(x,y+27);cprintf("GRACIAS POR UTILIZAR UCALORIE");
   while( !kbhit() );
   gotoxy(x,y+27);cprintf("");
   getch();

}
void bien(int x, int y,int color)
{
	textcolor(color);
	gotoxy(x,y);  cprintf("@@@@@  @  @@@@@ @@  @ @     @ @@@@@ @@  @  @  @@@@'  ;@@@;");
	gotoxy(x,y+1);cprintf("@   @' @  @     @@  @ #`    @ @     @@  @  @  @   @  @   @");
	gotoxy(x,y+2);cprintf("@   ;@ @  @     @@  @ .+   .+ @     @@' #  @  @   @  @   @");
	gotoxy(x,y+3);cprintf("@   ;@ @  @     @@; @  @   @  @     @,@ #  @  @   @  @   @");
	gotoxy(x,y+4);cprintf("@   ;@ @  @     @;@ @  @   @  @     @ @ #  @  @   @  @   @");
	gotoxy(x,y+5);cprintf("@  `@. @  @     @ @ @  @   @  @     @ @`#  @  @   @  @   @ ");
	gotoxy(x,y+6);cprintf("+@@@@@ @ @@@@@@ @ @ @  ,' `# +@@@@@ @ +@+  @  @   @  @   @");
	gotoxy(x,y+7);cprintf("@   #; @  @     @ ##@   @ #.  @     @  @+  @  @   @  @   @");
	gotoxy(x,y+8);cprintf("@   ;@ @  @     @  @@   @ @   @     @  @+  @  @   @  @   @");
	gotoxy(x,y+9);cprintf("@   ;@ @  @     @  @@   @ @   @     @  @@  @  @   @  @   @");
	gotoxy(x,y+10);cprintf("@   ;@ @  @     @  @@   ;;@   @     @  .@  @  @   @  @   @");
	gotoxy(x,y+11);cprintf("@   @' @  @     @  ,@    @,   @     @   @  @  @   @  @   @ ");
	gotoxy(x,y+12);cprintf("@@@@@  @  @@@@@ @   @    @    @@@@@ @   @  @  @@@@;  ;@@@;");
}

void creditos (int x, int y)
{
	gotoxy(x,y);  cprintf("  -----------------------  ");
	gotoxy(x,y+1);cprintf(" | ___      ____________| ");
	gotoxy(x,y+2);cprintf(" |    \\    /            | ");
	gotoxy(x,y+3);cprintf(" |     \\  /  CALORIE    | ");
	gotoxy(x,y+4);cprintf(" |      \\/              | ");
	gotoxy(x,y+5);cprintf("  -----------------------\n");
	gotoxy(x,y+6);cprintf("");
	gotoxy(x,y+7);cprintf("Desarrollado por:");
	gotoxy(x,y+8);cprintf("Orlando Renan Arce Valadez");
	gotoxy(x,y+9);cprintf("Alan Gerardo S�nchez V�zquez");
	gotoxy(x,y+10);cprintf("");
	gotoxy(x,y+11);cprintf("");
	gotoxy(x,y+12);cprintf("");
	gotoxy(x,y+13);cprintf("");
	gotoxy(x,y+14);cprintf("");
	gotoxy(x,y+15);cprintf("");
	gotoxy(x,y+16);cprintf("");
	gotoxy(x,y+17);cprintf("Presione una tecla para regresar");
	while( !kbhit() );
   	cprintf("");
   	getch();
}	
void psmenu (int x,int y)
{
	gotoxy(x,y);cprintf("�QUE DESEA HACER?");
	gotoxy(x,y+1);cprintf("1-CALCULA MI IMC");
	gotoxy(x,y+2);cprintf("2-�CUANTAS CALORIAS GASTO?");
	gotoxy(x,y+3);cprintf("3-CONSEJOS");
	gotoxy(x,y+4);cprintf("4-SALIR");
	gotoxy(x,y+5);cprintf("SELECCIONE UNA OPCION(1,2,3,4)\n");
}
int alea (void)
{
	int num;
	randomize();
	num=random(10)+1;
	return(num);
}
void con (int x, int y, int a)
{
	int cns;
	cns=a;
	if (cns==1)
	{
		gotoxy(x,y+1);cprintf("Mantener un horario fijo para las comidas principales.");
	}
	else
	if (cns==2)
	{
		gotoxy(x,y+1);cprintf("Masticar despacio los alimentos.");
	}
	else
	if (cns==3)
	{
		gotoxy(x,y+1);cprintf("Consumir una gran variedad de frutas y verduras, hasta 600 gramos diarios.");
	}
	else
	if (cns==4)
	{
		gotoxy(x,y+1);cprintf("Llenar el carrito de la comprar con productos lacteos desnatados o bajos en grasas. ");
	}
	else
	if (cns==5)
	{
		gotoxy(x,y+1);cprintf("Escoger �grasas saludables� como el aceite de oliva, mejor si es virgen, por su mayor riqueza en antioxidantes.");
	}
	else
	if (cns==6)
	{
		gotoxy(x,y+1);cprintf("Consumir pescado, especialmente azul, 3 o m�s veces por semana.");
	}
	else
	if (cns==7)
	{
		gotoxy(x,y+1);cprintf("Optar por carnes con un menor aporte graso como pollo, pavo, conejo o avestruz.");
	}
	else
	if (cns==8)
	{
		gotoxy(x,y+1);cprintf("No olvidar que los refrescos y bebidas azucaradas tienen muchas calor�as y si abusas de ellos te har�n ganar peso. ");
	}
	else
	if (cns==9)
	{
		gotoxy(x,y+1);cprintf(" Realizar al menos 4 veces por semana, durante 40 minutos al d�a, alg�n ejercicio f�sico, adaptado a tu condici�n.");
	}
	else
	if (cns==10)
	{
		gotoxy(x,y+1);cprintf("Deben evitarse a toda costa los remedios �milagro� y las dietas no recomendadas por m�dicos o profesionales sanitarios.");
	}
	while( !kbhit() );
   	cprintf("");
   	getch(); 
}
 

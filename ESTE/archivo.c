#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Calcular el total de comisión de cada vendedor (comisión venta = monto vendido * comisión por rubro). La
comisión se rescata de una tabla de tres elementos de acuerdo al rubro que se ingresa al inicio. Señalar en
un campo de observaciones con "*" aquellos que no realizaron ventas.
Obtener el total a pagar y actualizar el maestro

Se tiene:

Maestro = 	seccion | n° vendedor | nombre y apellido | ult. mes proceso

Array 2 =	seccion | n° vendedor | rubro | monto vendido | mes proceso
*/

struct Maestro {
		int seccion;
		int n_vendedor;
		char nombre[30];
		int ult_mes_proceso; // 1 - 12
		float comision;
		char observaciones;	
};

struct Movimientos {
		int seccion;
		int n_vendedor;
		int rubro; // 1 - 3
		float monto_venta;
		int mes_proceso;  // 1 - 12
		
};


void cargarMaestro(struct Maestro array[], int n){
	//lo guardo
	FILE *arch;
	arch = fopen("Maestro.txt","w+");
	int i;
	if(n>0){
		printf("\nCARGANDO ARRAY MAESTRO");
		for(i=0;i<n;i++){
			printf("\nIngrese la seccion del trabajador numero [%d]: ",i+1);
			scanf("%d", &array[i].seccion);
			printf("Ingrese el numero del vendedor: ");
			scanf("%d", &array[i].n_vendedor);
			getchar();
			printf("Ingrese el nombre y apellido del vendedor: ");
			fgets(array[i].nombre, 30, stdin);
			array[i].ult_mes_proceso = 13;
			while((array[i].ult_mes_proceso >12)||(array[i].ult_mes_proceso <1)){
				printf("Ingrese el ultimo mes de proceso (valor del 1 al 12): ");
				scanf("%d", &array[i].ult_mes_proceso);
			if((array[i].ult_mes_proceso >12)||(array[i].ult_mes_proceso <1)){
				printf("Valor invalido. Por favor, ingrese un numero del 1 al 12.\n");
			}
			getchar();
			}
			array[i].observaciones = '*';
			array[i].comision = 0;
			fprintf(arch, "Seccion: %d\nNum. Vendedor: %d\nNombre: %sUltimo mes de proceso: %d\nComision: %.2f\nObservaciones:%c\n\n",array[i].seccion,array[i].n_vendedor,array[i].nombre,array[i].ult_mes_proceso,array[i].comision,array[i].observaciones);
		}
		fclose(arch);
		printf("Se ha creado el archivo Maestro\n");
	}
}
void cargarMov(struct Movimientos arrayMov[], int m){
	int i;
	int aux;
	if(m>0){
		printf("\nCARGANDO ARRAY DE MOVIMIENTOS");
		for(i=0;i<m;i++){
		printf("\nIngrese la seccion del trabajador numero [%d]: ",i+1);
		scanf("%d", &arrayMov[i].seccion);
		printf("Ingrese el numero del vendedor: ");
		scanf("%d", &arrayMov[i].n_vendedor);
		getchar();
		arrayMov[i].rubro = 4;
		while((arrayMov[i].rubro >3)||(arrayMov[i].rubro <0)){
			printf("Ingrese un numero de rubro del 1 al 3 (10%, 15%, 20%): ");
			scanf("%d", &aux);
			aux--;
			arrayMov[i].rubro=aux;
			//printf("rb:: %d", arrayMov[i].rubro);
			if((arrayMov[i].rubro >3)||(arrayMov[i].rubro <0)){
				printf("Valor invalido. Por favor, ingrese un numero del 1 al 3.\n");
			}
		getchar();
		printf("Ingrese el monto de la venta: ");
		scanf("%f", &arrayMov[i].monto_venta);
		getchar();
//		printf("MONTO : %f", array[i].monto_venta);
		while((arrayMov[i].mes_proceso >12)||(arrayMov[i].mes_proceso <1)){
			printf("Ingrese el mes del proceso (valor del 1 al 12): ");
			scanf("%d", &arrayMov[i].mes_proceso);
			if((arrayMov[i].mes_proceso >12)||(arrayMov[i].mes_proceso <1)){
				printf("Valor invalido. Por favor, ingrese un numero del 1 al 12.\n");
			}

	}
}
}
	}
	printf("Movimientos cargados\n");
}



void actualizar(struct Maestro array[], struct Movimientos arrayMov[], float r[], int n, int m){
	int i, j;
	float comision, totalmes, totalcomision, gencomision;
	char mesproceso[10];
	
	
	i=0;
	j=0;
	totalcomision=0;
	gencomision=0;
	
	while((i<=n)&&(j<=m)){
		comision=0;
		totalmes=0;
		
		while((array[i].seccion==arrayMov[j].seccion)&&(i<=n)&&(j<=m)){
			while(((array[i].seccion==arrayMov[j].seccion)&&(array[i].n_vendedor==arrayMov[j].n_vendedor))&&(i<=n)&&(j<=m)){
				totalmes+=arrayMov[j].monto_venta;
				comision=arrayMov[j].monto_venta*r[arrayMov[j].rubro];
				totalcomision+=comision;
				array[i].ult_mes_proceso=arrayMov[j].mes_proceso;
								
				j++;
					}
				array[i].observaciones='-';
				array[i].comision=totalcomision;
				i++;	
				totalcomision=0;
				}
			totalcomision=0;
			i++;
			}
				
		}



	
	
void update(struct Maestro array[], int n){
	FILE *arch=fopen("Maestro.txt","wt");
	for(int i=0;i<n;i++){

	fprintf(arch, "Seccion: %d\nNum. Vendedor: %d\nNombre: %sUltimo mes de proceso: %d\nComision: %.2f\nObservaciones:%c\n\n",array[i].seccion,array[i].n_vendedor,array[i].nombre,array[i].ult_mes_proceso,array[i].comision,array[i].observaciones);
	}
	rewind(arch);
	fclose(arch);
}


void informe(struct Maestro array[], int n){
	//guardo en informe
	FILE *arch=fopen("Informe.txt","w+");
	int d;
	int d2;
	char s[30];
	char c;
	int f;
	float f1;
	float gencomision=0;
//	int com;
	
	if (arch==NULL){
		exit(1);
	}
	for (int i = 0; i < n; i++) {
	gencomision+=array[i].comision;
	fprintf(arch, "%d\n%d%s%.2f%c\n", array[i].seccion, array[i].n_vendedor, array[i].nombre, array[i].comision, array[i].observaciones);
	}
	fprintf(arch, "%.2f", gencomision);
	fclose(arch);
	
	FILE *arch2=fopen("Informe.txt","rt");
	rewind(arch2);
	for (int i = 0; i < n; i++) {
	// leo desde el archivo informe
	fscanf(arch2,"%d", &d);
	fscanf(arch2,"%d", &d2);
	fscanf(arch2,"%s", &s);
	
	printf("Seccion: %d\n", d);
	printf("Vendedor: %d\n", d2);
	printf("Nombre: %s\n", s);

	fscanf(arch2,"%d", &f);
	printf("Comision: %d\n", f);

	//muevo el cursor para que pase los decimales
	fseek(arch2,3,SEEK_CUR);
	
		
	fscanf(arch2,"%c", &c);
	if(c=='-'){
		printf("Observaciones: \n\n");
	}
	else{
		printf("Observaciones: %c\n\n", c);
	}
	

}
	fscanf(arch2, "%.2f", &gencomision);
	printf("\nComisiones en general: %.2f\n", gencomision);
	system("pause");
	fclose(arch2);
}
		

int main(){
	struct Maestro array_maestro[1000];
	struct Movimientos array_movimientos[5000];
	int cantidad_empleados;
	int cantidad_movimientos;
	float r[3] = {0.10,0.15,0.20};

	printf("Ingrese la cantidad de empleados que posee: ");
	scanf("%d", &cantidad_empleados);
	
	printf("Ingrese la cantidad de movimientos que hubo en el mes: ");
	scanf("%d", &cantidad_movimientos);
	getchar();
	
	cargarMaestro(array_maestro, cantidad_empleados);
	
	cargarMov(array_movimientos, cantidad_movimientos);
	actualizar(array_maestro, array_movimientos, r, cantidad_movimientos, cantidad_empleados);
	update(array_maestro, cantidad_empleados);
	printf("Maestro actualizado\n\n");

	informe(array_maestro, cantidad_empleados);

return 0;
}


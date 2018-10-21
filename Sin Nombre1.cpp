# include <iostream>
# include <stdlib.h>
# include <conio.h>

 using namespace std;
 
  void Crear_memoria_fija();
   void Crear_memoria_fijaConDiferenteTamanio();
 
 //SIMULACION DE PARTICIONES DE UNA MEMORIA
 int main()
 {
 	setlocale(LC_CTYPE,"spanish");
 	int opc=0;
 	cout<<"[1] Memoria fija"<<endl;
 	cout<<"[2] Memoria dinamica"<<endl;
 	cout<<"Digite el tipo de partición que desea usar: ";
 	cin>>opc;
 	
 	switch(opc)
 	{
 		case 1: Crear_memoria_fija(); 
 		break;
 		case 2: Crear_memoria_fijaConDiferenteTamanio();
 		break;
 		default: cout<<"Opcion incorrecta"<<endl;
 				 cout<<"Vuelve a intentarlo con una opcion correcta."<<endl;
 				 cout<<"Presiona cualquiere tecla."<<endl;
 				 getch();
 				 system("cls");
 				 main();
 		break;
	}
 	
 	return 0;
 }
 
 void Crear_memoria_fija()
 {
 	int TamMemoria=0, Particiones=0, NumParticiones=0, i=0;
 	int DimMemoria[1000];
 	cout<<"Introduzca el tamaño de la memoria: ";
 	cin>>TamMemoria;
 	do
 	{
 	cout<<"El tamaño de la memoria es de: "<<TamMemoria;
 	cout<<"\nIntroduzca el tamaño que llevará cada partición de la memoria: "; 
	 cin>>Particiones;
 	
 	while(i<TamMemoria)
 	{
 			i = i + Particiones;
			NumParticiones++;
	}
	if(i!=TamMemoria)
	{
		cout<<"Todos las particiones deben ser del mismo tamaño, revisa."<<endl;
		cout<<"Presiona cualquier tecla para volverlo a intentar.";
		getch();
		system("cls");
	}
 	}while(i!=TamMemoria);
 	for (int i=0; i<NumParticiones;i++)
 	{
 		DimMemoria[i]=Particiones;
	}
	
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		for(int j=0; j<DimMemoria[i];j++)
		{
			cout<<" ";
		}
		cout<<"|"<<endl;
	}

	/*
	int seleccion=0;
 	
 	do
 	{
 	cout<<"[1]Insertar proceso"<<endl;
 	cout<<"[2]Eliminar proceso"<<endl;
 	cout<<"[3]Salir"<<endl;
 	cout<<"Seleccione el proceso que desea hacer: ";
 	cin<<seleccion;
 	
 	switch(seleccion)
 	{
 		case 1: InsertarProceso(); break;
 		case 2: EliminarProceso(); break;
 		default: cout<<"Salir del programa"<<endl; break;
	}
 	
 	}while(seleccion==1||seleccion==2);
 	*/
 	char LetProsses[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 	int InsertarProceso[1000];
 	int TamProceso=0;
 	bool InsetarValidacion=true;
 	int opc=0;
 	
 	for(int i=0; i<NumParticiones; i++)
 	{
 		InsertarProceso[i]=0;
	}
 	
 	do
 	{
	 
 	do
 	{
 	cout<<"\nIntroduzca el tamaño del proceso que desea insertar a la particion: ";
 	cin>>TamProceso;
 	}while(TamProceso>Particiones);
 	
 	if(TamProceso<=Particiones)
 	{
 		InsetarValidacion=true;
 		for(int i=0; i<NumParticiones&&InsetarValidacion==true; i++)
 		{
 			if(InsertarProceso[i]==0)
 			{
 				InsertarProceso[i]=TamProceso;
 				cout<<"\nEl proceso se ha insertado correctamente"<<endl;
 				InsetarValidacion = false;
			}
		}
		
		if(InsetarValidacion==true)
		{
			cout<<"No hay espacio disponible."<<endl;
			cout<<"[1] Eliminar proceso"<<endl;
			cout<<"[2] Salir del programa"<<endl;
		}
	}

	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		
		if(InsertarProceso[i]==0)
		{
			for(int j=0; j<Particiones;j++)
			{
				cout<<" ";
			}
		}
		else
		{
			for(int k=0; k<Particiones;k++)
			{
				if(k<InsertarProceso[i])
					{
						cout<<LetProsses[i];
					}
				else
				{
					cout<<" ";
				}
			}
		}
			
		cout<<"|"<<endl;
	}
	
	cout<<"[1] Insertar proceso"<<endl;
	cout<<"[2] Eliminar proceso"<<endl;
	cout<<"[3] Salir"<<endl;
	cout<<"Introduce la opcion: ";
	cin>>opc;
	
	if(opc==2)
	{
		int EliminarProceso=0;
		cout<<"Introduzca el numero de proceso que desea eliminar: ";
		cin>>EliminarProceso;
	
		if(EliminarProceso<=NumParticiones)
		{
			InsertarProceso[EliminarProceso] = 0;
		}
	}
	
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		
		if(InsertarProceso[i]==0)
		{
			for(int j=0; j<Particiones;j++)
			{
				cout<<" ";
			}
		}
		else
		{
			for(int k=0; k<Particiones;k++)
			{
				if(k<InsertarProceso[i])
					{
						cout<<LetProsses[i];
					}
				else
				{
					cout<<" ";
				}
			}
		}
			
		cout<<"|"<<endl;
	}
	}while(opc==1||opc==2);
	
	
	
	
 }
 
 void Crear_memoria_fijaConDiferenteTamanio()
 {
 	int TamMemoria=0, Particiones=0, NumParticiones=0, NumDeCadaParticion=0, TamProceso=0;
 	bool EspacioDisponible = true;
 	int DimMemoria[1000];
 	int opc=0;
 	char LetProsses[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 	cout<<"Introduzca el tamaño de la memoria: ";
 	cin>>TamMemoria;
 	cout<<"El tamaño de la memoria es de: "<<TamMemoria;
 	
 	for(int i=0; i<1000&&EspacioDisponible==true; i++)
 	{
 		if(NumDeCadaParticion<=TamMemoria)
 		{
 			cout<<"\nTamaño de la partición ["<<i<<"] :";
 			cin>>Particiones;
 			NumDeCadaParticion = NumDeCadaParticion + Particiones;
 			cout<<"Te queda: "<<TamMemoria-NumDeCadaParticion<<" espacio en la memoria."<<endl;
 			DimMemoria[i]=Particiones;
 			NumParticiones++;
 			if(NumDeCadaParticion==TamMemoria)
 			{
 				EspacioDisponible=false;
			}
 		}
	}
	
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		for(int j=0; j<DimMemoria[i];j++)
		{
			cout<<" ";
		}
		cout<<"|"<<endl;
	}

	int ParticionesEficientes[1000];
	int Insertar[1000];
	
	for(int i=0; i<NumParticiones; i++)
	{
		Insertar[i]=0;
		ParticionesEficientes[i]=0;
	}
	
	int aux=0;
	
	for(int i=0; i<NumParticiones; i++)
	{
			ParticionesEficientes[i]=DimMemoria[i];
	}
	
	for(int i=0; i<NumParticiones; i++)
	{
		for(int j=i+1; j<NumParticiones; j++)
		{
			if(ParticionesEficientes[i]>ParticionesEficientes[j])
			{
				aux= ParticionesEficientes[i];
				ParticionesEficientes[i]=ParticionesEficientes[j];
				ParticionesEficientes[j]=aux;
			}
			
		}
	}
	
	do
	{
	cout<<"Introduzca el tamaño del proceso: ";
	cin>>TamProceso;
	
	bool validacion=true;
	int posicion=0, j=0;
	
	for(int i=0; i<NumParticiones&&validacion==true;i++)
	{
		if(TamProceso<=ParticionesEficientes[i])
		{	
			for(j=0; j<NumParticiones;j++)
			{
				if(ParticionesEficientes[i]==DimMemoria[j]&&validacion==true)
				{
					posicion=j;
					cout<<"posicion de j: "<<j<<endl;
					if(Insertar[posicion]==0)
					{
						Insertar[posicion] = TamProceso;
						validacion=false;
					}
				}
			}
		}
	}
	
	if(validacion==true)
	{
		cout<<"Falta espacio en la memoria, elimina algunos procesos"<<endl;
	}
	
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"posicion: "<<i<<"procesos: "<<Insertar[i]<<endl;
	}

		
		cin>>opc;
	}while(opc==1);
	
 }
 

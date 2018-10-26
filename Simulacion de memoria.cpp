# include <iostream>
# include <stdlib.h>
# include <conio.h>

 using namespace std;
 
  void Crear_memoria_fija();
   void Crear_memoria_fijaConDiferenteTamanio();
   void Memoria_Dinamica();
 
 //SIMULACION DE PARTICIONES DE UNA MEMORIA
 int main()
 {
 	setlocale(LC_CTYPE,"spanish");
 	int opc=0;
 	cout<<"[1] Memoria fija"<<endl;
 	cout<<"[2] Memoria fija de diferentes tamaños"<<endl;
 	cout<<"[3] Memoria Dinamica"<<endl;
 	cout<<"[4] Salir del programa"<<endl;
 	cout<<"Digite el tipo de partición que desea usar: ";
 	cin>>opc;
 	
 	switch(opc)
 	{
 		case 1: Crear_memoria_fija(); 
 		break;
 		case 2: Crear_memoria_fijaConDiferenteTamanio();
 		break;
 		case 3: Memoria_Dinamica();
 		break;
 		case 4:cout<<"Adios..."<<endl;
 				getch();
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
	cout<<"\n\n";
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		for(int j=0; j<DimMemoria[i];j++)
		{
			cout<<" ";
		}
		cout<<"|\n"<<endl;
	}
	
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
 		
 	cout<<"[1] Insertar proceso"<<endl;
	cout<<"[2] Eliminar proceso"<<endl;
	cout<<"[3] Salir"<<endl;
	cout<<"Introduce la opcion: ";
	cin>>opc;
	 
	if(opc==1) 
	{
		
 	do
 	{
 	cout<<"\nIntroduzca el tamaño del proceso que desea insertar a la particion: ";
 	cin>>TamProceso;
 	if(TamProceso>Particiones)
 	{
 		cout<<"Excediste el tamaño de la particion. Vuelvelo a intentar."<<endl;
	 }
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
			cout<<"Elimine algunos elementos."<<endl;
		}
	}
	cout<<"\n\n";
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
			
		cout<<"|\n"<<endl;
	}
	
	}
	
	if(opc==2)
	{
		int EliminarProceso=0;
		cout<<"Introduzca el numero de proceso que desea eliminar: ";
		cin>>EliminarProceso;
	
		if(EliminarProceso<=NumParticiones)
		{
			InsertarProceso[EliminarProceso] = 0;
		}
	
	cout<<"\n\n";
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
			
		cout<<"|\n"<<endl;
	}
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
 	int i=0;
 	while (i<TamMemoria&&EspacioDisponible==true)
 	{
 		cout<<"\nTamaño de la partición ["<<i<<"] :";
 		cin>>Particiones;
 		NumDeCadaParticion = NumDeCadaParticion + Particiones;
 			
 		if(NumDeCadaParticion<=TamMemoria)
 		{
 			cout<<"Te queda: "<<TamMemoria-NumDeCadaParticion<<" espacio en la memoria."<<endl;
 			DimMemoria[i]=Particiones;
 			NumParticiones++;
 			i++;
 			if(NumDeCadaParticion==TamMemoria)
 			{
 				EspacioDisponible=false;
			}
 		}
 		else
 		{
 			NumDeCadaParticion = NumDeCadaParticion - Particiones;
 			cout<<"Te queda: "<<TamMemoria-NumDeCadaParticion<<" espacio en la memoria."<<endl;
 			cout<<"No excedas el espacio que le queda a la memoria y vulvelo a intentar"<<endl;
		 }
	}
	cout<<"\n\n";
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		for(int j=0; j<DimMemoria[i];j++)
		{
			cout<<" ";
		}
		cout<<"|\n"<<endl;
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
	
	cout<<"[1] Insertar proceso"<<endl;
	cout<<"[2] Eliminar proceso"<<endl;
	cout<<"Seleccione la accion que desea hacer: ";
	cin>>opc;
	if(opc==1)
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
					if(Insertar[posicion]==0&&validacion==true)
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
	cout<<"\n\n";
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		
		if(Insertar[i]==0)
		{
			for(int j=0; j<DimMemoria[i];j++)
			{
				cout<<" ";
			}
		}
		else
		{
			for(int k=0; k<DimMemoria[i];k++)
			{
				if(k<Insertar[i])
					{
						cout<<LetProsses[i];
					}
				else
				{
					cout<<" ";
				}
			}
		}
			
		cout<<"|\n"<<endl;
	}
}
		
		if(opc==2)
		{	
			int EliminarProceso=0;
			cout<<"Introduzca el numero de proceso que desea eliminar: ";
			cin>>EliminarProceso;
	
			if(EliminarProceso<=NumParticiones)
			{
				Insertar[EliminarProceso] = 0;
			}
		
		cout<<"\n\n";
		for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		
		if(Insertar[i]==0)
		{
			for(int j=0; j<DimMemoria[i];j++)
			{
				cout<<" ";
			}
		}
		else
		{
			for(int k=0; k<DimMemoria[i];k++)
			{
				if(k<Insertar[i])
					{
						cout<<LetProsses[i];
					}
				else
				{
					cout<<" ";
				}
			}
		}
			
		cout<<"|\n"<<endl;
	}
}
	}while(opc==1||opc==2);
 }
 
 void Memoria_Dinamica()
 {
 	int TamProceso=0, TamMemoria=0, TamAcumulado=0, opc=0;
 	int Particion[1000];
 	int Proceso[1000];
 	int NumParticiones=0;
 	char LetProsses[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 	
 	cout<<"\nIntroduce el tamaño de la memoria total: ";
 	cin>>TamMemoria;
 	
 	for(int i=0; i<TamMemoria; i++)
 	{
 		Particion[i]=0;
 		Proceso[i]=0;
	}
	
	do
	{
		
	cout<<"[1] Insertar proceso"<<endl;
	cout<<"[2] Eliminar proceso"<<endl;
	cout<<"[3] Comprimir memoria"<<endl;
	cout<<"[4] Salir"<<endl;
	cout<<"Seleccione la accion que desea hacer: ";
	cin>>opc;
	
	if(opc==4)
	{
		main();
	}
	
	if(opc==1)
	{
 	
 	cout<<"Introduce el tamaño del proceso que desea insertar: ";
 	cin>>TamProceso;
 	bool ValidacionInsercion = true;
 	
 	TamAcumulado = TamAcumulado + TamProceso;
 	
 	if(TamAcumulado<=TamMemoria)
 	{
 		cout<<"El tamaño de la memoria restante es de: "<<TamMemoria-TamAcumulado<<endl;
	}
	else
	{
		TamAcumulado = TamAcumulado - TamProceso;
		cout<<"El tamaño de la memoria restante es de: "<<TamMemoria-TamAcumulado<<endl;
		cout<<"Se exedio el tamaño de la memoria. Vulevalo a intentar con un tamaño menor o igual"<<endl;
		ValidacionInsercion = false;
	}
 	
 	for(int i=0; i<TamMemoria&&ValidacionInsercion==true; i++)
 	{
 		if(Particion[i]==0)
 		{
 			Particion[i]=TamProceso;
 			Proceso[i]=TamProceso;
 			NumParticiones++;
 			ValidacionInsercion = false;
		}
		if(Particion[i]!=0&&Proceso[i]==0)
		{
			if(Proceso[i]==Particion[i])
			{
				Proceso[i]=TamProceso;
				ValidacionInsercion = false;
			}
			if(TamProceso<Particion[i])
			{
				int ParticionRestante=0, aux1=0, aux2=0;
				
				ParticionRestante=Particion[i]-TamProceso;
				Proceso[i] = TamProceso;
				Particion[i] = TamProceso;
				
				for(int j=NumParticiones+1; i+2<=j; j--)
				{
					aux1 = Proceso[j-1];
					aux2 = Particion[j-1];
					cout<<"\nj-1: "<<j-1<<endl;
					Proceso[j-1] = Proceso[j];
					Particion[j-1]= Particion[j];
					
					Proceso[j] = aux1;
					Particion[j] = aux2;
				}
				ValidacionInsercion = false;
				Particion[i+1] = ParticionRestante;
				NumParticiones++;
				cout<<"\nNumParticiones: "<<NumParticiones<<endl;
			}
		}
	}
	if(ValidacionInsercion==true)
		{
			cout<<"\nFalta espacio en la memoria, borre algunos procesos."<<endl;
		}
	cout<<"\n\n";
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		
		if(Proceso[i]==0)
		{
			for(int j=0; j<Particion[i];j++)
			{
				cout<<" ";
			}
		}
		else
		{
			for(int k=0; k<Particion[i];k++)
			{
				if(k<Proceso[i])
					{
						cout<<LetProsses[i];
					}
				else
				{
					cout<<" ";
				}
			}
		}
			
		cout<<"|\n"<<endl;
	}
}
	if(opc==2)
	{
	int EliminarProceso=0;
			cout<<"Introduzca el numero de proceso que desea eliminar: ";
			cin>>EliminarProceso;
	
			if(EliminarProceso<=NumParticiones)
			{
				TamAcumulado = TamAcumulado - Proceso[EliminarProceso];
				Proceso[EliminarProceso] = 0;
			}
	cout<<"\n\n";
	for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		
		if(Proceso[i]==0)
		{
			for(int j=0; j<Particion[i];j++)
			{
				cout<<" ";
			}
		}
		else
		{
			for(int k=0; k<Particion[i];k++)
			{
				if(k<Proceso[i])
					{
						cout<<LetProsses[i];
					}
				else
				{
					cout<<" ";
				}
			}
		}
			
		cout<<"|\n"<<endl;
	}
}
	if(opc==3)
	{
		int particion=0, proceso=0;
		bool validacion = true;
		for(int i=0; i<NumParticiones; i++)
		{
			validacion = true;
			if(Proceso[i]==0&&Particion[i]!=0)
			{
				for(int j=i+1; j<NumParticiones&&validacion == true; j++)
				{
					if(Proceso[j]!=0&&Particion[j]!=0)
					{
					proceso	=Proceso[i];
					particion	=Particion[i];
					
					Proceso[i] = Proceso[j];
					Particion[i] =Particion[j];
					
					Proceso[j] = proceso;
					Particion[j] = particion;
					validacion = false;
					}
				}
			}
		}
		
		for(int i=0; i<NumParticiones; i++)
		{
			cout<<"proceso ["<<i<<"]: "<<Proceso[i]<<"Particion: "<<Particion[i]<<endl;
		}
		
		int ParticionesRestantes=0;
		for(int i=0; i<NumParticiones; i++)
		{
			if(Proceso[i]!=0&&Particion[i]!=0)
			{
				ParticionesRestantes++;
			}
			else
			{
				Proceso[i] =0;
				Particion[i] = 0;
			}
			
		}
		
		cout<<"TamAcumulado: "<<TamAcumulado<<endl;
		
		
		
		cout<<"El tamaño de la memoria restante es de: "<<TamMemoria-TamAcumulado<<endl;
		
		NumParticiones = ParticionesRestantes;
		cout<<"\n\n";
		for(int i=0; i<NumParticiones; i++)
	{
		cout<<"p["<<i<<"]"<<"|";
		
		if(Proceso[i]==0)
		{
			for(int j=0; j<Particion[i];j++)
			{
				cout<<" ";
			}
		}
		else
		{
			for(int k=0; k<Particion[i];k++)
			{
				if(k<Proceso[i])
					{
						cout<<LetProsses[i];
					}
				else
				{
					cout<<" ";
				}
			}
		}
			
		cout<<"|\n"<<endl;
	}
		
	}
	
	

	}while(opc>=1&&opc<=3);
 }
 

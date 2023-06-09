#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void imprimirParametros();
void imprimirInfo();

struct ficha{
    char nombre[100];
    char contrasennya[100];
    int registro;
    
};

struct registro{
    float ph;
    float conductividad;
    float turbidez;
    int coliformes;
    char distrito [100];
    float temperatura;
};

int main(){
    
    struct ficha usuarios[500];
    struct registro parametros [500];
    int inicio,numeroUsuarios=0,numParametros=0;
       int numeracion=0, i=0, j=0, a, b, n=0;
       int opcion;
       FILE * fichero;
       FILE * datos;
    
    fichero=fopen("usuarios.txt","r");
    if(fichero==NULL){ //comprobamos que el fichero con el que vamos a trabajar funciona
        printf("Error en la apertura de ficheros.\n");
        return 0;
    }
    
    //Vamos a ir guardando los usuarios que se vayan registrando en el fichero
    
    while(fscanf(fichero,"%d %s %s", &usuarios[i].registro,usuarios[i].nombre,usuarios[i].contrasennya)!=EOF){
        numeroUsuarios++;
        i++;
    }
    fclose(fichero);
        printf("1.Registrarse\n2.Iniciar sesion\n");
        scanf("%d",&inicio);
        fflush(stdin);
        switch(inicio){
            
            //Vamos a introducir un nuevo usuario:
            case 1:
                
                usuarios[i].registro=i+1;
                
                //pedimos nombre y contrasennya
                
                printf("Introduzca su nombre de usuario\t");
                fflush(stdin);
                gets(usuarios[i].nombre);
                printf("Introduzca su contrasenya:\t");
                fflush(stdin);
                gets(usuarios[i].contrasennya);
                        
                        
                //vamos a comprobar que no coincida con el nombre de ninguno de los usuarios previamente registrados. En caso de que no coincida, este se annyadira al fichero y se quedar registrada la posicion en la que se annyadio de forma que el siguiente usuario en registrarse quedara annydido a continuacion.
                
                for(a=0;a<numeroUsuarios;a++){ //el numero de usuarios ira incrementando segun incremente el numero de registros, de forma que cada vez que haya un nuevo resgistro se compare con los ya existentes usuarios
                    
                    for(j=0;j<i;j++){ //en este caso estaremos comparando el nuevo usuario con los ya existentes
                        if(strcmp(usuarios[i].nombre,usuarios[j].nombre)==0){
                            printf("El nombre de usuario escogido ya existe. Por favor elija otro:\t");
                            fflush(stdin);
                            gets(usuarios[i].nombre);
                        }
                    }
                }
                
                fichero=fopen("usuarios.txt","w");
                if(fichero==NULL){ //comprobamos que el fichero que estamos abriendo funciona
                    printf("Error\n");
                    return 0;
                }
                for(n=0;n<=i;n++){
                    fprintf(fichero,"%d %s %s\n", usuarios[n].registro,usuarios[n].nombre,usuarios[n].contrasennya);
                }
                fclose(fichero);

                b=i;
                   
                break;
            
            //usuario ya registrado inicia sesión
            case 2:
           
               do{ //pedimos el nombre y la contrasennya y comprobamos que ambos coincidan con un usuario ya registrado anteriormente (este estara guardado en el fichero)
                   printf("Nombre de usuario:\t");
                   fflush(stdin);
                   gets(usuarios[i].nombre);
                   printf("Contrasennya:\t");
                   fflush(stdin);
                   gets(usuarios[i].contrasennya);
                   
                   for(b=0;b<numeroUsuarios;b++){
                       if((strcmp(usuarios[i].nombre,usuarios[b].nombre)==0)&&(strcmp(usuarios[i].contrasennya,usuarios[b].contrasennya)==0)){
                           numeracion++;
                           break;
                       }
                   }
                   if(numeracion==0){ //en caso de que no coincida con un usuario registrado no le dejara continuar
                       printf("El nombre de usuario o la contrasennya introducidos ha sido incorrecto, por favor introduzcalos de nuevo.\n");
                   }
                }while(numeracion==0);
                break;
        }
    
    
    do{
        printf("1-Consultar datos\n2-Introducir nuevos datos\n3-Media de los parametros\n4-Acerca de la aplicación\n5-Informacion de los parametros\n6.Salir\n");
        scanf("%d",&opcion);
        if(opcion==1){
            //abrir el fichero con datos previamente introducidos
            
            datos=fopen("parametros.txt","r");
            if(datos==NULL){ //comprobamos que el fichero con el que vamos a trabajar funciona
                printf("Error en la apertura de ficheros.\n");
                return 0;
            }
            i=0;
            while(fscanf(datos,"%s %f %f %f %d %f", parametros[i].distrito,&parametros[i].ph,&parametros[i].conductividad,&parametros[i].turbidez,&parametros[i].coliformes,&parametros[i].temperatura)!=EOF){
                numParametros++;
                i++;
            }
            fclose(datos);
           
            // imprimir el fichero con los datos
            for (i = 0; i < numParametros; i++) {
                printf("Distrito: %s\n", parametros[i].distrito);
                printf("pH: %.2f\n", parametros[i].ph);
                printf("Conductividad: %.2f\n", parametros[i].conductividad);
                printf("Turbidez: %.2f\n", parametros[i].turbidez);
                printf("Coliformes: %d\n", parametros[i].coliformes);
                printf("Temperatura: %.2f\n", parametros[i].temperatura);
                printf("\n");
            }
            
        }else if(opcion==2){
            //meter función para introducir nuevos datos
            datos=fopen("parametros.txt","a");
            if(datos==NULL){ //comprobamos que el fichero con el que vamos a trabajar funciona
                printf("Error en la apertura de ficheros.\n");
                return 0;
            }
            i=0;
            printf("Distrito:\t");
            fflush(stdin);
            gets(parametros[i].distrito);
            printf("pH:\t");
            fflush(stdin);
            scanf("%f", &parametros[i].ph);
            printf("Conductividad:\t");
            fflush(stdin);
            scanf("%f", &parametros[i].conductividad);
            printf("Turbidez:\t");
            fflush(stdin);
            scanf("%f", &parametros[i].turbidez);
            printf("Coliformes:\t");
            fflush(stdin);
            scanf("%d", &parametros[i].coliformes);
            printf("Temperatura:\t");
            fflush(stdin);
            scanf("%f", &parametros[i].temperatura);
            
            fprintf(datos,"%s\t", parametros[i].distrito);
            fprintf(datos,"%.2f\t", parametros[i].ph);
            fprintf(datos,"%.2f\t", parametros[i].conductividad);
            fprintf(datos,"%.2f\t", parametros[i].turbidez);
            fprintf(datos,"%d\t", parametros[i].coliformes);
            fprintf(datos,"%.2f\n", parametros[i].temperatura);
            
        
        }else if(opcion==3){
            
            //meter todo el printf de los parametros en la funcion que hay abajo
            
            datos=fopen("parametros.txt","r");
            if(datos==NULL){ //comprobamos que el fichero con el que vamos a trabajar funciona
                printf("Error en la apertura de ficheros.\n");
                return 0;
            }
            i=0;
            while(fscanf(datos,"%s %f %f %f %d %f", parametros[i].distrito,&parametros[i].ph,&parametros[i].conductividad,&parametros[i].turbidez,&parametros[i].coliformes,&parametros[i].temperatura)!=EOF){
                numParametros++;
                i++;
            }
            fclose(datos);
            
           float phTotal=0, conducTotal=0, turbTotal=0, tempTotal=0;
            float phTot[numParametros],condTot[numParametros],turbTot[numParametros],tempTot[numParametros];
           
            // imprimir el fichero con los datos
            for (i = 0; i < numParametros; i++) {
                phTot[i]=parametros[i].ph;
                condTot[i]=parametros[i].conductividad;
                turbTot[i]=parametros[i].turbidez;
                tempTot[i]=parametros[i].temperatura;
                
            }
            for(i=0;i < numParametros; i++){
                phTotal+=phTot[i];
                conducTotal+=condTot[i];
                turbTotal+=turbTot[i];
                tempTotal+=tempTot[i];
            }
            
            printf("pH medio = %.2f\n", phTotal/numParametros);
            printf("Conductividad media = %.2f\n", conducTotal/numParametros);
            printf("Turbidez media = %.2f\n", turbTotal/numParametros);
            printf("Temperatura media = %.2f\n", tempTotal/numParametros);
            printf("\n");

            
        }else if(opcion==4){
            imprimirInfo();
        }else if(opcion==5){
            imprimirParametros();
        }
    }while(opcion!=6);
    
}

//FUNCIONES
void imprimirParametros(){
    printf("El pH del agua es una medida que indica la acidez o alcalinidad del agua. Tiene influencia en diversos aspectos, tanto en terminos de la calidad del agua como en su impacto en el medio ambiente y en los sistemas biologicos. Algunas de las principales influencias del pH del agua son:\n1.Calidad del agua potable: El pH del agua potable puede afectar su sabor, olor y apariencia. Ademas, un pH extremadamente alto o bajo puede indicar la presencia de contaminantes o sustancias quimicas indeseables en el agua.\n2.Salud humana: El agua con un pH adecuado es importante para mantener un equilibrio saludable en el cuerpo humano. Un pH incorrecto puede tener efectos negativos en la salud, como irritacion de la piel, problemas gastrointestinales y dificultades en la absorción de nutrientes.\n3.Ecosistemas acuaticos: El pH del agua es un factor critico para la salud de los ecosistemas acuaticos. Diferentes especies de organismos acuaticos tienen rangos de pH especificos en los que pueden sobrevivir y reproducirse. Un cambio significativo en el pH del agua puede afectar negativamente a las plantas acuaticas, los peces y otros organismos acuaticos, alterando el equilibrio natural del ecosistema.\n4.Procesos quimicos y biologicos: El pH del agua puede influir en diversos procesos quimicos y biologicos. Por ejemplo, en la agricultura, el pH del agua de riego puede afectar la disponibilidad de nutrientes para las plantas. En procesos industriales, el pH puede influir en la eficiencia de reacciones quimicas y en la calidad de los productos.\nEs importante mantener un pH adecuado en el agua, tanto para asegurar su calidad para el consumo humano como para preservar los ecosistemas acuaticos. Los estandares de calidad del agua suelen incluir rangos de pH recomendados para diferentes usos, como agua potable, riego agricola y proteccion de la vida acuatica.\n\nLa conductividad del agua es una medida de su capacidad para transportar corriente electrica. Esta relacionada con la concentracion de iones disueltos en el agua y puede tener diversas influencias, como se describe a continuacion:\n1.Calidad del agua potable: La conductividad del agua puede indicar la presencia de sales disueltas, minerales y otros compuestos ionicos. Un aumento en la conductividad puede sugerir la presencia de contaminantes, como sales de metales pesados o productos quimicos disueltos, lo cual puede afectar la calidad del agua potable y su seguridad para el consumo humano.\n2.Salinidad del agua: La conductividad electrica del agua esta directamente relacionada con su salinidad. El agua con alta conductividad generalmente indica una mayor concentracion de sales disueltas, lo que puede tener implicaciones en la agricultura, especialmente en la irrigacion de cultivos sensibles a la sal. Un alto nivel de salinidad en el agua de riego puede afectar la calidad del suelo y la absorcion de agua y nutrientes por parte de las plantas.\n3.Impacto en los ecosistemas acuaticos: La conductividad del agua es un parametro importante para evaluar la salud de los ecosistemas acuaticos. Diferentes especies acuaticas tienen requerimientos especificos de conductividad, y cambios significativos en la conductividad del agua pueden afectar negativamente a la vida acuatica. Por ejemplo, un aumento repentino en la conductividad puede ser perjudicial para los peces y otros organismos acuaticos sensibles.\n4.Procesos industriales y tratamiento de agua: En los procesos industriales y en el tratamiento de agua, la medicion de la conductividad es esencial para monitorear y controlar la calidad del agua. La conductividad puede ser indicativa de la presencia de impurezas, como sales o productos quimicos disueltos, que pueden afectar la eficiencia de los procesos industriales y la calidad de los productos finales.\nEn resumen, la conductividad del agua es un parametro importante para evaluar la calidad del agua, identificar la presencia de contaminantes, determinar la salinidad y su impacto en los ecosistemas acuaticos, y controlar procesos industriales y de tratamiento de agua.\n\nLa turbidez del agua se refiere a la medida de la cantidad de particulas suspendidas en el agua que afectan la claridad visual. Estas particulas pueden ser solidos suspendidos, sedimentos, microorganismos, materia organica u otros materiales en suspension. La turbidez del agua puede tener varias influencias y efectos, como se detalla a continuacion:\n1.Calidad del agua potable: La turbidez del agua puede afectar la calidad y la apariencia del agua potable. Altos niveles de turbidez pueden hacer que el agua se vea sucia o poco atractiva, lo que puede generar preocupaciones en terminos de aceptabilidad y confianza del consumidor. Ademas, la turbidez puede albergar microorganismos, como bacterias y parasitos, que pueden requerir tratamientos adicionales para garantizar la seguridad del agua potable.\n2.Ecosistemas acuaticos: La turbidez puede tener efectos significativos en los ecosistemas acuaticos. Altos niveles de turbidez pueden reducir la penetracion de la luz solar en el agua, lo que afecta la fotosintesis de las plantas acuaticas y, a su vez, la produccion de oxigeno y el habitat para otras formas de vida acuatica. Ademas, las particulas suspendidas pueden obstruir las branquias de los peces y afectar su capacidad de alimentacion, reproduccion y supervivencia.\n3.Tratamiento de agua: La turbidez del agua puede afectar el proceso de tratamiento del agua. Las particulas en suspension pueden obstruir filtros y membranas utilizados en los sistemas de tratamiento de agua, lo que disminuye la eficiencia del proceso y aumenta la necesidad de limpieza y mantenimiento frecuentes. Ademas, algunas particulas pueden ser resistentes a los procesos de tratamiento convencionales, lo que requiere tecnicas adicionales para su eliminacion.\n4.Impacto en la salud humana: La turbidez del agua puede tener implicaciones para la salud humana. Las particulas suspendidas pueden albergar microorganismos patogenos, como bacterias, virus y parasitos, que representan riesgos para la salud si se consumen o se utilizan para la higiene personal. Ademas, algunas particulas pueden contener compuestos quimicos toxicos que se adsorben en su superficie y pueden representar un riesgo potencial para la salud si se ingieren.\nEn resumen, la turbidez del agua puede afectar la calidad del agua potable, los ecosistemas acuaticos, los procesos de tratamiento de agua y la salud humana. Su control y monitoreo son importantes para garantizar la seguridad del agua y el funcionamiento adecuado de los sistemas acuaticos y de tratamiento.\n\nLa temperatura del agua tiene una serie de efectos e influencias en diferentes aspectos, tanto en terminos de su uso humano como en los ecosistemas acuaticos. A continuacion se detallan algunas de las principales formas en las que la temperatura afecta al agua:\n1.Propiedades fisicas y quimicas: La temperatura del agua influye en varias propiedades fisicas y quimicas del agua. Por ejemplo, la temperatura afecta la densidad del agua, su viscosidad y su capacidad de disolver gases y sustancias quimicas. Tambien puede influir en la velocidad de las reacciones quimicas que ocurren en el agua.\n2.Vida acuatica: La temperatura del agua es un factor critico para la vida acuatica. Diferentes especies tienen rangos de temperatura optimos en los que pueden sobrevivir y reproducirse. Los cambios en la temperatura pueden afectar los patrones de migracion, el crecimiento, la reproduccion y la disponibilidad de alimentos para los organismos acuaticos. Ademas, las temperaturas extremas, como el agua demasiado caliente o demasiado fria, pueden ser perjudiciales e incluso letales para ciertas especies.\n3.Ciclo del agua: La temperatura del agua tambien influye en el ciclo hidrologico. La evaporacion del agua se acelera a temperaturas mas altas, lo que afecta la cantidad de agua disponible en la atmosfera y puede influir en los patrones de precipitacion. Ademas, la temperatura del agua en cuerpos de agua superficiales puede afectar la formacion de nubes y la transferencia de calor entre el agua y la atmosfera.\n4.Calidad del agua: La temperatura del agua puede afectar la calidad del agua y sus caracteristicas quimicas y biologicas. Por ejemplo, el aumento de la temperatura del agua puede disminuir la cantidad de oxigeno disuelto en ella, lo que afecta la vida acuatica y puede conducir a condiciones de hipoxia. Ademas, la temperatura puede influir en la solubilidad de sustancias quimicas, la formacion de algas y la proliferación de organismos patogenos.\n5.Usos humanos: La temperatura del agua es relevante para diversos usos humanos, como la recreacion, la agricultura, la generacion de energia y el abastecimiento de agua potable. Por ejemplo, las temperaturas calidas del agua pueden ser atractivas para actividades recreativas como nadar, mientras que las temperaturas frias pueden afectar los cultivos y la agricultura. Ademas, la temperatura del agua influye en la eficiencia de los procesos de generación de energia hidroelectrica y termica.\nEn conclusion, la temperatura del agua tiene un impacto significativo en las propiedades del agua, la vida acuatica, el ciclo hidrologico, la calidad del agua y los usos humanos. Es un parametro importante para monitorear y comprender tanto para la gestion de los recursos hidricos como para la conservacion de los ecosistemas acuaticos.\n\n");
}
void imprimirInfo(){
    printf("CLEAN WATER\n\n¡Bienvenidos a CleanWater!\n Somos una pagina web dedicada a recopilar datos sobre la calidad del agua en los distintos distritos de Madrid. Nuestra mision es proporcionar informacion precisa y actualizada sobre el estado del agua en cada area, para que los ciudadanos puedan tomar decisiones informadas sobre su consumo y uso.\nEn CleanWater, recopilamos datos de diversas fuentes confiables y los presentamos de manera clara y accesible. Nuestro objetivo es proporcionar información detallada sobre la calidad del agua, incluyendo niveles de pH, cloro, turbidez, y otros parametros importantes. Tambien ofrecemos consejos y recomendaciones para garantizar que el agua que se consume en casa sea segura y saludable.\nNuestra pagina web es facil de usar y esta disennyada para ser accesible a todos. Queremos que la informacion sobre la calidad del agua sea accesible a todos los ciudadanos de Madrid, para que puedan tomar decisiones informadas sobre su consumo de agua.\nEn CleanWater, creemos que el acceso a informacion precisa y actualizada sobre la calidad del agua es fundamental para garantizar la salud y el bienestar de las personas. Esperamos que nuestra pagina web sea una herramienta util para todos los ciudadanos de Madrid y contribuya a mejorar la calidad del agua en toda la ciudad.");
}



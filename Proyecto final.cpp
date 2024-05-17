/*********************************Presentacion**********************************

                            Nombre de los alumnos:
                      Kaleb Alejandro Falcón Márquez
                               Jimena Ramirez

                         Fecha: 10 de mayo de 2024
                        Programa: ProyectoFinal.cpp
                    CENTRO UNIVERSITARIO DE LOS ALTOS/
                        UNIVERSIDAD DE GUADALAJARA/
                        INGENIERIA EN COMPUTACION/
                             SEGUNDO SEMESTRE

                   Profesor: Carlos Javier Cruz Franco
  Descripcion: En este programa el usuario va a poder ingresar los datos de 5
alumnos individualmente dónde se van a guardar en un archivo de texto su nombre,
   carrera que está estudiando, además de 5 materias junto con su respectivo
maestro y materias. Además de esto el usuario va a poder ver en pantalla los
 datos que ha ingresado, junto con poder editar o borrar lo que ya ha ingresado.
Y finalmente este programa puede calcular el promedio de el último alumno con el
                      que se trabajó en el programa.

**********************************************************************************/
#include <string>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

int opcion;
int opcion_alumno;
int submenu;

struct Datos_Alumno{
    string Nombre_alumno; //El string es para guardar el nombre con espacios
    string Carrera_alumno;
}Al1; //Estructura para guardar datos
struct Materias{
    float Calificacion;
    string Nombre_profesor;
    string Materia_cursada;
}M1, M2, M3, M4, M5;

FILE *Archivo; //Se crea un puntero de nombre "Archivo", que se utilizará para el recopilamiento de los datos

void seleccion(){
    cout << "Que alumno desea registrar?" << endl;
    cout << "1. Alumno 1" << endl;
    cout << "2. Alumno 2" << endl;
    cout << "3. Alumno 3" << endl;
    cout << "4. Alumno 4" << endl;
    cout << "5. Alumno 5" << endl;
    cout << "\n\tIngrese la opcion deseada: ";
    cin >> opcion_alumno;

    switch(opcion_alumno){
        case 1:
        Archivo = fopen("Alumno1.txt","wt+");
        break;

        case 2:
        Archivo = fopen("Alumno2.txt","wt+");
        break;

        case 3:
        Archivo = fopen("Alumno3.txt","wt+");
        break;

        case 4:
        Archivo = fopen("Alumno4.txt","wt+");
        break;

        case 5:
        Archivo = fopen("Alumno5.txt","wt+"); //Dependiendo de que alumno el usuario quiera ingresar se va a abrir el archivo correspondiente en la maquina del usuario
        break;
    }
    if (Archivo == NULL){
        printf("El archivo no existe.\n"); //Si el usuario ingresa un numero que no esté entre el 1 y el 5 se marca error
    }
}

string Calificacion_nota(int nota){
    //comparar la calificacion
    if(nota == 100){
        return "Perfecto.";
    }
    else if(nota <= 99 && nota >= 90){
        return "Exelente.";
    }
    else if(nota <= 89 && nota >= 80){
        return "Muy bien.";
    }
    else if(nota <= 79 && nota >= 60){
        return "Regular.";
    }
    else if(nota <= 59 && nota >= 0){
        return "Reprobado.";
    }
    else {
        return "Calificacion no valida";
    }
}

void ingreso_alumno(){
    //datos del alumno
    cout << "Ingrese el nombre del alumno: " << endl;
    cin.ignore(); //Limpiar el buffer
    getline(cin, Al1.Nombre_alumno); //Guardar completamente el nombre del alumno, guardandolo en la estructura
    cout << "Ingrese la carrera: " << endl;
    getline(cin, Al1.Carrera_alumno);
}

void registro_materia(){
    //calificacion
    cout << "Ingrese el nombre de la materia 1: " << endl;
    cin.ignore();
    getline(cin, M1.Materia_cursada);
    do{
        cout << "Ingrese su calificacion: " << endl;
        cin >> M1.Calificacion;
        if(M1.Calificacion < 0 || M1.Calificacion > 100){
        cout << "Calificacion no Valida\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Para no entrar en bucle
    }while(M1.Calificacion < 0 || M1.Calificacion > 100); //Mientras el usuario no ponga un valor válido se va a hacer un bucle hasta que ponga uno que si sea
    cout << "Ingrese quien la imparte: " << endl;
    getline(cin, M1.Nombre_profesor);

    cout << "Ingrese el nombre de la materia 2: " << endl;
    getline(cin, M2.Materia_cursada);
    do{
        cout << "Ingrese su calificacion: " << endl;
        cin >> M2.Calificacion;
        if(M2.Calificacion < 0 || M2.Calificacion > 100){
        cout << "Calificacion no Valida\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(M2.Calificacion < 0 || M2.Calificacion > 100);
    cout << "Ingrese quien la imparte: " << endl;
    getline(cin, M2.Nombre_profesor);

    cout << "Ingrese el nombre de la materia 3: " << endl;
    getline(cin, M3.Materia_cursada);
    do{
        cout << "Ingrese su calificacion: " << endl;
        cin >> M3.Calificacion;
        if(M3.Calificacion < 0 || M3.Calificacion > 100){
        cout << "Calificacion no Valida\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(M3.Calificacion < 0 || M3.Calificacion > 100);
    cout << "Ingrese quien la imparte: " << endl;
    getline(cin, M3.Nombre_profesor);

    cout << "Ingrese el nombre de la materia 4: " << endl;
    getline(cin, M4.Materia_cursada);

    do{
        cout << "Ingrese su calificacion: " << endl;
        cin >> M4.Calificacion;
        if(M4.Calificacion < 0 || M4.Calificacion > 100){
        cout << "Calificacion no Valida\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(M4.Calificacion < 0 || M4.Calificacion > 100);
    cout << "Ingrese quien la imparte: " << endl;
    getline(cin, M4.Nombre_profesor);

    cout << "Ingrese el nombre de la materia 5: " << endl;
    getline(cin, M5.Materia_cursada);
    do{
        cout << "Ingrese su calificacion: " << endl;
        cin >> M5.Calificacion;
        if(M5.Calificacion < 0 || M5.Calificacion > 100){
        cout << "Calificacion no Valida\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(M5.Calificacion < 0 || M5.Calificacion > 100);
    cout << "Ingrese quien la imparte: " << endl;
    getline(cin, M5.Nombre_profesor);
}

void Ingreso_archivo(){
    //ingresar al archivo
    fprintf(Archivo, "Nombre del alumno: %s\n", Al1.Nombre_alumno.c_str()); //Guardando los datos en el archivo
    fprintf(Archivo, "Cursa la carrera: %s\n", Al1.Carrera_alumno.c_str());

    fprintf(Archivo, "\n\nLa primera materia que esta cursando el alumno es: %s\n", M1.Materia_cursada.c_str());
    fprintf(Archivo, "Impartida por el maestro %s\n", M1.Nombre_profesor.c_str());
    fprintf(Archivo, "Con una calificacion de %.2f (%s)\n", M1.Calificacion, Calificacion_nota(M1.Calificacion).c_str());

    fprintf(Archivo, "\nLa segunda materia que esta cursando el alumno es: %s\n", M2.Materia_cursada.c_str());
    fprintf(Archivo, "Impartida por el maestro %s\n", M2.Nombre_profesor.c_str());
    fprintf(Archivo, "Con una calificacion de %.2f (%s)\n", M2.Calificacion, Calificacion_nota(M2.Calificacion).c_str());

    fprintf(Archivo, "\nLa tercera materia que esta cursando el alumno es: %s\n", M3.Materia_cursada.c_str());
    fprintf(Archivo, "Impartida por el maestro %s\n", M3.Nombre_profesor.c_str());
    fprintf(Archivo, "Con una calificacion de %.2f (%s)\n", M3.Calificacion, Calificacion_nota(M3.Calificacion).c_str());

    fprintf(Archivo, "\nLa cuarta materia que esta cursando el alumno es: %s\n", M4.Materia_cursada.c_str());
    fprintf(Archivo, "Impartida por el maestro %s\n", M4.Nombre_profesor.c_str());
    fprintf(Archivo, "Con una calificacion de %.2f (%s)\n", M4.Calificacion, Calificacion_nota(M4.Calificacion).c_str());

    fprintf(Archivo, "\nLa quinta materia que esta cursando el alumno es: %s\n", M5.Materia_cursada.c_str());
    fprintf(Archivo, "Impartida por el maestro %s\n", M5.Nombre_profesor.c_str());
    fprintf(Archivo, "Con una calificacion de %.2f (%s)\n", M5.Calificacion, Calificacion_nota(M5.Calificacion).c_str());

    fclose(Archivo);
}

void mostrar(){
    int Mostrar_data;

    cout << "Datos del alumno a consultar" << endl;
    cout << "1. Alumno 1" << endl;
    cout << "2. Alumno 2" << endl;
    cout << "3. Alumno 3" << endl;
    cout << "4. Alumno 4" << endl;
    cout << "5. Alumno 5" << endl;
    cout << "\n\tIngrese la opcion deseada: ";
    cin >> Mostrar_data;

    switch(Mostrar_data){
        case 1:
        Archivo = fopen("Alumno1.txt","rt"); //Leyendo el archivo
        break;

        case 2:
        Archivo = fopen("Alumno2.txt","rt");
        break;

        case 3:
        Archivo = fopen("Alumno3.txt","rt");
        break;

        case 4:
        Archivo = fopen("Alumno4.txt","rt");
        break;

        case 5:
        Archivo = fopen("Alumno5.txt","rt");
        break;
    }
    if(Archivo == NULL){
        printf("Error al mostrar.\n");
    }
}

void editar(){
    //REPLICA EL COMPORTAMIENTO DEL INGRESO DE DATOS
    cout << "Ingresa el alumno a editar: " << endl;
    {
    seleccion();

    cout << "\n\t1. Edicion de alumno." << endl;
    cout << "\t2. Edicion de materias." << endl;
    cout << "\t3. Seguir." << endl;
    cout << "\n\tIngrese la opcion del metodo que desea usar: ";
    cin >> submenu;

    switch(submenu){
    case 1:
    ingreso_alumno();
    break;

    case 2:
    registro_materia();
    break;

    default:
    cout << "\tRegeso al menu." << endl;
    break;
    }
    Ingreso_archivo();

    }
    fclose(Archivo);
}

void borrar(){
    cout << "\tSeleccione el alumno para borrar los datos." << endl;
    seleccion();
    fclose(Archivo); //Se guarda sin datos
}

void calcular_promedio(){
    int promedio;
    promedio = M1.Calificacion + M2.Calificacion + M3.Calificacion + M4.Calificacion + M5.Calificacion;
    cout << promedio/5 << endl;
}

int main(){
    cout << "\t\t-Bienvenido-";
    do{
        cout << "\n\t1. Registro." << endl;
        cout << "\t2. Mostrar los datos ingresados." << endl;
        cout << "\t3. Edicion de datos." << endl;
        cout << "\t4. Borrado de datos." << endl;
        cout << "\t5. Calculo de promedio." << endl;
        cout << "\t6. Salir." << endl;

        cout << "\n\tIngrese la opcion del metodo que desea usar: ";
        cin >> opcion;

        switch(opcion){
            case 1://INGRESAR MATERIAS O CALIFICACIONES
            {
            seleccion();
            do{
                cout << "\n\t1. Registro de alumno." << endl;
                cout << "\t2. Registro de materias." << endl;
                cout << "\t3. Seguir." << endl;
                cout << "\n\tIngrese la opcion del metodo que desea usar: ";
                cin >> submenu;

                switch(submenu){
                case 1:
                ingreso_alumno();
                break;

                case 2:
                registro_materia();
                break;

                default:
                cout << "\tRegeso al menu." << endl;
                break;
                }

            }while(submenu != 3);

            Ingreso_archivo();

            }
            fclose(Archivo);
            break;

            case 2://IMPRIMIR LOS DATOS INGRESADOS
            {
            mostrar();
            char linea[100];

            while(fgets(linea, sizeof(linea), Archivo) != NULL) { //Para hasta que no hay más lineas de texto que leer
            cout << linea;
            }
            }

            fclose(Archivo);
            break;

            case 3:
            editar();
            cout << "Se han editado correctamente los datos del alumno" << endl;
            break;

            case 4:
            borrar();
            cout << "Se han borrado satisfactoriamente los datos del alumno" << endl;
            break;

            case 5:
            cout << "El promedio del alumno actual es de: ";
            calcular_promedio();
            break;

            case 6:
            fclose(Archivo);
            cout << "Saliendo..." << endl;
            break;
        }
    }while(opcion != 6);

    return 0;
}
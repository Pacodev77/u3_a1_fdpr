#include <stdio.h>
#include <string.h>

#define MAX_MASCOTAS 5

// Estructura para almacenar los datos de una mascota
typedef struct {
    int id;
    char nombre[50];
    char tipo[50];
    int edad;
    char dueno[50];
    int activa; // 1 para activa, 0 para eliminada
} Mascota;

// Función para mostrar los datos del estudiante
void mostrarDatosEstudiante() {
    printf("Nombre: Francisco Ruiz\n");
    printf("Matricula: ES251105301\n");
    printf("Grupo: DS-DFPR-2501-B1-002\n");
}

// Función para registrar una nueva mascota
void registrarMascota(Mascota mascotas[], int *numMascotas) {
    if (*numMascotas < MAX_MASCOTAS) {
        printf("Ingrese el ID de la mascota: ");
        if (scanf("%d", &mascotas[*numMascotas].id) != 1) {
            printf("Error al leer el ID\n");
            return;
        }

        printf("Ingrese el nombre de la mascota: ");
        if (scanf(" %[^\n]s", mascotas[*numMascotas].nombre) != 1) {
            printf("Error al leer el nombre\n");
            return;
        }

        printf("Ingrese el tipo de mascota: ");
        if (scanf(" %[^\n]s", mascotas[*numMascotas].tipo) != 1) {
            printf("Error al leer el tipo\n");
            return;
        }

        printf("Ingrese la edad de la mascota: ");
        if (scanf("%d", &mascotas[*numMascotas].edad) != 1) {
            printf("Error al leer la edad\n");
            return;
        }

        printf("Ingrese el nombre del dueño: ");
        if (scanf(" %[^\n]s", mascotas[*numMascotas].dueno) != 1) {
            printf("Error al leer el dueño\n");
            return;
        }

        mascotas[*numMascotas].activa = 1; // Establecer como activa
        (*numMascotas)++;
        printf("\nMascota registrada con éxito.\n");
    } else {
        printf("\nNo se pueden registrar más mascotas. Límite alcanzado.\n");
    }
}

// Función para listar las mascotas activas
void listarMascotas(const Mascota mascotas[], int numMascotas) {
    printf("Lista de mascotas activas:\n");
    for (int i = 0; i < numMascotas; i++) {
        if (mascotas[i].activa == 1) {
            printf("ID: %d, Nombre: %s, Tipo: %s, Edad: %d, Dueño: %s\n",
                   mascotas[i].id, mascotas[i].nombre, mascotas[i].tipo, mascotas[i].edad, mascotas[i].dueno);
        }
    }
}

// Función para buscar una mascota por ID
void buscarMascota(const Mascota mascotas[], int numMascotas) {
    int idBuscar;
    printf("\nIngrese el ID de la mascota a buscar: ");
    if (scanf("%d", &idBuscar) != 1) {
        printf("Error al leer el ID\n");
        return;
    }

    for (int i = 0; i < numMascotas; i++) {
        if (mascotas[i].id == idBuscar) {
            if (mascotas[i].activa == 1) {
                printf("\nMascota encontrada:\n");
                printf("ID: %d, Nombre: %s, Tipo: %s, Edad: %d, Dueño: %s\n",
                       mascotas[i].id, mascotas[i].nombre, mascotas[i].tipo, mascotas[i].edad, mascotas[i].dueno);
            } else {
                printf("Mascota encontrada pero eliminada.\n");
            }
            return;
        }
    }
    printf("\nMascota no encontrada.\n");
}

// Función para eliminar una mascota por ID
void eliminarMascota(Mascota mascotas[], int numMascotas) {
    int idEliminar;
    printf("Ingrese el ID de la mascota a eliminar: ");
    if (scanf("%d", &idEliminar) != 1) {
        printf("Error al leer el ID\n");
        return;
    }

    for (int i = 0; i < numMascotas; i++) {
        if (mascotas[i].id == idEliminar) {
            if (mascotas[i].activa == 1) {
                mascotas[i].activa = 0; // Marcar como eliminada
                printf("\nMascota eliminada con éxito.\n");
            } else {
                printf("\nMascota ya eliminada.\n");
            }
            return;
        }
    }
    printf("\nMascota no encontrada.\n");
}

int main() {
    Mascota mascotas[MAX_MASCOTAS];
    int numMascotas = 0;
    int opcion;

    mostrarDatosEstudiante();

    do {
        printf("\n--- Menú ---\n");
        printf("1. Registrar mascota\n");
        printf("2. Listar mascotas\n");
        printf("3. Buscar mascota\n");
        printf("4. Eliminar mascota\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida. Saliendo.\n");
            break;
        }

        switch (opcion) {
            case 1:
                registrarMascota(mascotas, &numMascotas);
                break;
            case 2:
                listarMascotas(mascotas, numMascotas);
                break;
            case 3:
                buscarMascota(mascotas, numMascotas);
                break;
            case 4:
                eliminarMascota(mascotas, numMascotas);
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}

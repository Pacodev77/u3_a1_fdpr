
#include <stdio.h>
#include <string.h>

// Función para mostrar los datos de identificación del estudiante
void mostrarDatosEstudiante() {
    printf("--------------------------------------\n");
    printf("-------DATOS DEL ESTUDIANTE-----------\n");
    printf("Nombre completo: Francisco Ruiz \n");
    printf("Matrícula: ES251105301\n");
    printf("Grupo:DS-DFPR-2501-B1-002\n");
    printf("---------------------------------------\n\n");
}

// Función para registrar la información del usuario
void registrarInformacionUsuario(char nombre[], char estadoSalud[], char sexo, int *edad, float *peso, int *altura) {
    printf("Ingrese el nombre del usuario: ");
    scanf(" %[^\n]s", nombre);
    printf("Ingrese el estado de salud (bueno, malo, lesiones o afecciones): ");
    scanf(" %[^\n]s", estadoSalud);
    printf("Ingrese el sexo (H=Hombre, M=Mujer): ");
    scanf(" %c", &sexo);
    printf("Ingrese la edad: ");
    scanf("%d", edad);
    printf("Ingrese el peso (en kilogramos): ");
    scanf("%f", peso);
    printf("Ingrese la altura (en centímetros): ");
    scanf("%f", altura);
}

// Función para calcular las calorías diarias recomendadas
float calcularCalorias(float peso, float altura, int edad, char sexo) {
    float calorias;
    if (sexo == 'H') {
        calorias = (10 * peso) + (6.25 * altura) - (5 * edad) + 5;
    } else {
        calorias = (10 * peso) + (6.25 * altura) - (5 * edad) - 161;
    }
    return calorias;
}

// Función para generar la sugerencia de actividad física
void generarSugerenciaActividad(char estadoSalud[]) {
    if (strcmp(estadoSalud, "bueno") == 0) {
        printf("\n--- Recomendaciones de Actividad Física (Estado de salud: Bueno) ---\n");
        printf("- 30 minutos de caminata.\n");
        printf("- 15 minutos de ejercicios de fuerza.\n");
        printf("- 10 minutos de estiramientos.\n");
        printf("------------------------------------------\n");
    } else if (strcmp(estadoSalud, "malo") == 0) {
        printf("\n--- Recomendaciones de Actividad Física (Estado de salud: Malo) ---\n");
        printf("Se recomienda realizar actividad física ligera, como caminar suavemente o estiramientos suaves.\n");
        printf("Es importante escuchar a tu cuerpo y descansar si sientes dolor.\n");
        printf("------------------------------------------\n");
    } else if (strcmp(estadoSalud, "lesion") == 0) {
        printf("\n--- Recomendaciones de Actividad Física (Lesión) ---\n");
        printf("Se recomienda consultar a un fisioterapeuta o especialista en rehabilitación para un plan de ejercicios personalizado.\n");
        printf("Evita cualquier actividad que cause dolor o molestias.\n");
        printf("------------------------------------------\n");
    } else if (strcmp(estadoSalud, "afeccion") == 0) {
        printf("\n--- Recomendaciones de Actividad Física (Afección) ---\n");
        printf("Se recomienda consultar a un médico o especialista para determinar qué tipo de actividad física es segura y adecuada para tu condición.\n");
        printf("------------------------------------------\n");
    } else {
        printf("Estado de salud no reconocido.\n");
    }
}

int main() {
    char nombre[100], estadoSalud[100], sexo;
    int edad;
    float peso, altura, caloriasRecomendadas;

    mostrarDatosEstudiante();
    registrarInformacionUsuario(nombre, estadoSalud, sexo, &edad, &peso, &altura);

    caloriasRecomendadas = calcularCalorias(peso, altura, edad, sexo);
    printf("\nHola %s; ", nombre);
    printf("Aquí están tus resultados:");
    printf("\nCalorias diarias recomendadas: %.2f\n", caloriasRecomendadas);

    generarSugerenciaActividad(estadoSalud);

    char continuar;
    printf("\n¿Desea calcular nuevamente para otro usuario S/N? ");
    scanf(" %c", &continuar);

    if (continuar == 'S' || continuar == 's') {
        main(); // Llamar a la función main() para reiniciar el programa
    } else if (continuar == 'N' || continuar == 'n') {
        printf("Gracias por utilizar el programa. ¡Hasta luego!\n");
    } else {
        printf("Opción no válida. El programa terminará.\n");
    }

    return 0;
}



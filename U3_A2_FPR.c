#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para la función toupper

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
void registrarInformacionUsuario(char nombre[], char estadoSalud[], char *sexo, int *edad, float *peso, float *altura) {
    printf("Ingrese el nombre del usuario: ");
    scanf(" %[^\n]s", nombre); // Lee hasta la primera línea

    // Validación del estado de salud
    do {
        printf("Ingrese el estado de salud (bueno, malo, lesiones o afecciones): ");
        scanf(" %[^\n]s", estadoSalud);
        // Convierte a minúsculas para comparar sin importar mayúsculas/minúsculas
    } while (strcmp(estadoSalud, "bueno") != 0 && strcmp(estadoSalud, "malo") != 0 &&
             strcmp(estadoSalud, "lesiones") != 0 && strcmp(estadoSalud, "afecciones") != 0);

    // Validación del sexo
    do {
        printf("Ingrese el sexo (H=Hombre, M=Mujer): ");
        scanf(" %c", sexo);
        *sexo = toupper(*sexo); // Convierte a mayúscula para validar más fácil
    } while (*sexo != 'H' && *sexo != 'M');

    // Validación de la edad
    do {
        printf("Ingrese la edad: ");
        scanf("%d", edad);
    } while (*edad <= 0); // La edad no puede ser negativa ni cero

    // Validación del peso
    do {
        printf("Ingrese el peso (en kilogramos): ");
        scanf("%f", peso);
    } while (*peso <= 0); // El peso no puede ser negativo ni cero

    // Validación de la altura
    do {
        printf("Ingrese la altura (en centímetros): ");
        scanf("%f", altura);
    } while (*altura <= 0); // La altura no puede ser negativa ni cero
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
    printf("\n--- Recomendaciones de Actividad Física (Estado de salud: %s) ---\n", estadoSalud); // Incluye el estado de salud

    if (strcmp(estadoSalud, "bueno") == 0) {
        printf("- 30 minutos de caminata.\n");
        printf("- 15 minutos de ejercicios de fuerza.\n");
        printf("- 10 minutos de estiramientos.\n");
    } else if (strcmp(estadoSalud, "malo") == 0) {
        printf("Se recomienda realizar actividad física ligera, como caminar suavemente o estiramientos suaves.\n");
        printf("Es importante escuchar a tu cuerpo y descansar si sientes dolor.\n");
    } else if (strcmp(estadoSalud, "lesiones") == 0) {
        printf("Se recomienda consultar a un fisioterapeuta o especialista en rehabilitación para un plan de ejercicios personalizado.\n");
        printf("Evita cualquier actividad que cause dolor o molestias.\n");
    } else if (strcmp(estadoSalud, "afecciones") == 0) {
        printf("Se recomienda consultar a un médico o especialista para determinar qué tipo de actividad física es segura y adecuada para tu condición.\n");
    } 
    printf("------------------------------------------\n");
}

int main() {
    char nombre[100], estadoSalud[100], sexo;
    int edad;
    float peso, altura, caloriasRecomendadas;

    mostrarDatosEstudiante();

    // Llama a la función registrarInformacionUsuario con las direcciones de memoria de las variables
    registrarInformacionUsuario(nombre, estadoSalud, &sexo, &edad, &peso, &altura);

    caloriasRecomendadas = calcularCalorias(peso, altura, edad, sexo);
    printf("\nHola %s; ", nombre);
    printf("Aquí están tus resultados:");
    printf("\nCalorias diarias recomendadas: %.2f\n", caloriasRecomendadas);

    generarSugerenciaActividad(estadoSalud);

    char continuar;
    // Bucle para preguntar si desea continuar
    do {
        printf("\n¿Desea calcular nuevamente para otro usuario S/N? ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar); // Convierte a mayúscula para validar más fácil
    } while (continuar != 'S' && continuar != 'N');

    if (continuar == 'S') {
        main(); // Llamar a la función main() para reiniciar el programa
    } else {
        printf("Gracias por utilizar el programa. ¡Hasta luego!\n");
    }

    return 0;
}
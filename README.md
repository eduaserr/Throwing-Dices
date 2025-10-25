# 🎲 Throwing Dices

Este programa simula el lanzamiento de dados en consola. Puedes elegir cuántos dados tirar, ver una animación de carga y obtener resultados aleatorios para cada dado. Al final, puedes decidir si quieres volver a tirar.
Ideal para juegos de mesa, decisiones aleatorias o simplemente para practicar programación en C.

## 🔧 Instalación y Compilación

### Compilación del Programa
```bash
# Compilar el programa
gcc -o throw_dices throw_dices.c
```

**Explicación:**
- `gcc` - Compilador de C
- `-o throw_dices` - Especifica el nombre del ejecutable
- `throw_dices.c` - Archivo fuente

## 🚀 Uso del Programa

```bash
./throw_dices
```

**Ejemplo de ejecución:**
```bash
$ ./throw_dices
Cuantos dados vas a tirar?
3
El 1º dado es:  4
El 2º dado es:  2
El 3º dado es:  6
Quieres tirar de nuevo? Y/N
```

## 🎨 Características

- ✅ Validación robusta de entrada
- ✅ Animación de carga visual
- ✅ Máximo 99 dados por tirada
- ✅ Generación aleatoria con `rand()` y `srand(time(NULL))`
- ✅ Soporte para dados de 3 a 999 caras (versión multicaras)

## 🔍 Validación de Entrada

El programa valida correctamente la entrada del usuario para evitar errores:

```c
// Siempre limpiamos el buffer después de leer
clear_stdin();

// Verificamos que scanf leyó correctamente
int ret = scanf("%d", &value);
if (ret != 1) {
	// Error: entrada no válida
}

// Verificamos el rango
if (value >= 1 && value <= 99) {
	// OK
}
```

## 📝 Notas

- El programa limpia automáticamente el buffer de entrada
- La animación se ralentiza progresivamente para mayor efecto visual
- Resultados completamente aleatorios (dentro de los límites de `rand()`)
- La versión multicaras soporta dados comunes: D4, D6, D8, D10, D12, D20, D100

**¡Que tengas suerte en tus tiradas!** 🎲🍀
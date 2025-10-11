# 🎲 Throwing Dices

Un simulador de lanzamiento de dados en C, con animación de carga y validación de entrada.
Haz tiradas de hasta un máximo de 99 dados.

## 📋 Descripción

Este programa simula el lanzamiento de dados en consola. Puedes elegir cuántos dados tirar (máximo 99), ver una animación de carga y obtener resultados aleatorios para cada dado. Al final, puedes decidir si quieres volver a tirar.  
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

### Ejecutar
```bash
./throw_dices
```

**Flujo del programa:**
1. Te pregunta cuántos dados quieres tirar (1-99)
2. Muestra una animación de carga
3. Genera números aleatorios para cada dado (1-6)
4. Te pregunta si quieres volver a tirar

### Ejemplo de Uso
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

- ✅ **Validación robusta** - Maneja entradas inválidas sin crashear
- ✅ **Animación de carga** - Efecto visual antes de mostrar resultados
- ✅ **Límite inteligente** - Máximo 99 dados por tirada
- ✅ **Números verdaderamente aleatorios** - Usa `rand()` con semilla de tiempo

## 📊 Especificaciones Técnicas

- **Rango de dados:** 1-99 por tirada
- **Valores posibles:** 1-6 (dado estándar)
- **Generador:** `rand()` con `srand(time(NULL))`
- **Animación:** 15 iteraciones con delays progresivos
- **Compilador:** GCC con estándares de C


## 📝 Notas Importantes

- El programa limpia automáticamente el buffer de entrada para evitar comportamientos extraños.
- Puedes tirar hasta 99 dados simultáneamente.
- La animación de carga se ralentiza progresivamente para mayor efecto visual.
- Los resultados son completamente aleatorios (dentro de los límites de `rand()`).

**¡Que tengas suerte en tus tiradas!** 🎲🍀
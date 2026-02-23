# 🐜 Hormiga de Langton - Práctica AYEDA
Simulación de la **Hormiga de Langton** en C++ utilizando programación orientada a objetos.  
Este proyecto sigue las indicaciones de la práctica para **Algoritmos y Estructuras de Datos Avanzadas**.

## 🔹 Descripción

La hormiga de Langton es un autómata celular bidimensional con reglas simples que generan comportamientos complejos:  
- Celda blanca → cambia a negra y gira **izquierda**  
- Celda negra → cambia a blanca y gira **derecha**  

El proyecto incluye tres clases principales:

| Clase       | Responsabilidad |
|------------|----------------|
| `Tape`      | Representa la cinta bidimensional y maneja la visualización de celdas blancas y negras |
| `Ant`       | Representa la hormiga, su posición, orientación y movimiento según las reglas |
| `Simulator` | Controla la simulación paso a paso, actualiza la cinta y la hormiga, y permite guardar el estado |

---

## 🔹 Cambios introducidos en la Práctica 2

En la Práctica 2 el proyecto se amplía para trabajar los conceptos de **herencia y polimorfismo dinámico en C++**, generalizando el comportamiento de la hormiga y permitiendo la coexistencia de distintos tipos de hormigas sobre una misma cinta.

Las principales modificaciones son:

### 🧬 Generalización de la clase `Ant`
- La clase `Ant` pasa a ser una **clase base abstracta**.
- Define un método virtual puro:


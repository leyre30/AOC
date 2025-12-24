# Dia 07 – Laboratories

**1) ¿Por qué se ha elegido este problema?** 

Hemos elegido este problema porque consiste en simular el recorrido de un rayo que se desplaza por una rejilla y puede dividirse en varios caminos. Esto obliga a controlar estados visitados, ramificaciones y condiciones de parada, lo que encaja muy bien con técnicas de recorrido vistas en clase.

**2) ¿Qué técnica o estructura de datos se emplea?**

Se utiliza una cola para realizar un recorrido tipo BFS y una matriz de visitados para evitar procesar dos veces la misma celda. Cada rayo activo se representa como un estado independiente dentro de la cola, lo que permite gestionar las divisiones de forma ordenada.

**3) ¿Cómo se ha abordado la resolución del problema?**

El rayo comienza en la posición marcada como S y avanza hacia abajo. Cuando encuentra un divisor (^), se generan dos nuevos rayos que se añaden a la cola. El algoritmo continúa procesando rayos hasta que todos salen de la rejilla o se detienen. Durante el proceso se lleva la cuenta de cuántas veces se produce una división.

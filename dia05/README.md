# Dia 05 – Cafeteria


**1) ¿Por qué se ha elegido este problema?** 

Hemos elegido este problema porque trabaja con rangos de números que pueden solaparse, lo que encaja muy bien con el uso de un árbol para organizar y procesar los datos de forma ordenada.

**2) ¿Qué técnica o estructura de datos se emplea?**

Se emplea un árbol binario de búsqueda (BST) implementado desde cero. Cada nodo almacena un intervalo y el árbol se ordena por el extremo izquierdo del rango. No se utilizan estructuras de la librería estándar.

**3) ¿Cómo se ha abordado la resolución del problema?**

Primero se insertan los intervalos en el BST. Después, mediante un recorrido inorden, se obtienen los intervalos ordenados y se fusionan los solapamientos. Con los intervalos ya fusionados, se comprueba qué identificadores pertenecen a la unión de rangos.

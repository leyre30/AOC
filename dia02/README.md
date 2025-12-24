# Dia 02 - Gift shop

**1) ¿Por qué se ha elegido este problema?**

Hemos elegido este problema porque, al trabajar con rangos grandes, aparecen muchos identificadores repetidos y es fácil recalcular las mismas comprobaciones varias veces si no se tiene cuidado. Esto hace necesario optimizar el algoritmo para evitar trabajo innecesario.

**2) ¿Qué técnica o estructura de datos se emplea?**

Se emplea una tabla hash, implementada manualmente con encadenamiento. Además, se utiliza la técnica de memorización, ya que se almacenan los resultados asociados a cada identificador para reutilizarlos si vuelven a aparecer.

**3) ¿Cómo se ha abordado la resolución del problema?**

Antes de evaluar un identificador, se comprueba si ya está almacenado en la tabla hash. Si no lo está, se calculan las condiciones de la parte 1 y de la parte 2, se guardan los resultados y se acumulan las sumas correspondientes. De esta forma se evitan comprobaciones repetidas y se mejora la eficiencia de la solución.

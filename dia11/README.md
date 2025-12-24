# Dia 11 - Reactor

<<<<<<< HEAD
**1) ¿Por qué se ha elegido este problema?**  
Hemos elegido este problema porque define un grafo dirigido y requiere contar caminos entre nodos bajo distintas condiciones, lo que lo hace adecuado para aplicar técnicas algorítmicas vistas en clase relacionadas con recorridos de grafos.

**2) ¿Qué técnica o estructura de datos se emplea?**  
Se emplea una estructura de grafo dirigido junto con recorridos en profundidad (DFS). Para evitar recalcular caminos ya explorados, se utiliza memorización de estados. En la segunda parte, el estado se amplía con información adicional para controlar si el recorrido ha pasado por ciertos nodos concretos.

**3) ¿Cómo se ha abordado la resolución del problema?**  
Se realiza un recorrido DFS con memorización para contar los caminos desde el nodo inicial hasta el nodo final. En la segunda parte, cada estado incluye información extra sobre el paso por determinados nodos, lo que permite evitar repetir subproblemas y reducir significativamente el tiempo de ejecución.

=======
**1) ¿Por qué se ha elegido este problema?** 
Hemos elegido este problema porque define un grafo dirigido y requiere contar caminos entre nodos bajo distintas condiciones, lo que lo hace adecuado para aplicar técnicas algorítmicas vistas en clase relacionadas con recorridos de grafos.

**2) ¿Qué técnica o estructura de datos se emplea?** 
Se emplea una estructura de grafo dirigido junto con recorridos en profundidad (DFS). Para evitar recalcular caminos ya explorados, se utiliza memorización de estados. En la segunda parte, el estado se amplía con información adicional para controlar si el recorrido ha pasado por ciertos nodos concretos.

**3) ¿Cómo se ha abordado la resolución del problema?** 
Se realiza un recorrido DFS con memorización para contar los caminos desde el nodo inicial hasta el nodo final. En la segunda parte, cada estado incluye información extra sobre el paso por determinados nodos, lo que permite evitar repetir subproblemas y reducir significativamente el tiempo de ejecución.


>>>>>>> 7188865 (Actualizar dias 2, 5, 7 y 11 y readmes)

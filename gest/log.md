Log del trabajo realizado por dia
HITO 1
## 20210108 FidelAznar @(1h)
Debe contener un sub item como el anterior, con la fecha de la entrada y las cuestiones generales que se realizaron, así como el tiempo total dedicado en la sesión.

## 20210225 elibalbinm @(2h45min)
Visualización de vídeos sobre el motor 2D y los mapas e investigación acerca de SFML y motores 2D en videojuegos. Creación de la rama prototipo-mapa en github a través de línea de comando.

## 20210227 elibalbinm @(6h30min)
Investigación y visualización de vídeos de Youtube acerca de cargado de mapa con SFML y C++ y creación de mapas con Tiled. Implementación de la misma en ej_modulos/Map.cpp junto con su cabecera "Map.h". Creación de mapas ejemplo con Tiled.

## 20210228 elibalbinm @(3h20min)
Búsqueda de diseño de mapas para tener una idea de cómo hacer el nuestro. Guardado de varios tipos de tilesets. Modificación de código en Map.cc y Map.h.

## 20210301 elibalbinm @(3h)
Revisión de código de Map.cpp, sigue sin funcionar correctamente el cargado de mapa. Se ha añadido función para visualizar el mapa y se ha modificado main.cpp.

## 20210302 elibalbinm @(1h55min)
Revisión de código de Map.cpp, sigue sin funcionar correctamente el cargado de mapa.

## 20210303 elibalbinm @(6h)
Revisión de código de Map.cpp, sigue sin funcionar correctamente el cargado de mapa, debuggeo del código con Visual Code.

## 20210304 elibalbinm @(3hmin)
Seguir implementando la clase de Map.cpp. Creación de más mapas con Tiled.

## 20210306 elibalbinm @(3h40min)
Revisionado de código de Map.cpp ya que no se realiza bien el cargado del mapa, (debuggeo de Map.cpp), además de implementar una cámara en main.cpp.

## 20210309 elibalbinm @(1h)
Revisión del código de Map.cpp de prototipo-mapa ubicado en ej_modulos y creación de otro mapa de ejemplo (resources/tmx/mapa-bea.tmx). Ya funciona el cargado de mapa (habría que modificar los gid manualmente en los .tmx para que no haya error a la hora de dibujar el spritesheet).

## 20210311 elibalbinm @(1h30min)
Modificación de log.md y sobre_nosotros.md en la rama 'experimental'.

## 20210225 agl131 @(1h30min)
Instalacion del entorno y máquina virtual + probando github + investigacion de los videos de la asignatura

## 20210227 agl131 @(3h21min)
Realizacion de mapas con Tiled + Investigacion del proyecto mediante videos y archivos.

## 20210228 agl131 @(3h26min)
Arreglo del core dumped del map.cpp que no cargaba mapas debido a que el mapa no se trataba correctamente a la hora de nombrar y crear punteros

## 20210301 agl131 @(3h38min)
Reestructuracion del documento map.cpp + intento de compilacion (que se tuvo que borrar mas adelante por fallos en la implementacion)

## 20210302 agl131 @(1h26min)
Correcion de Mapa solo imprimia la primera layer, puesto que guardabamos esta en la data del objeto y no recopilabamos bien la informacion

## 20210226 dhamyx @(3h52min)
Implementacion de la barra de vida y de mana. A su vez se esta establecido que el jugador gane y pierda vida asi como el mana

## 20210306 dhamyx @(1h13min)
Implementacion del hud del inventario principal

## 20210306 dhamyx @(1h31min)
Implementacion de la clase moneda por el cual el jugador al colisionar con la misma gana monedas. A su vez se implemento el mecanismo de que gaste las monedas y la interfaz pertinente para mostrarle las monedas en todo momento

## 20210312 dhamyx @(4h56min)
Implementacion de la tienda dibujando los objetos a comprar con su respectivo valor desvelaado encima del sprite del objeto. Entre los defectos se hallan el fallo en contables ocasiones de que se repitan los objetos de la tienda.

## 20210313 dhamyx @(3h46min)
Implementacion de la compra-venta de la tienda , en la que el jugador si colisiona con el objeto y tiene el dinero suficiente compra el objeto con la tecla , la cual , se refleja en el mensaje . Una vez comprado el objeto se guarda en el inventario. Entre los desperfectos de la implementacion se encuentran el hecho de que el mensaje de compra se muestra solo en el objeto de la derecha en el caso de que esten los dos objetos en la tienda.

## 20210226 Beatriz1928 @(1h46min)
Buscar informacion sobre como hacer las colisiones

## 20210227 Beatriz1928 @(1h3min)
Hacer las colisiones y un cuadrado con el que el personaje pueda comprobar que funcionan

## 20210227 Beatriz1928 @(34min)
Buscar los sprites para los personajes principales y crearlos

## 20210301 Beatriz1928 @(1h12min)
Hacer los spritesheets de cada uno de los personajes y de un enemigo

## 20210301 Beatriz1928 @(25min)
Cargar el sprite del personaje principal

## 20210309 Beatriz1928 @(59min)
Revision y arreglo con elibalbinm del codigo del mapa ya que no cargaba correctamente. Creacion de mapas de prueba

## 20210311 Beatriz1928 @(38min)
Arreglo de un bug que en colision con Gines98

## 20210313 Beatriz1928 @(39min)
Creacion del mapa de colisiones.

## 20210226 Gines98 @(2h)
Investigacion e intento de implementacion de colisiones con Beatriz1928

## 20210227 Gines98 @(1h)
Investigacion sobre metodos de movimiento de personajes

## 20210227 Gines98 @(2h50min)
Investigación e implementacion de movimiento de personajes

## 20210301 Gines98 @(1h17min)
Investigacion e implementacion sin exito de metodo para animacion del sprite

## 20210311 Gines98 @(30min)
Arreglo fallo en una colision con Beatriz1928

## 20210311 Gines98 @(1h24min)
Creacion metodo para cargar sprites

## 20210311 Gines98 @(1h24min)
Creacion de metodo de animacion de personajes

## 20210312 Gines98 @(1h53min)
Arreglo fallo metodo para cargar sprites

## 20210314 Gines98 @(2h18min)
Implementacion animacion de los sprites

HITO 2
## 20210320 elibalbinm @(2h14min)
Correción de la documentación de GitHub (gdd.md)

## 20210324 elibalbinm @(2h46min)
Correción de código y pruebas de compilación.

## 20210324 dhamyx, Gines98, Beatriz1928, agl131 @(1h15min)
Correción de código y pruebas de compilación.

## 20210325 elibalbinm @(3h08min)
Creación de la rama menú, correción de código, pruebas de compilación y realización del menú.

## 20210325 dhamyx @(1h52min)
Creación de la rama menú, correción de código, pruebas de compilación y realización del menú.

## 20210325 Gines98 @(55min)
Intento de movimiento de jugador.

## 20210326 elibalbinm @(2h03min)
Modificación de varias clases para la implementación de menú.

## 20210326 dhamyx @(1h19min)
Modificación de varias clases para la implementación de menú.

## 20210226 Beatriz1928 @(1h46min)
Buscar informacion sobre como hacer las colisiones

## 20210326 Gines98 @(1h15min)
Avances con el movimiento de jugador.

## 20210327 dhamyx @(1h30min)
Implementación de los modos de juego y posibilidad de salir del juego mediante exit.

## 20210327 Beatriz1928 @(1h)
Limpieza codigo.

## 20210327 Gines98 @(1h15min)
Movimiento de jugador acabado.

## 20210327 agl131 @(2h32min)
Script mapa aleatorio (cargado de salas al principio de iniciar el juego array).

## 20210330 dhamyx, elibalbinm @(46min)
Implementación de las opciones del submenú de opciones.Al final no ha quedado claro como enfocar esta parte y hemos pasado a otra tarea más urgente de realizar

## 20210330 dhamyx, elibalbinm @(1h54min)
Integración de los elementos del mundo cuando pulsamos New Game.Tenemos integrado tanto el HUD como el Sprite del jugador.

## 20210330 agl131 @(3h21min)
Creacion de mapas con Tiled.

## 20210331 dhamyx, elibalbinm @(2h)
Creación de la clase Enemigo, dibujar en el mundo.

## 20210401 Beatriz1928, elibalbinm @(2h30min)
Modificación de la clase Jugador y Enemigo.

## 20210401 Gines98 @(1h40min)
Modificación de la clase Jugador y Animacion.

## 20210402 agl131 @(2h39min)
Mapas nivel 1 completados con Tiled.

## 20210404 Gines98 @(3h37min)
Arreglo fallo de movimiento de Jugador.

## 20210404 Beatriz1928 @(2h50min)
Arreglo fallo de movimiento de Jugador.

## 20210404 dhamyx @(4h37min)
Arreglo fallo de movimiento de Jugador.

## 20210404 elibalbinm @(7h37min)
Arreglo fallo de movimiento de Jugador. Creacion clase Sprite, variables y funciones.

## 20210405 elibalbinm @(5h14min)
Motor grafico, clase sprites acabada. Modificacion de la clase Mapa.

## 20210405 agl131 @(2h26min)
Correcion de la clase Mapa + arreglo de los .tmx

## 20210406 dhamyx @(3h15min)
Implementacion de las clases Sprite y Textura en el HUD

## 20210406 elibalbinm @(2h50min)
Implementacion de las clases Sprite y Textura en el HUD

## 20210406 Gines98 @(1h48min)
Implementacion de las clases Sprite y Textura en el HUD

## 20210407 elibalbinm @(6h15)
Modificación clase de Animación, Mapa y Jugador para ver el funcionamiento de la Animación y Colisiones con el mapa.

## 20210407 Gines98 @(4h)
Modificación clase de Animación, Mapa y Jugador para ver el funcionamiento de la Animación y Colisiones con el mapa.

## 20210407 dhamyx @(2h06min)
Modificación clase de Animación, Mapa y Jugador para ver el funcionamiento de la Animación y Colisiones con el mapa.

## 20210407 Beatriz1928 @(4h25min)
Modificación clase de Animación, Mapa y Jugador para ver el funcionamiento de la Animación y Colisiones con el mapa.

## 20210407 agl131 @(1h40min)
Modificación clase Mapa y realización script para la creación de salas.

## 20210408 dhamyx, elibalbinm @(2h31min)
Intento de hacer colisiones con Jugador y Mapa.

## 20210409 elibalbinm @(1h44min)
Modificación de la clase Mapa para comprobar las colisiones.

## 20210409 Beatriz1928 @(1h35min)
Arreglo de mapas.

## 20210410 elibalbinm @(1h55min)
Colision de jugador hecha.

## 20210410 dhamyx @(1h10min)
Colision de jugador hecha.

## 20210410 agl131, elibalbim @(1h35min)
Arrays salidas + comprobacion jugador salida (incompleta + destruccion y spawn point (incomp)).

## 20210411 agl131 @(1h)
Cambio de salas y array de enemigos.

## 20210411 Gines98 @(1h51min)
Modificación de la clase Enemigo y clase Mapa para el cambio de sala.

## 20210411 elibalbinm @(3h33min)
Modificación de la clase Mapa para el cambio de sala, debuggeo de código.

## 20210411 dhamyx @(3h44min)
Modificación de la clase Mapa para el cambio de sala, debuggeo de código.

## 20210411 Beatriz1928 @(4h)
Creacion de mapas restantes de el segundo nivel y movimiento

## 20210412 agl131, elibalbinm, Gines98, Beatriz1928 @(1h)
Limpieza de codigo

## 20210413 dhamyx @(1h36min)
Movimiento del enemigo

## 20210413 Gines98 @(2h35min)
Movimiento del enemigo

## 20210413 Beatriz1928 @(3h)
Movimiento del enemigo

## 20210414 dhamyx @(50min)
Modificación de la clase Mapa para el cambio de sala, debuggeo de código.

## 20210414 agl131 @(1h36min)
Modificación de la clase Mapa para el cambio de sala, debuggeo de código.

## 20210414 Gines98 @(1h27min)
Modificación de la clase Enemigo y IA.

## 20210414 Beatriz1928 @(2h46min)
Modificación de la clase Enemigo y IA.

## 20210314 elibalbinm @(3h25min)
Modificación de la clase Mapa y Mundo para el cambio de sala, debuggeo de código y arreglo final del cambio de sala con éxito.

## 20210415 elibalbinm, agl131 @(2h59min)
Arreglo de cambio de sala (en función de la variante). Se ha modificado las clases Mundo y Mapa (constructor de Mapa). Modificación de los ficheros .tmx con Tiled.

## 20210415 Gines98 @(1h23min)
Implementación de algoritmo de IA.

## 20210415 Beatriz1928 @(3h53min)
Implementación de algoritmo de IA.

## 20210416 elibalbinm, agl131 @(2h40min)
Intento de mejora en cambio de sala (modificación de las clases Jugador y Mapa) y mejora de colisiones (rango de colisiones).

## 20210416 Beatriz1928, Gines98 @(2h53min)
Implementación de algoritmo de IA.

## 20210417 dhamyx @(1h)
Modificación de la clase Mapa, Jugador y Mundo para arreglar la colisión y movimiento de Jugador al cambiar de sala. Todo esto en la rama de 'cambiar-salas'.

## 20210417 elibalbinm @(4h30min)
Intento de mejora en cambio de sala (modificación de las clases Jugador, Mundo y Mapa) y mejora de colisiones (rango de colisiones). Creación de spawn. Todo esto en la rama de 'cambiar-salas'.

## 20210417 agl131 @(3h50min)
Intento de mejora en cambio de sala (modificación de las clases Jugador, Mundo y Mapa) y mejora de colisiones (rango de colisiones). Creación de spawn. Todo esto en la rama de 'cambiar-salas'.

## 20210417 Gines98 @(20min)
Implementación de algoritmo de IA.

## 20210421 elibalbinm @(1h02min)
Intento de hacer Screen Scrolling.

## 20210421 Gines98, Beatriz1928 @(2h12min)
Intento de IA y colisiones enemigo

## 20210421 dhamyx @(1h49min)
Intento de IA y colisiones enemigo

## 20210422 elibalbinm @(1h25min)
Screen scrolling.

## 20210426 elibalbinm @(1h59min)
Intento de IA

## 20210426 Gines98(58min)
Intento de IA

## 20210426 Beatriz1928 (1h51min)
Intento IA

## 20210427 elibalbinm @(5h)
Implementación de dibujado de enemigos en mapa y debugeo de IA. (Modificación de las clases Mapa, Enemigo, Mundo e IA).

## 20210427 agl131 @(3h30min)
Implementación de dibujado de enemigos en mapa. (Modificación de las clases Mapa, Enemigo, Mundo).

## 20210427 Gines98(3h53min)
Intento de IA

## 20210427 Beatriz1928 (4h20min)
Intento IA

## 20210427 dhamyx @(2h)
Implementación de dibujado del arma del personaje y movimiento del enemigo.

## 20210428 Gines98 (2h23min)
Movimiento IA completo

## 20210428 Beatriz1928 (3h36min)
Movimiento IA completo

## 20210428 elibalbinm (3h11min)
Modificación de clases Item, Jugador y NPC.

## 20210429 elibalbinm @(4h16min)
Implementación de dibujado del arma del personaje y movimiento del enemigo.

## 20210429 agl131 @(2h15min)
Implementación de dibujado del arma del personaje y movimiento del enemigo.

## 20210429 dhamyx @(2h)
Implementación de dibujado del arma del personaje y movimiento del enemigo.

## 20210430 elibalbinm @(1h41min)
Implementación de arma de jugador.

## 20210501 dhamyx,agl131 @(1h45min)
Persecucion del enemigo y modificacion de sala.

## 20210502 dhamyx,Gines98 @(1h35min)
Persecucion del enemigo

## 20210502 Beatriz1928 @(1h12min)
Persecucion del enemigo

## 20210503 dhamyx @(1h13min)
Persecucion del enemigo terminada

## 20210503 Beatriz1928, Gines98 @(1h35min)
Persecucion del enemigo terminada

## 20210503 elibalbinm, agl131 @(3h15min)
Dibujo de arma del Jugador y Scroll del juego acabado.

## 20210504 Beatriz1928 @(1h02min)
Modificación clases Mundo, Enemigo y HUD.

## 20210504 dhamyx @(1h20min)
Modificación clases Mundo, Enemigo y HUD.

## 20210504 elibalbinm @(1h50min)
Modificación clases Mundo, Mapa, Enemigo y HUD.

## 20210504 dhamyx @(1h10min)
Implementacion Proyectil

## 20210504 Gines98 @(1h10min)
Implementacion Proyectil

## 20210504 Beatriz1928 @(1h56min)
Implementacion Proyectil

## 20210505 elibalbinm @(2h30min)
Modificación del HUD.

## 20210506 agl131, elibalbinm @(1h)
Implementación del cambio de arma (dash) en proceso al hacer click izquierdo.

## 20210506 Gines98 @(1h05min)
Implementacion de proyectil

## 20210508 dhamyx @(2h13min)
Implementar hitbox arma y retocar hud

## 20210508 agl131, @(4h)
Implementación del hitbox del arma.

## 20210508 elibalbinm @(2h50min)
Implementación del hitbox del arma.

## 20210508 Beatriz1928 @(2h15min)
Implementar hitbox arma y animacion de sprites.

## 20210509 dhamyx @(1h40min)
Implementacion de proyectil.

## 20210509 Gines98 @(2h06min)
Implementacion de proyectil.

## 20210509 Beatriz1928 @(2h50min)
Implementacion de proyectil.

## 20210509 elibalbinm, agl131 @(2h27min)
Arreglo animación de enemigo.

## 20210510 Gines98, Beatriz1928 @(3h25min)
Colision y autodestrucción de proyectil y animación de enemigo arreglada.

## 20210510 elibalbinm @(3h)
Arreglo hud, pequeñas modificaciones de parámetro en el draw de Mapa para que se dibuje el jugador en Mapa.cpp en función de las capas y no en Mundo (si se hace esto, el juego se mueve lento). Debuggeo de código para ver fallo del proyectil (se dibuja mal cuando dispara hacia abajo).

## 20210511 agl131 @(4h)
Ataque y arreglo completo del juego.

## 20210511 Gines98 @(2h56min)
Ataque y arreglo completo del juego.

## 20210511 dhamyx, Beatriz1928 @(4h10min)
Ataque y arreglo completo del juego.

## 20210511 elibalbinm @(6h30min)
Ataque y arreglo completo del juego (continuación de añadir los commits restantes a la rama Arreglo + comprobaciones de proyectiles y muerte enemigos).

## 20210512 dhamyx, Beatriz1928 @(1h56min)
Arreglo del arma y proyectil (desaparece el enemigo a falta de eliminar el puntero).

## 20210512 elibalbinm @(3h)
Arreglo del arma y proyectil (desaparece el enemigo a falta de eliminar el puntero) y modificación de Mundo.cpp.

## 20210512 Gines98 @(1h05min)
Ataque con el arma y proyectil jugador

## 20210513 dhamyx @(4h20min)
Arreglo del HUD e implementación de la tienda.

## 20210513 elibalbinm @(13h) 
Arreglo del arma y proyectil (desaparece el enemigo a falta de eliminar el puntero) + modificación del menú (búsqueda de imágenes/sprites para hacer la parte visual del menú y modificación con Photoshop), animar el menú y animar moneda.

## 20210513 agl131 @(9h08min)
Modificación del menú (búsqueda de imágenes/sprites para hacer la parte visual del menú y modificación con Photoshop), modificación de mapas, dibujado NPC + diálogo.

## 20210513 dhamyx @(2h20min)
Arreglo animacion de la moneda.

## 20210513 Gines98 @(2h04min)
animar el menú + sprites + imágenes de los menús + proyectil de los enemigos. 

## 20210513 Beatriz1928 @(9h)
Creación de enemigos + modificación del menú (búsqueda de imágenes/sprites para hacer la parte visual del menú y modificación con Photoshop), animar el menú + sprites + imágenes de los menús + proyectil de los enemigos. 

## 20210514 elibalbinm @(4h30min)
Intento de animar personaje cuando está quieto mirando hacia abajo. (Se ha creado variable playerAnimation en Jugador.h y realizado draw y update de dicha animación, además de editar el sprite en Photoshop) + subir tmx a developer y seguir con la animación de jugador. Animación de llave.

## 20210514 dhamyx @(4h)
Arreglar cosas del menú, implementar llave y solucionar cosas del proyectil del Enemigo.

## 20210514 Beatriz1928 @(7h09min)
Arreglar cosas del menú, implementar llave y solucionar cosas del proyectil del Enemigo.

## 20210514 agl131 @(2h10min)
Arreglo de mapas e implementación de llave.

## 20210514 Gines98 @(3h30min)
Implementacion del proyectil enemigo

## 20210514 Beatriz1928 @(1hmin)
Implementar sala del boss

## 20210514 dhamyx @(1h37min)
Dibujar inventario e implementar compra-venta;

## 20210514 agl131 @(1h37min)
Implementar sala de boss.

## 20210515 Beatriz1928 @(6h21min)
Implementar sprite enemigo , implementar enemigo ,arreglo hitbox, arreglo proyectil

## 20210515 elibalbinm, dhamyx @(2h20min)
Tienda funcional. Modificación de las clases HUD, Item, Tienda, Mundo y Animación.

## 20210515 dhamyx @(2h30min)
Implementar pantalla de has perdido , mostrar en inventario el item que esta equipado , y solucionar warnings

## 20210516 dhamyx @(4h20min)
Implementar pantalla de has perdido , implementar destructor de Mundo , solucionar el flujo de estados Fin-Menu y Menu-Juego y solucionar warnings

## 20210516 Gines98 @(5h1min)
Arreglar vel enemigos , arreglar vel proyectil, arreglar llave

## 20210516 Beatriz1928 @(6h)
Implementar sprites de boss y enemigos, implementar sprites armas y menu

## 20210516 dhamyx @(6h54min)
Implementar pantalla de has ganado , dibujar llave en el hud , solucionar proyectil enemigo, solucionar velocidad enemigo , solucionar violacion de segmento al morir

## 20210517 dhamyx @(1h40min)
Implementar pantalla de has ganado , dibujar llave en el hud , implementar contador de quest , acabar primera version del juego

## 20210517 Beatriz1928 @(1h30min)
Implementar pantalla de has ganado, dibujar llave en el hud , implementar contador de quest , acabar primera version del juego

## 20210517 elibalbinm @(1h15min)
Arreglo del log y relleno de tareas

## 20210517 elibalbinm @(50min)
Grabacion video

## 20210517 agl131 @(50min)
Grabacion video

## 20210517 dhamyx, Beatriz1928 @(2h30min)
Retocar hitbox enemigo, stats players, log, tareas, checklist

## 20210517 Gines58 @(1h50min)
Últimos retoques y setup.h

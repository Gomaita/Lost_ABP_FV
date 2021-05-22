#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE

    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Proyectil.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Animacion.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Contexto.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Enemigo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Fin.cpp" 
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/HUD.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Item.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Juego.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Jugador.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Mapa.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Menu.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Moneda.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Opciones.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Win.cpp"      
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Mundo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/NPC.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Sprite.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Texture.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/Tienda.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/modulos/tinyxml2.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/headers"
)

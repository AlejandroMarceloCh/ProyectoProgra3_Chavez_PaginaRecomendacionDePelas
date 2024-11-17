# Establece la versión mínima de CMake y el nombre del proyecto
cmake_minimum_required(VERSION 3.10)
project(ProyectoProgra3)

# Configuración de C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agrega la opción para habilitar compilación en modo de depuración
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")

# Incluir las cabeceras de httplib y otras dependencias en el proyecto
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(include)
include_directories(/usr/local/include) # Si tienes otras dependencias en /usr/local/include

# Añadir todos los archivos fuente necesarios
set(SOURCES
    src/server.cpp
    src/endpoints.cpp
    src/movie.cpp
    src/movie_database.cpp
    src/recommendation_system.cpp
    src/search_engine.cpp
    src/trie.cpp
    src/user.cpp
    src/recommendation_factory.cpp
    src/authentication.cpp
    src/globals.cpp
)

# Define el ejecutable
add_executable(ProyectoProgra3 ${SOURCES})

# Configurar bibliotecas necesarias (si usas pthreads y nlohmann/json)
find_package(Threads REQUIRED)
target_link_libraries(ProyectoProgra3 PRIVATE Threads::Threads)

# Para nlohmann/json (si está instalada en el sistema):
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(ProyectoProgra3 PRIVATE nlohmann_json::nlohmann_json)

# Configura salida en la carpeta bin
set_target_properties(ProyectoProgra3 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Muestra mensajes para depuración
message("Configuración completada para el proyecto ProyectoProgra3.")

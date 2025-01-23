# Definindo a versão mínima do CMake necessária
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(ProjetoFinalBoasPraticas)

# Definir o padrão de compilação
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Adicionar os diretórios onde os arquivos de cabeçalho estão localizados
include_directories(
    algoritmosDeBusca
    algoritmosDeOrdenacao
    medicao
    utilitarios
)

# Adicionar os arquivos fonte para cada subdiretório
add_library(algoritmosDeBusca
    algoritmosDeBusca/BuscaBinaria.cpp
    algoritmosDeBusca/BuscaBinariaRecursiva.cpp
    algoritmosDeBusca/BuscaLinear.cpp
)

add_library(algoritmosDeOrdenacao
    algoritmosDeOrdenacao/BubbleSortIterativo.cpp
    algoritmosDeOrdenacao/BubbleSortRecursivo.cpp
    algoritmosDeOrdenacao/MergeSortIterativo.cpp
    algoritmosDeOrdenacao/MergeSortRecursivo.cpp
    algoritmosDeOrdenacao/QuickSortIterativo.cpp
    algoritmosDeOrdenacao/QuickSortRecursivo.cpp
)

add_library(medicao
    medicao/MedicaoDeTempo.cpp
    medicao/EscritaDeArquivos.cpp
)

add_library(utilitarios
    utilitarios/Utilitarios.cpp
)

# Garantir que 'utilitarios' reconheça dependências de 'medicao'
target_link_libraries(utilitarios
    PUBLIC medicao
)

# Criar o executável principal para o menu interativo
add_executable(menuPrincipal main.cpp)

# Vincular as bibliotecas ao executável principal
target_link_libraries(menuPrincipal
    PUBLIC
    algoritmosDeBusca
    algoritmosDeOrdenacao
    utilitarios
)

# Ativar suporte ao FetchContent para o Google Test
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

# Fazer o download e preparar o Google Test
FetchContent_MakeAvailable(googletest)

# Criar o executável de testes
add_executable(rodarTestes testes/testes.cpp)

# Vincular Google Test e as bibliotecas ao executável de testes
target_link_libraries(rodarTestes
    gtest
    gtest_main
    algoritmosDeBusca
    algoritmosDeOrdenacao
    utilitarios
)

# Incluir o diretório do Google Test
target_include_directories(rodarTestes PRIVATE ${gtest_SOURCE_DIR}/include)

# Habilitar a execução de testes com CTest
enable_testing()
add_test(NAME RunAllTests COMMAND rodarTestes)

# Adicionar opções para rodar separadamente os testes e o executável principal
add_custom_target(run-tests COMMAND ctest --output-on-failure
    DEPENDS rodarTestes
    COMMENT "Executando testes com Google Test"
)

add_custom_target(run-menu COMMAND menuPrincipal
    DEPENDS menuPrincipal
    COMMENT "Executando o menu interativo"
)
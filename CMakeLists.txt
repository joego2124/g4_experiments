cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_ASM_COMPILER_WORKS 1)

project(g4_experiment C CXX ASM)

# Set language standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

get_filename_component(CURR_PROJECT_NAME g4_experiment NAME)

# Generic compiler settings
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)
add_compile_options(-O0 -Wall -Werror)
add_link_options(-Wl,--print-memory-usage)
# add_link_options(-Wl,-gc-sections,--print-memory-usage)

add_executable(${CURR_PROJECT_NAME}.elf
    main.c

    startup_stm32g474xx.c
)

include_directories(
    ./
    hal
)

target_compile_definitions(${CURR_PROJECT_NAME}.elf PUBLIC CORE_CM4 STM32G4 STM32G474xx DEBUG)

target_compile_options(${CURR_PROJECT_NAME}.elf PUBLIC -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -nolibc -nostartfiles)
target_link_options(${CURR_PROJECT_NAME}.elf PUBLIC -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -nolibc -nostartfiles)

target_link_options(${CURR_PROJECT_NAME}.elf PUBLIC LINKER:-Map=${CURR_PROJECT_NAME}.map)
target_link_options(${CURR_PROJECT_NAME}.elf PUBLIC -T${CMAKE_SOURCE_DIR}/STM32G474RET.ld)

set(ELF_FILE "${CMAKE_BINARY_DIR}/${CURR_PROJECT_NAME}.elf")
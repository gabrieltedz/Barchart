cmake_minimum_required(VERSION 3.5)
project (BarCharRace VERSION 1.0.0 LANGUAGES CXX )

# Currently CMake (since 2.8.5) supports generation of compilation databases
# for Unix Makefile builds (Ninja builds in the works) with the option
# CMAKE_EXPORT_COMPILE_COMMANDS.
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#=== FINDING PACKAGES ===#


#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )

#=== Main App ===

# include_directories( "core" "libs" )

add_executable(bcr  "0Main.cpp"
                    "1a_BCR.cpp"
                    "2a_Database.cpp"
                    "3a_Barchart.cpp"
                    "4a_Bar.cpp"
                    "5a_Tokenizer.cpp" )

target_compile_features( bcr PUBLIC cxx_std_17 )

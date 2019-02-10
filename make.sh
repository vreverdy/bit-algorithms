#!/bin/bash
# =================================== MAKE =================================== #
# Project: 			The Experimental Bit Algorithms Library
# Name:				make.sh
# Description: 		Main makefile to compile different components of the project
# Creator:         	Vincent Reverdy
# Contributor(s):  	Vincent Reverdy [2019]
# License:         	BSD 3-Clause License
# ============================================================================ #
# This file allows to compile several parts of the bit algorithms library:
# 	- ./make.sh clean: removes temporary compilation files
#	- ./make.sh update: updates dependencies from online repositories
#	- ./make.sh doc: compiles documentation using latex
# ============================================================================ #



# ================================ PARAMETERS ================================ #
# Compiler for C++ compilation
COMPILER=g++
# Flags for C++ compilation
FLAGS="-std=c++17"
WFLAGS="-pedantic -Wall -Wextra -Wfatal-errors"
OFLAGS="-O3 -g -DNDEBUG -march=native -mtune=native"
DFLAGS="-O0 -g"
# ---------------------------------------------------------------------------- #
# Latex compilation
LATEX=pdflatex
BIBTEX=bibtex
# ============================================================================ #

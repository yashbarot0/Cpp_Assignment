#
# Description: 	Makefile for Assignment 1. 5614
# Author: 	R. Morrin
# Version: 	1.0
# Modified: 	2025-02-05

CXX 		:= g++
CXXFLAGS 	:=  --std=c++23    -Wextra -Wall  
LDFLAGS 	:= 


SRCS 		:= references.cc\
		   reorganise

EXES 		:= ${SRCS:.cc=}

all: ${EXES} 

${EXES}: %: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)


.PHONY: clean all

clean:
	$(RM) $(EXES) 


CFLAGS = -std=c++14 -Wall -Wextra -Wshadow -pedantic -I.
LDFLAGS = -lGL -lGLU -lglut

CC = gcc
CXX = g++

DEPS_SRC = demo.cpp
DEPS = $(DEPS_SRC:.cpp=.o)

BIN = demo

all: $(BIN)

demo: demo.o
	@echo "LD $@"
	@$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.c delaunay.hpp
	@echo "CC $<"
	@$(CC) -c $< -o $@ $(CFLAGS)

%.o: %.cpp
	@echo "CXX $<"
	@$(CXX) -c $< -o $@ $(CFLAGS)

clean:
	@echo "RM $(DEPS) $(BIN)"
	@rm -f $(DEPS) $(BIN) *.o

.PHONY: all clean

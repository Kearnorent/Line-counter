CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -pedantic -std=c++17 -fsanitize=address -g
LDFLAGS=
VPATH=src

SRC=main.cc find.cc pattern.cc utils.cc options.cc words.cc
OBJS=$(SRC:.cc=.o)

all: cl

cl: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm cl *.o

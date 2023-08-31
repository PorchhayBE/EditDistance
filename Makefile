CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-system
DEPS = EDistance.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: EDistance

EDistance: main.o EDistance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm *.o EDistance
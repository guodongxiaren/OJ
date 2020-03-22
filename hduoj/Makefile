SOURCE = $(wildcard *.cpp)
BIN = $(patsubst %.cpp,%,$(SOURCE))
CC = g++
CFLAGS = -Werror=return-type

ALL: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean love
clean:
	rm -rf *.out *.o *.so *.lib $(UT)
love:
	$(MAKE) clean && $(MAKE)

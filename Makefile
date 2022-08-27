CFLAGS = -g
CC = gcc

program_NAME = bin/main
program_SRCS = $(wildcard src/*.c)
program_OBJS = ${program_SRCS:.c=.o}
program_INCLUDES = include/ /usr/include

FLAGS = $(foreach dir, $(program_INCLUDES), -I$(dir))

.PHONY: all clean

all: $(program_NAME)

$(program_NAME): $(program_SRCS)
	$(CC) $(program_SRCS) -o $@ $(FLAGS) $(CFLAGS) -Wall -Wextra

clean:
	rm -rf $(program_NAME)
	rm -rf $(program_OBJS)


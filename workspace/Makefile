CC = gcc
CFLAGS = -g
SRCS = project_main.c complex.c
LDFLAGS = -lm

SRCS = project_main.c complex.c dataframe.c save_load.c
OBJS = $(SRCS:.c=.o)
TARGET = project_main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
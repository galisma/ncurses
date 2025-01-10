# Variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses
TARGET = programa

# Archivos fuente
SRCS = main.cpp

# Regla principal
all: $(TARGET)

# Regla para compilar el programa
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET)

# Regla para ejecutar
exec: $(TARGET)
	./$(TARGET)

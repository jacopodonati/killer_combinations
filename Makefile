# Nome del programma
TARGET = kc

# Compilatore
CC = clang

# Opzioni di compilazione
CFLAGS = -Wall -Wextra -O2

# File sorgente
SRCS = kc.c

# File oggetto
OBJS = $(SRCS:.c=.o)

# Regola principale per la compilazione
all: $(TARGET)

# Regola per creare l'eseguibile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regola per compilare i file sorgente in file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Regola per pulire i file generati
clean:
	rm -f $(OBJS) $(TARGET)

# Regola per eseguire il programma
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

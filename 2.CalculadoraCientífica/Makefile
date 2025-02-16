# Definição do compilador
CC = gcc

# Flags de compilação (-Wall ativa avisos do compilador)
CFLAGS = -Wall

# Nome do executável
TARGET = calculadora_cientifica

# Regra padrão para compilar o projeto
all: $(TARGET)

# Como criar o executável a partir do código-fonte
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

# Limpa os arquivos compilados
clean:
	rm -f $(TARGET)

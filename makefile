
CC = gcc
TARGET = calc
all:
	${CC} *.c src/*.c -o ${TARGET}

install:
	install -m 755 $(TARGET) /usr/bin/$(TARGET)

clean:
	rm -f $(TARGET)
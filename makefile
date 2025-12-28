
CC = gcc
TARGET = calc
all:
	@echo "installing the calc"
	@${CC} *.c -o ${TARGET}

install:
	install -m 755 $(TARGET) /usr/bin/$(TARGET)

clean:
	rm -f $(TARGET)
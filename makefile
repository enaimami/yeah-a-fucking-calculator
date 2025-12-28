
CC = gcc
TARGET = calc
all:
	@echo "installing the calc welcom :3"
	@${CC} *.c -o ${TARGET}

install:
	@echo "installing to your system"
	@install -m 755 $(TARGET) /usr/bin/$(TARGET)

clean:
	@echo "bye :<"
	@rm -f $(TARGET)
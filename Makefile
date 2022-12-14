# termble
CC = gcc
FILES = main.c
NAME = termble
DIR = /usr/bin
SCRIPT = termble_get.js
DATA = termble_data

build:
	$(CC) $(FILES) -o $(NAME)

install:
	make build
	cp -f $(NAME) $(DIR)/$(NAME)
	cp -f $(SCRIPT) $(DIR)/$(SCRIPT)
	cp -r $(DATA) $(DIR)/$(DATA)
	echo "Successfully installed $(NAME)."

uninstall:
	rm -f $(DIR)/$(NAME)
	rm -f $(DIR)/$(SCRIPT)
	rm -r $(DIR)/$(DATA)
	echo "Successfully uninstalled $(NAME)."

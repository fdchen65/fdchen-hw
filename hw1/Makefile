CC = g++  
CC_FLAG = -g -Wall 
all: listTest

listTest: ulliststr_test.cpp ulliststr.o
	$(CC) $(CC_FLAG) $^ -o $@

ulliststr.o: ulliststr.cpp
	$(CC) $(CC_FLAG) $^ -o $@

.PHONY: clean
clean: 
	-@rm -rf test
	-@echo All clean!

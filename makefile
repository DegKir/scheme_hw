# Компилятор и его флаги
CC = clang++
CFLAGS = -std=c++17 -Wall -Wextra -g

# Директории с исходными файлами, заголовочными файлами и объектными файлами
SRC_DIR = src
INCLUDE_DIR = headers
OBJ_DIR = obj
TESTS_DIR = Tests

# Исходные файлы
SOURCES = operators_generators.cpp scheme.cpp solution.cpp
TEST_SOURCES = conservative_test.cpp linearization_test.cpp main.cpp

# Генерация путей к исходным, заголовочным и объектным файлам
SOURCE_PATHS = $(addprefix $(SRC_DIR)/, $(SOURCES))
HEADER_PATHS = $(addprefix $(INCLUDE_DIR)/, $(wildcard *.hpp))
TEST_SOURCE_PATHS = $(addprefix $(TESTS_DIR)/, $(TEST_SOURCES))
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE_PATHS))
TEST_OBJECTS = $(patsubst $(TESTS_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SOURCE_PATHS))

# Правило для создания объектных файлов из исходных файлов в папке src
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_PATHS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Правило для создания объектных файлов из исходных файлов в папке Tests
$(OBJ_DIR)/%.o: $(TESTS_DIR)/%.cpp $(HEADER_PATHS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Правило для сборки программы conservative_test
conservative_test: $(OBJECTS) $(OBJ_DIR)/conservative_test.o
	$(CC) $(CFLAGS) -o $@ $^

# Правило для сборки программы linearization_test
linearization_test: $(OBJECTS) $(OBJ_DIR)/linearization_test.o
	$(CC) $(CFLAGS) -o $@ $^

# Правило для сборки основной программы
main: $(OBJECTS) $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -o $@ $^

# Создание директории obj, если она не существует
$(shell mkdir -p $(OBJ_DIR))

# Цель "all" для сборки всех программ
all: conservative_test linearization_test main

# Цель "clean" для удаления временных файлов и программ
clean:
	rm -rf $(OBJ_DIR) conservative_test linearization_test main

.PHONY: clean all

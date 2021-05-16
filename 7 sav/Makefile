CC = g++
CFLAGS = -c -Wall
TEST_TARGET = test.exe
TEST_OUT = test_out.txt
TEST_OBJ = test.o
TEST_CPP = test.cpp

PROGRAM_OBJ = main.o Weather.o myException.o

MAIN_OBJ = main.o
WEATHER_OBJ = weather.o
EXCEPTION_OBJ = myException.o

MAIN_CPP = main.cpp
WEATHER_CPP = weather.cpp
EXCEPTION_CPP = myException.cpp

all: program

program: $(PROGRAM_OBJ)
	$(CC) $(PROGRAM_OBJ) -o program

$(MAIN_OBJ): $(MAIN_CPP)
	$(CC) $(CFLAGS) $(MAIN_CPP)

$(WEATHER_OBJ): $(WEATHER_CPP)
	$(CC) $(CFLAGS) $(WEATHER_CPP)

$(EXCEPTION_OBJ): $(EXCEPTION_CPP)
	$(CC) $(CFLAGS) $(EXCEPTION_CPP)


build_test: $(TEST_OBJ) $(WEATHER_OBJ) $(EXCEPTION_OBJ)
	$(CC) $(TEST_OBJ) $(WEATHER_OBJ) $(EXCEPTION_OBJ) -o $(TEST_TARGET)

run_test: $(TEST_CPP)
	$(TEST_TARGET) > $(TEST_OUT) && $(TEST_TARGET)

$(TEST_OBJ): $(TEST_CPP) $(WEATHER_CPP) $(EXCEPTION_CPP)
	$(CC) $(CFLAGS) $(TEST_CPP) $(WEATHER_CPP) $(EXCEPTION_CPP)

rebuild: clean all

clean:
	del $(PROGRAM_OBJ)
	del $(TEST_OBJ)

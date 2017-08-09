MAIN=main.c
OBJECTS=message20.o
TARGET=main
DEFINES=-DDEBUG

all:$(OBJECTS)
	$(CC) $(MAIN) $^ -o $(TARGET) $(DEFINES)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

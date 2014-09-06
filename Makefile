.PHONY:clean
CC=g++
CFLAGS=-Wall -g
BIN=test
OBJS=buffer.o ConsumeThread.o ProduceThread.o queue.o Factory.o test.o Condition.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
%.o:%.cpp	
	$(CC) $(CFLAGS) -c $< -o $@ -lpthread
clean:
	rm -f *.o

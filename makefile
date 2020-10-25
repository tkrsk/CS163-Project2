CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJS = customer.o node.o queue.o stack.o block.o manager.o

app: $(OBJS)

app.o: customer.o node.o queue.o stack.o block.o manager.o

manager.o: queue.h stack.h node.h block.h customer.h

stack.o: stack.h block.h

block.o: block.h

queue.o: queue.h node.h customer.h

node.o: node.h customer.h

customer.o: customer.h

clean: 
	rm *.o app

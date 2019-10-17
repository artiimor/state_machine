CC = gcc -ansi
CFLAGS = -Wall
EXE = main

all : $(EXE)

.PHONY : clean	

$(EXE) : % : %.o transition.o state.o state_machine.o
	@echo "#---------------------------"
	@echo "# Generando $@ "
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -o $@ $@.o transition.o state.o state_machine.o

state_machine.o : state_machine.c state_machine.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

transition.o : transition.c transition.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

state.o : state.c state.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf *o

valgrind:
	valgrind --leak-check=full ./main

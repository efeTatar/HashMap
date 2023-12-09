SRC=$(wildcard src/*.c)
TEMP=$(SRC:.c=.o)
OBJ=$(subst src,obj,$(TEMP))
INC=$(wildcard lib/*.h)
STATIC=$(filter-out obj/main.o, $(OBJ))
DOX=$(`ls`)

all : exe

debug :
	@echo $(SRC)
	@echo $(OBJ)
	@echo $(INC)

obj/%.o : src/%.c $(INC)
	gcc -c $< -o $@

exe : $(OBJ)
	ar -rcs libhash.a $(STATIC)
	gcc -fsanitize=address obj/main.o libhash.a -o $@

clean:
	rm -f obj/*.o
	rm -f *.a
	rm -f exe
	
doxygen:
	echo `doxygen`

MAIN = get_next_line.c
UTILS = get_next_line_utils.c

all : run clean

compile :
	gcc $(MAIN) $(UTILS) -o gnl

run : compile
	./gnl

clean :
	rm -rf gnl

re : run clean


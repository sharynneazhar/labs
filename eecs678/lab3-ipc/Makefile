STUDENT_ID=2513206

DIR=bash-4.2
STR=execute
NUM_FILES=10

build:
	gcc -Wall -g finder.c -o finder

find:
	/bin/bash finder.sh $(DIR) $(STR) $(NUM_FILES)

test:
	/bin/bash finder.sh $(DIR) $(STR) $(NUM_FILES) > tmp1
	./finder $(DIR) $(STR) $(NUM_FILES) > tmp2
	-diff tmp1 tmp2
	rm -f tmp1 tmp2

pipe:
	gcc -Wall -g pipe.c -o pipe

clean:
	rm -f finder pipe tmp1 tmp2

archive:
	make clean
	mkdir $(STUDENT_ID)-ipc-lab
	cp finder.c $(STUDENT_ID)-ipc-lab
	zip -r $(STUDENT_ID)-ipc-lab.zip $(STUDENT_ID)-ipc-lab
	rm -rf $(STUDENT_ID)-ipc-lab

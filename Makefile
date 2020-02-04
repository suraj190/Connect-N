connect: main.o board.o cursorTrackWindow.o move.o win.o inputValidation.o
	cc -O -o connect main.o board.o cursorTrackWindow.o move.o win.o 
main.o: main.c 
	cc -O -c main.c 
board.o: board.c 
	cc -O -c board.c
cursorTrackWindow.o: cursorTrackWindow.c
	cc -O -c cursorTrackWindow.c
move.o: move.c
	cc -O -c move.c
win.o: win.c
	cc -O -c win.c
inputValidation.o: inputValidation.c
	cc -O -c inputValidation.c 
clean: 
	rm connect main.o board.o cursorTrackWindow.o move.o win.o
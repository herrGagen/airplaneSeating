COIN_INCLUDES=-I/usr/include/coin
COIN_LIBS=-lCgl -lOsi -lCbc -lCbcSolver -lClp -lCoinUtils -lOsiClp 
LIBS = ${COIN_LIBS} -lmysqlclient 
CC=g++
CFLAGS=-std=c++11 ${COIN_INCLUDES} ${MYSQL_INCLUDES}
MYSQL_INCLUDES= -I/usr/include/mysql

all: AIRPLANE

AIRPLANE:  LinearAirplane.o
	${CC} $^ ${LIBS} -o $@

%.o: %.cpp Makefile
	${CC} ${CFLAGS} $< -c

%.u: %.cpp Makefile
	${CC} -DUNIT_TESTING ${CFLAGS}  $< ${LIBS} -o $@
	./$@

%.ou: %.cpp Makefile
	${CC} -DUNIT_TESTING ${CFLAGS}  $< ${LIBS} -c -o $@

clean:
	rm -f *~ *.ou *.o *.u \#*

DOCS: Doxyfile ${SOURCES} Makefile
	doxygen Doxyfile


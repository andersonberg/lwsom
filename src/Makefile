CXXFLAGS =	-O2 -g -Wall

OBJS =		lwsom.o Aplicacao.o Matriz.o

LIBS =

TARGET =	lwsom

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

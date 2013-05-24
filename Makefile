CXXFLAGS =	-O2 -g -Wall

OBJS =		lwsom.o

LIBS =

TARGET =	lwsom

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

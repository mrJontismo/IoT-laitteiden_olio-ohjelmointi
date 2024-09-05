CXX = g++
CXXFLAGS = -Wall

TARGET = a.out

SRCS = main.cpp House.cpp Apartment.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS)

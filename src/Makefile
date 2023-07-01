# The target name
TARGET = chase.so

# The source files
SRCS = $(shell find . -name "*.cpp") 
# The object files
OBJS = $(SRCS:.cpp=.o)

# The compiler
CC = g++ 

# The compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -shared -fPIC -I include

# The linker flags
LDFLAGS = -shared -L. 

CPATH=src

VPATH = src
# The rule to compile a .cpp file into a .o file
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# The rule to link the object files into a shared library
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# The default rule
all: $(TARGET)

# The clean rule
clean:
	rm -f $(TARGET) $(OBJS)
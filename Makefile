COMPILER_FLAGS=-DNDEBUG -Wall -g -ggdb3
    
COMPILER_WARNINGS=-x c++ -Wall -std=c++11 
CC=g++
    
LDLIBS=-rdynamic
CFLAGS=$(COMPILER_FLAGS) $(COMPILER_WARNINGS) # AUTOGEN

NAME=callstack
OBJDIR=.

MY_OBJECTS=				\
    $(OBJDIR)/main.o 		        \

$(OBJDIR)/%.o: %.cpp
	@echo $(CC) $(EXTRA_CFLAGS) $(CFLAGS) -c -o $@ $<
	@$(CC) $(EXTRA_CFLAGS) $(CFLAGS) -c -o $@ $<

$(NAME): $(MY_OBJECTS)
	$(CC) $(MY_OBJECTS) $(LDLIBS) -o $(NAME)

clean:
	/bin/rm main.o

all: $(NAME) 


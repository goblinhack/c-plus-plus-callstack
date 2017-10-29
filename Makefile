COMPILER_FLAGS=-Wno-unused-result -Wsign-compare -Wunreachable-code -fno-common -dynamic -DNDEBUG -g -fwrapv -O3 -Wall  -pipe -Os -arch x86_64 -g -ggdb3 -O2 
    
COMPILER_WARNINGS=-x c++ -Wall -fmessage-length=0 -Wno-trigraphs -Wreturn-type -Wparentheses -Wswitch -Wno-unused-parameter -Wunused-variable -Wunused-value -std=c++11 
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

all: $(NAME) 


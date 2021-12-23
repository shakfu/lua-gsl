NAME = lua_gsl
EXTENSION = $(NAME).so
INCLUDE = -I./include
LIBS=$(wildcard lib/*)
ldflags += -lm

$(EXTENSION):
	@gcc $(LIBS) $(NAME).c -shared $(INCLUDE) -o $(EXTENSION) -fPIC


test:
	@lua test_$(NAME).lua

clean:
	@rm -f $(EXTENSION)

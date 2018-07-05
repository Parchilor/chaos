include $(ROOT)/config.$(OSTYPE).mk
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))
all:$(BINARYDIR)/main
$(BINARYDIR)/main:main.o
	$(LD) $(LDFLAGS) -o $(BINARYDIR)/main main.o
clean:
	$(RM) $(OBJS)
.PHONY:clean

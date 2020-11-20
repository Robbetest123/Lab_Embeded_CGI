src = $(wildcard Source/*.c)
obj = $(src:.c=.o)
Build/main: $(obj)
	$(CC) -o $@ $^
.PHONY: clean
clean:
	@echo "Lets clean it..."  
	rm -f $(obj) Build/main

MK := ./mk.sh

all:
	@$(MK) all

clean:
	@$(MK) clean

cleanall: clean
	$(RM) tags

.PHONY: all clean cleanall

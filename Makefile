DIRS := $(wildcard */)

all:
	@for dir in $(DIRS) ; do if ! $(MAKE) all -C $${dir} ; then exit 1 ; fi ; done

clean:
	@for dir in $(DIRS) ; do if ! $(MAKE) clean -C $${dir} ; then exit 1 ; fi ; done

cleanall: clean
	$(RM) tags

.PHONY: all clean

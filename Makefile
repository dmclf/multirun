PREFIX = /usr

multirun: multirun.c
	cc -std=gnu11 -o multirun multirun.c

.PHONY: install
install: multirun
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/multirun

.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/multirun
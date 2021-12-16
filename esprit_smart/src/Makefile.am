## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = esprit_smart

esprit_smart_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	smart.c	smart.h \
	reclamation.c reclamation.h \
	capteur.c capteur.h \
	stock.c stock.h

esprit_smart_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)


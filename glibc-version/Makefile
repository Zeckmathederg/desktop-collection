PREFIX=/usr/local
BINDIR=${PREFIX}/bin
INSTALL_DIR=${DESTDIR}${BINDIR}
glibc-version: main.c
	${CC} ${CFLAGS} -O2 main.c -o glibc-version
install: glibc-version
	$(Q)mkdir -p ${INSTALL_DIR}
	$(Q)install -vm755 glibc-version ${INSTALL_DIR}
clean:
	$(Q)rm -f glibc-version

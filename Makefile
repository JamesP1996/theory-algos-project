# The SHA512 Hashing Function(File) MakeFile
# Will clean and build a executeable from SHA512.c

EXECS= args bitoperations endian funcs preproc sha512 sha256

sha512: sha512.c
	cc -o sha512 sha512.c

test: tests.sh
	./tests.sh

clean:
	rm -f ${EXECS}
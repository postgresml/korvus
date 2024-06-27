BINARY_NAME=korvus
HEADER=${BINARY_NAME}.h
KORVUS_LIB=../target/debug/

bindings:
	cargo b --features c
	rustup default nightly
	cbindgen --config cbindgen.toml --output ${HEADER} ../
	rustup default stable

build: bindings
	gcc -Wall -o ./example -Iinclude/ -L${KORVUS_LIB} -l ${BINARY_NAME} example.c

run: build
	LD_LIBRARY_PATH=${KORVUS_LIB} ./example

clean:
	rm ${HEADER}
	rm -rf ./example


all: mrproper bootstrap
	ninja -C build/

clean:
	cd build && ninja clean

mrproper:
	rm -rf build

bootstrap:
	CC=gcc CXX=g++ meson build

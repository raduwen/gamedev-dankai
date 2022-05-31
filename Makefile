.PHONY: build
build:
	@mkdir -p build && \
	cd build && \
	cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && \
	cmake --build .

.PHONY: run
run:
	build/tetris/tetris

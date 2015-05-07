all: ruby-mapnik

install:
	rake install

ruby-mapnik:
	rake compile

clean:
	rake clean
	rm -rf ./tmp

test:
	rake test

.PHONY: clean test install

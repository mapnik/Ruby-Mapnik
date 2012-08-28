all: ruby-mapnik

install:
	rake install

ruby-mapnik:
	rake compile

clean:
	rake clean

test:
	rake test

.PHONY: clean test install

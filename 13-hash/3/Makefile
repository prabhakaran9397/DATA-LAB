
test_hashtable: hashtable
	./hashtable

hashtable: hashtable.c stub_hashtable.o
	gcc $^ -o $@

test_openhash: openhash
	./openhash

openhash: openhash.c stub_openhash.o
	gcc $^ -o $@

clean:
	rm -f hashtable openhash

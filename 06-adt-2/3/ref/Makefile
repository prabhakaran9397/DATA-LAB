
list: stub_list.o list.o
	gcc stub_list.o list.o -o list

arraylist: stub_arraylist.o arraylist.o
	gcc stub_arraylist.o arraylist.o -o arraylist

linkedlist: stub_linkedlist.o linkedlist.o 
	gcc stub_linkedlist.o linkedlist.o -o linkedlist

test_list: list
	./list

test_arraylist: arraylist
	./arraylist

test_linkedlist: linkedlist
	./linkedlist

clean:
	rm -f list.o list arraylist.o arraylist linkedlist.o linkedlist

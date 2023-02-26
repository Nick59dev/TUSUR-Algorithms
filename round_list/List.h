#ifndef LIST_H00
#define LIST_H00

namespace myList {
	
	typedef short int sh;

	class List {

	private:
		struct list {
			struct list* prev = NULL;
			struct list* next = NULL;
			int data;
		};
		struct list* list = new struct list;
		int length = 0;

	public:
		List();
		void add(int data, int position);
		void del(int position);
		void print() const;
		void delete_list();
		void push(int data);
		int get(sh poisition) const;
		void cycle_adding(int data, int amount, int c);
		int getLength() const;

	};
}
#endif


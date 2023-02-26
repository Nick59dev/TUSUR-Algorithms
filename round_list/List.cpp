#include <iostream>
#include "List.h"

using namespace std;

namespace myList {

	typedef short int sh;

	List::List() {
		this->list->data = 0;
		this->length++;
	}

	void List::add(int data, int position) {

		position = position % length;
		if (!position) {
			struct list* tmp = new struct list;
			struct list *tmp2 = this->list;
			tmp->data = data;
			this->list = tmp;
			tmp->next = tmp2;
			tmp->prev = tmp2->prev;
			tmp2->prev = tmp;
			tmp->prev->next = tmp;

			this->length++;
			
			return;
		}
		else if (position == length) {
			this->push(data);
			return;
		}

		this->length++;

		struct list* tmp = this->list;
		struct list* emptyTmp = NULL;
		struct list* tmp2 = new struct list;

		tmp2->data = data;

		for (int i = 1; i < position; i++) {
			tmp = tmp->next;
		}
		
		emptyTmp = tmp;

		tmp = tmp->next;
		emptyTmp->next = tmp2;
		tmp2->prev = emptyTmp;
		tmp2->next = tmp;
		tmp->prev = tmp2;
	}

	void List::print() const {
		struct list* tmp = this->list;
		while ((tmp->next != this->list) && (tmp->next != nullptr) && (tmp->next != NULL)) {
			cout << tmp->data << "\t";
			tmp = tmp->next;
		}
		cout << tmp->data << "\t";
		cout << endl;
	}

	void List::del(int position) {
		struct list *tmp = this->list;
		for (int i = 0; i < position; i++) {
			tmp = tmp->next;
		}

		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;

		this->length--;

		delete tmp;
	}

	void List::push(int data) {
		if (!length) {
			this->list->data = data;
			this->length++;
			return;
		}

		struct list* tmp = new struct list;
		tmp->data = data;
		tmp->next = this->list;

		struct list* tmp2 = this->list;

		while ((tmp2->next != NULL) && (tmp2->next != nullptr) && (tmp2->next != this->list)) {
			tmp2 = tmp2->next;
		}

		tmp2->next = tmp;
		tmp->prev = tmp2;
		this->list->prev = tmp;

		this->length++;

		return;
	}

	void List::delete_list() {
		struct list* tmp = this->list;
		struct list* tmp2;
		for (sh i = 0; i < length; i++) {
			if (tmp == nullptr || tmp == NULL) {
				break;
			}

			tmp2 = tmp;
			tmp = tmp->next;
			delete tmp2;
		}

		this->length = 0;
	}

	int List::get(sh position) const {
		struct list* tmp = this->list;
		for (sh i = 0; i < position; i++) {
			tmp = tmp->next;
		}

		return tmp->data;
	}

	void List::cycle_adding(int data, int amount, int c) {

		struct list * tmp = this->list;

		if (c <= 1) {
			return;
		}

		if (amount == 1) {
			this->add(data, c);
			return;
		}

		for (int i = 0; i < amount; i++) {
			for (int j = 0; j < c; j++) {
				tmp = tmp->next;
			}
			struct list * tmp2 = new struct list;
			tmp2->data = data;
			tmp2->next = tmp->next;
			tmp2->prev = tmp;
			tmp->next = tmp2;

			tmp = tmp->next->next;
		}

	}

	int List::getLength() const {
		return this->length;
	}
}


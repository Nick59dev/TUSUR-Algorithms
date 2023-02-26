#include <iostream>
#include "Tree.h"

using namespace std;

namespace myTree {

	Tree::Tree() {
		this->tr = new struct tree;
	}

	Tree::Tree(int data) {
		this->tr = new struct tree;
		this->tr->data = data;
		this->length++;
	}
	
	void Tree::add(int data, struct tree* tr2)
	{
		if (data > tr2->data)
		{
			if (tr2->right == NULL)
			{
				tr2->right = new struct tree;
				tr2->right->data = data;
				this->length++;
				return;
			}
			this->add(data, tr2->right);
		}
		else
		{
			if (tr2->left == NULL)
			{
				tr2->left = new struct tree;
				tr2->left->data = data;
				this->length++;
				return;
			}
			this->add(data, tr2->left);
		}

		return ;
	}

	void Tree::add(int data)
	{
		if (!(this->length)) {
			this->tr->data = data;
			this->length++;
			return;
		}
		else
		{
			if (data > this->tr->data)
			{
				if (this->tr->right == NULL)
				{
					this->tr->right = new struct tree;
					this->tr->right->data = data;
					this->length++;
					return ;
				}
				this->add(data, this->tr->right);
			}
			else
			{
				if (this->tr->left == NULL)
				{
					this->tr->left = new struct tree;
					this->tr->left->data = data;
					this->length++;
					return ;
				}
				this->add(data, this->tr->left);
			}
		}

		return ;
	}

	void Tree::delete_tree() {
		struct tree* tr = this->tr;
		this->delete_tree(tr);
	}

	void Tree::delete_tree(struct tree* tr) {
		if (tr->left != NULL) {
			this->delete_tree(tr->left);
		}
		else if (tr->right != NULL) {
			this->delete_tree(tr->right);
		}

		delete tr;
	}

	void Tree::print() {

		if (this->tr == NULL) {
			cout << "NONE" << endl;
			return ;
		}

		struct tree* trTemp = this->tr;
		this->print(tr->left);
		this->print(tr->right);
		cout << trTemp->data << "\t";

	}

	void Tree::print(struct tree* tr) {
		if (tr == NULL) {
			return;
		}

		this->print(tr->left);
		this->print(tr->right);
		cout << tr->data << "\t";
	}

	int Tree::count(int data) {
		if (this->tr == NULL) {
			return 0;
		}
		else {
			this->count(data, this->tr->left);
			this->count(data, this->tr->right);
			if (this->tr->data == data) {
				this->counter++;
			}
		}

		int tmp = this->counter;
		this->counter = 0;

		return tmp;
	}

	void Tree::count(int data, struct tree *tr) {
		if (tr == NULL) {
			return;
		}
		else {
			this->count(data, tr->left);
			this->count(data, tr->right);
			if (tr->data == data) {
				this->counter++;
			}
		}
	}

	int Tree::getLength() const
	{
		return this->length;
	}

	void Tree::print2() const {
		if (this->tr == NULL) {
			cout << "NONE" << endl;
			return;
		}

		int space = 5;
		this->print2(this->tr->left, space + 5);

		cout << this->tr->data;

		this->print2(this->tr->right, space + 5);

		cout << endl;
	}

	void Tree::print2(struct tree *tr, int space) const {
		if (tr == NULL) {
			return;
		}

		this->print2(t->left, space + 5);

		for (int i = 0; i < space; i++) {
			cout << " ";
		}

		cout << tr->data;
		cout << endl;

		this->print2(tr->right, space + 5);
	}
}

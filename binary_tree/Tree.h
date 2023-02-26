#ifndef TREE_H00
#define TREE_H00

namespace myTree {

	struct tree {
		struct tree* left = NULL;
		struct tree* right = NULL;
		int data;
	};

	class Tree {
	private:

		struct tree* tr;
		int counter = 0;
		int length = 0;

		void delete_tree(struct tree *tr);
		void count(int data, struct tree *tr);
		void print(struct tree* tr);
		void print2(struct tree* tr, int space) const;

	public:
		Tree();
		Tree(int data);
		void add(int data);
		void add(int data, struct tree* tr2);
		void delete_tree();
		void print();
		int count(int data);
		int getLength() const;
		void print2() const;
	};

}
#endif


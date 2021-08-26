#include "SearchTree.h"

Iterator& SearchTree<E>::Iterator::operator++()
{
	TPos w = v.right();
	if (w.isInternal())
	{
		do { v = w; w = w.left(); } while (w.isInternal);
	}
	else
	{
		w = v.parent();
		while (v == w.right())
		{
			v = w; w = w.parent();
		}

		v = w;
	}

	return *this;

}
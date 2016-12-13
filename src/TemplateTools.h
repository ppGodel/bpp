/*
 * TemplateTools.h
 *
 *  Created on: Oct 7, 2016
 *      Author: ppGodel
 */

#ifndef TEMPLATETOOLS_H_
#define TEMPLATETOOLS_H_

namespace Tools {

//class TemplateTools {
//public:
//	TemplateTools();
//	virtual ~TemplateTools();
//};
	
	template <class T>
	int GetSize(T list[])
	{
		double a = sizeof(list);
		double b = sizeof(T);
		return((int)(a/b));
	};
	template <class T>
	bool ArrayAddItem(T * O, T * A)
	{
		bool result = false;
		int n = GetSize(O);//(int)(sizeof(O)/sizeof(T));
		int m = GetSize(A);
		if(n>0)
		{
			T * aux;
			aux = new T[n+m];
			for(int i=0; i<n ; i++)
			{
				aux[i] = O[i];
			}
			for(int i = 0; i<m;i++)
			{
				aux[n+i] = *(A+i);
			}
			delete [] O;
			O = aux;
			result = true;
		}
		else
		{
			if(m>1)
			{
				O=A;
				result = true;
			}
			else
			{
				T aux [1]= {*A};
				O = aux;
				result = true;
			}
			//ItemSet[0] = I;
		}
		return result;
	};
} /* namespace bpp */

#endif /* TEMPLATETOOLS_H_ */

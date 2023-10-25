#ifndef _DEEP_H_
#define _DEEP_H_

// #define SHALLOW
#define DEEP
// #define MOVE

class CopyMoveClass
{
private:
	/* data */
	int *data;
	static int num_obj;
public:
	/* Methods */
	int get_data();
	static int get_num_obj();
	void set_data(int data);
	void display(CopyMoveClass s);

#ifdef SHALLOW
	/* Shallow copy constructor */
	CopyMoveClass(const CopyMoveClass &source);
#endif // SHALLOW

#ifdef DEEP
	/* Deep copy constructor */
	CopyMoveClass(const CopyMoveClass &source);
#endif // DEEP

#ifdef MOVE
	/* Move constructor - Expects an R-Value */
	CopyMoveClass(CopyMoveClass &&source) noexcept;
#endif // DEEP

	CopyMoveClass(int data);
	~CopyMoveClass();
};

#endif // _DEEP_H_
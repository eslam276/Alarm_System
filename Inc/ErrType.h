#ifndef ERRTYPE_H_
#define ERRTYPE_H_

typedef enum{
	OK,
	NOK,
	NULL_PTR_ERR
}ErrorState_t;

#define NULL ((void *)0)
#define FLAG_RESET		0
#define FLAG_SET		1


#endif

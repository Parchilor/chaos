#ifndef __TYPE_H_
#define __TYPE_H_

#include <stdint.h>
#include "list.h"
#define DEV_NAME_SIZE 64
#define COMPANY_NAME_SIZE 64

#define DEV_ADD_INFO(dev_company, dev_type, dev_id) \
	.type = dev_type, .id = dev_id, .company = dev_company
#define DEV_ADD_COMPANY(dev_company) \
	.company = dev_company
#define DEV_ADD_TYPE(dev_type) \
	.type = dev_type
#define DEV_ADD_ID(dev_id) \
	.id = dev_id


typedef struct {
	char		company[COMPANY_NAME_SIZE];
	char		type[DEV_NAME_SIZE];
	uint16_t	id;
} DEV_INFO;


#endif

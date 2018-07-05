#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"

struct dat{
	int id;
	struct list_head list;
	char name[100];
};

struct dat *pdat;
struct dat *tmp_dat;
struct list_head *pos;

LIST_HEAD(list);

int list_init(void)
{
	pdat = malloc(sizeof(struct dat) * 5);
	memset(pdat, 0, sizeof(struct dat) * 5);
	for(int i = 0; i < 5; i++){
		sprintf(pdat[i].name, "mIn9[%d]", i);
		pdat[i].id = i;
		list_add_tail(&(pdat[i].list), &list);
	}
	list_for_each(pos, &list){
		assert((tmp_dat = list_entry(pos, struct dat, list)));
		printf("Dat: %d name: %s\n", tmp_dat->id, tmp_dat->name);
	}
	return 0;
}

void list_del(void)
{
	putchar('M');
	for(int i = 0;i < 5; i++){
		list_del_init(&(pdat[i].list));
	}
	putchar('Y');
	free(pdat);
}

int
main(void)
{
	list_init();
	list_del();
}

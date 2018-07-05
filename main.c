

/*
 * 0 is get a line which start from pos ,end of '\n'. And return new position throught newpos
 * 1 is get a line 
 */
#if 0
char *readline(FILE *file, long pos, long *newpos)
#else
char *readline(FILE *file, int line, int *size)
#endif
{
/*
	char c;
	int index = 0;
	// To get a length for return string
	fseek(file, pos, SEEK_SET);
	while(((c = fgetc(file)) != '\n') && !feof(file))
	{
		index++;
	}
	// Start to get data
	char *ret = malloc(sizeof(char) * index);
	index = 0;
	fseek(file, pos, SEEK_SET);
	while(((c = fgetc(file)) != '\n') && !feof(file))
	{
		ret[index] = c;
		index++;
	}
	*newpos = ftell(file);
	if(pos == *newpos)
	{
		free(ret);
		ret = NULL;
	}
	return ret;
*/
	char c;
	int index = 0, CR_cnt = 0;
	int cur_line_start = 0, cur_line_end = 0, slen;
	// To get a length for return string
	fseek(file, 0, SEEK_SET);
	for(CR_cnt = 0; CR_cnt < line;)
	{
		c = fgetc(file);
		if(c == '\n' || feof(file))
		{
			cur_line_start = cur_line_end;
			cur_line_end = ftell(file);
			CR_cnt++;
		}
	}

	slen = cur_line_end - cur_line_start;
	// Return length
	*size = slen;

	// Start to get data
	char *ret = malloc(sizeof(char) * (slen -1));
	fseek(file, cur_line_start, SEEK_SET);
	fgets(ret, slen -1, file);
	if(cur_line_start == cur_line_end)
	{
		free(ret);
		ret = NULL;
	}
	return ret;
}

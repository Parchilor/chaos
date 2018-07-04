#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define PW_PATH "files/syspw"

void convert_hex(unsigned char *in, char *out)
{
	int i;
	for(i = 0; i < 16; i++)
	{
		sprintf(out + (i*2), "%02x", in[i]);  // Convert to 32 bit(lowercase) 
//		sprintf(out + (i*2), "%02X", in[i]);  // Convert to 32 bit(Capital) 
	}
	out[32] = 0;
}

int MD5_encrypt(char *input, char *output, int in_len)
{
	char *password = malloc(sizeof(char) * in_len+1);
	MD5_CTX x;
	char *out = NULL;

	unsigned char d[16];
	strcpy(password,input);
	MD5_Init(&x);
	MD5_Update(&x, password, in_len);
	MD5_Final(d, &x);
	out = (char *)malloc(35);
	memset(out, 0x00, 35);
	// printf("MD5(\"%s\") = ", password);
	convert_hex(d, out);
	// printf("%s\n", out);
	strcpy(output,out);
	free(out);
	return  0;
}

int save_pw(char *pw, int pw_len)
{
	char *wbuf = malloc(sizeof(char) * pw_len);
	MD5_encrypt(pw, wbuf, pw_len);
	FILE *fp = fopen(PW_PATH, "w");
	if(fp == NULL)
		return -1;
	fwrite(wbuf, strlen(wbuf), 1, fp);
	fclose(fp);
	return 0;

}

int read_md5_pw(char *rbuf, int rlen)
{
	FILE *fp = fopen(PW_PATH, "r");
	if(fp == NULL)
		return -1;
	fread(rbuf, rlen, 1, fp);
	fclose(fp);
	return 0;
}

int comfirm_pw(char *pw_in, int pw_len)
{
	char *rbuf = malloc(sizeof(char) * 32);
	char *ebuf = malloc(sizeof(char) * pw_len);
	MD5_encrypt(pw_in, ebuf, pw_len);
	read_md5_pw(rbuf, 32);
	if(!memcmp(rbuf, ebuf, 32))
	{
		printf("Pass!\n");
		return 0;
	}
	printf("invalid!\n");
	return -2;
}

int check_pw(void)
{
	char *rbuf = malloc(sizeof(char) * 32);
	read_md5_pw(rbuf, 32);
	if(!strncmp(rbuf, "", 32))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int
main (int argc, char *argv[])
{
	if(argv[1] == NULL)
	{
		printf("invalid!\n");
		return 2; 
	}

	char *password = malloc(sizeof(char) * 1024);
	if(check_pw())
	{
		printf("No password!\n");
		printf("Enter New Password: ");
		fflush(stdout);
		fgets(password, 1024, stdin);
		password[strlen(password) -1] = 0;
		printf("%s, len: %ld\n", password, strlen(password));
		if(!save_pw(password, strlen(password)))
		{
			printf("New Password Save Down!\n");
			return 0;
		}
		else
		{
			printf("Password Save Fail!\n");
			return -1;
		}
	}

	if(!comfirm_pw(argv[1], strlen(argv[1])))
	{
		fgets(password, 1024, stdin);
		password[strlen(password) -1] = 0;
		printf("%s, len: %ld\n", password, strlen(password));
		if(!save_pw(password, strlen(password)))
		{
			printf("New Password Save Down!\n");
			return 0;
		}
		else
		{
			printf("Password Save Fail!\n");
			return -1;
		}
	}
	return 0;
}



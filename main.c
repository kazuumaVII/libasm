/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:14:44 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/14 16:58:13 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int				ft_write(int fd, char *str, int len);
int				ft_read(int fd, char *buf, int len);
unsigned int 	ft_strlen(char *str);
int				ft_strcmp(char *s, char *s2);
void			*ft_memcpy(void *dest, void *src, unsigned int size);
char			*ft_strdup(char *str);
char 			*ft_strcpy(char *dest, char *src);

void 	ft_verif_strlen()
{
	printf("\n\n///////////////////////////  TEST FT_STRLEN ////////////////////////////\n\n");

			// init chaine
	char *str_1 = strdup("");
	char *str_2 = strdup("salut");
	char *str_3 = strdup("42");
	char *str = "1234567894335534635654674563453453454353";

//////////////////////////////////////////////////////////////////////////////////////////
											// 1er test = ""
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\tstr_1 : |%s|\n", str_1);
	printf("strlen : %d\n", (int)strlen(str_1));
	printf("ft_strlen : %d\n", (int)ft_strlen(str_1));

//////////////////////////////////////////////////////////////////////////////////////////
										// 2eme test = salut
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\tstr_2 : |%s|\n", str_2);
	printf("strlen : %d\n", (int)strlen(str_2));
	printf("ft_strlen : %d\n", (int)ft_strlen(str_2));

//////////////////////////////////////////////////////////////////////////////////////////
										// 3eme test = 42
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\tstr_3 : |%s|\n", str_3);
	printf("strlen : %d\n", (int)strlen(str_3));
	printf("ft_strlen : %d\n", (int)ft_strlen(str_3));

//////////////////////////////////////////////////////////////////////////////////////////
							// 4eme test = 1234567894335534635654674563453453454353
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\tstr_2 : |%s|\n", str);
	printf("strlen: %d\n", (int)strlen(str));
	printf("ft_strlen: %d\n\n", (int)ft_strlen(str));
}





void	ft_verif_strcpy()
{
	printf("\n\n///////////////////////////  TEST FT_STRCPY ////////////////////////////\n\n");
				
				// init chaine
	char *str_1;
	char *str_2;
	char *str1;
	char *str2;

//////////////////////////////////////////////////////////////////////////////////////////
												// 1er test = "" salut
//////////////////////////////////////////////////////////////////////////////////////////
	
	//vrais fonction
	str_1 = strdup("");
	str_2 = strdup("salut");
	printf("\t\tDestination : |%s|\n\t\tSource : |%s|\n", str_1, str_2);
	strcpy(str_1, str_2);
	printf("stcpy : %s\n", str_1);

	//ma fonction
	str1 = strdup("");
	str2 = strdup("salut");
	ft_strcpy(str1, str2);
	printf("ft_strcpy : %s\n", str1);
//////////////////////////////////////////////////////////////////////////////////////////
											// 2eme test = salut 42
//////////////////////////////////////////////////////////////////////////////////////////						

	//vrais fonction
	str_1 = strdup("salut");
	str_2 = strdup("42");
	printf("\n\n\t\tDestination : |%s|\n\t\tSource : |%s|\n", str_1, str_2);
	strcpy(str_1, str_2);
	printf("strcpy : %s\n", str_1);

	// ma fonction
	str1 = strdup("salut");
	str2 = strdup("42");
	ft_strcpy(str1, str2);
	printf("ft_strcpy : %s\n", str1);
//////////////////////////////////////////////////////////////////////////////////////////
										// 3eme test = 42 salut
//////////////////////////////////////////////////////////////////////////////////////////
	//vrais fonction
	str_1 = strdup("42");
	str_2 = strdup("salut");
	printf("\n\n\t\tDestination : |%s|\n\t\tSource : |%s|\n", str_1, str_2);
	strcpy(str_1, str_2);
	printf("strcpy : %s\n", str_1);

	//ma fonction
	str1 = strdup("42");
	str2 = strdup("salut");

	ft_strcpy(str1, str2);
	printf("ft_strcpy : %s\n", str1);
//////////////////////////////////////////////////////////////////////////////////////////
									// 4eme test = salut ""
//////////////////////////////////////////////////////////////////////////////////////////
	//vrais fonction
	str_1 = strdup("salut");
	str_2 = strdup("");
	printf("\n\n\t\tDestination : |%s|\n\t\tSource : |%s|\n", str_1, str_2);
	strcpy(str_1, str_2);
	printf("strcpy : |%s|\n", str_1);

	//ma fonction
	str1 = strdup("salut");
	str2 = strdup("");
	//ma fonction
	ft_strcpy(str1, str2);
	printf("ft_strcpy : |%s|\n", str1);
}




void	ft_verif_strcmp()
{
	printf("\n\n///////////////////////////  TEST FT_STRCMP ////////////////////////////\n\n");

	char *str_1 = strdup("coucou");
	char *str_2 = strdup("0");
	char *str_3 = strdup("7");
	char *str_4 = strdup("");
	char *str_5 = strdup("salut");


//////////////////////////////////////////////////////////////////////////////////////////
									// test 1 = 0 7
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t1ere_chaine : |%s|\n\t\t2eme_chaine : |%s|\n", str_2, str_3);
	printf("strcpm : %d\n", strcmp(str_2, str_3));
	printf("ft_strcmp : %d\n", ft_strcmp(str_2, str_3));

//////////////////////////////////////////////////////////////////////////////////////////
									// test 2 = coucou 7
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t1ere_chaine : |%s|\n\t\t2eme_chaine : |%s|\n", str_1, str_3);
	printf("strcpm : %d\n", strcmp(str_1, str_3));
	printf("ft_strcmp : %d\n", ft_strcmp(str_1, str_3));

//////////////////////////////////////////////////////////////////////////////////////////
									// test 3 = 7 ""
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t1ere_chaine : |%s|\n\t\t2eme_chaine : |%s|\n", str_3, str_4);
	printf("strcpm : %d\n", strcmp(str_3, str_4));
	printf("ft_strcmp : %d\n", ft_strcmp(str_3, str_4));

//////////////////////////////////////////////////////////////////////////////////////////
									// test 4 = coucou salut 
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t1ere_chaine : |%s|\n\t\t2eme_chaine : |%s|\n", str_1, str_5);
	printf("strcpm : %d\n", strcmp(str_1, str_5));
	printf("ft_strcmp : %d\n", ft_strcmp(str_1, str_5));
}




void	ft_verif_write(void)
{
	printf("\n\n///////////////////////////  TEST FT_WRITE ////////////////////////////\n\n");

	char *str_1 = strdup("coucou");
	char *str_2 = strdup("42");
	char *str_3 = strdup("");
	char *str_4 = strdup("abcdef !@#$ 12345");

	int ret;
	int ft_ret;

//////////////////////////////////////////////////////////////////////////////////////////
										// test 1 = coucou
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t1ere_chaine : |%s|\n", str_1);
	printf("\tlen -> %zd\n", write(1, str_1, strlen(str_1)));
	printf("\tlen -> %d\n", ft_write(1, str_1, strlen(str_1)));

//////////////////////////////////////////////////////////////////////////////////////////
										// test 2 = 42
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t2eme_chaine : |%s|\n", str_2);
	printf("\tlen -> %zd\n", write(1, str_2, strlen(str_2)));
	printf("\tlen -> %d\n", ft_write(1, str_2, strlen(str_2)));

//////////////////////////////////////////////////////////////////////////////////////////
										// test 3 = ""
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t3eme_chaine : |%s|\n", str_3);
	printf("\tlen -> %zd\n", write(1, str_3, strlen(str_3)));
	printf("\tlen -> %d\n", ft_write(1, str_3, strlen(str_3)));

//////////////////////////////////////////////////////////////////////////////////////////
										// test 4 = abcdef !@#$ 12345
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t4eme_chaine : |%s|\n", str_4);
	printf("\tlen -> %zd\n", write(1, str_4, strlen(str_4)));
	printf("\tlen -> %d\n", ft_write(1, str_4, strlen(str_4)));





//////////////////////////////////////////////////////////////////////////////////////////
							// Erreur fd numero 1 = coucou
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\n\n\t\t Error de FD\n");
	char *str = strdup("coucou");
	printf("\t\tchaine : |%s|\n", str);
	errno = 0;
	ret = write(6, str, strlen(str));
	printf("write returned : %d : %s -> %d\n", ret, strerror(errno), errno);
	errno = 0;
	ft_ret = ft_write(6, str, strlen(str));
	printf("ft_write returned : %d : %s -> %d\n", ret, strerror(errno), errno);

//////////////////////////////////////////////////////////////////////////////////////////
							// Erreur fd numero 2 = 42
//////////////////////////////////////////////////////////////////////////////////////////

	printf("\n\n\t\t Error de FD numero 2\n");
	char *tab = strdup("42");
	printf("\t\tchaine : |%s|\n", tab);
	errno = 0;
	ret = write(6, tab, strlen(tab));
	printf("write returned : %d : %s -> %d\n", ret, strerror(errno), errno);
	errno = 0;
	ft_ret = ft_write(6, tab, strlen(tab));
	printf("ft_write returned : %d : %s -> %d\n", ret, strerror(errno), errno);

}

void	ft_verif_read(void)
{
	printf("\n\n///////////////////////////  TEST FT_READ ////////////////////////////\n\n");

	char buffer[30];
	int fd;
	int r;

	char ft_buffer[30];
	int ft_fd;
	int ft_r;

	int ret;
	int ft_ret;

//////////////////////////////////////////////////////////////////////////////////////////
										// test 1 
//////////////////////////////////////////////////////////////////////////////////////////
	fd = open("text.txt", O_RDONLY);
	r = read(fd, buffer, 30);
	buffer[r] = '\0';

	ft_fd = open("text.txt", O_RDONLY);
	ft_r = ft_read(ft_fd, ft_buffer, 30);
	ft_buffer[ft_r] = '\0';

	printf("\t\tread : %d\n%s", r, buffer);
	printf("\t\tft_read : %d\n%s", ft_r, ft_buffer);




//////////////////////////////////////////////////////////////////////////////////////////
										// Error de fd numero 1
//////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t Error de FD\n");
	errno = 0;
	ret = read(-1, buffer, 15);
	printf("   read: errno: %d %s -> %d\n", errno, strerror(errno), ret);
	errno = 0;
	ft_ret = ft_read(-1, ft_buffer, 15);
	printf("   ft_read: errno: %d %s -> %d\n", errno, strerror(errno), ret);

}




void	ft_verif_strdup(void)
{
	printf("\n\n///////////////////////////  TEST FT_STRDUP ////////////////////////////\n\n");

	char *str1;

//////////////////////////////////////////////////////////////////////////////////////////
										// test 1 
//////////////////////////////////////////////////////////////////////////////////////////
	str1 = ft_strdup("coucou");
	printf("\t\t1ere_chaine : |%s|\n", str1);
	printf ("ft_strdup : |%s|\n", str1);
	free (str1);
	str1 = strdup ("coucou");
	printf ("strdup : |%s|\n", str1);
	free (str1);

//////////////////////////////////////////////////////////////////////////////////////////
										// test 2
//////////////////////////////////////////////////////////////////////////////////////////
	str1 = ft_strdup("");
	printf("\t\t2eme_chaine : |%s|\n", str1);
	printf ("ft_strdup : |%s|\n", str1);
	free (str1);
	str1 = strdup("");
	printf ("strdup : |%s|\n", str1);
	free(str1);

//////////////////////////////////////////////////////////////////////////////////////////
										// test 3
//////////////////////////////////////////////////////////////////////////////////////////
	char *text;

	text = "Bonsoir a toute et a tous";
	printf("\t\t3eme_chaine : |%s|\n", text);
	char *str = strdup(text);
	char *ft_str = ft_strdup(text);
	printf("ft_strdup: |%s|\nstrdup: |%s|\n\n", ft_str, str);
	free(str);
	free(ft_str);



//////////////////////////////////////////////////////////////////////////////////////////
										// test 4
//////////////////////////////////////////////////////////////////////////////////////////
	text = "Deuxieme test ca doit fonctionner :";
	printf("\t\t4eme_chaine : |%s|\n", text);
	str = strdup(text);
	ft_str = ft_strdup(text);
	printf("ft_strdup: |%s|\nstrdup: |%s|\n\n", ft_str, str);
	free(str);
	free(ft_str);

	printf ( "\n \t \t ----- END ----- \n");
}

int main(void)
{
	ft_verif_strlen();
	ft_verif_strcpy();
	ft_verif_strcmp();
	ft_verif_write();
	ft_verif_read();
	ft_verif_strdup();
	return (0);
}


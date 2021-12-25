/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:14:25 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/19 12:35:38 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

struct s_dicc
{
	char	*key;
	char	*value;
};

void			rush(char *name_file, char *num, int dig);
char			*ors_data(const char *name_file);
char			*key(char *data, int i);
char			*value(char *data, int i);
int				next_pos(char *data, int i);
struct s_dicc	*store_data(char *data, int num_keys);
int				extract_num_keys(char *data);
int				str_comp(char *str_dic, char *str_num, int size_num);
void			ft_putstr(char *str);
int				zero_case(char *num, struct s_dicc *dic, int dig);
int				print_key_num(char num, struct s_dicc *dic,
					int num_keys, int dig);
void			print_key_post(int dig, struct s_dicc *dic, int num_keys);
void			print_key_dec(char num, char num_dos,
					struct s_dicc *dic, int num_keys);
int				check_pos_value(int dig);

#endif

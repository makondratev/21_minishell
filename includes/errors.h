/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:17:16 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:09:54 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

enum	e_errors
{
	er_acces = 1,
	er_noent,
	er_noexec,
	er_isdir,
	er_tmargs,
	er_numargreq,
	er_notvalid,
	er_nohome,
	er_nooldpwd
};

void	ft_print_error(enum e_errors error, const char *exec,
		const char *arg);

#endif

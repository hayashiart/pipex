/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:32:02 by slin              #+#    #+#             */
/*   Updated: 2022/07/30 03:49:55 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char *str, char **strs)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (strs != NULL)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = NULL;
	}
}

static void	ft_start(int *fdin, int *fdout, int argc, char **argv)
{
	if (argc != 5)
	{
		write(STDERR, "Invalid number of arguments .\n", 29);
		exit(1);
	}
	if (access(argv[1], F_OK))
	{
		write(STDERR, "No such file or directory\n", 26);
		exit(1);
	}
	else
	{
		*fdin = open(argv[1], O_RDONLY);
		if (*fdin == -1)
			write(STDERR, "Permisson denied\n", 17);
	}
	*fdout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*fdout == -1)
		write(STDERR, "Permisson denied\n", 17);
	if (*fdin == -1 || *fdout == -1)
		exit(1);
}

static void	first_child(int pid1, int *fd, char **envp, char **argv)
{
	char	*cmd_path;
	char	**cmd_options;

	pid1 = fork();
	if (pid1 < 0)
		exit(1);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT);
		close(fd[0]);
		close(fd[1]);
		cmd_options = ft_split(argv[2], ' ');
		cmd_path = get_cmd(cmd_options[0], envp);
		execve(cmd_path, cmd_options, envp);
		write(STDERR, "pipex: ", 7);
		write(STDERR, argv[2], ft_strlen(argv[2]));
		write(STDERR, ": command not found\n", 20);
		exit(1);
	}
}

static void	second_child(int pid2, int *fd, char **envp, char **argv)
{
	char	*cmd_path;
	char	**cmd_options;

	pid2 = fork();
	if (pid2 < 0)
		exit(1);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN);
		close(fd[0]);
		close(fd[1]);
		cmd_options = ft_split(argv[3], ' ');
		cmd_path = get_cmd(cmd_options[0], envp);
		execve(cmd_path, cmd_options, envp);
		write(STDERR, "pipex: ", 7);
		write(STDERR, argv[3], ft_strlen(argv[3]));
		write(STDERR, ": command not found\n", 20);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		fdin;
	int		fdout;
	pid_t	pid1;
	pid_t	pid2;

	fdin = 0;
	fdout = 0;
	pid1 = 0;
	pid2 = 0;
	ft_start(&fdin, &fdout, argc, argv);
	dup2(fdin, STDIN);
	dup2(fdout, STDOUT);
	if (pipe(fd) < 0)
		return (1);
	first_child(pid1, fd, envp, argv);
	second_child(pid2, fd, envp, argv);
	close(fd[0]);
	close(fd[1]);
	close(fdin);
	close(fdout);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

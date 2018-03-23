# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makeitpop.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 14:04:01 by mbortnic          #+#    #+#              #
#    Updated: 2018/03/14 14:04:13 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# say -v Milena "Слава Украине!"

red=$(printf "\033[33mO\033[0m")
blue=$(printf "\033[36mX\033[0m")
red2=$(printf "\033[43m\033[30mo\033[0m")
blue2=$(printf "\033[46m\033[30mx\033[0m")

sed "s|O|$red|g" |
sed "s|X|$blue|g" |
sed "/^0.. /s|x|$blue2|g" |
sed "/^0.. /s|o|$red2|g" |
sed "s|fin|player|g"

# say -v Milena "Героям Слава!"


# int		main(void)
# {
# 	char		*str;
# 	t_filler	*game;

# 	game = ft_memalloc(sizeof(t_filler));
# 	CHECK(game);
# 	get_next_line(0, &str);
# 	game->player = (ft_atoi(str + 10) == 1) ? PL_1 : PL_2;
# 	free(str);
# 	while (42)
# 	{
# 		// ft_clean(game);
# 		get_next_line(0, &str);
# 		game->map_y = ft_atoi(&str[8]);
# 		game->map_x = ft_atoi(&str[11]);
# 		if (str)
# 			ft_strdel(&str); //ios
# 		ft_take_map(game);
# 		if (ft_moves(game) == 0)
# 			game->ko = 1;
# 		ft_make_move(game);
# 		if (game->endgame == 1)
# 			break ;
# 		// while (69);
# 	}
# 	free(game);
# 	return (0);
# }
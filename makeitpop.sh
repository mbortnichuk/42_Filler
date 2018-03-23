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

say -v Karen "Starting the game!"

red=$(printf "\033[33mO\033[0m")
blue=$(printf "\033[36mX\033[0m")
red2=$(printf "\033[43m\033[30mo\033[0m")
blue2=$(printf "\033[46m\033[30mx\033[0m")

sed "s|O|$red|g" |
sed "s|X|$blue|g" |
sed "/^0.. /s|x|$blue2|g" |
sed "/^0.. /s|o|$red2|g" |
sed "s|fin|player|g"

say -v Karen "Game ended!"

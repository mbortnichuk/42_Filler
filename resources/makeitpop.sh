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

red=$(printf "\e[41m\e[30mO\e[0m")
blue=$(printf "\e[44m\e[30mX\e[0m")
green=$(printf "\e[43m\e[30mo\e[0m")
magenta=$(printf "\e[45m\e[30mx\e[0m")
yellow=$(printf "\e[33mplayer\e[0m")

sed "s|O|$red|g" |
sed "s|X|$blue|g" |
sed "s|x|$magenta|g" |
sed "s|o|$green|g" |
sed "s|fin|$yellow|g"

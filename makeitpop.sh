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

# say "Starting the game!"

# red=$(printf "\033[41m\033[30mO\033[0m")
# blue=$(printf "\033[44m\033[30mX\033[0m")
# red2=$(printf "\033[47m\033[31mo\033[0m")
# blue2=$(printf "\033[47m\033[34mx\033[0m")

# sed "s|O|$red|g" |
# sed "s|X|$blue|g" |
# sed "s|x|$blue2|g" |
# sed "/^0.. /s|o|$red2|g" |
# sed "s|fin|player|g" 

# say "Game ended!"



say "Starting the game!"

red=$(printf "\033[31mO\033[0m")
blue=$(printf "\033[34mX\033[0m")
red2=$(printf "\033[41m\033[30mo\033[0m")
blue2=$(printf "\033[44m\033[30mx\033[0m")

sed "s|O|$red|g" |
sed "s|X|$blue|g" |
sed "s|x|$blue2|g" |
sed "/^0.. /s|o|$red2|g" |
sed "s|fin|player|g"

say "Game ended!"
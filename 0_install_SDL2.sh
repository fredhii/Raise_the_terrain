#!/usr/bin/env bash

GREEN='\033[0;32m'
BLUE='\033[0;36m'
NC='\033[0m'

if [ "$(id -u)" != "0" ]; then
	echo "Sorry, you are not root."
	exit 1
fi

echo -e "Checking PATH..."
if [[ ! "$PATH" =~ (^|:)"/usr/local/bin"(:|$) ]]; then
	export PATH="/usr/local/bin:$PATH"
fi

if [ "$(uname)" == "Darwin" ]; then
	# Mac OS X

	echo -e "\n${BLUE}Installing SDL2 !${NC}"

	rm -fr /tmp/SDL2_install
	mkdir -p /tmp/SDL2_install
	cd /tmp/SDL2_install
	echo -e "${BLUE}Downloading SDL sources...${NC}"
	if ! curl https://libsdl.org/release/SDL2-2.0.4.tar.gz > SDL2-2.0.4.tar.gz; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Unziping sources ...${NC}"
	if ! tar -zxf SDL2-2.0.4.tar.gz; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	cd SDL2-2.0.4
	echo -e "${BLUE}Downloading script...${NC}"
	if ! curl https://hg.libsdl.org/SDL/raw-file/afd286e26823/build-scripts/gcc-fat.sh > gcc-fat.sh; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	if ! chmod 755 gcc-fat.sh; then exit 1; fi
	mkdir build
	cd build
	echo -e "${BLUE}Configure...${NC}"
	if ! CC=/tmp/SDL2_install/SDL2-2.0.4/gcc-fat.sh /tmp/SDL2_install/SDL2-2.0.4/configure; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Building...${NC}"
	if ! make; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Installing...${NC}"
	if ! make install; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	rm -fr /tmp/SDL2_install

	echo -e "\n${BLUE}Installing freetype2 !${NC}\n\n"

	#Install freetype2
	rm -fr /tmp/freetype2_install
	mkdir -p /tmp/freetype2_install
	cd /tmp/freetype2_install
	echo -e "${BLUE}Downloading freetype2 sources...${NC}"
	if ! curl https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/graphics_programming/freetype-2.6.5.tar.gz > freetype-2.6.5.tar.gz; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Unziping sources ...${NC}"
	if ! tar -zxf freetype-2.6.5.tar.gz; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	cd freetype-2.6.5
	echo -e "${BLUE}Configure...${NC}"
	if ! ./configure; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Building...${NC}"
	if ! make; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Installing...${NC}"
	if ! make install; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	rm -fr /tmp/freetype2_install


	echo -e "\n${BLUE}Installing SDL2_ttf !${NC}\n\n"

	#Install SDL2_ttf
	rm -fr /tmp/SDL2_ttf_install
	mkdir -p /tmp/SDL2_ttf_install
	cd /tmp/SDL2_ttf_install
	echo -e "${BLUE}Downloading SDL2_ttf sources...${NC}"
	if ! curl https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz > SDL2_ttf-2.0.14.tar.gz; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Unziping sources ...${NC}"
	if ! tar -zxf SDL2_ttf-2.0.14.tar.gz; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	cd SDL2_ttf-2.0.14
	echo -e "${BLUE}Configure...${NC}"
	if ! ./configure; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Building...${NC}"
	if ! make; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	echo -e "${BLUE}Installing...${NC}"
	if ! make install; then exit 1; fi
	echo -e "${GREEN}Done!${NC}"
	rm -fr /tmp/SDL2_ttf_install

	echo -e "\n${GREEN}All set!${NC}"


elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
	# GNU/Linux

	if ! apt-get install libsdl2-dev; then exit 1; fi
	if ! apt-get install libsdl2-ttf-dev; then exit 1; fi

	echo -e "\n${GREEN}All set!${NC}"

elif [ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]; then
	# Windows NT

	echo "Can't be installed on Windows..."
	echo "Please visit SDL2 website for more informations"
	exit 1
else
	echo "Can't be installed on this operating system..."
	echo "Please visit SDL2 website for more informations"
	exit 1
fi

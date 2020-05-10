[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<p align="center">
  <img src="https://i.imgur.com/hnwTrBB.png" width="100" height="80">
  <h3 align="center">Raise The Terrain</h3>

  <p align="center">
        <em>Plot a 3D grid</em>
    <br /><br />
    <a href="https://github.com/fredhii/Python_Projects/issues">Report Bug</a>
    ·
    <a href="https://github.com/fredhii/Python_Projects/issues">Request Feature</a>
  </p>
</p>

### Usage
- Install SDL2 libraries
```sh
$ chmod 755 0_install_SDL2.sh
$ sudo ./0_install_SDL2.sh
```
- Compile the program
```sh
$ gcc -Wall -Werror -Wextra -pedantic *.c -lm $(sdl2-config --cflags --libs) -o raise_the_terrain
```
- Run the program
```sh
$ ./raise_the_terrain <file>
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.



[contributors-shield]: https://img.shields.io/github/contributors/fredhii/Raise_the_terrain?style=flat-square
[contributors-url]: https://github.com/fredhii/Raise_the_terrain/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/fredhii/Raise_the_terrain.svg?style=flat-square
[forks-url]: https://github.com/fredhii/Raise_the_terrain/network/members
[stars-shield]: https://img.shields.io/github/stars/fredhii/Raise_the_terrain.svg?style=flat-square
[stars-url]: https://github.com/fredhii/Raise_the_terrain/stargazers
[issues-shield]: https://img.shields.io/github/issues/fredhii/Raise_the_terrain?style=flat-square
[issues-url]: https://github.com/fredhii/Raise_the_terrain/issues
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/fredhii

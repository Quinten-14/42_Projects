## 42 Projects

**List of All the 42 Common Core projects and my progress on them:**
| Project Name | Mandatory | Bonus |
|--|--|--|
| Libft | :heavy_check_mark: | :heavy_check_mark:
| Printf| :heavy_check_mark: | &#10007; 
| Born2Beroot | :heavy_check_mark: | Not fully
| Get_Next_line | :heavy_check_mark: | :heavy_check_mark:
| Push_Swap | :heavy_check_mark: | &#10007;
| Pipex | :heavy_check_mark: | :heavy_check_mark:
| Fdf | :heavy_check_mark: | &#10007;
| Philosophers | :heavy_check_mark: | &#10007;
| Minishell | :heavy_check_mark: | &#10007;
| Netpractice | :heavy_check_mark: | N/A
| Cub3D | :heavy_check_mark: | :heavy_check_mark:
| CPP 00-04 | :heavy_check_mark: | &#10007;
| Inceptions | &#10007; | &#10007;
| Cpp 05 - 09 | &#10007; | &#10007;
| Webserv | &#10007; | &#10007;
| Transcendence | &#10007; | &#10007;

As you can see I am not fully done with the CommonCore yet but I am already pretty far. My goal is to finish in the 4th quarter of 2024 and to then apply for internships. But After my internship I still want to do a lot of the specialization projects.

## Overview of the Projects

**Libft**

Libft is a project where you make a standard library with functions you will use a lot over the whole CommonCore. For the project we first need to restrict us to the subject but later we can add any functions we want to it. Mine is still pretty stock because I never had the need to extend it a lot.

[Link to my Libft](https://github.com/Quinten-14/42_Projects/tree/master/42_Libft)

**Printf**

Printf is a very basic project and still making a function actually. In this project we need to remake the Printf function with some basic format specifiers. This project isn't that challenging but it is the first project we have in the commonCore that requires us to create multiple files and link them together. We also learn the concepts of variadic functions. This can be really helpfull for later on.

[Link to my Printf](https://github.com/Quinten-14/42_Projects/tree/master/42_Printf)

**Born2Beroot**

Virtual machines and servers. Always a handy concept to have in your arsenal. In this project we are reached how to set up a server with Debian (Other options like Rocky are also allowed). It also teaches us a bit about security and password policies. Some basic stuff like Sudo and APT are also talked about. In general this project isn't that hard and the bonus of it lets you setup your own Wordpress website if this is something you are interested in.

**Get_Next_Line**

The first real challenge. Not an easy project at all. Get next line makes us write a function we can call later on in the CommonCore to read from files and return the output to a string line per line. This project teaches us a bit about File I/O and teaches us some new functions to use (read, open and close). We also need to use static variables for the first time to safe the buffer state between function calls.

[Link to my GNL](https://github.com/Quinten-14/42_Projects/tree/master/42_Gnl)

**Push_Swap**

Push swap is the first real project that doesn't just let us make a function we can use later. The goal of the project is to make a sorting algorithm that only has a very limited amount of moves and we need to sort a list of integers from low to high in the lowest amount of moves possible. A project where you can really get to know how to optimize your code. This project is hated by some but loved by others. I personally liked it a lot but I have to admit it is not an easy project.

[Link to my Push_Swap](https://github.com/Quinten-14/42_Projects/tree/master/42_Push_Swap)

**Pipex**

A feature not a lot of people outside of the UNIX space know of it the ability to pipe commands togheter. Take the output from one command as the input to another is useful in so many cases. But at 42 we don't like to use stuff that we don't know how it works. So the solution for that? Remake pipes in a small project called Pipex. It is not a big project but for a lot of people really challenging. The new functions you learn are handy for the future projects  but error handling in this project is really handy. The smallest of mistakes can really start to mess stuff up. At the end of the day a project you learn a lot on.

[Link to my Pipex](https://github.com/Quinten-14/42_Projects/tree/master/42_Pipex)

**FdF**

So far one of my favorite projects of the CommonCore. FdF lets you make a 3d map wireframe viewer. You get a bunch of files with maps in and you need to read them and make a nice graphical program for them. The graphical part is handled by MinilibX (X11 under the hood). So not one of the fancy options like Vulcan or openGL but still really powerful in the right hands. The only thing Minilibx isn't great at is performance but this is not the biggest deal breaker yet. The bonus of this project is super nice and also lets you make it so you can rotate the map and zoom in. Sadly I didn't do the bonus but I will revisit this project and do it that time.
 
 [Link to my FDF](https://github.com/Quinten-14/42_Projects/tree/master/42_Fdf)

**Philosophers**

Threads are a very important part of coding and computer science. So why not learn them by making the dining philosophers problem. A super precise project where the smallest bug can throw everything of and all of this while also constantly need to work about deadlocks. Writing this for faster computers isn't that hard but doing it so the campus computers also work fine with it and don't mess up the results is a real challenge. At the end it is all worth it when you can work with threads to make functions run at the same time and don't need to let them wait for another function to finish.

[Link to my Philosophers](https://github.com/Quinten-14/42_Projects/tree/master/42_Philosophers)

**Minishell**

The biggest project possibly of the whole CommonCore. Minishell lets us create a simple version of bash. This is also the first group project. You and Your partner are required to build a few builtins and the environment system. Getting the input and then running the right commands. Using pipes and redirections when needed. This project really teaches you a lot and was so far the most fun I had coding. Here the knowledge I got from pipex really was helpful to make it all work. This project can be made on so many different ways. Even just parsing the input is done on countless different ways. Some people will go for a linked list of a string array, we went for an abstract syntax tree just because we wanted to work with something new. It's actually just a glorified linked list in our minds. But it was super helpful when it came to the execution of the commands and the redirections so it was probably the right call to use it.

[Link to my Minishell](https://github.com/Quinten-14/42_Projects/tree/master/42_Minishell)

[Link to my teammate](https://github.com/LorenzoDP2)

**Netpractice**

This is a really small project and it teaches us the very basics of networking. Using IP addresses and putting masks. Very small and they should go a bit deeper into it but at the end with your own will power you can go as deep into networking as you wish.

**Cub3D**

The final project of the CommonCore with the famous MinilibX library. In this project we go back in time to the 90's, 1992 to be exact. The year where Microsoft releases Windows 3.1 and Euro Disney opens it doors. Well we are not here for that, let's get to the point. Maybe even more important in that year is the birth of the first person shooter genre. Yes I am talking about Wolvenstein 3D. The game that surprised gamers over the whole world and looked amazing in 92. Well let's make that but a bit simpler. We pair up with a fellow student to recreate this legendary game. Well atleast the raycasting engine. The mandatory just makes it so you create a basic game where you can look and move around. But with some of the bonuses you can make this project level up. It really lets you create anything you want as long that it still uses the raycaster under the hood. This project I am really proud of and I would like to do it another time but then with C++ and OpenGL for better performance.

[Link to my Cub3D](https://github.com/Quinten-14/42_Projects/tree/master/42_Cub3d)

[Link to my teammate](https://github.com/Ella-42)

**CPP Modules 00-04**

Well C is nice but what about Object oriented programming? Let me introduce you to C++, let's just call it C on steroids shall we. First I was really scared of C++ but while learning it I really started to love it. Classes and inheritance are some of my favorite concepts I have learned yet. These modules are just step by step little projects that teach us more about how OOP concepts work and how we should use them. 

[Link to my CPP modules](https://github.com/Quinten-14/42_Projects/tree/master/42_Cpp)

These are all the projects I did for now but keep an eye on this repo to checkout more about the other projects once I finished them.

## Some more people I want to mention

Lorenzo - [Github page](https://github.com/LorenzoDP2)
For being an amazing Minishell teammate and A really chill guy

Ella - [Github page](https://github.com/Ella-42)
For being an amazing Cub3D teammate and always super helpful

Elias - [Github page](https://github.com/STROBOLKOP)
Being super helpful and really well educated on Neovim

Pieter - [Github page](https://github.com/P-Claus)
Being super chill and a good talking point for 42 projects

Jalal - [Github page](https://github.com/suspectedoceano) - [Youtube](https://www.youtube.com/@onaecO)
Being the helping hand to a lot of new students and just the GOAT under the 42 Youtubers
